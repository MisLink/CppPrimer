#include"Sales_data.h"
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using std::vector;
using std::string;
class match {
private:
    vector<Sales_data>::size_type st;
    vector<Sales_data>::const_iterator it1;
    vector<Sales_data>::const_iterator it2;
public:
    match(vector<Sales_data>::size_type s, vector<Sales_data>::const_iterator i1, vector<Sales_data>::const_iterator i2) :st(s), it1(i1), it2(i2) { }
};
vector<match> findBook(const vector<vector<Sales_data>> &files, const string &book) {
    vector<match> ret;
    for(auto i = files.begin( ); i != files.end( ); ++i) {
        auto found = std::equal_range(i->begin( ), i->end( ), book, compareIsbn);
        if(found.first != found.second) {
            ret.push_back(match(i - files.begin( ), found.first, found.second));
        }
    }
    return ret;
}

int main( ) {
    return 0;
}