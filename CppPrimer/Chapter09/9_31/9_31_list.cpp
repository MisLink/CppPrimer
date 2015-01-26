#include<list>
#include<iostream>
using std::list;
using std::cout;
using std::endl;

int main( ) {
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin( );
    while(iter != li.end( )) {
        if(*iter % 2) {
            iter = li.insert(iter, *iter);
            iter++;
            iter++;
        } else {
            iter = li.erase(iter);
        }
    }
    for(auto & x : li) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}