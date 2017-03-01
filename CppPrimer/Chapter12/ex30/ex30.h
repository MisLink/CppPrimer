#ifndef TEXTQUERY
#define TEXTQUERY
#include<map>
#include<string>
#include<set>
#include<vector>
#include<memory>
#include<fstream>
#include<sstream>
#include<algorithm>
class QueryResult;
class TextQuery {
    friend class QueryResult;
    using line_no = std::vector<std::string>::size_type;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
public:
    TextQuery(std::ifstream & is);
    QueryResult query(const std::string & s)const;
};

class QueryResult {
    friend std::ostream & print(std::ostream & os, const QueryResult & qr);
private:
    std::string sought;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
public:
    QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> f, std::shared_ptr<std::set<TextQuery::line_no>> l) :sought(s), file(f), lines(l) { }
};
// class TextQuery

TextQuery::TextQuery(std::ifstream & is) :file(std::make_shared< std::vector<std::string>>( )) {
    std::string text;
    while(std::getline(is, text)) {
        file->push_back(text);
        int n = file->size( ) - 1;
        std::istringstream line(text);
        std::string word;
        while(line >> word) {
            auto end = std::find_if(word.begin( ), word.end( ), ispunct);
            word.erase(end, word.end( ));
            auto & lines = wm[word];
            if(!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string & s)const {
    static std::shared_ptr<std::set<TextQuery::line_no>> nodata(std::make_shared<std::set<line_no>>( ));
    auto loc = wm.find(s);
    if(loc != wm.end( )) {
        return QueryResult(s, file, loc->second);
    } else {
        return QueryResult(s, file, nodata);
    }
}

//print

std::ostream & print(std::ostream & os, const QueryResult & qr) {
    os << qr.sought << " occurs " << qr.lines->size( ) << " time(s). " << std::endl;
    for(auto & x : *qr.lines) {
        os << "(line " << x + 1 << ") " << *(qr.file->begin( ) + x) << std::endl;
    }
    return os;
}
#endif // !TEXTQUERY

