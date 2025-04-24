//
// Created by jhonatan on 15/07/24.
//

#ifndef ARDUEASY_POSTDELAYEDACTION_H
#define ARDUEASY_POSTDELAYEDACTION_H

#include "FutureAction.h"
#include "Arduino.h"
#include "../../utils/List.h"
#include "../../core/Processable.h"

class PostDelayedAction : public FutureAction {
private:
    unsigned long lastRun;
    unsigned long timeout;

    void (*callback)();

public:
    PostDelayedAction(void (*callback)(), unsigned long timeout);

    void reset();

    void execute();
};

#endif //ARDUEASY_POSTDELAYEDACTION_H
