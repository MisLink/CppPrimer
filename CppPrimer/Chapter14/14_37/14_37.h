#ifndef REPLACE
#define REPLACE
#include<string>
class compare {
public:
    compare(std::string l = "", std::string r = "") :find(l), newvalue(r) { }
    void operator()(std::string & s) {
        if(find == s) {
            s = newvalue;
        }
    }
private:
    std::string find;
    std::string newvalue;
};
#endif // !REPLACE
