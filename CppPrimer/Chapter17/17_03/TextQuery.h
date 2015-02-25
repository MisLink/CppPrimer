#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<map>
#include<string>
#include<set>
#include<vector>
#include<memory>
#include<fstream>
#include<sstream>
#include<algorithm>


class TextQuery {
    using line_no = std::vector<std::string>::size_type;
    using result_tuple = std::tuple < std::string, std::shared_ptr<std::vector<std::string>>, std::shared_ptr<std::set<line_no>> > ;
    friend std::ostream & print(std::ostream &, const result_tuple &);
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
public:
    TextQuery(std::ifstream &);
    result_tuple query(const std::string &)const;

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

TextQuery::result_tuple TextQuery::query(const std::string & s)const {
    static std::shared_ptr<std::set<line_no>> nodata(std::make_shared<std::set<line_no>>( ));
    auto loc = wm.find(s);
    if(loc != wm.end( )) {
        return result_tuple(s, file, loc->second);
    } else {
        return result_tuple(s, file, nodata);
    }
}

//print

std::ostream & print(std::ostream & os, const TextQuery::result_tuple & qr) {
    os << std::get<0>(qr) << " occurs " << std::get<2>(qr)->size( ) << " time(s). " << std::endl;
    for(auto & x : *std::get<2>(qr)) {
        os << "(line " << x + 1 << ") " << *(std::get<1>(qr)->begin( ) + x) << std::endl;
    }
    return os;
}
#endif // !TEXTQUERY

