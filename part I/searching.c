#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fundamentals.h"
#include "searching.h"

int binarySearch(table_data *arr, int low, int high, time_t x)
{

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (difftime(mktime(&arr[mid].date), x) == 0)
        {
            return mid;
        }
        else if (difftime(mktime(&arr[mid].date), x) > 0)
        {
            high = mid - 1;
        }
        else if (difftime(mktime(&arr[mid].date), x) < 0)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int interpolation_Search(table_data *arr, int low, int high, time_t x)
{

    while ((difftime(mktime(&arr[high].date), mktime(&arr[low].date)) >= 0) && (difftime(x, mktime(&arr[low].date)) >= 0) && (difftime(x, mktime(&arr[high].date)) <= 0))
    {
        if (low == high)
        {
            if ((difftime(x, mktime(&arr[low].date)) == 0))
                return low;
            return -1;
        }

        int pos = low + ((double)(high - low) /
                         (difftime(mktime(&arr[high].date), mktime(&arr[low].date))) * (difftime(x, mktime(&arr[low].date))));

        if (difftime(mktime(&arr[pos].date), x) == 0) // (difftime(mktime(&arr[pos].date), x) == 0)
            return pos;

        if (difftime(mktime(&arr[pos].date), x) < 0)
            low = pos + 1;

        else
            high = pos - 1;
    }
    return -1;
}

int binary_interpolation_search(table_data *array, time_t date, int n)
{
    int left = 0,
        right = n - 1,
        size = right - left + 1,
        next = 0,
        pseudo_next = 0,
        i = 0;

    if (difftime(date, mktime(&array[right].date)) > 0) // if the date is anterior of the first date, return -1
        return -1;
    if (difftime(date, mktime(&array[left].date)) < 0) // if the date is later of the last date, return -1
        return -1;

    // Find the possible next position of the date we are searching
    next = (int)ceil(size * (difftime(date, mktime(&array[left].date)) /
                             difftime(mktime(&array[right].date), mktime(&array[left].date)))) +
           1;

    // The while loop runs until we find the position of the seaching date
    while (difftime(date, mktime(&array[next].date)) != 0.0)
    {

        i = 0;
        size = right - left + 1;

        // if the array contains less than 4 elements, linear search is executed.
        if (size < 4)
            return Linear_Search(array, date, left, right);

        if (difftime(date, mktime(&array[next].date)) >= 0.0) // the searching date is later than the array[next]
        {
            pseudo_next = (int)(next + i * sqrt((double)size) - 1);
            if (pseudo_next >= n)
                pseudo_next = n - 1;
            else if (pseudo_next < 0)
                pseudo_next = 0;
            while (difftime(date, mktime(&array[pseudo_next].date)) > 0.0)
            {
                // farwards jumps till we find the small posible space where the searching date exists.
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
        else if (difftime(date, mktime(&array[next].date)) < 0.0) // the searching date is anterior than the array[next]
        {
            pseudo_next = (int)(next - i * sqrt((double)size) + 1);
            if (pseudo_next >= n)
                pseudo_next = n - 1;
            else if (pseudo_next < 0)
                pseudo_next = 0;
            while (difftime(date, mktime(&array[pseudo_next].date)) < 0.0)
            {
                // backward jumps till we find the small posible space where the searching date exists.
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
        // ensure that the next variable has value between 0..(n-1)
        if (next < 0)
            next = 0;
        if (next >= n)
            next = n - 1;
    }

    if (difftime(date, mktime(&array[next].date)) == 0.0) // check if the date we found is which we're searching
        return next;
    else
    {
        return -1;
    }
}

int optimized_binary_interpolation_search(table_data *array, time_t date, int n)
{
    int left = 0,
        right = n - 1,
        size = right - left + 1,
        next = 0,
        prev = 0,
        i = 0;
    double diff_l, diff_r, diff_next;

    diff_r = difftime(date, mktime(&array[right].date));
    diff_l = difftime(date, mktime(&array[left].date));
    if (diff_r > 0) // if the date is anterior of the first date, return -1
        return -1;
    if (diff_l < 0) // if the date is later of the last date, return -1
        return -1;

    // Find the possible next position of the date we are searching
    next = (int)ceil(size * (diff_l /
                             difftime(mktime(&array[right].date), mktime(&array[left].date)))) +
           1;

    i = 0;
    size = right - left + 1;
    diff_next = difftime(date, mktime(&array[next].date));

    if (diff_next >= 0.0) // the searching date is later than the array[next]
    {
        while (diff_next > 0.0)
        {
            prev = next;
            next = (int)(next + pow(2.0, (double)i++) * sqrt((double)size) - 1);
            if (next >= n)
            {
                next = n - 1;
                prev = next - sqrt((double)size) + 1;
            }
            diff_next = difftime(date, mktime(&array[next].date));
        }
        return binary_search(array, date, prev, next);
    }
    else if (diff_next < 0.0) // the searching date is anterior than the array[next]
    {

        while (diff_next < 0.0)
        {
            prev = next;

            next = (int)(next - pow(2.0, (double)i++) * sqrt((double)size) + 1);
            if (next < 0)
            {
                next = 0;
                prev = sqrt((double)size) - 1;
            }
            diff_next = difftime(date, mktime(&array[next].date));
        }
        return binary_search(array, date, next, prev);
    }

    return -1;
}

int Linear_Search(table_data *array, time_t date, int start, int finish)
{
    int i;

    for (i = start; i <= finish; i++)
        if (difftime(date, mktime(&array[i].date)) == 0.0)
            return i;

    return -1;
}

int binary_search(table_data *array, time_t date, int start, int finish)
{
    int first = start,
        last = finish,
        middle;
    double difference = 0.0;

    while (last >= first)
    {
        middle = first + (last - first) / 2;
        difference = difftime(date, mktime(&array[middle].date));

        if (difference == 0.0)
            return middle;
        if (difference < 0.0)
            last = middle - 1;
        else // difference > 0.0
            first = middle + 1;
    }

    return -1;
}
