#ifndef STRING
#define STRING
#include <algorithm>
#include <memory>
class String {
 private:
  char* elements;
  char* first_free;
  char* cap;
  std::allocator<char> alloc;

  void free() {
    if (elements) {
      std::for_each(elements, first_free,
                    [this](char& c) { alloc.destroy(&c); });
      alloc.deallocate(elements, cap - elements);
    }
  }

 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  explicit String(const char* const c) {
    auto p = c;
    auto newdata = alloc.allocate(sizeof(p));
    std::uninitialized_copy(p, p + sizeof(p), newdata);
    elements = newdata;
    cap = newdata + sizeof(p);
    first_free = newdata + sizeof(p);
  }
  ~String() { free(); }
};
#endif  // STRING
