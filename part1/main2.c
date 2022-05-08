#include "fundamentals.h"
#include "file_manager.h"
#include "countingsort.h"


int main(){
table_data values[1406]; // array
open_file('ocean.csv', values, NULL);
int k= sizeof(values) / sizeof(values[0]);
countingsort(values,k);
printArray(values, k);









}

