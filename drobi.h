//---------------------------------------------------------------------------
#ifndef DROBH
#define DROBH
//---------------------------------------------------------------------------
class drobi
{
        public:
        int a;
        int b;
        int znak;
        double c;

        drobi();
        drobi(int , int );
        drobi(int );
        sokrat();
        min(int ,int);
        double chislo();
        drobi operator+( drobi );
        drobi operator-( drobi );
        drobi operator/( drobi );
        drobi operator*( drobi );
        operator==( drobi );
};

char * DrobiToStr( drobi a );

#endif
