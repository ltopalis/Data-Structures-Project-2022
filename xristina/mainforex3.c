#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "exe3.h"

int main()
{
  table_data values[DATA];
  char contents[LINE_SIZE];
  int year, mon, day;
  struct tm timeinfo;
  printf("Give year, month and day.\n");
  scanf("%d\t%d\t%d", &timeinfo.tm_year, &timeinfo.tm_mon, &timeinfo.tm_mday);
  open_file("ocean.csv", values, contents);

  timeinfo.tm_year = year - 1900;
  timeinfo.tm_mon = mon - 1;
  timeinfo.tm_mday = day;
  timeinfo.tm_hour = 0;
  timeinfo.tm_min = 0;
  timeinfo.tm_sec = 0;

  printf("Give year, month and day.\n");
  scanf("%d\t%d\t%d", &timeinfo.tm_year, timeinfo.tm_mon, &timeinfo.tm_mday);

  int n = binarySearch(values, 0, DATA, mktime(&timeinfo));

  if (n != -1)
  {
    int choice;
    printf("\n1.Temperature\n2.Phosphate\n3.Both\n(1, 2 or 3)\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("%.2f", values[n].T_degC);
    }
    if (choice == 2)
    {
      printf("\nPhosphate = %.2f", values[n].PO4uM);
    }
    if (choice == 3)
    {
      printf("\nTemperature = %.2f\tPhosphate = %.2f", values[n].T_degC, values[n].PO4uM);
    }
  }
  else
  {
    printf("date not found.\n");
  }
  return 0;
}