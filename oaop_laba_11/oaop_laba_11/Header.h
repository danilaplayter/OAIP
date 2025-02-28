#ifndef Source_H
#define Source_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct purchase{
};

extern void sort_task();

extern bool check(string some);

extern bool put_array_a(vector<int>& array);
extern void put_array_b(vector<int>& array);
extern void put_array_c(vector<int>& array);
extern void put_array_d(vector<int>& array);
extern void put_array_e(vector<int>& array);

extern void enter(vector<purchase>& purchase_array);

extern void bubble_sort(vector<int>& array);
extern void selection_sort(vector<int>& array_b);
extern void insertion_sort(vector<int>& array_c);
extern void shell_sort(vector<int>& array_d);
extern void quick_sort(vector<int>& array_e, int low, int high);
extern void struct_sort();

extern void sort_by_invoice_number(vector<purchase>& purchase_array);
extern void sort_by_quantity(vector<purchase>& purchase_array);
extern void sort_by_price_per_unit(vector<purchase>& purchase_array);

extern bool find_cons(vector<int> array, int to_find);
extern bool bin_find(vector<int> array, int to_find);

extern void put_data_into_file();


extern void clear();

#endif