#include "SinglePinDev.h"

uint8_t SinglePinDev::getPin() {
    return pin;
}

SinglePinDev::SinglePinDev(uint8_t pin) : pin(pin)  {

}
