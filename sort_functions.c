#include <time.h>
#include <stdlib.h>
#include "fundamentals.h"
#include "sort_functions.h"

void bubble_sort(table_data *pinakas, int n, FIELD t)
{
	int i, j;

	switch (t)
	{
	case TEMPERATURE:
		for (i = 0; i < n; i++)
			for (j = n - 1; j >= i + 1; j--)
				if (pinakas[j].temp < pinakas[j - 1].temp)
					swap(&pinakas[j], &pinakas[j - 1], TABLE_DATA);
		break;
	case PHOSPHATE:
		for (i = 0; i < n; i++)
			for (j = n - 1; j >= i + 1; j--)
				if (pinakas[j].PO4uM < pinakas[j - 1].PO4uM)
					swap(&pinakas[j], &pinakas[j - 1], TABLE_DATA);
		break;
	default:
		break;
	}
}