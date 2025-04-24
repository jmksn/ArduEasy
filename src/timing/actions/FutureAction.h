//
// Created by jhonatan on 14/07/24.
//

#ifndef ARDUEASY_FUTUREACTION_H
#define ARDUEASY_FUTUREACTION_H

#include "Arduino.h"
#include "../../utils/List.h"
#include "../../core/Processable.h"

enum ActionState {
    STOPPED,
    RUNNING,
    FINISHED
};

class FutureAction {
private:
    ActionState state;
    virtual void onStateChange(ActionState &newState);

public:
    FutureAction();

    ActionState getState();

    virtual void reset();

    void terminate();

    virtual void execute() = 0;

    void setState(ActionState state);
};

#endif //ARDUEASY_FUTUREACTION_H
