#ifndef FOLDER
#define FOLDER
#include <set>
#include <string>
#include "ex36_message.h"

class Folder {
 private:
  std::set<Message*> messages;
  std::string name;

 public:
  explicit Folder(const std::string& s = "") : name(s) {}
  Folder(const Folder& f) : name(f.name), messages(f.messages) {
    for (auto m : messages) {
      m->folders.insert(this);
    }
  }
  Folder& operator=(const Folder& f) {
    for (auto m : messages) {
      m->folders.erase(this);
    }
    name = f.name;
    messages = f.messages;
    for (auto m : f.messages) {
      m->folders.insert(this);
    }
    return *this;
  }
  ~Folder() {
    for (auto m : messages) {
      m->folders.erase(this);
    }
  }
  void addMsg(Message* m) { messages.insert(m); }
  void remMsg(Message* m) { messages.erase(m); }
};
#endif  // !FOLDER
