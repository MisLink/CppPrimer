#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include"DebugDelete.h"
template<typename T, typename D = DebugDelete>
class Unique_ptr {
public:
    Unique_ptr( ) = default;
    Unique_ptr(D d) :del(d) { }
    ~Unique_ptr( ) { del(ptr); }
private:
    T *ptr = nullptr;
    D del = D( );
};
#endif // !UNIQUEPTR_H
