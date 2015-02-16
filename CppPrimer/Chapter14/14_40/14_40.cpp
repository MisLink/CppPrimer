#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::sort;
using std::stable_sort;
using std::find_if;
using std::for_each;
#include<iostream>
using std::cout;
using std::endl;
class Sort {
public:
    bool operator()(const string & lhs, const string & rhs) {
        if(lhs.size( ) < rhs.size( )) {
            return true;
        } else {
            return false;
        }
    }
};
class Find {
private:
    std::size_t sz = 0;
public:
    Find(std::size_t s = 0) :sz(s) { }
    bool operator()(const string & lhs) {
        if(lhs.size( ) >= sz) {
            return true;
        } else {
            return false;
        }
    }
};
class print {
public:
    void operator()(const string & s) {
        cout << s << ' ';
    }
};
void elimDups(vector<string> & vec) {
    sort(vec.begin( ), vec.end( ));
    auto end_unique = unique(vec.begin( ), vec.end( ));
    vec.erase(end_unique, vec.end( ));
}
void biggies(vector<string> & words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin( ), words.end( ), Sort( ));
    auto iter = find_if(words.begin( ), words.end( ), Find(sz));
    for_each(iter, words.end( ), print( ));
    cout << endl;

}

int main( ) {
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(vec, 5);
    return 0;
}