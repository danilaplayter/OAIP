#include <iostream>
#include <string>
#include <fstream>
#include "Functions.h"

using namespace std;

struct Purchse
{
    string invoice_number;
    string supplier_name; 
    string material_name; 
    string quantity; 
    string price_per_unit; 
    string total_price; 
};

static Purchse purchase[30];
static string something;

int amount = 0;
bool jim;

fstream file_purchase;

extern bool check()
{
    for (int i = 0; i < something.size(); i++) {
        if (48 > something[i] || something[i] > 57) {
            return false;
            break;
        }
        return true;
    }
}

extern void get_data_from_file() {
    file_purchase.open("Purchase.txt", ios::in);
    if (file_purchase.is_open()) {
        if (!file_purchase.eof()) {
            register string some;
            register int flag = 0;
            amount = 1;
            while (getline(file_purchase, some)) {
                flag++;

                if (flag == 12) {
                    flag = 0;
                    amount++;
                }
                if(flag == 4) {
                    purchase[amount - 1].supplier_name = "";
                    for (int i = 39; i < some.size(); i++) {
                        purchase[amount - 1].supplier_name += some[i];
                    }
                }
                if (flag == 5){
                    purchase[amount - 1].invoice_number = "";
                    for (int i = 31; i < some.size(); i++) {
                        purchase[amount - 1].invoice_number += some[i];
                    }
                }
                if (flag == 6) {
                    purchase[amount - 1].material_name = "";
                    for (int i = 37; i < some.size(); i++) {
                        purchase[amount - 1].material_name += some[i];
                    }
                }
                if (flag == 7) {
                    purchase[amount - 1].quantity = "";
                    for (int i = 41; i < some.size()-3; i++) {
                        purchase[amount - 1].quantity+= some[i];
                    }
                }
                if (flag == 8) {
                    purchase[amount - 1].price_per_unit = "";
                    for (int i = 19; i < some.size()-3; i++) {
                        purchase[amount - 1].price_per_unit += some[i];
                    }
                }
                if (flag == 9) {
                    purchase[amount - 1].total_price = "";
                    for (int i = 49 ; i < some.size()-3; i++) {
                        purchase[amount - 1].total_price += some[i];
                    }
                }

            }

            amount--;
            file_purchase.close();
            cout << "Данные считаны из файла.\n";
        }
        else {
            cout << "Файл пустой.";
        }
    }
    else {
        cout << "Файл не открыт.\n";
    }
}

extern void put_data_into_file() {
    if (amount == 0) {
        cout << "Нету данных, чтобы ввести в файл.\n";
    }
    else {
        clear();
        file_purchase.open("Purchase.txt", ios::app);
        if (file_purchase.is_open()) {
            for (int i = 0; i < amount; i++) {
                file_purchase << "\n************************\n";
                file_purchase << "\nНазвание поставщика: " << purchase[i].supplier_name;
                file_purchase << "\nНомер накладной: " << purchase[i].invoice_number;
                file_purchase << "\nНазвание материала: " << purchase[i].material_name;
                file_purchase << "\nКоличество материала: " << purchase[i].quantity << "м3";
                file_purchase << "\nЦена за м3: " << purchase[i].price_per_unit << "BYN";
                file_purchase << "\nЦена за общее количество " << purchase[i].material_name << ": " << stoi(purchase[i].price_per_unit) * stoi(purchase[i].quantity) << "BYN\n";
                file_purchase << "\n************************\n\n";
            }
            file_purchase.close();
            cout << "Данные записаны в файл.\n";
        }
        else {
            cout << "Файл не открыт.\n";
        }
    }
}

extern void enter_material_amount() {
    printf("Введите колличество материала в м3: ");
    cin >> something;

    if (check()) {
        purchase[amount].quantity = something;
    }
    else {
        cout << "Введите число, а не символы.\n";
        enter_material_amount();
    }
}
extern void enter_price_per_unit() {

    cout << "Введите цену материала за м3: ";
    cin >> something;

    if (check()) {
        purchase[amount].price_per_unit = something;
    }
    else {
        cout << "Введите число, а не символы.\n";
        enter_price_per_unit();
    }
}
extern void enter() {
    register string something;
    register bool faggot = true;
    cout << "Введите номер накладной: ";
    cin >> something;
    
    for (int i = 0; i < amount; i++) {
        if (stoi(something) == stoi(purchase[i].invoice_number)) {
            cout << "Запись с таким номером уже существует.\n";
            faggot = false;
        }
    }
    if (faggot) {

        purchase[amount].invoice_number = something;

        cout << "Введите название поставщика: ";
        cin >> purchase[amount].supplier_name;

        cout << "Введите название материала: ";
        cin >> purchase[amount].material_name;

        enter_material_amount();

        enter_price_per_unit();

        purchase[amount].total_price = to_string(stoi(purchase[amount].price_per_unit) * stoi(purchase[amount].quantity));

        amount++;
    }
    else {
        cout << "Введите уникальный номер накладной.\n";
        enter();
    }
}

