#ifndef QUERYRESULT_H
//#define QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

class QueryResult {
    friend std::ostream &operator<<(std::ostream &, QueryResult &);
public:
    using line_no = std::vector<std::string>::size_type;
    using Result_iter = std::set<line_no>::const_iterator;

    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) :sought(s), lines(p), file(f) { }

    Result_iter begin( ) const { return lines->begin( ); }
    Result_iter end( ) const { return lines->end( ); }
    std::shared_ptr<std::vector<std::string> > get_file( ) { return file; }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

inline std::ostream & operator<<(std::ostream &os, QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size( ) << " "
        << (qr.lines->size( ) == 1 ? "time" : "times") << std::endl;
    for(auto num = qr.lines->begin( );
        num != qr.lines->end( ); ++num)
        os << "\t(line " << *num + 1 << ") "
        << *(qr.file->begin( ) + *num) << std::endl;
    return os;
}

#endif
