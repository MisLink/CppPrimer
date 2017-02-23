#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr {
 private:
  std::vector<Screen> screens;

 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex i);
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);

 public:
  using pos = std::string::size_type;

  Screen() = default;
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const { return contents[r * width + c]; }
  Screen& move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
  }
  Screen& set(char c) {
    contents[cursor] = c;
    return *this;
  }
  Screen& set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
  }
  Screen& display(std::ostream& os) {
    do_display(os);
    return *this;
  }
  const Screen& display(std::ostream& os) const {
    do_display(os);
    return *this;
  }

 private:
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  std::string contents;

 private:
  void do_display(std::ostream& os) const {
    int flag = 0;
    for (const auto& c : contents) {
      os << c;
      flag++;
      if (flag == width) {
        flag = 0;
        os << std::endl;
      }
    }
  }
};

void Window_mgr::clear(ScreenIndex i) {
  Screen& s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}

#endif  // !SCREEN
