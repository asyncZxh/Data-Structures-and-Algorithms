#include <iostream>
#include <ctime>

void generateElements(int[], size_t);
void printArray(int[], size_t);
void switchValue(int&, int&);
void mergeSort(int [], int, int);
void merge(int[], int, int, int);
int main(){
    int array[10]{0};
    size_t sizeOfArray {sizeof(array)/sizeof(array[0])};
    generateElements(array, sizeOfArray);

    std::cout << "Array before sort: ";
    printArray(array, sizeOfArray);

    mergeSort(array, 0, sizeOfArray - 1);

    std::cout << "Array after sort: ";
    printArray(array, sizeOfArray);

    return 0;
}
void generateElements(int array[], size_t size){
    srand(time(0));
    for(int i {0}; i < size; ++i){
        array[i] = (rand()%10) + 1;
    }
}
void printArray(int array[], size_t size){
    std::cout << "[ ";
    for(int i{0}; i < size; ++i){
        std::cout << array[i] << (i < size - 1? ", " : "");
    }
    std::cout << " ]" << std::endl;
}
void switchValue(int &value1, int &value2){
    int holder = value1;
    value1 = value2;
    value2 = holder;
}
void mergeSort(int array[], int left, int right){
    if(left < right){
        int mid {left + (right - left) / 2};
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
void merge(int array[], int left, int mid, int right){
    int sizeOfLeftArray {mid - left + 1};
    int sizeOfRightArray {right - mid};

    int* leftSubArray = new int[sizeOfLeftArray]{0};
    int* rightSubArray = new int[sizeOfRightArray]{0};

    for(int i {0}; i < sizeOfLeftArray; ++i){
        leftSubArray[i] = array[left + i];
    }
    
    for(int i {0}; i < sizeOfRightArray; ++i){
        rightSubArray[i] = array[mid + 1 + i];
    }

    int indexOfLeftSubArray {0}, indexOfRightSubArray {0}, indexOfOriginalArray {left};

    while((indexOfLeftSubArray < sizeOfLeftArray) && (indexOfRightSubArray < sizeOfRightArray)){
        if(leftSubArray[indexOfLeftSubArray] < rightSubArray[indexOfRightSubArray]){
            array[indexOfOriginalArray] = leftSubArray[indexOfLeftSubArray];
            indexOfLeftSubArray++;
        }
        else{
            array[indexOfOriginalArray] = rightSubArray[indexOfRightSubArray];
            indexOfRightSubArray++;
        }
        indexOfOriginalArray++;
    }

    while(indexOfLeftSubArray < sizeOfLeftArray){
        array[indexOfOriginalArray] = leftSubArray[indexOfLeftSubArray];
        indexOfLeftSubArray++;
        indexOfOriginalArray++;
    }

    while(indexOfRightSubArray < sizeOfRightArray){
        array[indexOfOriginalArray] = rightSubArray[indexOfRightSubArray];
        indexOfRightSubArray++;
        indexOfOriginalArray++;
    }
}