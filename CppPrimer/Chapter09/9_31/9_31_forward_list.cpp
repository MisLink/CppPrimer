#include<forward_list>
#include<iostream>
using std::forward_list;
using std::cout;
using std::endl;

int main( ) {
    forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = fli.begin( );
    auto prev = fli.before_begin( );
    while(iter != fli.end( )) {
        if(*iter % 2) {
            iter = fli.insert_after(prev, *iter);
            iter++;
            iter++;
            prev++;
            prev++;
        } else {
            iter = fli.erase_after(prev);
        }
    }
    for(auto & x : fli) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}