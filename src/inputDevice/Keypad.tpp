//
// Created by jhonatan on 23/04/25.
//

#ifndef ARDUEASY_KEYPAD_TPP
#define ARDUEASY_KEYPAD_TPP

template<byte rows, byte cols>
Keypad<rows, cols>::Keypad(const byte (&row_pins)[rows], const byte (&col_pins)[cols], const char (&keymap)[rows][cols]) :
        row_pins(row_pins), col_pins(col_pins), state(WAITING), keyPressCallback(nullptr),
        readNKeysCallback(nullptr), readKeysUntilKeyPressCallback(nullptr), keymap(keymap),
        nKeys(0), keyCount(0), keyToWait(0), buffer(String("")) {

    colPinsState(LOW);

    for (int i = 0; i < cols; i++) {
        pinMode(col_pins[i], OUTPUT);
    }

    for (int i = 0; i < rows; i++) {
        pinMode(row_pins[i], INPUT_PULLUP);
    }
}

template<byte rows, byte cols>
void Keypad<rows, cols>::colPinsState(unsigned int value) {
    for (int i = 0; i < cols; i++) {
        digitalWrite(col_pins[i], value);
    }
}

template<byte rows, byte cols>
void Keypad<rows, cols>::onPress(void (*cb)(char)) {
    this->keyPressCallback = cb;
}

template<byte rows, byte cols>
void Keypad<rows, cols>::readKeys(int n, void (*cbk)(String)) {
    this->nKeys = n;
    this->readNKeysCallback = cbk;
}

template<byte rows, byte cols>
void Keypad<rows, cols>::readKeys(char key, void (*cbk)(String)) {
    this->keyToWait = key;
    this->readKeysUntilKeyPressCallback = cbk;
}

template<byte rows, byte cols>
void Keypad<rows, cols>::reset() {
    this->buffer = String("");
    this->keyCount = 0;
}

template<byte rows, byte cols>
void Keypad<rows, cols>::process() {
    if (state == WAITING) {
        processWaiting();
    } else if (state == PRESSED) {
        processPressed();
    } else {
        processReleased();
    }
}

template<byte rows, byte cols>
void Keypad<rows, cols>::processPressed() {
    for (int i = 0; i < cols; i++) {
        if (i != 0)
            digitalWrite(col_pins[i - 1], HIGH);
        digitalWrite(col_pins[i], LOW);
        if (digitalRead(row_pins[row]) == LOW) {
            const char &key = keymap[row][i];
            if (keyPressCallback != nullptr) {
                keyPressCallback(key);
            }
            if (nKeys > 0 || keyToWait != 0) {
                buffer += String(key);
                if (nKeys > 0) {
                    keyCount++;
                    if (keyCount == nKeys) {
                        if (readNKeysCallback != nullptr) {
                            readNKeysCallback(buffer);
                        }
                        reset();
                    }
                }

                if (key == keyToWait) {
                    if (readKeysUntilKeyPressCallback != nullptr) {
                        readKeysUntilKeyPressCallback(buffer.substring(0, buffer.length() - 1));
                    }
                    reset();
                }
            }
            colPinsState(LOW);
            state = RELEASED;
            break;
        }
    }
}

template<byte rows, byte cols>
void Keypad<rows, cols>::processWaiting() {
    for (int i = 0; i < rows; i++) {
        if (digitalRead(row_pins[i]) == LOW) {
            row = i;
            colPinsState(HIGH);
            state = PRESSED;
        }
    }
}

template<byte rows, byte cols>
void Keypad<rows, cols>::processReleased() {
    if (digitalRead(row_pins[row]) == HIGH) {
        state = WAITING;
    }
}

#endif //ARDUEASY_KEYPAD_TPP
