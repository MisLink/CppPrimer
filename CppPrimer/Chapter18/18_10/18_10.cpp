#include"Sales_data.h"
#include"Sales_data_exception.h"

int main( ) {
    Sales_data s1("c++primer", 10, 12.5);
    Sales_data s2("clrs", 8, 15);
    Sales_data sum;
    try {
        sum = s1 + s2;
    } catch(isbn_mismatch e) {
        std::cerr << e.what( ) << ": left isbn( " << e.left << " ) right isbn( " << e.right << " )" << std::endl;
    }
    return 0;
}