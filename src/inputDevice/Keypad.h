//
// Created by jhonatan on 23/04/25.
//

#ifndef ARDUEASY_KEYPAD_H
#define ARDUEASY_KEYPAD_H

enum KeypadState : uint8_t {
    WAITING,
    PRESSED,
    RELEASED
};

/// Class that implements a generic matrix keypad.
template<byte rows, byte cols>
class Keypad : public Processable {
private:
    byte row;
    const byte (&row_pins)[rows];
    const byte (&col_pins)[cols];
    const char (&keymap)[rows][cols];
    String buffer;
    KeypadState state;
    byte keyCount;
    byte nKeys;
    char keyToWait;

    void (*keyPressCallback)(char); //callback to call on key press
    void (*readNKeysCallback)(String); //callback to call passing buffer after read N keys
    void (*readKeysUntilKeyPressCallback)(String); //callback to call passing buffer after some key pressed

    /// Set columns pins state
    /// \param value
    void colPinsState(unsigned int value);

public:
    /// Class constructor
    /// \param row_pins Row pins
    /// \param col_pins Column pins
    /// \param keymap Keymap matrix
    Keypad(const byte (&row_pins)[rows], const byte (&col_pins)[cols], const char (&keymap)[rows][cols]);

    /// Set callback to be called on any key press.
    /// \param cb
    void onPress(void (*cb)(char));

    /// Set callback to be called after read N keys.
    /// \param n Number of keys to be read.
    /// \param cbk Function that receives a String containing N read keys.
    void readKeys(int n, void (*cbk)(String));

    /// Set callback to be called after some key pressed.
    /// \param key Key that indicates inputting finish.
    /// \param cbk Function that receives a String containing read keys (Including last key pressed).
    void readKeys(char key, void (*cbk)(String));

    /// Clear read keys buffer.
    void reset();

    void process();
    void processPressed();
    void processWaiting();
    void processReleased();
};

#include "Keypad.tpp"

#endif //ARDUEASY_KEYPAD_H
