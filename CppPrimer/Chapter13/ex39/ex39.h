#include <memory>
#include <string>
#include <utility>
class StrVec {
 private:
  static std::allocator<std::string> alloc;
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
      for (auto p = first_free; p != elements;) {
        alloc.destroy(--p);
      }
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
  StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
  }
  StrVec &operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
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
