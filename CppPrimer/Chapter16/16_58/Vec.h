#ifndef VEC_H
#define VEC_H
#include<memory>
#include<algorithm>

template<typename T>
class Vec;
template<typename T>
bool operator==(const Vec<T> &, const Vec<T> &);
template<typename T>
bool operator!=(const Vec<T> &, const Vec<T> &);
template<typename T>
bool operator>(const Vec<T> &, const Vec<T> &);
template<typename T>
bool operator<(const Vec<T> &, const Vec<T> &);
template<typename T>
bool operator>=(const Vec<T> &, const Vec<T> &);
template<typename T>
bool operator<=(const Vec<T> &, const Vec<T> &);

template<typename T>
class Vec {
    friend bool operator==<T>(const Vec &, const Vec &);
    friend bool operator!=<T>(const Vec &, const Vec &);
    friend bool operator><T>(const Vec &, const Vec &);
    friend bool operator< <T>(const Vec &, const Vec &);
    friend bool operator>=<T>(const Vec &, const Vec &);
    friend bool operator<=<T>(const Vec &, const Vec &);
public:
    Vec( ) :elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(const Vec &);
    Vec & operator=(const Vec &);
    Vec(Vec &&);
    Vec & operator=(Vec &&);
    Vec & operator=(std::initializer_list<T>);
    T & operator[](std::size_t n) { return elements[n]; }
    const T & operator[](std::size_t n)const { return elements[n]; }
    ~Vec( );

    void push_back(const T &);
    template<typename... Args>
    void emplace_back(Args&&...);

    std::size_t size( )const { return first_free - elements; }
    std::size_t capacity( )const { return cap - elements; }

    T * begin( )const { return elements; }
    T * end( )const { return first_free; }

    void reserve(std::size_t);
    void resize(std::size_t);
    void resize(std::size_t, const T &);
private:
    static std::allocator<T> alloc;

    void chk_n_alloc( ) { if(size( ) == capacity( )) reallocate( ); }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free( );
    void reallocate( );

    T * elements;
    T * first_free;
    T * cap;
};

template<typename T>
Vec<T>::Vec(const Vec &s) {
    auto newdata = alloc_n_copy(s.begin( ), s.end( ));
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin( ), rhs.end( ));
    free( );
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

template<typename T>
Vec<T>::Vec(Vec &&s) :elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) {
    if(this != &rhs) {
        free( );
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template<typename T>
Vec<T> & Vec<T>::operator=(std::initializer_list<T> il) {
    auto newdata = alloc_n_copy(il.begin( ), il.end( ));
    free( );
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

template<typename T>
Vec<T>::~Vec( ) {
    free( );
}

template<typename T>
void Vec<T>::push_back(const T &t) {
    chk_n_alloc( );
    alloc.construct(first_free++, t);
}

template<typename T>
template<typename... Args>
void Vec<T>::emplace_back(Args&&... args) {
    chk_n_alloc( );
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template<typename T>
void Vec<T>::reserve(std::size_t n) {
    if(n <= capacity( )) {
        return;
    }
    T *newdata = alloc.allocate(n);
    T *dest = newdata;
    T *elem = elements;
    for(std::size_t i = 0; i != size( ); ++i) {
        alloc.construct(dest++, *elem++);
    }
    free( );
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

template<typename T>
void Vec<T>::resize(std::size_t n) {
    resize(n, T( ));
}

template<typename T>
void Vec<T>::resize(std::size_t n, const T &t) {
    if(n < size( )) {
        for(auto p = elements + n; p != first_free;) {
            alloc.destroy(p++);
        }
        first_free = elements + n;
    } else if(n > size( )) {
        for(auto i = size( ); i != n; ++i) {
            push_back(t);
        }
    }
}

template<typename T>
void Vec<T>::reallocate( ) {
    std::size_t newcap = size( ) ? 2 * size( ) : 1;
    T *newdata = alloc.allocate(newcap);
    T *dest = newdata;
    T *elem = elements;
    for(std::size_t i = 0; i != size( ); ++i) {
        alloc.construct(dest++; *elem++);
    }
    free( );
    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}

template<typename T>
std::pair<T *, T*>
Vec<T>::alloc_n_copy(const T *b, const T *e) {
    T *data = alloc.allocate(e - b);
    return std::make_pair(data, std::uninitialized_copy(b, e, data));
}

template<typename T>
void Vec<T>::free( ) {
    if(elements) {
        std::for_each(elements, first_free, [this](t &t) {alloc.destroy(&p); });
    }
    alloc.deallocate(elements, cap - elements);
}

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    if(lhs.size( ) == rhs.size( )) {
        auto r = rhs.begin( );
        for(auto l = lhs.begin( ); l != lhs.end( ); ++l) {
            if(*l != *r) {
                return false;
            } else {
                r++;
            }
        }
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}
template<typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    auto r = rhs.begin( );
    for(auto l = lhs.begin( ); l != lhs.end( ); ++l) {
        if(*l <= *r) {
            return false;
        } else {
            ++r;
        }
    }
    if(r == rhs.end( )) {
        return false;
    } else {
        return true;
    }
}
template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    if(lhs == rhs) {
        return false;
    } else {
        return !(lhs > rhs);
    }
}
template<typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
}
template<typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs > rhs);
}













#endif // !VEC_H
