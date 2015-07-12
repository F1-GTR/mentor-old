#ifndef _NG_UTILS
#define _NG_UTILS

#include "MLog.h"
struct  pAnswer
{
        char str[255];
        bool legit;
};

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


//Получение знака, если was = True - знак рандомный, если нет - вернёт +
//При минусе Was обращается в False
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

//Обращение в ноль, если was = True - возврат рандомный, если нет - вернёт 1
//При нуле Was обращается в False
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