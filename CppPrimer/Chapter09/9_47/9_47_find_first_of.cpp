#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::string;

int main( ) {
    string numbers{"1234567890"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string str{"ab2c3d7R4E6"};
    for(string::size_type i = 0; i != string::npos; ++i) {
        i = str.find_first_of(numbers, i);
        if(i == string::npos) {
            break;
        }
        cout << i << ": " << str[i] << endl;
    }
    cout << endl;
    for(string::size_type i = 0; i != str.size( ); ++i) {
        i = str.find_first_of(alphabet, i);
        if(i == string::npos) {
            break;
        }
        cout << i << ": " << str[i] << endl;
    }
    return 0;
}