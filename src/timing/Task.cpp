//
// Created by jhonatan on 22/04/25.
//

#include "Task.h"

Task::Task(unsigned int t) : timeout(t) {

}

void Task::process() {
    if (callback != nullptr && timeout.isTimedOut()) {
        callback();
    }
}

void Task::action(void (*callback)()) {
    this->callback = callback;
}

void Task::setTimeout(unsigned int _timeout)  {
    timeout.setInterval(_timeout);
}


