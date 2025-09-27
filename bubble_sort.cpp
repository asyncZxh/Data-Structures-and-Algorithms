#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void printArray(int[], int);
void bubbleSort(int[], int);
void switchValue(int &, int &);
int main()
{
    srand(time(0));
    int array[10];
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    generateElements(array, sizeOfArray);

    std::cout << "Before Sort: ";
    printArray(array, sizeOfArray);

    bubbleSort(array, sizeOfArray);

    std::cout << "After Sort: ";
    printArray(array, sizeOfArray);

    return 0;
}
void generateElements(int array[], size_t size)
{
    srand(time(0));
    for (int i{0}; i < size; ++i)
    {
        array[i] = (rand() % 10) + 1;
    }
}
void printArray(int array[], int size)
{
    for (int j = 0; j < size; j++)
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
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int k = 0; k < size - 1 - i; k++)
        {
            if (array[k] > array[k + 1])
            {
                switchValue(array[k], array[k + 1]);
            }
        }
    }
}
void switchValue(int &value1, int &value2)
{
    int holder = value1;
    value1 = value2;
    value2 = holder;
}