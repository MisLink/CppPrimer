#include"Query.h"

int main( ) {
    Query q = Query("fiery")&Query("bird") | Query("wind");
    std::cout << q;
    return 0;
}

