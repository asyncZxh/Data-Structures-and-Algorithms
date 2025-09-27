#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void printArray(int[], int);
void insertionSort(int[], int);
void shift(int &, int &);
int main()
{
    srand(time(0));
    int array[10];
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    generateElements(array, sizeOfArray);

    std::cout << "Before Sort: ";
    printArray(array, sizeOfArray);

    insertionSort(array, sizeOfArray);

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
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int holder = array[i];
        int key = i - 1;
        while (key >= 0 && array[key] > holder)
        {
            shift(array[key + 1], array[key]);
            key--;
        }
        array[key + 1] = holder;
    }
}
void shift(int &key1, int &key)
{
    key1 = key;
}