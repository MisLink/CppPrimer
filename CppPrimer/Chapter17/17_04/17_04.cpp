#include"Sales_data.h"
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using std::vector;
using std::string;
using matches = std::tuple < vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator > ;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;
    for(auto i = files.begin( ); i != files.end( ); ++i) {
        auto found = std::equal_range(i->begin( ), i->end( ), book, compareIsbn);
        if(found.first != found.second) {
            ret.push_back(std::make_tuple(i - files.begin( ), found.first, found.second));
        }
    }
    return ret;
}

int main( ) {
    return 0;
}