#ifndef _NG_UTILS
#define _NG_UTILS

#include "MLog.h" 

//шанс выпадения отрицательного значения для функций знака     (0-10)
#define _SIGN_CHANCE 3

//шанс выпадения нуля для функций обнуления                       (0-10)
#define _ZERO_CHANCE 3

//хранит ответ на тест и флаг, указывающий на его правильность
struct  pAnswer
{
        char str[255];
        bool legit;
};

//функция для обмена между структурой pAnswer
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

//перемешивает массив структур pAnswer
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

//тоже самое, но без флага сохранения результата
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


//тоже самое, но без флага сохранения результата
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

//defines for fast generator greating
//plist printng
#define  mwl; plist->Add(strdup(buf)); Log->Add(buf);
#define  msl; plist->Add(strdup("String( )"));
#define  mbuffsinit; char buf1[255],buf2[255],buf3[255],buf4[255], buf5[255],buf6[255],buf7[255],buf8[255];
#define  mbuffsclear; *buf1 = '\0'; *buf2 = '\0';*buf3 = '\0';*buf4 = '\0';*buf5 = '\0';*buf6 = '\0';*buf7 = '\0';*buf8 = '\0';
#define  mbuffscat;   *buf = '\0'; strcat(buf,buf1); strcat(buf,buf2);strcat(buf,buf3);strcat(buf,buf4);strcat(buf,buf5);strcat(buf,buf6);strcat(buf,buf7);strcat(buf,buf8);

//normal test
#define  mqinit; Log->Add("Printing to test.."); char* buf = new char[256]; if( keygen == 0 ){keygen = random( 1000 ) + 1;} srand( keygen );
#define  mqtask; if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) ){ sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );plist->Add( strdup(buf) );} else{ sprintf( buf, "String(#)" );plist->Add( strdup(buf) );}sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );plist->Add( strdup(buf) );
#define  mqteacher; msl; sprintf( buf, "String(@Часть преподавателя )" );plist->Add( strdup(buf) );sprintf( buf, "String(\"Тема - %s \")", selecttask->name );plist->Add( strdup(buf) );sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );plist->Add( strdup(buf) );
#define  mqend; msl; keygen = 0; delete buf;  Log->Add("Completed"); return 0;

//online test
#define  tqinit; char* buf = new char[256];Log->Add("Printing to Joomla test..");if( keygen == 0 ){keygen = random( 1000 ) + 1;}pAnswer pAns[4];srand( keygen );int Right_Numb = -1;
#define  tqtask; if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) ){sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );plist->Add( strdup(buf) );}else{sprintf( buf, "String(#)" );plist->Add( strdup(buf) );}sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );plist->Add( strdup(buf) );
#define  tqend;    \
        Log->Add("Shuffle.."); \
        shuffleAnswers(pAns); \
        Log->Add("Find right.."); \
        for (int i = 0; i < 4 && Right_Numb == -1; i++)\
        {\
                if (pAns[i].legit) \
                { \
                        Right_Numb = i+1; \
                         Log->Add("Right"); \
                } \
                else  \
                {\
                        Log->Add("Wrong");\
                } \
        }\
        plist->Add(strdup("String(Вариант a: )")); \
        plist->Add( strdup(pAns[0].str) ); \
        Log->Add(pAns[0].str);\
        sprintf( buf, "String( )" );\
        plist->Add( strdup(buf) );\
                  \
        plist->Add(strdup("String(Вариант b: )"));\
        plist->Add( strdup(pAns[1].str) );\
        Log->Add(pAns[1].str);\
        sprintf( buf, "String( )" );\
        plist->Add( strdup(buf) );\
                                            \
        plist->Add(strdup("String(Вариант c: )"));\
        plist->Add( strdup(pAns[2].str) );\
        Log->Add(pAns[2].str); \
        sprintf( buf, "String( )" );\
        plist->Add( strdup(buf) );\
                                         \
        plist->Add(strdup("String(Вариант d: )"));\
        plist->Add( strdup(pAns[3].str) );\
        Log->Add(pAns[3].str); \
        sprintf( buf, "String( )" );\
        plist->Add( strdup(buf) ); \
                                             \
        t.pr_tst = 1;                        \
        t.ch_ask = 4;                        \
        t.right_ask = Right_Numb;            \
        t.msg = "Тест успешно сгенерирован.";\
        Log->Add("Completed");\
                                             \
        keygen = 0;                           \
                                              \
        delete buf;                           \
                                              \
        return 0;
//-----------------------------------------------

#endif