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
	printf("Original array:\n\n  ");
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n\n");
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
	
	minArrayElement--;
	maxArrayElement++;

	//printf("min: %d\nmax: %d\n", minArrayElement, maxArrayElement);
}

int sortArray(void)
{
	findMinMaxOfArray();

	// from min to zero without zero
	countingArrayNeg = (int*)malloc(abs(minArrayElement) * sizeof(int));
	
	for (int i = 0; i < abs(minArrayElement); i++)
	{
		countingArrayNeg[i] = 0;
	}
	for (int i = 1; i < abs(minArrayElement); i++)
	{
		for (int j = 1; j < arraySize; j++)
		{
			if (-i == array[j])
			{
				countingArrayNeg[i] += 1;
			}
		}
	}

	// from zero to max
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
				countingArrayPos[i] += 1;
			}
		}
	}

	//output of sorted array
	printf("\nSorted array:\n\n  ");

	// negatives
	for (int i = abs(minArrayElement); i > 0; i--)
	{
		for (int j = 0; j < countingArrayNeg[i]; j++)
		{
			printf("%d  ", -i);
		}
	}
	
	// positives
	for (int i = 0; i < maxArrayElement; i++)
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
	free(countingArrayNeg);
	free(countingArrayPos);
}