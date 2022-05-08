/*
    The time.h header defines four variable types, two macro and various functions for manipulating date and time.
    ----VARIABLE TYPES----
    struct tm -> This is a structure used to hold the time and date.
    time_t    -> This is a type suitable for storing the calendar time. (seconds from 01/01/1970)
    clock_t   -> This is a type suitable for storing the processor time.
    ----FUNCTIONS----
    double difftime(time_t time1, time_t time2) ->  Returns the difference of seconds between time1 and time2 (time1-time2).
    time_t mktime(struct tm *timeptr)           ->  Converts the structure pointed to by timeptr into a time_t value
                                                    according to the local time zone.
    clock_t clock(void)                         ->  Returns the processor clock time used since the beginning of an
                                                    implementation defined era (normally the beginning of the program).
    ----LINKS----
    https://www.tutorialspoint.com/c_standard_library/time_h.htm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fundamentals.h"
#include "file_manager.h"

int open_file(char *filename, table_data *data_array, char *contents)
{
    FILE *fp = NULL;
    char *pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    char *date_str = (char *)malloc(sizeof(char) * (10 + 1));
    if (check_allocation((char *)pinakas) == FALSE)
        return FALSE;
    if (check_allocation((char *)date_str) == FALSE)
        return FALSE;
    int i = 0;

    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "File could not be opened!");
        return FALSE;
    }
    pinakas = fgets(pinakas, LINE_SIZE, fp); // Διαβάζουμε την πρώτη γραμμή του
                                             // αρχείου με τις επικεφαλίδες κάθε τιμής
    strcpy(contents, pinakas);

    while (fgets(pinakas, LINE_SIZE - 1, fp) != NULL) // Η while εκτελέιται εώς ότου
                                                      // φτάσουμε στο τέλος του αρχείου
    {
        strcpy(date_str, strtok(pinakas, ","));
        data_array[i].T_degC = atof(strtok(NULL, ","));
        data_array[i].PO4uM = atof(strtok(NULL, ","));
        data_array[i].SiO3uM = atof(strtok(NULL, ","));
        data_array[i].NO2uM = atof(strtok(NULL, ","));
        data_array[i].NO3uM = atof(strtok(NULL, ","));
        data_array[i].Salnty = atof(strtok(NULL, ","));
        data_array[i].O2ml_L = atof(strtok(NULL, ","));
        data_array[i].date.tm_mon = atoi(strtok(date_str, "/")) - 1; /* month, range 0 to 11             */
        data_array[i].date.tm_mday = atoi(strtok(NULL, "/"));        /* day of the month, range 1 to 31  */
        data_array[i].date.tm_year = atoi(strtok(NULL, "/")) - 1900; /* The number of years since 1900   */
        data_array[i].date.tm_sec = 0;                               /* seconds,  range 0 to 59          */
        data_array[i].date.tm_min = 0;                               /* minutes, range 0 to 59           */
        data_array[i].date.tm_hour = 0;                              /* hours, range 0 to 23             */
        data_array[i].date.tm_wday = 0;                              /* day of the week, range 0 to 6    */
        data_array[i].date.tm_yday = 0;                              /* day in the year, range 0 to 365  */
        data_array[i].date.tm_isdst = -1;                            /* daylight saving time             */
        i++;
    }

    fclose(fp);
    free(pinakas);
    free(date_str);

    return TRUE;
}
