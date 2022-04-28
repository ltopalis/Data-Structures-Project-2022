#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 1405
#define M 11

typedef struct tag_ocean
{
  char date[M];
  float T_degC;
  float PO4uM;
  float SiO3uM;
  float NO2uM;
  float NO3uM;
  float Salnty;
  float O2ml_L;
} ocean;

void swap(ocean *str_1, ocean *str_2)
{
  ocean temp = *str_1;
  *str_1 = *str_2;
  *str_2 = temp;
}

void quicksort(ocean values[], int min, int max)
{
  int i=(min-1);
  int j;

  for(j=min+1; j<=max; j++)
  {
    if(values[j].T_degC>=values[max].T_degC)
      continue;
    else if(values[j].T_degC<values[max].T_degC)
    {
      i++;
      swap(&values[i], &values[j]);
    }

  }
  swap(&values[i+1], &values[j]);

  quicksort(values, min, i);
  quicksort(values, i+1, max);
}

void printValues(ocean values[]);

int main()
{
  FILE *fp = fopen("ocean.csv", "r"); //  read mode
  if (!fp)
  {
    return 0;
  }
  char buff[N]; // stores first 1024 lines
  int row_count = 0;
  int field_count = 0;

  ocean values[N]; // array

  int i = 0;
  int k = 0;
  int half = (int)(N/2);

 rewind(fp);
  i = 0;
  while (fgets(buff, N, fp))
  {
    field_count = 0;
    row_count++;

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
      field = strtok(NULL, ",");
      field_count++;
    }

    i++;
    free(field);
  }

  printValues(values);

  quicksort(values, 1, N);

  for(i=1; i<=N; i++)
  {
    printf("\n%s\t%.3f", values[i].date, values[i].T_degC);
    printf("\n");
  }

  fclose(fp);

  return 0;
}

// print
void printValues(ocean values[])
{
  int i = 1;
  printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for (i = 1; i <= N; i++)
  {
    printf("%s\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f", values[i].date, values[i].T_degC, values[i].PO4uM, values[i].SiO3uM, values[i].NO2uM, values[i].NO3uM, values[i].Salnty, values[i].O2ml_L);
    printf("\n");
  }
}
