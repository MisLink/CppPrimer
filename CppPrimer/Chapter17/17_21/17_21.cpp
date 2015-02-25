#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<regex>
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;

bool valid(const std::smatch &s) {
    if(s[1].matched) {
        return s[3].matched && ((s[4].matched == 0) || (s[4].str( ) == " "));
    } else {
        return !s[3].matched && (s[4].str( ) == s[6].str( ));
    }
}
struct PersonInfo {
    string name;
    vector<string> phones;
};

string format(const string & str) {
    string temp = str.substr(0, 3) + '-' + str.substr(3, 3) + '-' + str.substr(6);
    return temp;

}
int main( ) {
    ifstream open("C:\\Users\\Jiaqi\\Documents\\Visual Studio 2013\\Projects\\CppPrimer\\CppPrimer\\Chapter08\\8_13\\sstream");
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(std::getline(open, line)) {
        PersonInfo info;
        record.clear( );
        record.str(line);
        record >> info.name;
        while(record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for(const auto & entry : people) {
        ostringstream formatted, badNums;
        string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(phone);
        for(auto &num : entry.phones) {
            for(std::sregex_iterator i(num.begin( ), num.end( ), r), end; i != end; ++i) {
                if(!valid(*i)) {
                    badNums << " " << i->str( );
                } else {
                    formatted << " " << format(i->str( ));
                }
            }
        }
        if(badNums.str( ).empty( )) {
            std::cout << entry.name << " " << formatted.str( ) << std::endl;
        } else {
            std::cerr << "input error: " << entry.name << " invailed number(s) " << badNums.str( ) << std::endl;
        }
    }

    return 0;
}