#include <iostream>
#include <cmath>
using namespace std;

void Transform ( char arr[], int n, double Num ) {

double temp = abs(Num);
    for (int i = 3; i < n; i++){
        temp = temp - int(temp);
        temp *= 2;
        arr[i] = char(int(temp) + 48);// 48 код по ASCII - 0 , а 49 код по ASCII 1
}

if(Num > 0 && Num <= 1){
    arr[0] = '0';
    arr[1] = '0';
    arr[2] = '.';
}

if(Num < 0 && Num >= -1){
    Num *= -1;
    arr[0] = '0';
    arr[1] = '1';
    arr[2] = '.';
    for (int i = 3; i < n; i++){
        arr[i] == '1' ? arr[i] = '0' : arr[i] = '1';
    }
}

if (Num == 0){
    cout << "Num is 0" << endl;
    }
}

void Action (  char BinArr1[], char BinArr2[], char AnswerArr[], int n ){
    char p , p1;
    for (int i = n - 1; i >= 0; i--) {
        if (BinArr1[i] == '.') {
            AnswerArr[i] = '.';
        }
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

void PrintArr ( char arr1[], char arr2[], char arr3[], int n) {

    cout << "*************************************************************************************" << endl;
    cout << " ";

    cout << endl;
    cout << " ";
    for (int i = 1; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "+" << endl;
    cout << " ";
    for (int i = 1; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << " ";
    cout << "-----------------------" << endl;
    cout << " ";
    for (int i = 1; i < n; i++) {
        cout << arr3[i] << " ";
    }
}

    int main() {
        double NumFist, NumSecond;
        unsigned int n = 12;
        char BinNum1[n], BinNum2[n], Answer[n];
        char BinNumPO[n], AnswerNow[n], AnswerNow2[n];

        cout << "Ввидите первое дробное в дясятичной записи" << endl;
        cin >> NumFist;
        cout << "Ввидите второе дробное в дясятичной записи" << endl;
        cin >> NumSecond;

        if (NumFist == 0 || NumSecond == 0) {
            cout << "Num is NULL" << endl;
            return 1;
        } else if (NumFist >= 1 || NumSecond >= 1) {
            cout << "Выберете дробь меньше" << endl;
            return 1;
        } else {
            Transform(BinNum1, n, NumFist);
            Transform(BinNum2, n, NumSecond);
        }
        if (BinNum1[1] == '0' && BinNum2[1] == '0') {
            Action(BinNum1, BinNum2, Answer, n);
            PrintArr(BinNum1, BinNum2, Answer, n);
        }
        if (BinNum1[1] == '0' && BinNum2[1] == '1') {

            for (int i = 0; i < n; i++) {
                BinNumPO[i] = '0';
            }
            BinNumPO[n-1] = '1';

            Action(BinNum2, BinNumPO, AnswerNow, n);
            Action(BinNum1, AnswerNow, Answer, n);
            PrintArr(BinNum1, AnswerNow, Answer, n);
        }
        if (BinNum1[1] == '1' && BinNum2[1] == '0') {

            for (int i = 0; i < n; i++) {
                BinNumPO[i] = '0';
            }
            BinNumPO[n-1] = '1';

            Action(BinNum1, BinNumPO, AnswerNow, n);
            Action(BinNum2, AnswerNow, Answer, n);
            PrintArr(BinNum1, AnswerNow, Answer, n);
        }
        if (BinNum1[1] == '1' && BinNum2[1] == '1') {

            for (int i = 0; i < n; i++) {
                BinNumPO[i] = '0';
            }
            BinNumPO[n-1] = '1';

            Action(BinNum1, BinNumPO, AnswerNow, n);
            Action(BinNum1, BinNumPO, AnswerNow2, n);
            Action(AnswerNow2, AnswerNow, Answer, n);
            PrintArr(AnswerNow2, AnswerNow, Answer, n);
        }
        return 0;
    }