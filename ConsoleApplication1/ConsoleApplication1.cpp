#include<iostream>
#include<Windows.h>
using namespace std;
const int MAX_WIDTH = 100;

struct List {
	int array[MAX_WIDTH];
	int size;
};

void add(List&, int);
void add(List&,int,int);
void show(List&);
void remove(List&,int);
void remove_byValue(List&,int);
void init(List&);
int search(List&, int);
int search_byValue(List&, int);
bool isFull(List&);
bool isEmpty(List&);
void clear(List&);
void insert(List&,int,int);
void insert_before(List&,int,int);
void remove_after(List&, int);
void removeBefore(List&,int);
int find_min_position(List&);
void sort(List&);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int choice;
    int position, value;
    List list;
    init(list);// Инициализация
    while (true) {
        cout << "Выберите операцию:" << endl;
        cout << "0. Добавить элемент" << endl; cout << "1. Добавить элемент по позиции" << endl;
        cout << "2. Удалить по позиции" << endl; cout << "3. Удалить по значению" << endl;
        cout << "4. Поиск по позиции" << endl; cout << "5. Поиск по значению" << endl;
        cout << "6. Вывести список" << endl; cout << "\033[1;31m7. Выход с программы\033[0m" << endl;
        cout << "8. Очистка списка" << endl; cout << "9. Добавить после заданного значения" << endl; 
        cout << "10. Добавить перед заданным значением" << endl; cout << "11. Удаление после заданного элемента" << endl; 
        cout << "12. Удаление перед заданным элементом" << endl; cout << "13. Нахождение позиции минимального элемента списка" << endl; 
        cout << "14. Упорядочивание списка" << endl;

        cin >> choice;
        switch (choice) {
        case 0: {
            system("cls");
            if (!isFull(list)) {
                cout << "Введите элемент: "; cin >> value;
                add(list, value);
            }
            else cout << "Список переполнен." << endl;
            break;
            }
        case 1: { // Добавить элемент
            system("cls");
            if (!isFull(list)) {
                cout << "Введите элемент: "; cin >> value;
                cout << "Введите позицию: "; cin >> position;
                add(list, value, position);
            }
            else cout << "Список переполнен." << endl;
            break;
        }
        case 2: { // Удалить элемент
            system("cls");
            if (!isEmpty(list)) {
                cout << "Введите позицию: "; cin >> position;
                remove(list,position);
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 3: { // Удалить по значению
            system("cls");
            if (!isEmpty(list)) {
                cout << "Введите элемент: "; cin >> value;
                remove_byValue(list, value);
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 4: { // Поиск по позиции
            system("cls");
            if (!isEmpty(list)) {
                int idx;
                cout << "Введите позицию: "; cin >> position;
                idx = search(list, position);
                if(idx!=-1)
                    cout <<"Элемент: " << list.array[idx] << endl;
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 5: { // Поиск по значению
            system("cls");
            if (!isEmpty(list)) {
                int idx;
                cout << "Введите элемент: "; cin >> value;
                idx = search_byValue(list, value);
                if (idx >= 0)
                    cout << "Позиция " << idx << endl;
                else cout << "В списке нет такого элемента" << endl;//------
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 6: {   // Вывести список
            if (!isEmpty(list)) {
                cout << "Список: "; show(list);
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 7: return 0; //Выход
        case 8: {
            if (!isEmpty(list)) {
            clear(list);
            cout << "Очистка завершена" << endl;
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 9: { // Добавление после заданного элемента
            if (!isFull(list)) {
                if (!isEmpty(list)) {
                    int newValue;
                    cout << "Введите значение элемента после которого нужно добавить: ";
                    cin >> value;
                    cout << "Введите новый элемент: ";
                    cin >> newValue;
                    insert(list, value, newValue);
                }
                else cout << "Список пуст." << endl;
            }
            else cout << "Список полон." << endl;
            break;
        }
        case 10: { // Добавление перед заданным элемента
            system("cls");
            if (!isFull(list)) {
                if (!isEmpty(list)) {
                    int newValue;
                    cout << "Введите значение элемента перед которым нужно добавить: ";
                    cin >> value;
                    cout << "Введите новый элемент: ";
                    cin >> newValue;
                    insert_before(list, value, newValue);
                }
                else cout << "Список пуст." << endl;
            }
            else cout << "Список полон." << endl;
            break;
        }
        case 11: {
            system("cls");
            if (!isEmpty(list)) {
                cout << "Введите значение элемента после которого нужно удалить следующий элемент: ";
                cin >> value;
                remove_after(list, value);
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 12: {
            system("cls");
            if (!isEmpty(list)) {
                cout << "Введите значение элемента перед которым нужно удалить предыдущий элемент: ";
                cin >> value;
                removeBefore(list, value); 
            }
            else cout << "Список пуст." << endl;
            break;
        }
        case 13: {
            if (!isEmpty(list)) {
                int pos;
                pos = find_min_position(list);
                cout << "Позиция минимального значения в списке" << pos << endl;
            }
            else cout << "Список пуст." << endl;
            break;
               }
        case 14: {
            if (!isEmpty(list)) {
                sort(list);
                cout << "Сортировка завершена" << endl;
            }
            else cout << "Список пуст." << endl << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    }
    return 0;
}

void add(List& list,int value) {
        list.array[list.size++] = value;
}
void init(List& list) {
    list.size = 0; 
}
void add(List& list, int value,int position) { // Вставка по позиции
    if (list.size < MAX_WIDTH && position >= 0 && position <= list.size) {
        for (int i = list.size; i > position; i--)
            list.array[i] = list.array[i - 1];
        list.array[position] = value;
        list.size++;
    }
    else cout << "Недопустимая позиция для добавления элемента." << endl;
}
void remove(List& list,int position) { // Удаление по позиции
    if (position >= 0 && position < list.size) {
        for (int i = position; i < list.size - 1; i++) 
            list.array[i] = list.array[i + 1];
        list.size--;
    }
    else cout << "Недопустимая позиция для удаления элемента." << endl;
}
void remove_byValue(List& list, int value) { // Удаление по значению
    int index = -1;
    for (int i = 0; i < list.size; i++)
        if (list.array[i] == value) {
            index = i; break;
        }
    if (index >= 0)
        remove(list, index);
    else cout << "В списке нет такого элемента" << endl;
}
void show(List& list) {
    system("cls");
    cout << "Список:  ";
    for (int i = 0; i < list.size; ++i)
        cout << list.array[i] << " ";
    cout << endl;
}
int search(List& list, int position) {
    if (position >= 0 && position < list.size) {
        for (int i = 0; i < list.size; i++)
            if (i == position)
                return i;
    }
    else cout << "Недопустимая позиция для поиска элемента." << endl;
    return -1;
}
int search_byValue(List& list, int value) {
    for (int i = 0; i < list.size; i++) {
        if (list.array[i] == value)
            return i;
    }
    return -1;
}
bool isFull(List& list) {
    return list.size == MAX_WIDTH;
}
bool isEmpty(List& list) {
    return list.size == 0;
}
void clear(List& list) {
    for (int i = list.size - 1; i >= 0; i--) {
        list.array[i] = 0;
        list.size--;
    }
    list.size = 0;
}
void insert(List& list, int value,int newValue) { // Вставка после заданного значения
    if (list.size < MAX_WIDTH) {
        int index = search_byValue(list,value);
        if (index != -1) {
            for (int i = list.size; i > index; --i)
                list.array[i] = list.array[i - 1];
            list.array[index + 1] = newValue;
            list.size++;
        }
        else cout << "В списке нет такого элемента" << endl;
    }
}
void insert_before(List& list, int value, int newValue) { // Вставка перед заданного значения
    if (list.size < MAX_WIDTH) {
        int index = search_byValue(list, value);
        if (index != -1) {
            for (int i = list.size; i > index; --i)
                list.array[i] = list.array[i - 1];
            list.array[index] = newValue;
            list.size++;
        }
        else cout << "В списке нет такого элемента" << endl;
    }
}
void remove_after(List& list,int value) {
    int index = search_byValue(list,value);
    if (index != -1 && index < list.size - 1) {
        for (int i = index + 1; i < list.size - 1; i++)
            list.array[i] = list.array[i + 1];
        list.size--;
    }
    else cout << "Не получилось возможны неккоректные данные" << endl;
}
void removeBefore(List& list,int value) {
    int index = search_byValue(list, value);
    if (index != -1 && index > 0) {
        for (int i = index - 1; i < list.size - 1; i++)
            list.array[i] = list.array[i + 1];
        list.size--;
    }
    else cout << "Не получилось возможны неккоректные данные" << endl;
}
int find_min_position(List& list) {
   int count = 0;
   int index = 0;
        for (int i = 1; i < list.size; i++) {
            if (list.array[count++] > list.array[i]) 
                index = i;
        }
        return index;
}
void sort(List& list) {
    int j, swap;
    for (int i = 1; i < list.size; i++) {
        swap = list.array[i];
        j = i;
        while (j > 0 && swap < list.array[j - 1]) {
            list.array[j] = list.array[j - 1];
            --j;
        }
        list.array[j] = swap;
    }
}
