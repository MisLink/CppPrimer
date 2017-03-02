#ifndef MESSAGE
#define MESSAGE
#include <set>
#include <string>
class Folder;
class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_folders(const Message &);
  void remove_from_folders();

 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();
  void save(Folder &);
  void remove(Folder &);
};
// define Message
void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}
void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}
void Message::remove_from_folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}
void Message::add_to_folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_folders(m);
}
Message::~Message() { remove_from_folders(); }
Message &Message::operator=(const Message &m) {
  remove_from_folders();
  contents = m.contents;
  folders = m.folders;
  add_to_folders(m);
  return *this;
}
void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders) {
    f->remMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->remMsg(&rhs);
  }
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->addMsg(&rhs);
  }
}
#endif  // !MESSAGE
