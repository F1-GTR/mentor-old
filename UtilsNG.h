#ifndef _NG_UTILS
#define _NG_UTILS

#include "MLog.h"

//���� ��������� �������������� �������� ��� ������� �����     (0-10)
#define _SIGN_CHANCE 3

//���� ��������� ���� ��� ������� ���������                       (0-10)
#define _ZERO_CHANCE 3

//������ ����� �� ���� � ����, ����������� �� ��� ������������
struct  pAnswer
{
        char str[255];
        bool legit;
};

//������� ��� ������ ����� ���������� pAnswer
void swapAnswers(pAnswer &one, pAnswer &two)
{
        char buff[255];
        strcpy(buff,one.str);
        strcat(buff," to ");
        strcat(buff,two.str);
        Log->Add("Swapping:");
        Log->Add(buff);

        pAnswer tmp = one;
        one = two;
        two = tmp;
}

//������������ ������ �������� pAnswer
void shuffleAnswers(pAnswer pAns[4])
{
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                swapAnswers(pAns[j],pAns[random(4)]);
            }
        }
}


//��������� �����, ���� was = True - ���� ���������, ���� ��� - ����� +
//��� ������ Was ���������� � False
int sign(bool &was)
{
        if (was)
        {
                int RD = random(10);
                if (RD >= 3)
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

//���� �����, �� ��� ����� ���������� ����������
int sign()
{
       int RD = random(10);
       char buff[10];
       if (RD >= 3)
       {
              return 1;
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
                int RD = random(10);
                if (RD >= 3)
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


//���� �����, �� ��� ����� ���������� ����������
int zero()
{
   int RD = random(10);
   if (RD >= 3)
   {
           return 1;
   }
   else
   {
         return 0;
   }

}

#endif