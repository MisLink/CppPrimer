#ifndef STRING
#define STRING
#include <algorithm>
#include <iostream>
#include <memory>
class String {
 private:
  char *elements;
  char *first_free;
  char *cap;
  std::allocator<char> alloc;

  void free() {
    if (elements) {
      std::for_each(elements, first_free,
                    [this](char &c) { alloc.destroy(&c); });
      alloc.deallocate(elements, cap - elements);
    }
  }
  std::pair<char *, char *> alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
  }

 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *const c) {
    auto p = c;
    auto newdata = alloc.allocate(sizeof(p));
    std::uninitialized_copy(p, p + sizeof(p), newdata);
    elements = newdata;
    cap = newdata + sizeof(p);
    first_free = newdata + sizeof(p);
  }
  String(const String &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
    std::cout << "Copy constructing...\n";
  }
  String(String &&s)
      : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
    std::cout << "Move Copy constructing...\n";
  }
  String &operator=(const String &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    std::cout << "Assigning...\n";
    return *this;
  }
  String &operator=(String &&s) {
    if (this != &s) {
      free();
      elements = s.elements;
      first_free = s.first_free;
      cap = s.cap;
      s.elements = s.first_free = s.cap = nullptr;
    }
    std::cout << "Move Assigning...\n";
    return *this;
  }
  ~String() { free(); }

  std::size_t size() { return first_free - elements; }
  char *begin() const { return elements; }
  char *end() const { return first_free; }
};
#endif  // STRING
