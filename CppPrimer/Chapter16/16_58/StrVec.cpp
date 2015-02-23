#include"StrVec.h"
#include<algorithm>
StrVec::StrVec(const StrVec & s) {
    auto newdata = alloc_n_copy(s.begin( ), s.end( ));
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec & StrVec::operator=(const StrVec & rhs) {
    auto newdata = alloc_n_copy(rhs.begin( ), rhs.end( ));
    free( );
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}
StrVec::StrVec(StrVec && s) :elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec & StrVec::operator=(StrVec && rhs) {
    if(this != &rhs) {
        free( );
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
StrVec & StrVec::operator=(std::initializer_list<std::string> il) {
    auto newdata = alloc_n_copy(il.begin( ), il.end( ));
    free( );
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}
StrVec::~StrVec( ) {
    free( );
}

void StrVec::push_back(const std::string & s) {
    chk_n_alloc( );
    alloc.construct(first_free++, s);
}
template<typename... Args>
void StrVec::emplace_back(Args&&... args) {
    chk_n_alloc( );
    alloc.construct(first_free++, std::forward<Args>(args)...);
}


void StrVec::reserve(std::size_t n) {
    if(n <= capacity( )) {
        return;
    }
    std::string * newdata = alloc.allocate(n);
    std::string * dest = newdata;
    std::string * elem = elements;
    for(std::size_t i = 0; i != size( ); ++i) {
        alloc.construct(dest++, *elem++);
    }
    free( );
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}
void StrVec::resize(std::size_t n) {
    resize(n, std::string( ));
}
void StrVec::resize(std::size_t n, const std::string & s) {
    if(n < size( )) {
        for(auto p = elements + n; p != first_free;) {
            alloc.destroy(p++);
        }
        first_free = elements + n;
    } else if(n > size( )) {
        for(auto i = size( ); i != n; ++i) {
            push_back(std::string(s));
        }
    }
}
void StrVec::reallocate( ) {
    std::size_t newcap = size( ) ? 2 * size( ) : 1;
    std::string * newdata = alloc.allocate(newcap);
    std::string * dest = newdata;
    std::string * elem = elements;
    for(std::size_t i = 0; i != size( ); ++i) {
        alloc.construct(dest++, *elem++);
    }
    free( );
    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}

inline std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string * b, const std::string * e) {
    std::string * data = alloc.allocate(e - b);
    return std::make_pair(data, std::uninitialized_copy(b, e, data));
}

void StrVec::free( ) {
    if(elements) {
        std::for_each(elements, first_free, [&](std::string & p) {alloc.destroy(&p); });
    }
    alloc.deallocate(elements, cap - elements);
}

inline bool operator==(const StrVec & lhs, const StrVec & rhs) {
    if(lhs.size( ) == rhs.size( )) {
        auto r = rhs.begin( );
        for(auto l = lhs.begin( ); l != lhs.end( ); ++l) {
            if(*l != *r) {
                return false;
            } else {
                ++r;
            }
        }
        return true;
    } else {
        return false;
    }
}
inline bool operator!=(const StrVec & lhs, const StrVec & rhs) {
    return !(lhs == rhs);
}
inline bool operator>(const StrVec & lhs, const StrVec & rhs) {
    auto r = rhs.begin( );
    for(auto l = lhs.begin( ); l != lhs.end( ); ++l) {
        if(*l <= *r) {
            return false;
        } else {
            if(*l > *r) {
                return true;
            } else {
                r++;
            }
        }
    }
    if(r == rhs.end( )) {
        return false;
    } else {
        return true;
    }
}
inline bool operator<(const StrVec & lhs, const StrVec & rhs) {
    if(lhs == rhs) {
        return false;
    } else {
        return !(lhs > rhs);
    }
}
inline bool operator>=(const StrVec & lhs, const StrVec & rhs) {
    return !(lhs < rhs);
}
inline bool operator<=(const StrVec & lhs, const StrVec & rhs) {
    return !(lhs > rhs);
}