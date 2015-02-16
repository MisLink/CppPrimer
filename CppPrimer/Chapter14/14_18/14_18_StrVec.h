#ifndef STRVEC_H
#define STRVEC_H
#include<memory>
#include<string>
class StrVec {
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);
    friend bool operator>=(const StrVec &, const StrVec &);
    friend bool operator<=(const StrVec &, const StrVec &);
public:
    StrVec( ) :elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec &);
    StrVec & operator=(const StrVec &);
    StrVec(StrVec &&);
    StrVec & operator=(StrVec &&);
    ~StrVec( );

    void push_back(const std::string &);

    std::size_t size( )const { return first_free - elements; }
    std::size_t capacity( )const { return cap - elements; }

    std::string * begin( )const { return elements; }
    std::string * end( )const { return first_free; }

    void reserve(std::size_t);
    void resize(std::size_t);
    void resize(std::size_t, const std::string &);
private:
    static std::allocator<std::string> alloc;

    void chk_n_alloc( ) { if(size( ) == capacity( )) reallocate( ); }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free( );
    void reallocate( );

    std::string * elements;
    std::string * first_free;
    std::string * cap;
};

inline bool operator==(const StrVec &, const StrVec &);
inline bool operator!=(const StrVec &, const StrVec &);
#endif // !STRVEC_H
