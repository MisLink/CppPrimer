#include"Bulk_quote.h"

int main( ) {
    Bulk_quote bq1;
    Bulk_quote bq2(std::move(bq1));
    //Visual Studio 2013 ��δʵ�ּ̳й��캯��
    //Bulk_quote bq3("aaa", 12.5, 10, 0.2);
    Bulk_quote bq4(bq2);
    bq1 = bq2;
    bq2 = std::move(bq2);


    return 0;
}