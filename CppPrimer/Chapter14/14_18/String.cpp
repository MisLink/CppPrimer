#include"14_18_String.h"
#include<algorithm>
String::String(const char * const c) {
    auto p = c;
    std::size_t len = 0;
    while(*p++ != '\0') {
        len++;
    }
    auto newdata = alloc.allocate(len);
    std::uninitialized_copy(c, c + len, newdata);
    elements = newdata;
    cap = first_free = newdata + len;
}
String::String(const String & s) {
    auto newdata = alloc.allocate(s.size( ));
    std::uninitialized_copy(s.begin( ), s.end( ), newdata);
    elements = newdata;
    cap = first_free = newdata + s.size( );
}
String::String(String && s) :elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

String & String::operator=(const String & rhs) {
    auto newdata = alloc.allocate(rhs.size( ));
    std::uninitialized_copy(rhs.begin( ), rhs.end( ), newdata);
    free( );
    elements = newdata;
    cap = first_free = newdata + rhs.size( );
    return *this;
}
String & String::operator=(String && rhs) {
    if(this != &rhs) {
        free( );
        elements = rhs.elements;
        cap = rhs.cap;
        first_free = rhs.first_free;
        rhs.elements = rhs.cap = rhs.first_free = nullptr;
    }
    return *this;
}

void String::free( ) {
    if(elements) {
        std::for_each(elements, first_free, [this](char & p) {alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

std::ostream & operator<<(std::ostream & os, const String & s) {
    for(char c : s) {
        std::cout << c;
    }
    return os;
}
bool operator==(const String & lhs, const String & rhs) {
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
bool operator!=(const String & lhs, const String & rhs) {
    return !(lhs == rhs);
}

bool operator>(const String & lhs, const String & rhs) {
    auto r = rhs.begin( );
    for(auto l = lhs.begin( ); l != lhs.end( ); ++l) {
        if(*r <= *l) {
            return false;
        } else {
            if(*r > *l) {
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
bool operator<(const String & lhs, const String & rhs) {
    if(lhs == rhs) {
        return false;
    } else {
        return !(lhs > rhs);
    }
}
bool operator>=(const String & lhs, const String & rhs) {
    return !(lhs < rhs);
}
bool operator<=(const String & lhs, const String & rhs) {
    return !(lhs > rhs);
}
