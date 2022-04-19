#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fundamentals.h"
#include "searching.h"

int interpolation_search(table_data *array, time_t date, int n)
{
    int left = 0,
        right = n - 1,
        size = right - left + 1,
        next = 0,
        pseudo_next = 0,
        i = 0;

    if (difftime(date, mktime(&array[right].date)) > 0)
        return -1;
    if (difftime(date, mktime(&array[left].date)) < 0)
        return -1;

    next = (int)ceil(size * (difftime(date, mktime(&array[left].date)) /
                             difftime(mktime(&array[right].date), mktime(&array[left].date)))) +
           1;

    while (difftime(date, mktime(&array[next].date)) != 0.0)
    {
        i = 0;
        size = right - left + 1;

        if (size <= 3)
            return Linear_Search(array, date, left, right);

        if (difftime(date, mktime(&array[next].date)) >= 0.0)
        {
            pseudo_next = (int)(next + i * sqrt((double)size) - 1);
            while (difftime(date, mktime(&array[pseudo_next].date)) > 0.0)
            {
                i++;
                pseudo_next = (int)(next + i * sqrt((double)size) - 1);
                if (pseudo_next >= n)
                    pseudo_next = n - 1;
            }
            right = (int)(next + i * sqrt(size));
            left = (int)(next + (i - 1) * sqrt(size));
            if (right >= n)
            {
                right = n - 1;
                left = right - (int)sqrt((double)size);
            }
        }
        else if (difftime(date, mktime(&array[next].date)) < 0.0)
        {

            pseudo_next = (int)(next - i * sqrt((double)size) + 1);

            while (difftime(date, mktime(&array[pseudo_next].date)) < 0.0)
            {
                i++;
                pseudo_next = (int)(next - i * sqrt((double)size) + 1);
                if (pseudo_next < 0)
                    pseudo_next = 0;
            }
            right = (int)(next - (i - 1) * sqrt(size));
            left = (int)(next - i * sqrt(size));
            if (left < 0)
                left = 0;
        }

        next = left + (int)ceil((right - left + 1) * difftime(date, mktime(&array[left].date)) / difftime(mktime(&array[right].date), mktime(&array[left].date))) - 1;
        if (next < 0)
            next = 0;
        if (next >= n)
            next = n - 1;
    }

    if (difftime(date, mktime(&array[next].date)) == 0.0)
        return next;
    else
    {
        return -1;
    }
}

int Linear_Search(table_data *array, time_t date, int start, int finish)
{
    int i;

    for (i = start; i <= finish; i++)
        if (difftime(date, mktime(&array[i].date)) == 0.0)
            return i;

    return -1;
}