#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void printArray(int[], size_t);
void switchValue(int &, int &);
void shellSort(int[], int);
void shift(int *, int);
int main()
{
    int array[10];
    size_t sizeOfArray{sizeof(array) / sizeof(array[0])};
    generateElements(array, sizeOfArray);

    std::cout << "Before sort: ";
    printArray(array, sizeOfArray);

    shellSort(array, sizeOfArray);

    std::cout << "After sort: ";
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
void printArray(int array[], size_t size)
{
    std::cout << "[ ";
    for (int i{0}; i < size; ++i)
    {
        std::cout << array[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << " ]" << std::endl;
}
void shift(int *pointer1, int pointer2)
{
    *pointer1 = pointer2;
}
void shellSort(int array[], int size)
{
    int gap{size / 2};

    for (int i{gap}; i > 0; i /= 2)
    {
        for (int j{i}; j < size; ++j)
        {
            int holder{array[j]};
            int k;
            for (k = j; (k >= i) && (array[k - i] > holder); k -= i)
            {
                shift(&array[k], array[k - i]);
            }
            array[k] = holder;
        }
    }
}