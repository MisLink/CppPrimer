#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

class QueryResult {
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

#endif
