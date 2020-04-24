#include <iostream>
#include <cmath>
using namespace std;

void FreeArr (char arr[]){ // функция для очистки массива, чтобы измежаьб ошибки в вычислении
    for (int i = 0; i < 10; i++ ){
        arr[i]='0';
    }
}
void Bin (char arr[], int num, int  i) { //перевод в двочиную систему счисления
    int copy, temp;
    while (num != 0) {
        copy = num;
        copy = copy / 2;
        temp = num % 2;
        num = copy;
        arr[i] = char(temp + 48);
        i--;
        }
    }
void Transform(char arr[], int Num){// разделения десятчиных чисел на разряды
    FreeArr(arr);
    int Num1 = Num / 10, Num2 = Num % 10;
    Bin(arr, Num1, 4);
    Bin(arr, Num2, 9);
}
void Action (  char BinArr1[], char BinArr2[], char AnswerArr[], int n){ // функция выполняющая сложения двочный чисел
    char p , p1;
    for (int i = n ; i >= 0; i--) {
        switch (BinArr1[i]) {
            case '0' :
                if (BinArr2[i] == '0') {
                    AnswerArr[i] = '0';
                    p = '0';
                } else {
                    AnswerArr[i] = '1';
                    p = '0';
                }
                break;
            case '1' :
                if (BinArr2[i] == '0') {
                    AnswerArr[i] = '1';
                    p = '0';
                } else {
                    AnswerArr[i] = '0';
                    p = '1';
                }
                break;
         }
        if (p1 == '1') {
            switch (AnswerArr[i]) {
                case '1' :
                    AnswerArr[i] = '0';
                    p = '1';
                    break;
                case '0' :
                    AnswerArr[i] = '1';
                    break;
            }
        }
        p1 = p;
    }
}
void Correction(int n, char AnswerArr[] , char TempArr[]) { // функцуия для коррекции значений
char BinTen1[10] = {'0','1','0','1','0','0','0','0','0','0'};
char BinTen2[10] = {'0','0','0','0','0','0','1','0','1','0'};

switch (n){
    case 1 :
     Action( AnswerArr , BinTen1 , TempArr , 10);
        break;
    case 2 :
     Action( AnswerArr , BinTen2 , TempArr , 10);
        break;
    case 3 :
        Action( AnswerArr , BinTen1 , TempArr , 10);
        Action( TempArr , BinTen2 , AnswerArr , 10);
        break;
    }
}

void PrintArr( char arr[], int n ) {// функция вывода массива
    cout<<endl;
    cout<<"Ответ: ";
      arr[5] = '|';
   for (int i = 1; i < n; i++ ){
       cout<<arr[i]<<" ";
   }
    cout<<endl;
}

int main() {
int NumFirst, NumSecond;
int n = 10;
char BinNum1[n], BinNum2[n], BinAnswer[n], TempArr[n];
char BinSix1[10] = {'0','0','1' ,'1' ,'0','0','0','0','0','0'};
char BinSix2[10] = {'0','0','0','0','0','0','0','1' ,'1' ,'0'};
char calibration[10] = {'0','0','0' ,'0' ,'1','0','0','0','0','0'};

cout<<"Ввидите первое число в десятичной ситеме счиясления  : ";
cin>>NumFirst;
cout<<endl;
cout<<"Ввидите второе число в десятичной ситеме счиясления : ";
cin>>NumSecond;

// если ввведено отрицательное число
if (NumFirst < 0) {
    NumFirst = 100 - abs(NumFirst);
}
if (NumSecond < 0) {
    NumSecond  = 100 - abs(NumSecond);
}

Transform(BinNum1, NumFirst);// перевожу первое число в двоично-десятчиную систему счисления
Transform(BinNum2, NumSecond);// перевожу второе число в двоично-десятчиную систему счисления

FreeArr(TempArr);

Action(BinNum1,BinSix1,TempArr, 10);//код с избытком 6
Action(TempArr,BinSix2,BinNum1,10 );//код с избытком 6

Action(BinNum1,BinNum2,BinAnswer,10);//выполнения арефметической опперации

//корекция значения и вывод на экран
if (BinAnswer[5] == '1') {
    Action( BinAnswer, calibration,  TempArr,  10);
    for (int i = 0; i < n; ++i ){
        BinAnswer[i] = TempArr[i];
    }
}
    FreeArr(TempArr);
if (BinAnswer[0] == '1' && BinAnswer[5] == '0') {
    Correction(2, BinAnswer, TempArr);
    PrintArr(TempArr, n );
}
if (BinAnswer[0] == '1' && BinAnswer[5] == '1') {
        PrintArr(BinAnswer, n );
}
if (BinAnswer[0] == '0' && BinAnswer[5] == '1') {
    Correction(1, BinAnswer, TempArr);
    PrintArr(TempArr, n );
}
if ( BinAnswer[0] == '0' && BinAnswer[5] == '0') {
    Correction(3, BinAnswer, TempArr);
    PrintArr(TempArr, n );
}
return  0;
}
