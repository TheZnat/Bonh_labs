#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<typename T>
struct list{
public:
    list();
    ~list();
    int get_Size() {
        return Size;
    }
    void push_beack(T nomer, T year, T Surname, T Name, T Mid_Name);
    void pop_front();
    void dat(int index);
    void edit(int index, T nomer, T year, T Surname, T Name, T Mid_Name);
    T& operator[](const int index);
private:
    template<typename T1>
    struct uzer{
    public:
        uzer* adress;
        T1 nomer;
        T1 year;
        T1 Surname;
        T1 Name;
        T1 Mid_Name;

        uzer(T1 nomer = T1(), T1 year = T1(), T1 Surname = T1(), T1 Name = T1(), T1 Mid_Name = T1(), uzer* adress = nullptr){
            this -> nomer = nomer;
            this -> adress = adress;
            this -> year = year;
            this -> Surname = Surname;
            this -> Name  = Name;
            this -> Mid_Name = Mid_Name;
        }
    };
    int Size;//количество элементов
    uzer<T> *head;
};
template<typename T>
list<T>::list(){
    Size = 0;
    head = nullptr;
}
template<typename T>
list<T>::~list(){
    while (Size){
        pop_front();
    }
}
template<typename T>
void list<T>::push_beack(T nomer, T year, T Surname, T Name, T Mid_Name){
    if (head == nullptr){
        head = new uzer<T>(nomer, year, Surname, Name, Mid_Name);
    }
    else{
        uzer<T>* current = this -> head;
        while (current -> adress != nullptr){
            current = current -> adress;
        }
        current -> adress = new uzer<T>(nomer, year, Surname, Name, Mid_Name);
    }
    Size++;
}
int L;
template<typename T>
T& list<T>::operator[](const int index){
    uzer<T>* current = this -> head;
    int temp = 0;
    if (L == 0)
        while (current != nullptr){
            if (temp == index){
                return current -> Surname;
            }
            current = current -> adress;
            temp++;
        }
    else if (L == 1)
        while (current != nullptr){
            if (temp == index)
            {
                return current -> Name;
            }
            current = current -> adress;
            temp++;
        }
    else if (L == 2)
        while (current != nullptr){
            if (temp == index){
                return current -> Mid_Name;
            }
            current = current -> adress;
            temp++;
        }
    else if (L == 3)
        while (current != nullptr){
            if (temp == index){
                return current -> year;
            }
            current = current -> adress;
            temp++;
        }
    else if (L == 4)
        while (current != nullptr){
            if (temp == index){
                return current -> nomer;
            }
            current = current -> adress;
            temp++;
        }
}
template<typename T>
void list<T>::pop_front(){
    uzer<T> *Mid_Name = head;
    head = head -> adress;
    delete Mid_Name;
    Size--;
}
template<typename T>
void list<T>::dat(int index){
    if (index == 0){
        pop_front();
    }
    else{
        uzer<T>* Kp = this -> head;
        for (int i = 0; i < index - 1; i++)
        {
            Kp = Kp -> adress;
        }
        uzer<T>* Ge = Kp -> adress;
        Kp -> adress = Ge -> adress;
        delete Ge;
        Size--;
    }
}
template<typename T>
void list<T>::edit(int index, T nomer, T year, T Surname, T Name, T Mid_Name){
    uzer<T>* current = this -> head;
    for (int i = 0; i < index; i++){
        current = current -> adress;
    }
    current -> Surname = Surname;
    current -> Name = Name;
    current -> Mid_Name = Mid_Name;
    current -> year = year;
    current -> nomer = nomer;
}
int main(){
list <string> lst;
ifstream txt;
string Surname = "", Name = "", Mid_Name = "", year = "", nomer = "";

txt.open("File.txt");
if (txt.is_open()){
    while (!txt.eof()){
        Surname = "", Name = "", Mid_Name = "", year = "", nomer = "";
        char b, q = ' ';
        int y = 0, r1 = 0;

        txt >> b;
        while (b != ' ' && y < 3){
            q = b;
            txt.get(b);
            if (q == b)
                y++;
        }
        txt.get(b);
        while (b != ' ' && y < 3){
            Surname += b;
            txt.get(b);
        }
        txt.get(b);
        while (b != ' ' && y < 3){
            Name += b;
            txt.get(b);
        }
        txt.get(b);
        while (b != ' ' && y < 3){
            Mid_Name += b;
            txt.get(b);
        }
        txt.get(b);
        while (b != ' ' && y < 3){
            year += b;
            txt.get(b);
        }
        txt.get(b);
        while (b != ' ' && b != '\n' && y < 3){
            nomer += b;
            txt.get(b);
        }
        txt >> b;
        if (y < 3)
            lst.push_beack(nomer, year, Surname, Name, Mid_Name);
        }
    }
    txt.close();

    for (; ; ){
        int Num_Operation;
        cout<<"______Все операции______\n"
              "1 Load - загрузить файл данных с диска и вывести данные на экран\n"
              "2 Edit – редактировать выбранную запись(узел)\n"
              "3 Edit – редактировать выбранную запись(узел)\n"
              "4 Add – добавить запись(узел)\n"
              "5 Delete – удалить запись(узел)\n"
              "6 Exit – выход из программы с очисткой памяти от списка\n"
              "------------------------- \n"
              "Ввидите номер операции \n";
        cin >> Num_Operation;
        if (Num_Operation == 1)
        {
            for (int i = 0; i < lst.get_Size(); i++)
            {
                L = 0;
                cout << i + 1 << ") " << lst[i] << " "; L++;
                cout << lst[i] << " "; L++;
                cout << lst[i] << " "; L++;
                cout << lst[i] << " "; L++;
                cout << lst[i] << " "; L++;
                cout << endl;
            }
        }
        else
        if (Num_Operation == 2)
        {
            ofstream txt3;
            txt3.open("File.txt");
            if (txt3.is_open())
            {
                for (int i = 0; i < lst.get_Size(); i++)
                {
                    L = 0;
                    txt3 << endl;
                    txt3 << i + 1 << ") " << lst[i] << " "; L++;
                    txt3 << lst[i] << " "; L++;
                    txt3 << lst[i] << " "; L++;
                    txt3 << lst[i] << " "; L++;
                    txt3 << lst[i] << " "; L++;
                }
            }
            txt3.close();
        }
        else
        if (Num_Operation == 3){
            cout << "\nВидите: номре в списке , ФИО, Год рождения и Номер тел.\n";
            string s;
            int a;
            cin >> a;
            getline(cin, s);
            getline(cin, Surname);
            getline(cin, Name);
            getline(cin, Mid_Name);
            getline(cin, year);
            getline(cin, nomer);
            lst.edit(a - 1, nomer, year, Surname, Name, Mid_Name);
        }
        else if (Num_Operation == 4){
            string s;
            getline(cin, s);
            getline(cin, Surname);
            getline(cin, Name);
            getline(cin, Mid_Name);
            getline(cin, year);
            getline(cin, nomer);
            lst.push_beack(nomer, year, Surname, Name, Mid_Name);
        }
        else if (Num_Operation == 5) {
            int temp;
            cin >> temp;
            lst.dat(temp - 1);
        }
        else if (Num_Operation == 6){
            return 0;
        }
    }
}