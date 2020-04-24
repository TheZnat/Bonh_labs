#include <iostream>
#include <fstream>
using namespace std;

int BubbleSort( int *arr, int n ){
    unsigned int noco = 0; //number of comparison operations
    int temp; // временная переменная для обмена элементов местами
    // Сортировка массива пузырьком
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                noco++;
                // меняем элементы местами
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return noco;
}
int CocktailSort( int n,int arr1[n]){
    unsigned int noco = 0; //number of comparison operations
    int left = 0, right = n - 1, flag = 1;
    while ((left < right) && flag > 0) {// пока границы не смокнуться и пока в массиве есть эл
        flag = 0;
        for (int i = left; i < right; i++) {// двигаемся с лево на права
            if (arr1[i] > arr1[i + 1]) {
                swap(arr1[i], arr1[i + 1]);
                flag = 1;
                noco++;
            }
        }
        right--;//уменьгаем границу с права
        for (int i = right; i > left; i--) {//двигаемся с права на лево
            if (arr1[i - 1] > arr1[i]) {
                swap(arr1[i], arr1[i - 1]);
                flag = 1;
                noco++;
            }
        }
        left++;//уменьгаем границу с лева
    }
    return noco;
}
int SelectionSort (int *arr2, int n){
    int key;
    unsigned int noco = 0; //number of comparison operations
    int j;
    for (int i = 1; i < n; i++) {
        key = arr2[i]; // запомним обрабатываемый элемент
        // и начнем перемещение элементов слева от него
        // пока запомненный не окажется меньше чем перемещаемый
        for (j = i - 1; j >= 0 && arr2[j] > key; j--)
            arr2[j + 1] = arr2[j];
            arr2[j + 1] = key; // и поставим запомненный на его новое место
            noco++;
    }
    return noco;
}
int BinarySearch (int *arr, int n, int x, unsigned int noco){
    noco = 0;
    int left = 0;
    int right = n;
    int middle;
    while (left < right) {
        middle = (left + right) / 2;
        if (arr[middle] > x) {
            left = middle + 1;
            noco++;
        } else {
            right = middle;
            noco++;
        }
    }
    return middle;
}
int main() {
ifstream inp("inp.txt");
ofstream out("out.txt");
int n = 20;
int arr[n];
unsigned int noco; //number of comparison operations

//пузырькавая сортировка
for ( int i = 0; i < n; i++){ // заполняем эл
    inp>>arr[i];
}
out<<"Пузырьковая Сортировка : ";
noco = BubbleSort(arr, n);
for (auto now: arr){
    out<<now<<" ";
}
out<<endl<<"Количество операций сравнения : "<< noco;
out<<endl<<endl;
inp.close();

// шейкерная сортировка
inp.open("inp.txt");
int arr1[n];
for ( int i = 0; i < n; i++){ // заполняем эл
    inp>>arr1[i];
}
noco = CocktailSort(n, arr1);
out<<"Шейкерная Сортировка : ";
for (auto now: arr1){
    out<<now<<" ";
}
out<<endl<<"Количество операций сравнения : "<< noco;
out<<endl<<endl;
inp.close();

//Сортировка Выбором
inp.open("inp.txt");
int arr2[n];
for (int i = 0; i < n; i++){
    inp>>arr2[i];
}
out<<"Сортировка Выбором : ";
noco = SelectionSort(arr2,n);
for (auto now: arr2){
    out<<now<<" ";
}
out<<endl<<"Количество операций сравнения : "<< noco<<endl;
out<<endl;
inp.close();

//бинарный поиск
inp.open("inp.txt");
int x = 88;// искомое число в массиве
out<<"Бинарный поиск числа "<<x<<endl;
out<<"В массиве : ";
for (int i = 0; i < n; i++){
    out<<arr2[i]<<" ";
}
out<<endl;
int left = 0;
int right = n;
int middle;
noco = 0;
while (left < right ){
int middle = (left + right) / 2;
    if (arr2[middle] < x){
        left = middle + 1;
        noco ++;
}
    else{
        right = middle;
        noco++;
    }
}
out<<"Ответ:"<<left<<endl;
out<<"Количество операций сравнения : "<< noco<< endl<<endl;
inp.close();

// сквозной поиск
out<<"Сквозной Поиск числа "<<x<<endl;
out<<"В массиве : ";
for (int i = 0; i < n; i++){
    out<<arr2[i]<<" ";
}
out<<endl;
noco = 0;
for (int i = 1; i < n ; ++i){
    if (arr2[i] == x){
        out<<"Ответ:"<<i<<endl;;
        break;
    }
}
out<<"Количество операций сравнения : "<< noco;
inp.close();
out.close();
    return 0;
}
