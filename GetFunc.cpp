//---------------------------------------------------------------------------
#include <vcl.h>
#include "GetFunc.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

int rgen(int key,int n, int min,int max)
{
        int a = min;

//     a=min+(max-min+0.8)*0.5*(sin(6.2832/150.*n*key)+1.);

        a = min + random( max - min + 1 );

        if ( a = 0)
                a = 1;

        return a;
}

//��������� �����, ���� was = True - ���� ���������, ���� ��� - ����� +
//��� ������ Was ���������� � False
int sign(bool &was)
{
        if (was)
        {
                int RD = random(2);
                if (RD)
                {
                        return 1;
                }
                else
                {
                        was = false;
                        return -1;
                }
        }
        else
        {
                return -1;
        }

}

//��������� � ����, ���� was = True - ������� ���������, ���� ��� - ����� 1
//��� ���� Was ���������� � False
int zero(bool &was)
{
        if (was)
        {
                int RD = random(2);
                if (RD)
                {
                        return 1;
                }
                else
                {
                        was = false;
                        return 0;
                }
        }
        else
        {
                return 1;
        }

}
