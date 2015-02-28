namespace test1 {

    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;

    }
    int ivar = 0;
    //位置1
    //多次声明ivar
    //using Exercise::ivar;
    using Exercise::dvar;
    using Exercise::limit;
    void manip( ) {
        //位置2
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
    //位置1
    
    void manip( ) {
        //位置2
        using Exercise::ivar;
        //多次声明dvar
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
    //位置1
    using namespace Exercise;
    void manip( ) {
        //位置2

        double dvar = 3.1416;
        int iobj = limit + 1;
        //ivar不明确
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
    //位置1

    void manip( ) {
        //位置2
        using namespace Exercise;
        double dvar = 3.1416;
        int iobj = limit + 1;
        //ivar不明确
        //++ivar;
        ++test2::ivar;
    }
}
