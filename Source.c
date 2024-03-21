#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE_OF_ARRAY 5120

int array[MAX_SIZE_OF_ARRAY];
int arraySize = 0;

void arraySplitter(int array[], int arrayLen);

int main()
{
	getArrayFromFile();

	/*while (isSorted(array, 0, arraySize) != 0)
	{
		mergeSort(array, arraySize);
	}*/

	mergeSort(array, arraySize);

	//outputArray();
	
	finish();
}

int getArrayFromFile(void)
{
	//считываем массив из файла
	FILE* file = fopen("input.txt", "r");

	if (file != NULL)
	{
		while ( fscanf(file, "%d", &array[arraySize]) == 1
				&& arraySize < MAX_SIZE_OF_ARRAY )
			{
				arraySize++;
			}
		fclose(file);
	}
	else
	{
		puts("Error opening file");
		exit(0);
	}

	outputArray("Original array:", 0, array, arraySize);
}

int outputArray(char text[], int i, int array[], int arraylen)
{
	//вывод полученного из файла массива
	printf("%s\n", text);
	for (i = 0; i < arraylen; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int mergeSort(int array[], int arrayLen)
{
	int leftHalf, rightHalf;

	if (arraySize % 2 == 0)
	{
		leftHalf = rightHalf = arraySize / 2;
	}
	else
	{
		leftHalf = arraySize / 2 + 1;
		rightHalf = arraySize / 2;
	}

	int* Larr = (int*)malloc(leftHalf * sizeof(int));
	int* Rarr = (int*)malloc(rightHalf * sizeof(int));

	for (int i = 0; i < leftHalf; i++)
	{
		Larr[i] = array[i];
	}
	outputArray("\nleft half:", 0, Larr, leftHalf);


	for (int i = 0; i < rightHalf; i++)
	{
		Rarr[i] = array[i + leftHalf];
	}
	outputArray("\nright half:", 0, Rarr, rightHalf);

	int k = 0; // og array
	int i = 0; // left array
	int j = 0; // right array
	
	while (i < leftHalf && j < rightHalf)
	{
		if (Larr[i] <= Rarr[i])
		{
			array[k] = Larr[i];
		}
		else
		{
			array[k] = Rarr[j];
		}

		if (array[k] == Larr[i])
		{
			k++; i++;
			if (Larr[i] <= Rarr[i])
			{
				array[k] = Larr[i];
			}
			else
			{
				array[k] = Rarr[j];
			}
		}
		else
		{
			k++; j++;
			if (Larr[i] <= Rarr[i])
			{
				array[k] = Larr[i];
			}
			else
			{
				array[k] = Rarr[j];
			}
		}
	}

	outputArray("\nSorted array:", 0, array, arraySize);

	free(Larr);
	free(Rarr);
}

int isSorted(int array[], int i, int arraylen)
{
	for (i = 1; i < arraySize; i++)
	{
		if (array[i - 1] < array[i])
		{

		}
		else
		{
			return 1; //not sorted
		}
	}
	return 0; //sorted
}

int mergeSortRecursion(int array[], int l, int r)
{

}

int finish(void)
{

}