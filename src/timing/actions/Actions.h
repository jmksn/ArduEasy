//
// Created by jhonatan on 23/03/24.
//

#ifndef ARDUEASY_ACTIONS_H
#define ARDUEASY_ACTIONS_H

#include "../../core/Processable.h"
#include "../../utils/List.h"
#include "Arduino.h"
#include "FutureAction.h"
#include "PostDelayedAction.h"
#include "WaitForConditionAction.h"

class Actions : public Processable {
private:
    List<FutureAction> actions;
    ActionState state;
    bool repeat;
public:
    Actions(bool repeat = false);

    Actions &add(FutureAction *action);

    Actions &doAndWait(void (*callback)(), long delay);

    Actions &_do(void (*callback)());

    Actions &wait(long delay);

    Actions &waitFor(bool (*function)());

    void execute();

    bool isRunning();

    void stop();

    void process();
};

#endif //ARDUEASY_ACTIONS_H
