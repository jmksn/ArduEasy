//
// Created by jhonatan on 14/07/24.
//

#include "WaitForConditionAction.h"

WaitForConditionAction::WaitForConditionAction(bool (*function)()) : func(function) {

}

void WaitForConditionAction::execute() {
    if (func == nullptr || func()) {
        terminate();
    }
}
