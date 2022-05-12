#ifndef SEARCHING_H

#define SEARCHING_H

int binarySearch(table_data *arr, int low, int high, time_t x);

int interpolationSearch(table_data *arr, int low, int high, time_t x);

/*
    interpolation search (O(sqrt(n))) given the array, the searching date and
    the number of elements, the array contains
*/
int binary_interpolation_search(table_data *array, time_t date, int n);

/*
    interpolation search optimized in worst case given the array, the searching
    date and the number of elements, the array contains
*/
int optimized_binary_interpolation_search(table_data *array, time_t date, int n);

/*
    linear search (O(n)) given the array, the searching date, the position where we start
    to search and the final position (included it)
*/
int Linear_Search(table_data *array, time_t date, int start, int finish);
/*
    binary search (O(log n)) given the array, the searching date, the position where we start
    to search and the final position (included it)
*/
int binary_search(table_data *array, time_t date, int start, int finish);

#endif