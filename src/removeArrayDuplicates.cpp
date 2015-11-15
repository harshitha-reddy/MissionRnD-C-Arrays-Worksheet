/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if ((Arr == NULL) || (len <= 0))
		return NULL;
	int lv1 = 0, lv2 = 0, lv3 = 0;
	for (lv1 = 0; lv1<len - 1; lv1++)
	{
		for (lv2 = lv1 + 1; lv2<len; lv2++)
		{
			if (Arr[lv1] == Arr[lv2])
			{
				for (lv3 = lv2; lv3<len - 1; lv3++)
					Arr[lv3] = Arr[lv3 + 1];
				len--;
				lv2--;
			}
		}
	}
}