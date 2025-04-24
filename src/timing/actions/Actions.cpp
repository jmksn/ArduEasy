//
// Created by jhonatan on 23/03/24.
//

#include "Actions.h"

Actions::Actions(bool repeat = false) : repeat(repeat), state(STOPPED) {}

Actions &Actions::add(FutureAction *action) {
    actions.add(action);
    return *this;
}

Actions &Actions::doAndWait(void (*callback)(), long delay) {
    return add(new PostDelayedAction(callback, delay));
}

Actions &Actions::_do(void (*callback)()) {
    return doAndWait(callback, 0);
}

Actions &Actions::wait(long delay) {
    return doAndWait(nullptr, delay);
}

Actions &Actions::waitFor(bool (*function)()) {
    return add(new WaitForConditionAction(function));
}

void Actions::execute() {
    state = RUNNING;
}

void Actions::process() {

    if (state != RUNNING || actions.getSize() == 0) {
        return;
    }

    FutureAction *currentAction = actions.getCurr();

    if (currentAction->getState() == FINISHED) {
        currentAction->setState(STOPPED);
        actions.next();
        if (actions.hasNext()) {
            currentAction = actions.getCurr();
        } else if (repeat) {
            currentAction = actions.first();
        } else {
            stop();
            return;
        }
    }

    if (currentAction->getState() == STOPPED) {
        currentAction->reset();
        currentAction->setState(RUNNING);
    }

    if (currentAction->getState() == RUNNING) {
        currentAction->execute();
    }

}

void Actions::stop() {
    FutureAction *currentAction = actions.getCurr();
    if (currentAction != nullptr) {
        currentAction->setState(STOPPED);
        currentAction->reset();
    }
    state = STOPPED;
    actions.first();
}

bool Actions::isRunning() {
    return isEnabled() && state == RUNNING;
}

