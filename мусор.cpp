#include <iostream>
#include <cmath>
using namespace std;

class Tochka{
private:
    int x_Coord; //координаты точки
    int y_Coord;
public:
    void Set_Coords(int x1, int y1){ //задание координат точки в программе
        x_Coord = x1;
        y_Coord = y1;
    }
    void get_name_calss(){
        cout << "______Tochka______" << endl;
    }
    void get_x(){
        cout << "Координата точки по X: " << x_Coord << endl;
    }
    void get_y(){
        cout << "Координата точки по Y: " << y_Coord << endl;
    }
};
class Circle  {  //класс "Круг", наследник точки
protected:
    int Radius; //радиус
    int S_Circle; // Площадь круга
    double pi = 3.14, L_Circles;
public:
    void Set_Radius(int r1){
        Radius = r1;
    }
    virtual void Square( ){ // вычисляем Плащадь круга
        S_Circle = pi * pow( Radius, 2);
    }
    virtual void Length () {
        L_Circles = 2 * pi * Radius;
    }
    virtual void Perimeter() {};
    virtual void Side() {};

    virtual void get (){ // вывод
        cout << "_______Circle______" << endl;
        cout << "Радиус окружности: " << Radius << endl;
        cout << "Плащадь круга:  " << S_Circle << endl;
        cout << "Длинаа окраджности: " << L_Circles << endl;
    }
};
class Trangle: public Circle {
private:
    int a_Trangle; // возможно переведение типов
    double S_Trangle;
    double P_Trangle;
public:
    void Side() override  {
        a_Trangle = ( Radius * 3 ) / sqrt(3);
    }
    void Square() override {
        S_Trangle = (sqrt(3) * pow (a_Trangle, 2)) / 4;
    }
    void Perimeter () override {
        P_Trangle = 3 * a_Trangle;
    }
    void get() override { // вывод
        cout << "_______Trangle______" << endl;
        cout << "Сторона Трекгольника:  " << a_Trangle << endl;
        cout << "Плащадь Трекгольника:  " << S_Trangle << endl;
        cout << "Периметр Треугольника: " << P_Trangle << endl;
    }
};
class Squear: public Circle {
private:
    int a_Squear;// возможно переведение типов
    double S_Squear;
    double P_Squear;
public:
    void Square() override {
        S_Squear = 2 * pow(Radius,2);
    }
    void Side() override  { // тут может быть косяк
        a_Squear = sqrt(S_Squear);
    }
    void Perimeter() override  {
        P_Squear = 4 * a_Squear;
    }
    void get() override { // вывод
        cout << "_______Circle______" << endl;
        cout << "Сторона Квадрата:  " << a_Squear << endl;
        cout << "Плащадь Квадрата:  " << S_Squear << endl;
        cout << "Периметр Квадрата: " << P_Squear << endl;
    }
};

class Hexagon: public Circle{
private:
    int a_Hexagon; // возможно переведение типов
    double S_Hexagon;
    double P_Hexagon;
public:
    void Side() override {
        a_Hexagon = Radius;

    }
    void Square() override {
        S_Hexagon = ( pow (a_Hexagon,2) * 3 * sqrt(3)) / 2;

    }
    void Perimeter() override {
        P_Hexagon = 6 * a_Hexagon;
    }
    void get() override{ // вывод
        cout << "_______Hexagon______" << endl;
        cout << "Сторона Шестиугольника:  " << a_Hexagon << endl;
        cout << "Плащадь Шестиугольника:  " << S_Hexagon << endl;
        cout << "Периметр Шестиугольника: " << P_Hexagon << endl;
    }
};
int main(){
int Num_Operation;

cout<<"______Все операции______\n"
      "1 Показать все объекты.\n"
      "2 Показать точку.\n"
      "3 Показать круг.\n"
      "4 Показать треугольник.\n"
      "5 Показать квадрат.\n"
      "6 Показать шестиугольник.\n"
      "------------------------- \n"
      "Ввидите номер операции: ";
cin >> Num_Operation;
cout << endl;
if (Num_Operation == 1) {// КОСТЫЛЬ РЕАЛИЗАЦИЯ
    Circle Krug;
    Krug.Set_Radius(30);
    Krug.Square();
    Krug.Length();
    Krug.get();

    Trangle Treugolnik;
    Treugolnik.Set_Radius(30);
    Treugolnik.Side();
    Treugolnik.Perimeter();
    Treugolnik.Square();
    Treugolnik.get();

    Squear Kvadrat;
    Kvadrat.Set_Radius(30);
    Kvadrat.Square();
    Kvadrat.Side();
    Kvadrat.Perimeter();
    Kvadrat.get();

    Hexagon Sestiugol;
    Sestiugol.Set_Radius(30);
    Sestiugol.Side();
    Sestiugol.Square();
    Sestiugol.Perimeter();
    Sestiugol.get();
}
else if (Num_Operation == 2) {
    Tochka Point;
    Point.Set_Coords(15, 20);
    Point.get_name_calss();
    Point.get_x();
    Point.get_y();
}
else if (Num_Operation == 3) {
     Circle Krug;
     Krug.Set_Radius(30);
     Krug.Square();
     Krug.Length();
     Krug.get();
 }
else if (Num_Operation == 4) {
    Trangle Treugolnik;
    Treugolnik.Set_Radius(30);
    Treugolnik.Side();
    Treugolnik.Perimeter();
    Treugolnik.Square();
    Treugolnik.get();
}
else if ( Num_Operation == 5 ) {
    Squear Kvadrat;
    Kvadrat.Set_Radius(30);
    Kvadrat.Square();
    Kvadrat.Side();
    Kvadrat.Perimeter();
    Kvadrat.get();
}
else if ( Num_Operation == 6 ) {
    Hexagon Sestiugol;
    Sestiugol.Set_Radius(30);
    Sestiugol.Side();
    Sestiugol.Square();
    Sestiugol.Perimeter();
    Sestiugol.get();
    }
else{
    cout << "Введите число от 1 до 6";
    return 1;
}
return 0;
}

