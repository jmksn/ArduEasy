//
// Created by jhonatan on 22/04/25.
//

#ifndef LIST_TPP
#define LIST_TPP

template<class T>
List<T>::List() : head(nullptr), curr(nullptr), last(nullptr), size(0) {};

template<class T>
List<T>::~List() {
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }

}

template<class T>
void List<T>::add(T *d) {
    Node<T> *n = new Node<T>();
    n->data = d;
    n->prev = nullptr;
    n->next = nullptr;
    size++;
    if (head == nullptr) {
        head = n;
        last = n;
        curr = n;
    } else {
        n->prev = last;
        last->next = n;
        last = n;
    }
}

template<class T>
bool List<T>::remove(T *d) {
    Node<T> *prev = nullptr;
    for (Node<T> *p = head; p != nullptr; p = p->next) {
        if (p->data == d) {

            if (p == head) {
                head = p->next;
            } else if (p == last) {
                prev->next = nullptr;
                last = prev;
            } else {
                prev->next = p->next;
            }

            delete p;
            size--;
            return true;
        }
        prev = p;
    }
    return false;
}

template<class T>
void List<T>::pop() {
    if (head != nullptr) {
        Node<T> *n = head;
        head = head->next;
        delete n;
        size--;
    }
}

template<class T>
template<class F>
void List<T>::forEach(F f) {
    this->first();
    while (this->hasNext()) {
        T *e = this->next();
        f(*e);
    }
}

template<class T>
void List<T>::clear(bool delete_data = false) {
    curr = head;
    while (curr != nullptr) {
        Node<T> *aux = curr;
        curr = curr->next;
        if (delete_data)
            delete aux->data;
        delete aux;
    }
    head = nullptr;
    size = 0;
}

template<class T>
unsigned int List<T>::getSize() {
    return size;
}

template<class T>
T* List<T>::first() {
    curr = head;
    return curr->data;
}

template<class T>
bool List<T>::hasNext() {
    return (curr != nullptr);
}

template<class T>
T* List<T>::next() {
    T *d = curr->data;
    curr = curr->next;
    return d;
}

template<class T>
T* List<T>::getCurr() {
    if (curr == nullptr) return nullptr;
    return curr->data;
}

#endif //LIST_TPP