extern void print_all() {
    if (amount == 0) {
        cout << "В файле нету записей.\n";
    }
    else {
        if (amount == 1) {
            cout << "В файле только одна запись: \n";
            cout << "\n************************\n";
            cout << "Введите название поставщика: " << purchase[0].supplier_name << '\n';
            cout << "Введите номер накладной: " << purchase[0].invoice_number << '\n';
            cout << "Введите название материала: " << purchase[0].material_name << '\n';
            cout << "Введите колличество материала в м3: " << purchase[0].quantity << '\n';
            cout << "Введите цену материала за м3: " << purchase[0].price_per_unit << '\n';
            cout << "Общая стоимость: " << purchase[0].total_price << '\n';
            cout << "*************************\n";
        }
        else {
            for (int i = 0; i < amount; i++) {
                cout << "\n************************\n";
                cout << "Введите название поставщика: " << purchase[i].supplier_name << '\n';
                cout << "Введите номер накладной: " << purchase[i].invoice_number << '\n';
                cout << "Введите название материала: " << purchase[i].material_name << '\n';
                cout << "Введите колличество материала в м3: " << purchase[i].quantity << '\n';
                cout << "Введите цену материала за м3: " << purchase[i].price_per_unit << '\n';
                cout << "Общая стоимость: " << purchase[i].total_price << '\n';
                cout << "*************************\n";
            }
        }
        cout << '\n';
    }
}

extern void print_the_one() {
    if (amount == 0) {
        cout << "В файле нету записей.\n";
    }
    else {
        if (amount == 1) {
            cout << "В файле только одна запись: ";
            cout << "\n************************\n";
            cout << "Введите название поставщика: " << purchase[0].supplier_name << '\n';
            cout << "Введите номер накладной: " << purchase[0].invoice_number << '\n';
            cout << "Введите название материала: " << purchase[0].material_name << '\n';
            cout << "Введите колличество материала в м3: " << purchase[0].quantity << '\n';
            cout << "Введите цену материала за м3: " << purchase[0].price_per_unit << '\n';
            cout << "Общая стоимость: " << purchase[0].total_price << '\n';
            cout << "*************************\n";
        }
        else {
            register bool faggot = true;
            cout << "Введите номер накладной: \n";
            cin >> something;
            if (check()) {
                for (int i = 0; i < amount; i++) {
                    if (purchase[i].invoice_number == something) {
                        cout << "\n************************\n";
                        cout << "Введите название поставщика: " << purchase[i].supplier_name << '\n';
                        cout << "Введите номер накладной: " << purchase[i].invoice_number << '\n';
                        cout << "Введите название материала: " << purchase[i].material_name << '\n';
                        cout << "Введите колличество материала в м3: " << purchase[i].quantity << '\n';
                        cout << "Введите цену материала за м3: " << purchase[i].price_per_unit << '\n';
                        cout << "Общая стоимость: " << purchase[i].total_price << '\n';
                        cout << "*************************\n";
                        faggot = false;
                    }
                }
                if (faggot) {
                    cout << "Накладная по данному номеру не найдена либо она не существует.\n";
                }
            }
            else {
                cout << "Введите число, а не симолы.\n";
            }
        }
    }
}

extern void sort() {
    register Purchse temp;
    if (amount == 0) {
        cout << "В файле нету записей.\n";
    }
    else {
        if (amount == 1) {
            cout << "В файле только одна накладная.\n";
        }
        else {
            for (int i = 0; i < amount - 1; i++) {
                for (int j = 0; j < amount - 1; j++) {
                    if (purchase[j].invoice_number > purchase[j + 1].invoice_number) {
                        temp = purchase[j];
                        purchase[j] = purchase[j + 1];
                        purchase[j + 1] = temp;
                    }
                }
            }
            cout << "Набор накладных отсортирован по номеру.\n";
        }
    }
}

