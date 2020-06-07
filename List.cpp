#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List{
public:
    List ();
    ~List();

    void push_beack (T data);
    void pop_front ();
    void clear ();
    void push_front ();
    int get_Size(){
        return Size;
    }
    T&operator[](const int index);

private:
    template <typename Ti> // делаем через шаблонные классы, чтобы не мучатся с изменением по разные тепи данных
    class Node{//класс узла
    public:
        Node *pNext;
        Ti data;

        Node(Ti data = Ti(), Node *pNext = nullptr){
            this-> data = data;
            this->pNext = pNext;
        }
    };

    int Size; //количество элементов
    Node<T> *head;

};

template <typename T>
List<T>::List(){
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List(){// очистак  памяти в конце всего говна
    clear();

}

template <typename T>
void List<T>::push_beack(T data) { // функция добавления
    if (head == nullptr){ // если нет эл в начале списка
        head = new Node<T>(data); // создаем
    }
    else{     //если первые элемент имеется реализуем добавление элементов
        Node<T> *current = this-> head;
        while (current-> pNext != nullptr){ // Проверка на пустое поле
            current = current -> pNext;
        }
        current -> pNext = new Node<T>(data);// если поле не пустое присвоеваем след элементу

    }
Size++; // покле каждого вызова метода добавление эл, увлел переменную ответсвенную ха размер List
}

template<typename T>
T &List<T>::operator[](const int index) {// нахождение индекса
    int counter = 0; // счетчик
    Node<T> *current = this-> head;
    while (current != nullptr){ // пока не конец списка

        if (counter == index){ // если элемент найден
            return current -> data; // забираем адрес элемента
        }
        // ищем дельше элемент
        current = current -> pNext;
        counter++;

    }

}

template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head ->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::clear() {

    while (Size != 0){
        pop_front();
    }

}

int main() {
    List<int> lst;


    int Num , temp;
    cin >> Num;


    for (int i = 0; i < Num; i++){
        cin >> temp;
         lst.push_beack(temp);
    }

    cout << "Size of List: " << lst.get_Size() << endl;

    for (int i = 0; i < lst.get_Size(); i++){
        cout << i << "  ";
    }

    cout << endl;

    for (int i = 0; i < lst.get_Size(); i++){
        cout << lst[i] << " ";
    }




    return 0;
}
