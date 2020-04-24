#include <iostream>
#include <cmath>
using namespace std;
struct Complex{
    float Real;
    float Imag;
};
// функция ввода вомплексного числа
Complex CinComplex ( ){
    Complex temp;
    cout<<"Введите действительную часть числа"<<endl;
    cin>>temp.Real;
    cout<<"Введите мнимую часть комплексного числа "<<'\n';
    cin>>temp.Imag;
return temp;
}
// функция вывода на экран
void PrintComplex (Complex chislo){
    cout<<"z = "<<chislo.Real;
if (chislo.Imag > 0){
        cout<<" + "<<chislo.Imag<<"i"<<endl;
    }
else {
        cout<<" - "<<abs(chislo.Imag)<<"i"<<endl;
    }
}
// функция сложения
Complex plus1 (Complex chislo1, Complex chislo2){
Complex temp;

temp.Real = chislo1.Real + chislo2.Real;
temp.Imag = chislo1.Imag + chislo2.Imag;
PrintComplex(temp);
}

//функция для вычитания
Complex minus1 (Complex chislo1, Complex chislo2){
Complex temp;

temp.Real = chislo1.Real - chislo2.Real;
temp.Imag = chislo1.Imag - chislo2.Imag;
PrintComplex(temp);
}

//функция умножения двух клмплексных чисел
Complex mult1 (Complex chislo1,Complex chislo2){
Complex temp;
temp.Real=chislo1.Real* chislo2.Real-chislo1.Imag* chislo2.Imag;
temp.Imag=chislo1.Imag* chislo2.Real+chislo1.Real* chislo2.Imag;
PrintComplex ( temp );
return temp;
}

// Функция деления двух комплексных числа
Complex divide1 (Complex chislo1,Complex chislo2){
Complex temp;
temp.Real=( chislo1.Real* chislo2.Real+chislo1.Imag* chislo2.Imag )
        / ( chislo2.Real* chislo2.Real+chislo2.Imag* chislo2.Imag );
temp.Imag=( chislo1.Imag* chislo2.Real-chislo1.Real* chislo2.Imag )
        / ( chislo2.Real* chislo2.Real+chislo2.Imag* chislo2.Imag);
PrintComplex ( temp );
return temp;
}
int main() {Complex chislo1, chislo2; //Описание комплексных
chislo1 = CinComplex ( ); //Ввод исходных данных
chislo2 = CinComplex ( );

PrintComplex (chislo1) ; //Вывод исходных данных
PrintComplex(chislo2);
cout<<"-------------------------------------------"<<endl;
cout<<"Сумма чисел: ";
plus1(chislo1, chislo2);
cout<<"Разность чисел: ";
minus1(chislo1, chislo2);
cout<<"Произведение чисел: ";
mult1(chislo1, chislo2);
cout<<"Частное чисел: ";
divide1(chislo1, chislo2);
return 0;
}
