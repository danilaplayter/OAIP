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

static Purchse purchase[30], temp[30];
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
extern void struct_out() {
    for (int i = 0; i < amount; i++) {
        cout << purchase[i].invoice_number << '\n';
        cout << purchase[i].supplier_name << '\n';
        cout << purchase[i].material_name << '\n';
        cout << purchase[i].quantity << '\n';
        cout << purchase[i].price_per_unit << '\n';
        cout << purchase[i].total_price << '\n';
    }
    
}
extern void enter_material_amount() {
    printf("Введите колличество материала в м3: ");
    cin >> purchase[amount].quantity;

    something = purchase[amount].quantity;

    if (check()) {
        file_purchase << "\nКоличество материала: " << purchase[amount].quantity << "м3";
    }
    else {
        cout << "Введите число, а не символы.\n";
        enter_material_amount();
    }
}
extern void enter_price_per_unit() {
    printf("Введите цену материала за м3: ");
    cin >> purchase[amount].price_per_unit;

    something = purchase[amount].price_per_unit;

    if (check()) {
        file_purchase << "\nЦена за м3: " << purchase[amount].price_per_unit << "BYN";
    }
    else {
        cout << "Введите число, а не символы.\n";
        enter_price_per_unit();
    }
}
extern void enter() {

    printf("Введите название поставщика: ");
    cin >> purchase[amount].supplier_name;
    file_purchase << "\nНазвание поставщика: " << purchase[amount].supplier_name;

    printf("Введите номер накладной: ");
    cin >> purchase[amount].invoice_number;
    file_purchase << "\nНомер накладной: " << purchase[amount].invoice_number;


    printf("Введите название материала: ");
    cin >> purchase[amount].material_name;
    file_purchase << "\nНазвание материала: " << purchase[amount].material_name;

    enter_material_amount();

    enter_price_per_unit();

    file_purchase << "\nЦена за общее количество " << purchase[amount].material_name << ": " << stoi(purchase[amount].price_per_unit) * stoi(purchase[amount].quantity) << "BYN\n";

    purchase[amount].total_price = to_string(stoi(purchase[amount].price_per_unit) * stoi(purchase[amount].quantity));

    file_purchase << "\n************************\n";
    
} 
extern bool check_amount() {
    register string lim;
    while (getline(file_purchase, lim)) {
        if (lim == " ") {
            return false;
        }
        if (lim == "************************") {
            amount++;
        }
        return true;
    }
}


extern void sort() {
    file_purchase.open("Purchase.txt", ios::in);

    if (file_purchase.is_open()) {

        register string some;
        register int count = 0;
        while (getline(file_purchase, some)) {
            if (some == "************************") {
                count = 0;
                amount++;
            }
            switch (count) {
            case 1: {
                purchase[amount].supplier_name = some;
            }
            case 2: {
                purchase[amount].invoice_number = some;
            }
            case 3: {
                purchase[amount].material_name = some;
            }
            case 4: {
                purchase[amount].quantity = some;
            }
            case 5: {
                purchase[amount].price_per_unit = some;
            }
            case 6: {
                purchase[amount].total_price = some;
            }
            }
            count++;
        }
    }
    else {
        cout << "Ошибка открытия файла.\n";
    }
    file_purchase.close();
    cout << "До сортировки : \n*************************\n";
    for (int i = 0; i < amount; i++) {
        cout << purchase[i].supplier_name << endl;
        cout << purchase[i].invoice_number << endl;
        cout << purchase[i].material_name << endl;
        cout << purchase[i].quantity << endl;
        cout << purchase[i].price_per_unit << endl;
        cout << purchase[i].total_price << endl;
        cout << "*************************\n";
    }

    for (int i = 0; i < amount - 1; i++) {
        for (int n = 0; n < amount - 1; n++) {
            if (purchase[n].invoice_number > purchase[n + 1].invoice_number) {
                temp[0] = purchase[n + 1];
                purchase[n + 1] = purchase[n];
                purchase[n] = temp[0];
            }
        }
    }

    cout << "После сортировки : \n";
    for (int i = 0; i < amount; i++) {
        cout << purchase[i].supplier_name << endl;
        cout << purchase[i].invoice_number << endl;
        cout << purchase[i].material_name << endl;
        cout << purchase[i].quantity << endl;
        cout << purchase[i].price_per_unit << endl;
        cout << purchase[i].total_price << endl;
        cout << "*************************\n";
    }

    clear();

    for (int i = 0; i < amount; i++) {
        file_purchase << "************************\n";
        file_purchase << purchase[i].supplier_name << endl;
        file_purchase << purchase[i].invoice_number << endl;
        file_purchase << purchase[i].material_name << endl;
        file_purchase << purchase[i].quantity << endl;
        file_purchase << purchase[i].price_per_unit << endl;
        file_purchase << purchase[i].total_price << endl;
        file_purchase << "*************************\n";
    }
    file_purchase.close();
}

extern void print_all() {
        file_purchase.open("Purchase.txt", ios::in);
        if (file_purchase.is_open()) {
            register string some;
            while (getline(file_purchase, some)) {
                cout << some << '\n';
            }
            cout << "\n";
        }
        else {
            cout << "Ошибка открытия файла.\n";
        }
        file_purchase.close();
}
extern void clear() {
    file_purchase.close();
    file_purchase.open("Purchase.txt", ios::out);
    file_purchase.close();
    file_purchase.open("Purchase.txt", ios::app);
}
extern void purchase_task() {
    register int flag;
    printf("1. Ввести новую накладную.\n");
    printf("2. Вывести накладную.\n");
    printf("3. Отсортировать накладные.\n");
    printf("4. Очистить файл.\n");
    printf("5. Выйти из программы.\n");
    printf("Введите номер операции: ");
    cin >> something;
    if (check()) {
        flag = stoi(something);
        switch (flag)
        {
        case 1: {
            file_purchase.open("Purchase.txt", ios::app);
            enter();
            file_purchase.close();
            purchase_task();
            break;
        }
        case 2: {
            if (check()) {
                if (file_purchase.peek() == EOF) {
                    print_all();
                    purchase_task();
                    break;
                }
                else {
                    cout << "Файл пустой.\n";
                    file_purchase.close();
                    purchase_task();
                    break;
                }
            }
            else {
                cout << "Введите номер операции, а не символы.\n";
                purchase_task();
                break;
            }
        }
        case 3: {
            sort();
            purchase_task();
            break;
        }
        case 4: {
            if (file_purchase.peek() == EOF) {
                clear();
                cout << "Файл очищен.\n";
                purchase_task();
                break;
            }
            else {
                cout << "Файл пустой.\n";
                purchase_task();
                break;
            }
            purchase_task();
            break;
        }
        case 5: {
            break;
            file_purchase.close();
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
