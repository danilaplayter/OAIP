#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

struct purchase
{
	int invoice_number;
	int quantity;
	int price_per_unit;

};

fstream file_sorts;
int amount = 0;

vector <int> array_a, array_b, array_c, array_d, array_e;
vector<purchase> purchase_array;

extern bool check(string something)
{
    for (int i = 0; i < something.size(); i++) {
        if (48 > something[i] || something[i] > 57) {
            return false;
            break;
        }
        return true;
    }
}

extern void enter(vector<purchase>& purchase_array) {
	register int size;
	cout << "Введите количество структур: ";
	cin >> size;

	if (size > 10) {

		purchase_array.resize(size);
		for (int i = 0; i < size; i++) {
			purchase_array[i].invoice_number = rand() * 10;
			purchase_array[i].price_per_unit = rand() * 10;
			purchase_array[i].quantity = rand() * 10;
		}

		for (int i = 0; i < purchase_array.size(); i++) {
			cout << "\n************************\n";
			cout << "Введите номер накладной: " << purchase_array[i].invoice_number << '\n';
			cout << "Введите колличество материала в м3: " << purchase_array[i].quantity << '\n';
			cout << "Введите цену материала за м3: " << purchase_array[i].price_per_unit << '\n';
			cout << "*************************\n";
		}
	}
	else {
		cout << "Введите размерность 10 или более";
		enter(purchase_array);
	}
}

