#ifndef STRING_H
#define STRING_H
#include<memory>
#include<iostream>
class String {
    friend std::ostream & operator<<(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend bool operator<=(const String &, const String &);
public:
    String( ) :elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char * const);
    String(const String &);
    String(String &&);
    String & operator=(const String &);
    String & operator=(String &&);
    char & operator[](std::size_t n) { return elements[n]; }
    const char & operator[](std::size_t n)const { return elements[n]; }
    ~String( ) { free( ); }

    char * begin( )const { return elements; }
    char * end( )const { return first_free; }
    std::size_t size( )const { return first_free - elements; }
private:
    char * elements;
    char * first_free;
    char * cap;
    std::allocator<char> alloc;
    void free( );
};
#endif // !STRING_H
