#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_SIZE_OF_ARRAY 5120

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

int outputArray()
{
	//вывод полученного из файла массива
	printf("Original array:\n\n  ");
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int sortArray(void)
{
	
}

int finish(void)
{

}