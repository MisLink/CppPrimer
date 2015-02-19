#include"Query.h"
#include<algorithm>
#include<iterator>
QueryResult NotQuery::eval(const TextQuery &text)const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>( );
    auto beg = result.begin( ), end = result.end( );

    auto sz = result.get_file( )->size( );
    for(size_t n = 0; n != sz; ++n) {
        if(beg == end || *beg != n) {
            ret_lines->insert(n);
        } else if(beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep( ), ret_lines, result.get_file( ));
}

QueryResult OrQuery::eval(const TextQuery &text)const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin( ), left.end( ));
    ret_lines->insert(right.begin( ), right.end( ));

    return QueryResult(rep( ), ret_lines, left.get_file( ));
}

QueryResult AndQuery::eval(const TextQuery &text)const {
    auto left = lhs.eval(text), right = rhs.eval(text);

    auto ret_lines = std::make_shared<std::set<line_no>>( );
    std::set_intersection(left.begin( ), left.end( ), right.begin( ), right.end( ), std::inserter(*ret_lines, ret_lines->begin( )));
    return QueryResult(rep( ), ret_lines, left.get_file( ));
}
