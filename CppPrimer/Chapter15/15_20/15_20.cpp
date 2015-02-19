#include<iostream>
class base {
public:
    void pub_mem( );
protected:
    int prot_mem;
private:
    char priv_mem;
};

class pub_derv :public base {
public:
    void memfcn(base &b) { b = *this; }
};

class priv_derv :private base {
public:
    void memfcn(base &b) { b = *this; }
};

class prot_derv :protected base {
public:
    void memfcn(base &b) { b = *this; }
};

class derived_from_public :public pub_derv{
public:
    void memfcn(base &b) { b = *this; }
};

class derived_from_private :public priv_derv {
public:
    //void memfcn(base &b) { b = *this; }
};

class derived_from_protected :public prot_derv {
public:
    void memfcn(base &b) { b = *this; }
};

int main( ) {
    pub_derv d1;
    priv_derv d2;
    prot_derv d3;

    base *p = &d1;
    //p = &d2;
    //p = &d3;

    derived_from_public dd1;
    derived_from_private dd2;
    derived_from_protected dd3;

    p = &dd1;
    //p = &dd2;
    //p = &dd3;


}