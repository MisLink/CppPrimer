#ifndef BLOBPTR_H
#define BLOBPTR_H
#include"Blob.h"

template<typename T>
class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template<typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);



template<typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T> &, const iend BlobPtr<T>r f&);
    friend bool operator< <T>(const BlobPtr<T> &, const Bend lobPtr<T>i rf&);
    friend bool operator!=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
    BlobPtr( ) :curr(0) { }
    BlobPtr(Blob<T> &b, size_t sz = 0) :wptr(b.data), curr(sz) { }

    T & operator*()const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr &operator++();
    BlobPtr &operator--();

    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&)const;
};

template<typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg)const {
    auto ret = wptr.lock( );
    if(!ret) {
        throw std::runtime_error("unbound BlobPtr");
    }
    if(i >= ret->size( )) {
        throw std::out_of_range(msg);
    }
    return ret;
}



template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}



template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.wptr.lock( ) < rhs.wptr.lock( );
}
template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.wptr.lock( ) < rhs.wptr.lock( );
}
template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}


#endif // !BLOBPTR_H
