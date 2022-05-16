#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fundamentals.h"
#include "file_manager.h"
#include "searching.h"
#include "sort_functions.h"

int main()
{
  table_data values[DATA];
  char contents[LINE_SIZE];
  int year, mon, day;
  struct tm timeinfo;
  do
  {
    printf("Give year, month and day.\n");
    scanf("%d\t%d\t%d", &year, &mon, &day);
  } while (year < 0 || mon < 0 || day <= 0);

  open_file("ocean.csv", values, contents);

  bubble_sort(values, DATA, TIME);

  timeinfo.tm_year = year - 1900;
  timeinfo.tm_mon = mon - 1;
  timeinfo.tm_mday = day;
  timeinfo.tm_hour = 0;
  timeinfo.tm_min = 0;
  timeinfo.tm_sec = 0;

  double time1 = 0.0;
  clock_t start1 = clock();
  int n = binarySearch(values, 0, DATA - 1, mktime(&timeinfo));
  clock_t end1 = clock();
  time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

  double time2 = 0.0;
  clock_t start2 = clock();
  int m = interpolation_Search(values, 0, DATA - 1, mktime(&timeinfo));
  clock_t end2 = clock();
  time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

  if (n != m)
  {
    fprintf(stderr, "An unexpected error occured! Try again, please!\n");
    printf("\nBinarySearch: %.10f", time1);
    printf("\nInterpolationSearch: %.10f\n", time2);
    exit(0);
  }

  // printf("%d\n", n);
  if (n != -1)
  {
    int choice;
    printf("\n1.Temperature\n2.Phosphate\n3.Both\n(1, 2 or 3)\n");
    scanf("%d", &choice);
    printf("date: %d %d %d\n", values[n].date.tm_year + 1900, values[n].date.tm_mon + 1, values[n].date.tm_mday);
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
  printf("\nBinarySearch: %.10f", time1);
  printf("\nInterpolationSearch: %.10f\n", time2);
  return 0;
}
