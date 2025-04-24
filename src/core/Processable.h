//
// Created by jhonatan on 22/03/2020.
//

#ifndef ARDUEASY_PROCESSABLE_H
#define ARDUEASY_PROCESSABLE_H

#include "../utils/List.h"

namespace ArduEasy {
    void run();
}

/// Base class for all hardware or software that needs a periodic execution
class Processable {
private:
    static List<Processable> instances;
    bool enabled;

    /// Register a @Processable instance
    /// |param p
    static void _register(Processable *p);

    static void _unregister(Processable *p);

    virtual void onDisable();

    virtual void process() = 0;

    static void processInstances();

public:
    Processable();

    virtual ~Processable();

    bool isEnabled();

    void enable();

    void disable();

    friend void ArduEasy::run();
};

#endif //ARDUEASY_PROCESSABLE_H
