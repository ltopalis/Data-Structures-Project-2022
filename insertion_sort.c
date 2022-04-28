#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

  for(i=1; i<=N; i++)
  {
    if(values[i].T_degC<=values[i+1].T_degC)
      continue;
    else if(values[i].T_degC>values[i+1].T_degC)
    {
      swap(&values[i], &values[i+1]);
      
      if(i==1)
        continue;
      else
      {
        for(k=i; k>0; k--)
        {
          if(values[k].T_degC>=values[k-1].T_degC)
            break;
          else if(values[k].T_degC<values[k-1].T_degC)
            swap(&values[k], &values[k-1]);
        }
      }  
    }
  }

  for(i=1; i<=N; i++)
  {
    printf("%d) %s\t%.3f", i, values[i].date, values[i].T_degC);
    printf("\n");
  }

  fclose(fp);

  return 0;
}

