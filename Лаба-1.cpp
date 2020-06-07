#include <iostream>
#include <cmath>
using namespace std;

void krug ( double x1, double x2, double x3, double S, double R ){
    double p;
    p = (x1+x2+x3)/2.0;
    S = sqrt(p*(p-x1)*(p-x2)*(p-x3));
    R = (x1*x2*x3)/(4*S);
    double r = (2*S)/(x1+x2+x3);
    cout<<"Площадь треугольника S = "<<S<<endl;
    cout<<"Радиус описаной окружности R = "<<R<<endl;
    cout<<"Радиус вписанной окружности r = "<<r<<endl;
}
double Fun (double x){
    double Fun;
    Fun = tan(x) - 1.5;
    return Fun;
}
int main() {
    cout <<"Задание - 1"<<endl;
    double a = 0.7,b = 1.5 ,e = 0.0001,x;
    int k;
    cout <<"-----------------------------"<<endl;
    cout << "Значения" << endl;
    cout <<"a = 0.7 e = 0.0001 d = 1.5"<<endl;
    cout <<"Функция"<<endl;
    cout <<"Fun = tan(x) - 1.5"<<endl;
    if(Fun(a) * Fun(b) < 0){
        cout<<"Условие сходимости выполнено"<<endl;
        k = 0;
        while (true){
            x =(a+b)/2.0;
            k++;
            if( fabs(Fun(x)) < e) break;
            if( Fun(a) * Fun(x) < 0){
                a=a; b=x;
            }
            else{
                a=x; b=b;
            }
        }
        cout<<"Ответ: x = "<<x<<endl;
    }
    else{
        cout<<"Условие сходимости не выполнено"<<endl;
    }
    cout <<"-----------------------------"<<endl;
    cout<<endl;

    cout<<"Задание - 2"<<endl;
    cout <<"-----------------------------"<<endl;
    cout<<"Введите значения сторон треугольника"<<endl;
    double x1, x2, x3, S, R;

    cin>>x1;
    cin>>x2;
    cin>>x3;
    krug(x1, x2, x3, S, R);
    cout <<"-----------------------------"<<endl;
    return 0;
}
