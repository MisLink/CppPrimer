#include<iostream>
#include<string>
#include<vector>
#include<list>
template<typename iterT, typename valueT>
iterT Find(const iterT &begin, const iterT &end, const valueT &v) {
    auto iter = begin;
    for(iter; iter != end; iter++) {
        if(*iter == v) {
            break;
        }
    }
    return iter;
}

int main( ) {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = Find(vec.begin( ), vec.end( ), 2);
    std::cout << *it << std::endl;
    std::list<std::string> li{"a", "b", "c", "d", "e"};
    auto iter = Find(li.begin( ), li.end( ), "a");
    std::cout << *iter << std::endl;
    return 0;
}