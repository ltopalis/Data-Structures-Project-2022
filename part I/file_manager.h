#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define LINE_SIZE 100
#define DATA 1405
#define TABLE_SIZE 1405

/* open_file(): diavazoume ta periexomena tou arxeiou filename kai ta
   apothikeoume ston pinaka data_array. Thn epikefalida tou arxeiou mporoume
   na thn apotikeusoume ston pinaka contents, se antitheti periptwsi to thetoume
   NULL 
*/
int open_file(char *filename, table_data *data_array, char *contents);

#endif