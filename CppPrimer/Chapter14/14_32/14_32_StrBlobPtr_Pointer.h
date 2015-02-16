#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H
#include"14_30_StrBlob.h"
class StrBlobPtr_pointer {
public:
    StrBlobPtr_pointer( ) = default;
    StrBlobPtr_pointer(StrBlobPtr * p) :pointer(p) { }

    StrBlobPtr & operator*()const;
    StrBlobPtr * operator->()const;
private:
    StrBlobPtr * pointer = nullptr;
};
#endif // !STRBLOBPTR_POINTER_H