extern void put_array_a(vector<int>& array) {
	register int size;
	register string something;
	if (check(something)) {
		cout << "Введите размерность a: ";
		cin >> size;
		if (size > 10) {
			array.resize(size);
			for (int i = 0; i < size; i++) {
				array[i] = rand() * 10;
			}
			cout << "Введённые элементы массива а: ";
			for (int i = 0; i < 10; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "Введите размерность 10 или более\n";
			put_array_a(array);
		}
	}
	else {
		cout << "Введите числа, а не символы.\n";
		put_array_a(array);
	}
	cout << '\n';
}
extern void put_array_b(vector<int> &array) {
	register int size;
	register string something;
	if (check(something)) {
		cout << "Введите размерность b: ";
		cin >> size;
		if (size > 10) {
			array.resize(size);
			for (int i = 0; i < size; i++) {
				array[i] = rand() * 10;
			}
			cout << "Введённые элементы массива b: ";
			for (int i = 0; i < 10; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "Введите размерность 10 или более";
			put_array_b(array);
		}
	}
	else {
		cout << "Введите числа, а не сиволы\n";
		put_array_b(array);
	}
	cout << '\n';
}
extern void put_array_c(vector<int> &array) {
	register int size;
	register string something;
	if (check(something)) {
		cout << "Введите размерность c: ";
		cin >> size;
		if (size > 10) {
			array.resize(size);
			for (int i = 0; i < size; i++) {
				array[i] = rand() * 10;
			}
			cout << "Введённые элементы массива c: ";
			for (int i = 0; i < 10; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "Введите размерность 10 или более";
			put_array_c(array);
		}
	}
	else {
		cout << "Введите число, а не символы.\n";
		put_array_c(array);
	}
	cout << '\n';
}
extern void put_array_d(vector<int> &array) {
	register int size;
	register string something;
	if (check(something)) {
		cout << "Введите размерность d: ";
		cin >> size;
		if (size > 10) {
			array.resize(size);
			for (int i = 0; i < size; i++) {
				array[i] = rand() * 10;
			}
			cout << "Введённые элементы массива d: ";
			for (int i = 0; i < 10; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "Введите размерность 10 или более";
			put_array_d(array);
		}
	}
	else {
		cout << "Введите число, а не символы.\n";
		put_array_d(array);
	}
	cout << '\n';
}
extern void put_array_e(vector<int>& array) {
	register int size;
	register string something;
	if (check(something)) {
		cout << "Введите размерность e: ";
		cin >> size;
		if (size > 10) {
			array.resize(size);
			for (int i = 0; i < size; i++) {
				array[i] = rand() * 10;
			}
			cout << "Введённые элементы массива e: ";
			for (int i = 0; i < 10; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "Введите размерность 10 или более";
			put_array_e(array);
		}
	}
	else {
		cout << "Введите число, а не символы.\n";
		put_array_e(array);
	}
	cout << '\n';
}

extern void bubble_sort(vector<int>& array_a) {

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < array_a.size() - 1; i++) {
		for (int j = 0; j < array_a.size() - 1; j++) {
			if (array_a[j] > array_a[j+1]) {
				int tmp = array_a[j];
				array_a[j] = array_a[j + 1];
				array_a[j + 1] = tmp;
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "Затраченное время на сортировку пузырьком: " << duration.count() << " (в миллисекундах)\n";

	/*cout << "Отсортированный массив a: ";
	for (int i = 0; i < array_a.size(); i++) {
		cout << array_a[i] << " ";
	}*/
	cout << "\n";
}
extern void selection_sort(vector<int>& array_b) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < array_b.size() - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < array_b.size(); j++) {
			if (array_b[j] < array_b[minIndex]) {
				minIndex = j;
			}
		}
		int tmp = array_b[i];
		array_b[i] = array_b[minIndex];
		array_b[minIndex] = tmp;
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "Затраченное время на сортировку обменом: " << duration.count() << " (в миллисекундах)\n";

	/*cout << "Отсортированный массив c: ";
	for (int i = 0; i < array_b.size(); i++) {
		cout << array_b[i] << " ";
	}*/
	cout << "\n";
}
extern void insertion_sort(vector<int>& array_c) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 1; i < array_c.size(); i++) {
		int key = array_c[i];
		int j = i - 1;
		while (j >= 0 && array_c[j] > key) {
			array_c[j + 1] = array_c[j];
			j--;
		}
		array_c[j + 1] = key;
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "Затраченное время на сортировку вставвкой: " << duration.count() << " (в миллисекундах)\n";

	/*cout << "Отсортированный массив c: ";
	for (int i = 0; i < array_c.size(); i++) {
		cout << array_c[i] << " ";
	}*/
	cout << "\n";
}
extern void shell_sort(vector<int>& array_d) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t gap = array_d.size() / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < array_d.size(); i++) {
			int temp = array_d[i];
			size_t j;
			for (j = i; j >= gap && array_d[j - gap] > temp; j -= gap) {
				array_d[j] = array_d[j - gap];
			}
			array_d[j] = temp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "Затраченное время на сортировку Шеллом: " << duration.count() << " (в миллисекундах)\n";

	/*cout << "Отсортированный массив d: ";
	for (int i = 0; i < array_d.size(); i++) {
		cout << array_d[i] << " ";
	}*/
	cout << "\n";
}
extern void quick_sort(vector<int>& array_e, int low, int high) {
	if (low < high+1) {
		int pivot = array_e[high];
		int i = low - 1;
		for (int j = low; j < high+1; j++) {
			if (array_e[j] < pivot) {
				i++;
				swap(array_e[i], array_e[j]);
			}
		}
		swap(array_e[i + 1], array_e[high]);
		register int partitionIndex = i + 1;

		quick_sort(array_e, low, partitionIndex - 1);
		quick_sort(array_e, partitionIndex + 1, high);
	}
	
	/*cout << "Отсортированный массив е: ";
	for (int i = 0; i < array_e.size(); i++) {
		cout << array_e[i] << " ";
	}
	cout << "\n";*/
}	

extern void sort_by_invoice_number(vector<purchase>& purchase_array){

	for (int i = 0; i < purchase_array.size()-1;i++) {
		for (int j = 0; j < purchase_array.size()-1; j++){
			if (purchase_array[j].invoice_number > purchase_array[j + 1].invoice_number) {
				purchase tmp = purchase_array[j];
				purchase_array[j] = purchase_array[j + 1];
				purchase_array[j + 1] = tmp;
			}
		}
	}

}
extern void sort_by_quantity(vector<purchase>& purchase_array) {
	for (int i = 0; i < purchase_array.size()-1; i++) {
		for (int j = 0; j < purchase_array.size() - 1; j++) {
			if (purchase_array[j].quantity > purchase_array[j + 1].quantity) {
				purchase tmp = purchase_array[j];
				purchase_array[j] = purchase_array[j + 1];
				purchase_array[j + 1] = tmp;
			}
		}
	}
}
extern void sort_by_price_per_unit(vector<purchase>& purchase_array) {
	for (int i = 0; i < purchase_array.size()-1; i++) {
		for (int j = 0; j < purchase_array.size() - 1; j++) {
			if (purchase_array[j].price_per_unit > purchase_array[j + 1].price_per_unit) {
				purchase tmp = purchase_array[j];
				purchase_array[j] = purchase_array[j + 1];
				purchase_array[j + 1] = tmp;
			}
		}
	}
}

extern void struct_sort() {
	register string some;

	cout << "1. Сортировка по номеру накладной.\n2. Сортировка по количеству товара. \n3. Сортировка по цене за единицу.\nВведите номер по чему хотите отсортировать массив: ";
	cin >> some;
	if (check(some)) {
		switch (stoi(some)) {
		case 1: {
			sort_by_invoice_number(purchase_array);
			break;
		}
		case 2: {
			sort_by_quantity(purchase_array);
			break;
		}
		case 3: {
			sort_by_price_per_unit(purchase_array);
			break;
		}
		default: {
			cout << "Введите номер от 1 до 3\n";
			struct_sort();
		}
		}
		for (int i = 0; i < purchase_array.size(); i++) {
			cout << "\n************************\n";
			cout << "Введите номер накладной: " << purchase_array[i].invoice_number << '\n';
			cout << "Введите колличество материала в м3: " << purchase_array[i].quantity << '\n';
			cout << "Введите цену материала за м3: " << purchase_array[i].price_per_unit << '\n';
			cout << "*************************\n";
		}
	}
	else {
		cout << "Введите число а не символы.\n";
		struct_sort();
	}
}

extern bool find_cons(vector<int> array, int to_find) {
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == to_find) {
			return true;
		}
	}
	return false;
}
extern bool bin_find(vector<int> array, int to_find) {
	
	register int left = 0;                 
	register int right = array.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (array[mid] == to_find) {
			return true; 
		}
		else if (array[mid] < to_find) {
			left = mid + 1; 
		}
		else {
			right = mid - 1; 
		}
	}

	return false; 
}

