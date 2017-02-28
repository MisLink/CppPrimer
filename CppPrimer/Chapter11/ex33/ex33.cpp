#include <map>
using std::map;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout;
using std::endl;
map<string, string> buildMap(ifstream& ifs) {
  map<string, string> trans;
  string line;
  while (getline(ifs, line)) {
    istringstream iss(line);
    string word;
    iss >> word;
    string value;
    getline(iss, value);
    value = value.substr(1, value.size() - 1);
    trans.insert({word, value});
  }
  return trans;
}
string transform(string s, map<string, string> trans) {
  auto it = trans.find(s);
  if (it != trans.end()) {
    return it->second;
  } else {
    return s;
  }
}
void word_transform(ifstream& rule, ifstream& input) {
  auto trans_map = buildMap(rule);
  string line;
  while (getline(input, line)) {
    istringstream iss(line);
    string word;
    bool first = true;
    while (iss >> word) {
      if (first) {
        first = false;
      } else {
        cout << " ";
      }
      cout << transform(word, trans_map);
    }
    cout << endl;
  }
}

int main(int argc, char* argv[]) {
  ifstream rule(argv[1]);
  ifstream input(argv[2]);
  word_transform(rule, input);
  return 0;
}
