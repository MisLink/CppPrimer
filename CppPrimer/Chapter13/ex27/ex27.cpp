#include <string>
class HasPtr {
 public:
  HasPtr(const std::string& s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
  HasPtr& operator=(const HasPtr& hp) {
    ++*(hp.use);
    --*use;
    if (*use == 0) {
      delete ps;
      delete use;
    }
    ps = hp.ps;
    i = hp.i;
    use = hp.use;
    return *this;
  }
  ~HasPtr() {
    --*use;
    if (*use == 0) {
      delete ps;
      delete use;
    }
  }

 private:
  std::string* ps;
  int i;
  std::size_t* use;
};