extern void clear() {
	file_sorts.open("Sorts.txt", ios::out);
	file_sorts.close();
	file_sorts.open("Sorts.txt", ios::app);
	file_sorts.close();
}

extern void put_data_into_file() {
	if (array_a.size() == 0) {
		cout << "Нету данных, чтобы ввести в файл.\n";
	}
	else {

		clear();
		file_sorts.open("Sorts.txt", ios::app);
		if (file_sorts.is_open()) {

			file_sorts << "\n************************\n";
			file_sorts << "Массив a: ";
			for (int i = 0; i < array_a.size(); i++) {
				file_sorts << array_a[i] << " ";
			}
			file_sorts << "\n************************\n\n";

			file_sorts << "\n************************\n";
			file_sorts << "Массив b: ";
			for (int i = 0; i < array_b.size(); i++) {
				file_sorts << array_b[i] << " ";
			}
			file_sorts << "\n************************\n\n";

			file_sorts << "\n************************\n";
			file_sorts << "Массив c: ";
			for (int i = 0; i < array_c.size(); i++) {
				file_sorts << array_c[i] << " ";
			}
			file_sorts << "\n************************\n\n";

			file_sorts << "\n************************\n";
			file_sorts << "Массив d: ";
			for (int i = 0; i < array_d.size(); i++) {
				file_sorts << array_d[i] << " ";
			}
			file_sorts << "\n************************\n\n";

			file_sorts << "\n************************\n";
			file_sorts << "Массив e: ";
			for (int i = 0; i < array_e.size(); i++) {
				file_sorts << array_e[i] << " ";
			}
			file_sorts << "\n************************\n\n";

			for (int i = 0; i < purchase_array.size(); i++) {
				file_sorts << "\n************************";
				file_sorts << "\nНомер накладной: " << purchase_array[i].invoice_number;
				file_sorts << "\nКоличество материала: " << purchase_array[i].quantity << "м3";
				file_sorts << "\nЦена за м3: " << purchase_array[i].price_per_unit << "BYN";
				file_sorts << "\n************************\n\n";
			}

			file_sorts.close();
			cout << "\nДанные записаны в файл.\n";
		
		}
		else {
			cout << "Файл не открыт.\n";
		}
	}
}
/*extern void get_data_from_file() {
	file_sorts.open("Sorts.txt", ios::in);
	if (file_sorts.is_open()) {
		if (!file_sorts.eof()) {
			register string some;
			register int flag = 0, number_size = 0, size = 1, j = 0, array[100];

			while (getline(file_sorts, some)) {

				if (flag == 2) {
					cout << "Массив a: ";
					array_a.resize(10);

					for (int i = 16; i < some.size(); i++) {
						if (48 <= some[i] && some[i] <= 57) {
							cout << some[i];
							number_size++;
						}
					}
					cout << "\n";
				}

				if (flag == 7) {
					j = 0;
					cout << "Массив b: ";
					for (int i = 16; i < some.size(); i++) {
						cout << some[i] << " ";
						array_b.resize(j + 1);
						array_b[j] = some[i]-48;
						j++;
						i++;
					}
					cout << "\n";
				}
				if (flag == 12) {
					j = 0;
					cout << "Массив c: ";
					for (int i = 16; i < some.size(); i++) {
						cout << some[i] << " ";
						array_c.resize(j + 1);
						array_c[j] = some[i]-48;
						j++;
						i++;
					}
					cout << "\n";
				}
				if (flag == 17) {
					j = 0;
					cout << "Массив d: ";
					for (int i = 16; i < some.size(); i++) {
						cout << some[i] << " ";
						array_d.resize(j + 1);
						array_d[j] = some[i]-48;
						j++;
						i++;
					}
					cout << "\n";
				}
				if (flag == 22) {
					j = 0;
					cout << "Массив e: ";
					for (int i = 16; i < some.size(); i++) {
						cout << some[i] << " ";
						array_e.resize(j + 1);
						array_e[j] = some[i]-48;
						j++;
						i++;
					}
					cout << "\n";
				}
				flag++;
			}

			file_sorts.close();
			cout << "Данные считаны из файла.\n\n";
		}
		else {
			cout << "Файл пустой.";
		}
	}
	else {
		cout << "Файл не открыт.\n";
	}
}
*/
extern void sort_task() {
	register string something;
	register int flag;
	cout << "1. Инициалиазия массивов и структур.\n";//+
	cout << "2. Сортировка пузырьком.\n";//+
	cout << "3. Сортировка обменом.\n";//+
	cout << "4. Сортировка вставкой.\n";//+
	cout << "5. Сортировка методом Шелла.\n";//+
	cout << "6. Сортировка методом Хоара.\n";
	cout << "7. Поиск.\n";//+
	cout << "8. Очистить файл.\n";//+
	cout << "9. Сортировка структуры.\n";//+
	cout << "10. Записать данные в файл.\n";//+
	cout << "11. Выйти из программы.\n";//+
	cout << "\nВведите номер операции: ";
	cin >> something;
	if (check(something)) {
		switch (stoi(something)) {
		case 1: {
			put_array_a(array_a);
			put_array_b(array_b);
			put_array_c(array_c);
			put_array_d(array_d);
			put_array_e(array_e);
			enter(purchase_array);
			sort_task();
			break;
		}
		case 2: {
			if (array_a.size() != 0) {
				bubble_sort(array_a);
			}
			else {
				cout << "Массив не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 3: {
			if (array_b.size() != 0) {
				selection_sort(array_b);
			}
			else {
				cout << "Массив не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 4: {
			if (array_c.size() != 0) {
				insertion_sort(array_c);
			}
			else {
				cout << "Массив не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 5: {
			if (array_d.size() != 0) {
				shell_sort(array_d);
			}
			else {
				cout << "Массив не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 6: {
			if (array_e.size() != 0) {
				auto start = chrono::high_resolution_clock::now();
				quick_sort(array_e, 0, array_e.size() - 1);
				auto end = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

				cout << "Затраченное время на сортировку Хоара: " << duration.count() << " (в миллисекундах)\n";
			}
			else {
				cout << "Массив не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 7: {
			if (array_a.size() != 0 || array_b.size() != 0 || array_c.size() != 0 || array_d.size() != 0 || array_e.size() != 0) {
				cout << "\nВыберите вид поиска.\n1. Последовательный поиск.\n2. Бинарный поиск\n\nВведите номер желаемого поиска: ";
				cin >> something;
				if (check(something)) {
					switch (stoi(something)) {
					case 1: {
						register string some;
						cout << "Введите элемент, который вы хоитете найти: ";
						cin >> some;
						if (check(some)) {
							register int to_find = stoi(some);
							auto start = chrono::high_resolution_clock::now();
							if (find_cons(array_a, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве a\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве a\n";
							}
							if (find_cons(array_b, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве b\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве b\n";
							}
							if (find_cons(array_c, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве c\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве c\n";
							}
							if (find_cons(array_d, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве d\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве d\n";
							}
							if (find_cons(array_e, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве e\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве e\n";
							}
							auto end = chrono::high_resolution_clock::now();
							auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

							cout << "Затраченное время на последовательный поиск: " << duration.count() << " (в миллисекундах)\n";
							break;
						}
						else {
							cout << "Введите число, а не символы.\n";
							break;
						}
					}
					case 2: {
						register string some;
						cout << "Для бинарного поиска массивы будут отсортированы.\nВведите элемент, который вы хоитете найти: ";
						cin >> some;
						if (check(some)) {
							register int to_find = stoi(some);
							bubble_sort(array_a);
							selection_sort(array_b);
							insertion_sort(array_c);
							shell_sort(array_d);
							auto start = chrono::high_resolution_clock::now();
							if (bin_find(array_a, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве a\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве a\n";
							}
							if (bin_find(array_b, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве b\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве b\n";
							}
							if (bin_find(array_c, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве c\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве c\n";
							}
							if (bin_find(array_d, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве d\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве d\n";
							}
							if (find_cons(array_e, to_find)) {
								cout << "Элемент " << to_find << " найден в массиве e\n";
							}
							else {
								cout << "Элемент " << to_find << " не найден в массиве e\n";
							}
							auto end = chrono::high_resolution_clock::now();
							auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);

							cout << "Затраченное время на бинарный поиск, не считая время на сортировку: " << duration.count() << " (в миллисекундах)\n";
							break;
						}
						else {
							cout << "Введите число, а не символы.\n";
							break;
						}
					}
					default: {
						cout << "\nВведите число от 1 до 2.\n";
					}
					}
				}
				else {
					cout << "Введите номер операции, а не символы.\n";
				}
			}
			else {
				cout << "Один из массивов не инициализирован.\n";
			}
			sort_task();
			break;
		}
		case 8: {
			clear();
			sort_task();
			break;
		}
		case 9: {
			struct_sort();
			sort_task();
			break;
		}
		case 10: {
			put_data_into_file();
			sort_task();
			break;
		}
		case 11: {
			break;
		}
		default: {
			cout << "Введите число от 1 до 11, а не символы.\n";
			sort_task();
			break;
		}
		}
	}
	else {
		cout << "Введите число, а не символы.\n";
		sort_task();
	}
}
