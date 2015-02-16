#include"14_30_ConstStrBlobPtr.h"

inline bool operator==(const StrBlob & lhs, const StrBlob & rhs) {
    return *lhs.data == *rhs.data;
}
inline bool operator!=(const StrBlob & lhs, const StrBlob & rhs) {
    return !(lhs == rhs);
}
inline bool operator>(const StrBlob & lhs, const StrBlob & rhs) {
    return *lhs.data > *rhs.data;;
}
inline bool operator<(const StrBlob & lhs, const StrBlob & rhs) {
    return *lhs.data < *rhs.data;;
}
inline bool operator>=(const StrBlob & lhs, const StrBlob & rhs) {
    return *lhs.data >= *rhs.data;;
}
inline bool operator<=(const StrBlob & lhs, const StrBlob & rhs) {
    return *lhs.data <= *rhs.data;;
}

inline StrBlob & StrBlob::operator=(const StrBlob & sb) {
    auto p = std::make_shared<std::vector<std::string>>(*sb.data);
}
inline ConstStrBlobPtr StrBlob::end( ) {
    ConstStrBlobPtr ret = ConstStrBlobPtr(*this, data->size( ));
    return ret;
}
inline ConstStrBlobPtr StrBlob::begin( ) {
    return ConstStrBlobPtr(*this);
}
void StrBlob::check(size_type i, const std::string & msg)const {
    if(i >= data->size( )) {
        throw std::out_of_range(msg);
    }
}



inline bool operator==(const ConstStrBlobPtr & lhs, const ConstStrBlobPtr & rhs) {
    auto l = lhs.wptr.lock( );
    auto r = rhs.wptr.lock( );
    if(l == r) {
        if(lhs.curr == rhs.curr) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
inline bool operator!=(const ConstStrBlobPtr & lhs, const ConstStrBlobPtr & rhs) {
    return !(lhs == rhs);
}

inline const std::string & ConstStrBlobPtr::deref( )const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
inline std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string & msg)const {
    auto ret = wptr.lock( );
    if(!ret) {
        throw std::runtime_error("unbound ConstStrBlobPtr");
    }
    if(i >= ret->size( )) {
        throw std::out_of_range(msg);
    }
    return ret;
}

inline ConstStrBlobPtr & ConstStrBlobPtr::incr( ) {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}
inline ConstStrBlobPtr & ConstStrBlobPtr::decr( ) {
    --curr;
    check(-1, "decrement past begin of ConstStrBlobPtr");
    return *this;
}

std::string & ConstStrBlobPtr::operator[](std::size_t n) {
    auto p = check(n, "unbound or out of range");
    return (*p)[n];
}
const std::string & ConstStrBlobPtr::operator[](std::size_t n)const {
    auto p = check(n, "unbound or out of range");
    return (*p)[n];
}

ConstStrBlobPtr & ConstStrBlobPtr::operator++() {
    check(curr, "increment past end of ConstStrBlobPtr");
    curr++;
    return *this;
}
ConstStrBlobPtr & ConstStrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of ConstStrBlobPtr");
    return *this;
}
ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}

ConstStrBlobPtr operator+(const ConstStrBlobPtr & lhs, std::size_t n) {
    ConstStrBlobPtr ret = lhs;
    ret.curr = lhs.curr + n;
    lhs.check(ret.curr, "past end of ConstStrBlobPtr");
    return ret;
}
ConstStrBlobPtr operator-(const ConstStrBlobPtr & lhs, std::size_t n) {
    ConstStrBlobPtr ret = lhs;
    ret.curr = lhs.curr - n;
    lhs.check(ret.curr, "past end of ConstStrBlobPtr");
    return ret;
}

const std::string & ConstStrBlobPtr::operator*()const {
    auto p = check(curr, "dereference past end");
    return(*p)[curr];
}

const std::string * ConstStrBlobPtr::operator->()const {
    return &this->operator*();
}