extern void change() {
    
    if (amount == 0) {
        cout << "В файле нету накладных.";
    }
    else {
        if (amount == 1) {
            cout << "Изменить единственную накладную: \n";
            cout << "\n************************\n";
            cout << "Введите название поставщика: ";
            cin >> purchase[0].supplier_name;
            cout << "Введите номер накладной: ";
            cin >> purchase[0].invoice_number;
            cout << "Введите название материала: ";
            cin >> purchase[0].material_name;
            cout << "Введите колличество материала в м3: ";
            cin >> purchase[0].quantity;
            cout << "Введите цену материала за м3: ";
            cin >> purchase[0].price_per_unit;
            cout << "Общая стоимость: ";
            cin >> purchase[0].total_price;
            cout << "*************************\n";
        }
        else {
            register string something;
            cout << "Введите номер накладной, которую вы хотите изменить: ";
            cin >> something;
            if (check()) {
                for (int i = 0; i < amount; i++) {
                    if (stoi(purchase[i].invoice_number) == stoi(something)) {
                        cout << "\n************************\n";
                        cout << "Введите название поставщика: ";
                        cin >> purchase[0].supplier_name;
                        cout << "\nВведите номер накладной: ";
                        cin >> purchase[0].invoice_number;
                        cout << "\nВведите название материала: ";
                        cin >> purchase[0].material_name;
                        cout << "\nВведите колличество материала в м3: ";
                        cin >> purchase[0].quantity;
                        cout << "\nВведите цену материала за м3: ";
                        cin >> purchase[0].price_per_unit;
                        cout << "\nОбщая стоимость: ";
                        cin >> purchase[0].total_price;
                        cout << "\n*************************\n";
                    }
                }
            }
            else {
                cout << "Введите число, а не символы.";
                sort();
            }
            
        }
    }/*
        else {
            cout << "Введите номер накладной: ";
            cin >> something;
            if (check()) {
            else {

            else {
                
            }
            cout << "Введите число, а не символы.\n";
            }
            }
        }
    }*/
}

extern void delete_invoice() {
    if (amount == 0) {
        cout << "В файле нету записей.\n";
    }
    else {
        if (amount == 1) {
            cout << "В файле была только одна запись.\n";
            amount = 0;
            
        }
        else {
            register bool faggot = true;
            register int flag = 0;
            cout << "Введите номер накладной: ";
            cin >> something;
            if (check()) {

                for (int i = 0; i < amount; i++) {
                    if (purchase[i].invoice_number == something) {
                        flag = i;
                        break;
                    }
                    faggot = false;
                }

                for (flag; flag < amount - 1; flag++) {
                    purchase[flag].supplier_name = purchase[flag + 1].supplier_name;
                    purchase[flag].invoice_number = purchase[flag + 1].invoice_number;
                    purchase[flag].material_name = purchase[flag + 1].material_name;
                    purchase[flag].quantity = purchase[flag + 1].quantity;
                    purchase[flag].price_per_unit = purchase[flag + 1].price_per_unit;
                    purchase[flag].total_price = purchase[flag + 1].total_price;
                }

                if (faggot) {
                    cout << "Накладная по данному номеру не найдена либо она не существует.\n";
                }
                else {
                    amount--;
                }
            }
            else {
                cout << "Введите число, а не симолы.\n";
            }
        }
    }
}

extern void clear() {
    file_purchase.open("Purchase.txt", ios::out);
    file_purchase.close();
    file_purchase.open("Purchase.txt", ios::app);
    file_purchase.close();
}

extern void purchase_task() {
    register int flag;
    cout << "1. Ввести новую накладную.\n";
    cout << "2. Вывести накладные.\n";
    cout << "3. Вывести наклодную.\n";
    cout << "4. Отсортировать накладные.\n";
    cout << "5. Изменить накладную.\n";
    cout << "6. Удалить накладную.\n";
    cout << "7. Очистить файл.\n";
    cout << "8. Считать данные из файла.\n";
    cout << "9. Записать данные в файл.\n";
    cout << "10. Выйти из программы.\n";
    cout << "Введите номер операции: ";
    cin >> something;
    if (check()) {
        flag = stoi(something);
        switch (flag)
        {
        case 1: {
            enter();
            purchase_task();
            break;
        }
        case 2: {
            print_all();
            purchase_task();
            break;
        }

        case 3: {
            print_the_one();
            purchase_task();
            break;
        }
        case 4: {
            sort();
            purchase_task();
            break;
        }

        case 5: {
            change();
            purchase_task();
            break;
        }
        case 6: {
            delete_invoice();
            purchase_task();
            break;
        }
        case 7: {
            clear();
            cout << "Файл очищен.\n";
            purchase_task();
            break;
        }
        case 8: {
            get_data_from_file();
            purchase_task();
            break;
        }
        case 9: {
            put_data_into_file();
            purchase_task();
            break;
        }
        case 10: {
            break;
        }
        default: {
            cout << "Введите корректное число или '5', чтобы выйти из программы\n";
            purchase_task();
        }
        }
    }
    else {
        cout << "Введите число, а не символы.\n";
        purchase_task();
    }
}
