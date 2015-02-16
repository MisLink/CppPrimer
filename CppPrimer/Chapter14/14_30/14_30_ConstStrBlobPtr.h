#ifndef STRBLOB_H
#define STRBLOB_H
#include<memory>
#include<vector>
#include<vector>
class ConstStrBlobPtr;

class StrBlob {
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob( ) :data(std::make_shared<std::vector<std::string>>( )) { }
    StrBlob(std::initializer_list<std::string> il) :data(std::make_shared<std::vector<std::string>>(il)) { }
    StrBlob(const StrBlob & sb) :data(std::make_shared<std::vector<std::string>>(*sb.data)) { }
    StrBlob & operator=(const StrBlob &);
    std::string & operator[](std::size_t n) { return (*data)[n]; }
    const std::string & operator[](std::size_t n) const { return (*data)[n]; }

    size_type size( )const { return data->size( ); }
    bool empty( )const { return data->empty( ); }
    void push_back(const std::string & s) { data->push_back(s); }
    void push_back(std::string && s) { data->push_back(std::move(s)); }
    void pop_back( ) { data->pop_back( ); }
    std::string & front( ) { return data->front( ); }
    std::string & back( ) { return data->back( ); }
    ConstStrBlobPtr begin( );
    ConstStrBlobPtr end( );

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type, const std::string &)const;
};




class ConstStrBlobPtr {
    friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
    friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
public:
    ConstStrBlobPtr( ) :curr(0) { }
    ConstStrBlobPtr(const StrBlob & a, const size_t sz = 0) :wptr(a.data), curr(sz) { }

    const std::string & deref( )const;
    ConstStrBlobPtr & incr( );
    ConstStrBlobPtr & decr( );

    std::string & operator[](std::size_t);
    const std::string & operator[](std::size_t)const;

    ConstStrBlobPtr & operator++();
    ConstStrBlobPtr & operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);

    const std::string & operator*()const;
    const std::string * operator->()const;
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
};
#endif // !STRBLOB_H
