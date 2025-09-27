#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void quickSort(int[], int, int);
int partition(int[], int, int);
void switchValue(int *, int *);
void printArray(int array[], int size);
int main()
{
	srand(time(0));
	int array[10];
	int sizeOfArray{sizeof(array) / sizeof(array[0])};
	generateElements(array, sizeOfArray);

	std::cout << "Before Sort: ";
	printArray(array, sizeOfArray);

	quickSort(array, 0, sizeOfArray - 1);

	std::cout << "After Sort: ";
	printArray(array, sizeOfArray);

	return 0;
}
void printArray(int array[], int size)
{
	for (int j{}; j < size; j++)
	{
		std::cout << (j == 0 ? "[ " : "");
		std::cout << array[j];
		if (j < size - 1)
		{
			std::cout << ", ";
		}
		std::cout << (j == size - 1 ? " ]" : "");
	}
	std::cout << std::endl;
}
void quickSort(int array[], int start, int end)
{
	if (end > start)
	{
		int pivot{partition(array, start, end)};
		quickSort(array, start, pivot - 1);
		quickSort(array, pivot + 1, end);
	}
}
int partition(int array[], int start, int end)
{
	int pivot{array[end]};
	int j{start - 1};

	for (int i{start}; i < end; ++i)
	{
		if (array[i] <= pivot)
		{
			++j;
			switchValue(&array[i], &array[j]);
		}
	}
	int holder{array[end]};
	array[end] = array[j + 1];
	array[j + 1] = holder;

	return j + 1;
}
void switchValue(int *value1, int *value2)
{
	int holder{*value1};
	*value1 = *value2;
	*value2 = holder;
}
void generateElements(int array[], size_t size)
{
	srand(time(0));
	for (int i{0}; i < size; ++i)
	{
		array[i] = (rand() % 10) + 1;
	}
}