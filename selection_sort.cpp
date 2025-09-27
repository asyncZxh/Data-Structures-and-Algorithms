#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void printArray(int[], int);
void selectionSort(int[], int);
void switchValue(int &, int &);
int main()
{
    srand(time(0));
    int array[10];
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    generateElements(array, sizeOfArray);

    std::cout << "Before sort: ";
    printArray(array, sizeOfArray);

    selectionSort(array, sizeOfArray);

    std::cout << "After sort: ";
    printArray(array, sizeOfArray);

    return 0;
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
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int hold = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[hold])
            {
                hold = j;
            }
        }
        switchValue(array[hold], array[i]);
    }
}
void switchValue(int &value1, int &value2)
{
    int holder = value1;
    value1 = value2;
    value2 = holder;
}
void generateElements(int array[], size_t size)
{
    srand(time(0));
    for (int i{0}; i < size; ++i)
    {
        array[i] = (rand() % 10) + 1;
    }
}