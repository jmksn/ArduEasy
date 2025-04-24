//
// Created by jhonatan on 14/07/24.
//

#ifndef ARDUEASY_WAITFORCONDITIONACTION_H
#define ARDUEASY_WAITFORCONDITIONACTION_H


#include "Actions.h"
#include "FutureAction.h"

class WaitForConditionAction : public FutureAction {
public:
    WaitForConditionAction(bool (*function)());
    void execute();
private:
    bool (*func)();
};


#endif //ARDUEASY_WAITFORCONDITIONACTION_H
