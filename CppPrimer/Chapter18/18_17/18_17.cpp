namespace test1 {

    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;

    }
    int ivar = 0;
    //λ��1
    //�������ivar
    //using Exercise::ivar;
    using Exercise::dvar;
    using Exercise::limit;
    void manip( ) {
        //λ��2
        double dvar = 3.1416;
        int iobj = limit + 1;
        ++ivar;
        ++test1::ivar;
    }
}

namespace test2 {

    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;

    }
    int ivar = 0;
    //λ��1
    
    void manip( ) {
        //λ��2
        using Exercise::ivar;
        //�������dvar
        //using Exercise::dvar;
        using Exercise::limit;

        double dvar = 3.1416;
        int iobj = limit + 1;
        ++ivar;
        ++test2::ivar;
    }
}

namespace test3 {

    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;

    }
    int ivar = 0;
    //λ��1
    using namespace Exercise;
    void manip( ) {
        //λ��2

        double dvar = 3.1416;
        int iobj = limit + 1;
        //ivar����ȷ
        //++ivar;
        ++test2::ivar;
    }
}

namespace test4 {

    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;

    }
    int ivar = 0;
    //λ��1

    void manip( ) {
        //λ��2
        using namespace Exercise;
        double dvar = 3.1416;
        int iobj = limit + 1;
        //ivar����ȷ
        //++ivar;
        ++test2::ivar;
    }
}
