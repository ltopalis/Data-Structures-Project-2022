#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tag_ocean
{
  char date[11];
  float T_degC;
  float PO4uM;
  float SiO3uM;
  float NO2uM;
  float NO3uM;
  float Salnty;
  float O2ml_L;
} ocean;

void printthisshit(ocean array[], int n);
void printValues(ocean values[]);
void Heapify(ocean array[], int node, int heap_size);
void swap(float *x, float *y);
void HeapSort(float array[], int heap_size);

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

    // char *field = strtok(buff, ","); // xwrizei
    char *field = (char *)malloc(sizeof(char) * 500);
    strcpy(field, strtok(buff, ","));
    if (row_count == 0)
      continue; // oxi
    while (field_count < 8)
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

  // printValues(values);
  int k = sizeof(values) / sizeof(values[0]);

  HeapSort(values, k);
  printthisshit(values, k);
  fclose(fp);

  return 0;
}

void printValues(ocean values[])
{
  int i = 1;
  printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for (i = 1; i < 1406; i++)
  {
    printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t ", values[i].date, values[i].T_degC, values[i].PO4uM, values[i].SiO3uM, values[i].NO2uM, values[i].NO3uM, values[i].Salnty, values[i].O2ml_L);
    printf("\n");
  }
}
void Heapify(ocean array[], int node, int heap_size)
{

  int bigger = node;       // root
  int left = 2 * node + 1; // node is an index in array[]
  int right = 2 * node + 2;
  // If left child is bigger than root
  if (left < heap_size && array[left] > array[bigger])
    bigger = left;

  // If right child is bigger than (int) bigger
  if (right < heap_size && array[right] > array[bigger])
    bigger = right;

  // If bigger is not root
  if (bigger != node)
  {
    swap(&array[node], &array[bigger]);

    //  heapify the sub-tree
    Heapify(array, bigger, heap_size);
  }
}

void swap(float *x, float *y)
{
  float temp = *x;
  *x = *y;
  *y = temp;
}
void HeapSort(float array[], int heap_size)
{
  // Build heap
  for (int i = heap_size / 2 - 1; i >= 0; i--)
    Heapify(array, i, heap_size);
  // One by one extract an element from heap
  for (int i = heap_size - 1; i > 0; i--)
  {
    // Move current root to end
    swap(&array[0], &array[i]);

    // call max heapify on the reduced heap
    Heapify(array, 0, i);
  }
}
void printthisshit(ocean array[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%f\t", array[i].PO4uM);
    printf("\n");
  }
}

//}
