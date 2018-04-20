void swapElements(int* data, unsigned a, unsigned b) {
    unsigned tmp = data[b];
    data[b] = data[a];
    data[a] = tmp;
}

unsigned partition(int* data, unsigned left, unsigned right)
{
    //use first scope element as split value
    int splitValue = data[left];
    //loop until left and right meet up together
    while (left < right) {
        //find any element greater or equal than split point from right
        while (left < right && data[right] >= splitValue) right--;
        //find any element lower than split point from left
        while (left < right && data[left] < splitValue) left++;
        swapElements(data, left, right);
    }    
    //return scope beginning index
    return left + 1;
}

#include <stdio.h>

void swapElements(int* data, unsigned a, unsigned b) {
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

int partition(int* data, unsigned left, unsigned right) {
    unsigned pivot = data[left];
    while(left < right) {
        while (data[left] < pivot) left++;
        while (data[right] > pivot) right--;
        swapElements(data, left, right);
    }
    return left;
}

void quicksort(int* data, int left, int right) {
    if (left >= right) return;
    int k = partition(data, left, right);
    quicksort(data, left, k);
    quicksort(data, k + 1, right);
}

void printArray(int* data, unsigned length) {
    for (int x = 0; x < length; x++) {
        printf("%d ", data[x]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int data[] = {8, 3, 1, 2, 7, 5, 4, 9, 6};
    quicksort(data, 0, 8);
    printArray(data, 9);    
}
