/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include<stdio.h>
#include<malloc.h>
void rightShiftAndInsert(int *, int , int , int );
int findPositionToInsert(int *, int , int );


int * sortedArrayInsertNumber(int *Arr, int len, int num)
{

	int i, position;
	if ((Arr == NULL) || (len <= 0))
		return NULL;

	position = findPositionToInsert(Arr, len, num);
	len = len + 1; // length must be increased
	int *temp = Arr;
	Arr = (int *)realloc(Arr, len*sizeof(int));
	rightShiftAndInsert(Arr, position, len, num);
	return Arr;
}


void rightShiftAndInsert(int *Arr, int position, int len, int num) // this must perform right shift
{
	int i, j;
	if (position == len - 1)// last position
		Arr[position] = num;
	else
	{
		for (i = len - 1; i>position; i--)
		{
			Arr[i] = Arr[i - 1];
		}
		Arr[position] = num;
	}

}
int findPositionToInsert(int *Arr, int len, int num)
{
	int i, position;
	if (num <= Arr[0]) // first position
		position = 0;
	else if (num >= Arr[len - 1]) //last position
		position = len;
	else{
		for (i = 0; i<len - 1; i++)
		{
			if ((Arr[i] <= num) && (Arr[i + 1] >= num)) // middle 
			{
				printf("\n%d and %d ", Arr[i], Arr[i + 1]);
				position = i + 1;
				break;
			}
		}
	}
	return position;
}
