#include<map>
using std::map;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<algorithm>
using std::remove_if;
int main( ) {
    map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        for(auto & c : word) {
            c = tolower(c);
        }
        word.erase(remove_if(word.begin( ), word.end( ), ispunct), word.end( ));
        ++word_count[word];
    }
    for(const auto & w : word_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}