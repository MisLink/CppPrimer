#include<bitset>
#include<iostream>


template<size_t N>
void update(std::bitset<N> &bset, std::pair<size_t, bool> p) {
    bset[p.first] = p.second;
}
template<size_t N>
size_t mark(std::bitset<N> &std_answer, std::bitset<N> &answer) {
    std::bitset<N> result = std_answer^answer;
    return result.size( ) - result.count( );
}
int main( ) {
    std::bitset<10> bset("1010101010");
    update(bset, std::make_pair(3, false));
    std::bitset<10> std_ans("0110101001");
    std::cout << mark(std_ans, bset) << std::endl;
    return 0;
}