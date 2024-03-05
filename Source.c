#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE_OF_ARRAY 128

int array[MAX_SIZE_OF_ARRAY];
int maxArrayElement = 0, minArrayElement = 0, arraySize = 0;
int* countingArrayPos;
int* countingArrayNeg;

int main()
{
	getArrayFromFile();
	sortArray();
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

	outputArray();
}

int outputArray(void)
{
	//вывод полученного из файла массива
	printf("Original array:\n\n  ");
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int findMinMaxOfArray(void)
{
	maxArrayElement = array[0];
	minArrayElement = array[0];

	for (int i = 0; i < arraySize; i++)
	{
		if (maxArrayElement < array[i])
		{
			maxArrayElement = array[i];
		}

		if (minArrayElement > array[i])
		{
			minArrayElement = array[i];
		}
	}
	 
	//для размера массивов, т.к. индексация с нуля
	minArrayElement--;
	maxArrayElement++;

	//printf("min: %d\nmax: %d\n", minArrayElement, maxArrayElement);
}

int sortArray(void)
{
	findMinMaxOfArray();

	// от наименьшего до нуля не включительно
	countingArrayNeg = (int*)malloc(abs(minArrayElement) * sizeof(int));
	
	for (int i = 0; i < abs(minArrayElement); i++)
	{
		countingArrayNeg[i] = 0;
	}

	for (int i = 1; i < abs(minArrayElement); i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (-i == array[j])
			{
				countingArrayNeg[i]++;
			}
		}
	}

	// от нуля до наибольшего
	countingArrayPos = (int*)malloc(maxArrayElement * sizeof(int));

	for (int i = 0; i < maxArrayElement; i++)
	{
		countingArrayPos[i] = 0;
	}

	for (int i = 0; i < maxArrayElement; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (i == array[j])
			{
				countingArrayPos[i]++;
			}
		}
	}

	//Вывод отсортированного массива
	printf("\nSorted array:\n\n  ");

	// от минимального до 0 не включительно
	for (int i = abs(minArrayElement); i > 0; i--) 
	{
		for (int j = 0; j < countingArrayNeg[i]; j++)
		{
			printf("%d  ", -i);
		}
	}
	
	// от нуля до максимального
	for (int i = 0; i < maxArrayElement; i++) //arr[0] = 2
	{
		for (int j = 0; j < countingArrayPos[i]; j++)
		{
			printf("%d  ", i);
		}
	}

	printf("\n");
}

int finish(void)
{
	//освобождение памяти
	free(countingArrayNeg);
	free(countingArrayPos);
}