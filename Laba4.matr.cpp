#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
//считаем размер матрицы в исходном файле
ifstream inp("inp.txt");
int n = 0;
int a;
while(!inp.eof()){
    inp >> a;
    n++;
}
inp.close();
// создание динамического массива
int MatInf = sqrt(n);

int **array = new int * [MatInf];

for (int i = 0; i < MatInf; i++){
    array[i] = new int[MatInf];
}
//заполняем двумерный диномический массив
inp.open("inp.txt");
for ( int i = 0; i < MatInf; i++ ){
    for ( int j = 0; j < MatInf; j++ ){
        inp >> array[i][j];
    }
}
inp.close();
//вывод диномеческого массива
for (int i = 0; i < MatInf; i++){
    for( int j = 0; j < MatInf; j++){
        cout << array[i][j] <<" ";
    }
    cout << endl;
}
cout<<"------------------------------------------------"<<endl;
//поиск макс мин и их индексы
int maxi, MaxiLine = 0 , mini , MiniColumn = 0;
maxi = mini = array[0][0];
for ( int i = 0; i < MatInf; i++ ){
    for ( int j = 0; j < MatInf; j++ ){
        if(array[i][j] > maxi){
            maxi = array[i][j];
            MaxiLine = i;
        }
        if(array[i][j] < mini){
            mini = array[i][j];
            MiniColumn = j;
        }
    }
}
cout << "Максимальный элемент в матрице: " << maxi << " " << "В строке: " << MaxiLine + 1 << endl;
cout << "Минимальный элемент в матрице: " << mini << " " << "В столбце: " << MiniColumn + 1<< endl;
/*Меняем строки местами*/
for( int j = 0; j < MatInf; j++){
    int temp;
    temp = array[MiniColumn][j];
    array[MiniColumn][j] = array[MaxiLine][j];
    array[MaxiLine][j] = temp;
}
cout<<"------------------------------------------------"<<endl;
//вывод диномеческого массива нового
for (int i = 0; i < MatInf; i++){
    for( int j = 0; j < MatInf; j++){
        cout<<array[i][j]<<" ";
    }
    cout<<endl;
}
//очистка памяти выделенной для диномического массива динамического массива
for ( int i = 0 ;i < MatInf ; i++){
        delete[](array[i]);
}
delete[](array);
return 0;
}
