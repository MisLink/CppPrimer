#include <memory>
#include <string>
#include <vector>
class StrBlobPtr;
class StrBlob {
  friend class StrBlobPtr;

 public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  StrBlob(const StrBlob& sb)
      : data(std::make_shared<std::vector<std::string>>(*(sb.data))) {}
  StrBlob& operator=(const StrBlob& sb) {
    auto newp = std::make_shared<std::vector<std::string>>(*(sb.data));
    data = newp;
    return *this;
  }
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string& s) { data->push_back(s); }
  void push_buck(std::string&& s) & { data->push_back(std::move(s)); }
  void pop_back();
  std::string& front();
  std::string& back();
  const std::string& front() const;
  const std::string& back() const;

  StrBlobPtr begin();
  StrBlobPtr end();

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string& msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}
