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

void quicksort(int* data, unsigned left, unsigned right) {
    if (left >= right) return;
    int k = partition(data, left, right);
    quicksort(data, left, k);
    quicksort(data, k + 1, right);
}

int main(int argc, const char * argv[]) {
    int data[] = {8, 3, 1, 2, 7, 5, 4, 9, 6};
    quicksort(data, 0, 8);
}
