#include <stdio.h>

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

int hoare(int* data, unsigned length, unsigned elementNumberToFind) {
    unsigned divisionPoint;
    unsigned left = 0;
    unsigned right = length - 1;
    
    while (left != right)
    {
        //partition the data
        divisionPoint = partition(data, left, right);
        //adjust division point using current scope beginning (left..right)
        divisionPoint = divisionPoint - left;
        if (divisionPoint >= elementNumberToFind) {
            //element belongs to left side (left..divisionPoint-1)
            //slice out right side from further processing
            right = left + divisionPoint - 1;
        } else {
            //element belongs to right side (disivisonPoint..right)
            //move left pointer by divisionPoint
            //substract all left elements from element number (each of them is less than n-element)
            elementNumberToFind -= divisionPoint;
            left += divisionPoint;
        }
    }
    
    return data[left];
}

int main(int argc, const char * argv[]) {
    int data[] = {8, 3, 1, 2, 7, 5, 4, 9, 6};
    int result = hoare(data, 9, 3);
    printf("%d\n", result);
}
