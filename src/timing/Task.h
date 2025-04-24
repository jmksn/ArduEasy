//
// Created by jhonatan on 22/03/2020.
//

#ifndef ARDUEASY_TASK_H
#define ARDUEASY_TASK_H

#include "../core/Processable.h"
#include "../core/Timeout.h"

class Task : public Processable {
private:
    Timeout timeout;

    void (*callback)();

    void process();

public:

    Task(unsigned int t);

    void action(void (*callback)());

    void setTimeout(unsigned int _timeout);
};


#endif //ARDUEASY_TASK_H
