#include <algorithm>
#include <memory>
#include <string>
#include <utility>
class StrVec {
 private:
  std::allocator<std::string> alloc;
  std::string *elements;
  std::string *first_free;
  std::string *cap;
  void check_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b,
                                                       const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
  }
  void free() {
    if (elements) {
      std::for_each(elements, first_free,
                    [this](std::string &p) { alloc.destroy(&p); });
      alloc.deallocate(elements, cap - elements);
    }
  }
  void reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
  }

 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> il) {
    auto newdata = alloc.allocate(il.size());
    auto p = newdata;
    for (auto s : il) {
      alloc.construct(p++, s);
    }
    elements = newdata;
    first_free = elements + il.size();
    cap = elements + il.size();
  }
  StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
  }
  StrVec(StrVec &&s) noexcept
      : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
  }
  StrVec &operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
  }
  StrVec &operator=(StrVec &&s) noexcept {
    if (this != &s) {
      free();
      elements = s.elements;
      first_free = s.first_free;
      cap = s.cap;
      s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
  }
  ~StrVec() { free(); }
  void push_back(const std::string &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
  }
  size_t size() const { return (first_free - elements); }
  size_t capacity() const { return (cap - elements); }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  void reserve(std::size_t n) {
    if (n < capacity()) {
      return;
    }
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
  }
  void resize(std::size_t n) { resize(n, std::string()); }
  void resize(std::size_t n, const std::string &s) {
    if (n < size()) {
      for (auto p = elements + n; p != first_free;) {
        alloc.destroy(p++);
      }
      first_free = elements + n;
    } else if (n > size()) {
      for (auto p = size(); p != n; ++p) {
        push_back(s);
      }
    }
  }
};
