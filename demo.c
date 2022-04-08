#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"


int main()
{
    table_data *ocean_data = (table_data *)malloc(sizeof(table_data) * 1405);
    char *pinakas = (char *)malloc(sizeof(char) * 100);
    open_file("ocean.csv", ocean_data, pinakas);
    int i;
    
    for(i=0; i<1405; i++){
        printf("\n%s", ctime(&ocean_data[i].date));
        printf("\t%.3lf", ocean_data[i].temp);
        printf("\t%.3lf", ocean_data[i].PO4uM);
        printf("\t%.3lf", ocean_data[i].SiO3uM);
        printf("\t%.3lf", ocean_data[i].NO2uM);
        printf("\t%.3lf", ocean_data[i].NO3uM);
        printf("\t%.3lf", ocean_data[i].Salnty);
        printf("\t%.3lf", ocean_data[i].O2ml_L);
    }
    printf("\n");
    
    free(pinakas);
    free(ocean_data);
}
