//
// Created by jhonatan on 22/04/25.
//

template<class C>
Between<C>::Between(C &caller, double from, double to) : caller(caller), interval(from, to), callback(nullptr) {
}

template<class C>
C &Between<C>::then(void (*callback)()) {
    this->callback = callback;
    return this->caller;
}

template<class C>
void Between<C>::testAndInvokeCallback(double v) {
    if (callback != nullptr && interval.contains(v)) {
        callback();
    }
}