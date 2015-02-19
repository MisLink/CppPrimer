#include"Query.h"
#include<fstream>
int main(int argc, char *argv[ ]) {
    std::ifstream file(argv[1]);

    TextQuery query(file);

    Query q = Query("fiery")&Query("bird") | Query("wind");

    std::cout << q.eval(query);
}
