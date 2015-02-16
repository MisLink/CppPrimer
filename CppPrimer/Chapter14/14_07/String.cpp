#include"14_07_String.h"
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