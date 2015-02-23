#ifndef SCREEN_H
#define SCREEN_H
#include<string>
template<unsigned H, unsigned W>
class Screen {
    using pos = std::string::size_type;
public:
    Screen( ) = default;
    Screen(char c) :contents(H*W, c) { }
    char get( )const { return contents[cursor]; }
    Screen &move(pos, pos);
private:
    pos cursor = 0;
    pos height = H;
    pos width = W;
    std::string contents;
};

template<unsigned H, unsigned W>
Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
    cursor = r*width + c;
    return *this;
}


#endif // !SCREEN_H
