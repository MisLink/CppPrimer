#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::ifstream;
void function(string file, vector<string> & vec) {
    ifstream open(file);
    string str;
    while(open >> str) {
        vec.push_back(str);
    }
}

int main( ) {
    vector<string> vec;
    function("C:\\Users\\Jiaqi\\Documents\\Visual Studio 2013\\Projects\\CppPrimer\\CppPrimer\\Chapter08\\8_4\\add_item", vec);
    for(auto & x : vec) {
        std::cout << x << std::endl;
    }
    return 0;
}