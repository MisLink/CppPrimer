#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include"DebugDelete.h"
#include<iostream>
#include<functional>
template<typename T>
class Shared_ptr {
public:
    Shared_ptr( ) = default;
    Shared_ptr(const Shared_ptr &sp) :ptr(sp.ptr), count(sp.count), del(sp.del) {
        ++*count;
    }
    Shared_ptr &operator=(const Shared_ptr &rhs);

    operator bool( )const { return ptr ? true : false; }

    T &operator*()const { return *ptr; }
    T *operator->()const { return &this->operator*(); }

    
    ~Shared_ptr( );
private:
    T *ptr = nullptr;
    std::size_t *count = new std::size_t(1);
    std::function<void(T *)> del = DebugDelete( );
};

template<typename T>
Shared_ptr<T>::~Shared_ptr( ) {
    --*count;
    if(*count == 0) {
        del(p);
        delete count;
    }
}

#endif // !SHAREDPTR_H
