#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fundamentals.h"
#include "file_manager.h"

int open_file(char *filename, table_data *data_array, char *contents)
{
    FILE *fp;
    char *pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    char *date_str = (char *)malloc(sizeof(char) * (10 + 1));
    struct tm *mytime = (struct tm *)malloc(sizeof(struct tm));
    if (check_allocation((char *)pinakas) == FALSE)
        return FALSE;
    if (check_allocation((char *)date_str) == FALSE)
        return FALSE;
    if (check_allocation((struct tm *)mytime) == FALSE)
        return FALSE;
    int i = 0;

    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "File could not be open!");
        return FALSE;
    }
    pinakas = fgets(pinakas, LINE_SIZE, fp);
    strcpy(contents, pinakas);

    while (fgets(pinakas, LINE_SIZE, fp) != NULL)
    {
        strcpy(date_str, strtok(pinakas, ","));
        data_array[i].temp = atof(strtok(NULL, ","));
        data_array[i].PO4uM = atof(strtok(NULL, ","));
        data_array[i].SiO3uM = atof(strtok(NULL, ","));
        data_array[i].NO2uM = atof(strtok(NULL, ","));
        data_array[i].NO3uM = atof(strtok(NULL, ","));
        data_array[i].Salnty = atof(strtok(NULL, ","));
        data_array[i].O2ml_L = atof(strtok(NULL, ","));
        mytime->tm_hour = 0;
        mytime->tm_isdst = 0;
        mytime->tm_mday = 0;
        mytime->tm_min = 0;
        mytime->tm_sec = 0;
        mytime->tm_wday = 0;
        mytime->tm_wday = 0;
        mytime->tm_yday = 0;
        mytime->tm_zone = NULL;
        mytime->tm_mon = atoi(strtok(date_str, "/")) - 1;
        mytime->tm_mday = atoi(strtok(NULL, "/"));
        mytime->tm_year = atoi(strtok(NULL, "/")) - 1900;
        data_array[i].date = mktime(mytime);
        i++;
    }

    fclose(fp);
    free(pinakas);
    free(date_str);
    free(mytime);

    return TRUE;
}