#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1405
typedef struct tag_ocean
{
  char date[11];
  double T_degC;
  double PO4uM;
  double SiO3uM;
  double NO2uM;
  double NO3uM;
  double Salnty;
  double O2ml_L;
} ocean;
void printArray(ocean array[], int size);
void printValues(ocean values[]);
void countingsort(ocean array[], int size);
int main()
{
  FILE *fp = fopen("ocean.csv", "r"); //  read mode
  if (!fp)
  {
    printf("problem");
    return 0;
  }
  char buff[1024]; // stores first 1024 lines
  int row_count = 0;
  int field_count = 0;

  ocean values[1406]; // array

  int i = 0;
  /*
  while (fgets(buff, 1024, fp)) //
  {
    printf("%s\n", buff);
  }
*/

 rewind(fp);
  i = 0;
  while (fgets(buff, 1406, fp))
  {
    field_count = 0;
    row_count++;

    //char *field = strtok(buff, ","); // xwrizei
    char *field = (char *)malloc(sizeof(char)*500);
    strcpy(field, strtok(buff, ","));
    if (row_count == 0)
      continue; // oxi
    while (field_count<8)
    {
      if (field_count == 0)
        strcpy(values[i].date, field);
      else if (field_count == 1)
        values[i].T_degC = atof(field);
      else if (field_count == 2)
        values[i].PO4uM = atof(field);
      else if (field_count == 3)
        values[i].SiO3uM = atof(field);
      else if (field_count == 4)
        values[i].NO2uM = atof(field);
      else if (field_count == 5)
        values[i].NO3uM = atof(field);
      else if (field_count == 6)
        values[i].Salnty = atof(field);
      else if (field_count == 7)
        values[i].O2ml_L = atof(field);
      field = strtok(NULL, ","); // updates values
      field_count++;

    }

    i++;
    free(field);
  }

  //printValues(values);
  int n = sizeof(values) / sizeof(values[0]);
  countingsort(values, n);
  printarray(values, n);
  fclose(fp);



  return 0;
}

void countingsort(ocean array[], int size){
ocean final[N];
//Find the largest
int max=array[0].PO4uM;
for(int i=0;i<size; i++){
    if(array[i].PO4uM>max) max = array[i].PO4uM;
}
ocean new_array[N];
// Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    new_array[i].PO4uM = 0;
  }
// Store the count of each element
  for (int i = 0; i < size; i++) {
    new_array[(int)array[i].PO4uM].PO4uM++;
  }
// Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    new_array[i].PO4uM += new_array[i - 1].PO4uM;
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    final[(int)new_array[(int)array[i].PO4uM].PO4uM - 1].PO4uM = array[i].PO4uM;
    new_array[(int)array[i].PO4uM].PO4uM--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i].PO4uM = final[i].PO4uM;
  }
}
void printarray(ocean array[],int n){
for (int i = 1; i <= N; i++)
  {
    printf("\n%s\t%.3f", array[i].date, array[i].PO4uM);
    printf("\n");
  }



}


void printValues(ocean values[])
{
  int i = 1;
  printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for (i = 1; i < 1406; i++)
  {
    printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t ", values[i].date, values[i].T_degC,  values[i].PO4uM, values[i].SiO3uM, values[i].NO2uM, values[i].NO3uM, values[i].Salnty, values[i].O2ml_L);
  printf("\n");}

}
