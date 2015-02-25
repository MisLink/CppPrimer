#include<fstream>
#include<string>
using std::string;
using std::fstream;
int main( ) {
    fstream inout("C:\\Users\\Jiaqi\\Documents\\Visual Studio 2013\\Projects\\CppPrimer\\CppPrimer\\Chapter17\\17_39\\17_39", fstream::ate | fstream::in | fstream::out);
    auto end_mark = inout.tellp( );
    inout.seekg(0, fstream::beg);
    size_t cnt = 0;
    string line;
    while(inout&&inout.tellg( ) != end_mark&&std::getline(inout, line)) {
        cnt += line.size( ) + 1;
        auto mark = inout.tellg( );
        inout.seekp(0, fstream::end);
        inout << cnt;
        if(mark != end_mark) {
            inout << " ";
        }
        inout.seekg(mark);
    }
    inout.seekp(0, fstream::end);
    inout << '\n';

    return 0;
}