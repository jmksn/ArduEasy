//
// Created by jhonatan on 14/07/24.
//

#include "FutureAction.h"

FutureAction::FutureAction() : state(STOPPED) {

}

ActionState FutureAction::getState() {
    return state;
}

void FutureAction::reset() {}

void FutureAction::terminate() {
    state = FINISHED;
}

void FutureAction::setState(ActionState state) {
    this->state = state;
    this->onStateChange(state);
}

void FutureAction::onStateChange(ActionState &newState) {

}