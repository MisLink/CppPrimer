#include"TextQuery.h"
namespace Chapter10 {

    using std::string;
    using std::vector;

    TextQuery::TextQuery(std::ifstream &is) :file(new vector<string>) {
        string text;
        while(std::getline(is, text)) {
            file->push_back(text);
            size_t n = file->size( ) - 1;
            std::istringstream line(text);
            string word;
            while(line >> word) {
                auto &lines = wm[word];
                if(!lines) {
                    lines.reset(new std::set<line_no>);
                }
                lines->insert(n);
            }
        }
    }

    QueryResult TextQuery::query(const string &sought)const {
        static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

        auto loc = wm.find(sought);
        if(loc == wm.end( )) {
            return QueryResult(sought, nodata, file);
        } else {
            return QueryResult(sought, loc->second, file);
        }
    }
}
