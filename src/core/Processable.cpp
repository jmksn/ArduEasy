//
// Created by jhonatan on 12/03/24.
//

#include "Processable.h"

List<Processable> Processable::instances;

Processable::Processable() : enabled(true) {
    _register(this);
}

Processable::~Processable() {
    _unregister(this);
}

void Processable::processInstances() {
    instances.forEach([](Processable &p) {
        if (p.enabled) {
            p.process();
        }
    });
}

bool Processable::isEnabled() {
    return enabled;
}

void Processable::enable() {
    enabled = true;
}

void Processable::disable() {
    enabled = false;
    this->onDisable();
}


/// Register a @Processable instance
/// |param p
void Processable::_register(Processable *p) {
    instances.add(p);
}

void Processable::_unregister(Processable *p) {
    instances.remove(p);
}

void Processable::onDisable() {
}

void ArduEasy::run() {
    Processable::processInstances();
}

