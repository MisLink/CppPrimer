#ifndef INPUTSTRING
//#define INPUTSTRING
#include<string>
#include<iostream>
class InputString {
public:
    InputString(std::istream & i = std::cin) :is(i) { }
    std::string operator()( );
private:
    std::istream & is;
};

#endif // !INPUTSTRING
