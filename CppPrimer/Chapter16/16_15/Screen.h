#ifndef SCREEN_H
#define SCREEN_H
#include<string>

template<unsigned H, unsigned W>
class Screen {
    friend std::ostream &operator<<(std::ostream &, Screen &);
    using pos = std::string::size_type;
public:
    Screen( ) = default;
    Screen(char c) :contents(H*W, c) { }

    char get( )const { return contents[cursor]; }

    Screen &move(pos, pos);

    Screen & operator<<(const char &);
    Screen & operator>>(char &);
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
template<unsigned H, unsigned W>
Screen<H, W> & Screen<H, W>::operator<<(const char &c) {
    contents[cursor] = c;
    return *this;
}
template<unsigned H, unsigned W>
Screen<H, W> & Screen<H, W>::operator>>(char &c) {
    c = contents[cursor];
    return *this;
}



#endif // !SCREEN_H
