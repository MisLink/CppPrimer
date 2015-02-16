#include"14_32_StrBlobPtr_Pointer.h"

StrBlobPtr & StrBlobPtr_pointer::operator*()const {
    return *(this->pointer);
}
StrBlobPtr * StrBlobPtr_pointer::operator->()const {
    return &this->operator*();
}