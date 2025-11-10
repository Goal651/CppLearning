#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            int check = 0;
            if(arr[j] > arr[j + 1]) {
                check = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if(check == 0) {
                break;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int targetIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[targetIndex]) {
                targetIndex = j;
            }
        }
        swap(arr[i], arr[targetIndex]);
    }
}

void mergeArrays(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int leftArrSize = midIndex - leftIndex + 1;
    int rightArrSize = rightIndex - midIndex;
    int leftArr[leftArrSize], rightArr[rightArrSize];
    for(int i = 0; i < leftArrSize; i++) {
        leftArr[i] = arr[leftIndex + i];
    }
    for(int i = 0; i < rightArrSize; i++) {
        rightArr[i] = arr[midIndex + 1 + i];
    }

    int i = 0, j = 0, k = leftIndex;
    while(i < leftArrSize && j < rightArrSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }


    while(j < rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if(leftIndex >= rightIndex) {
        return;
    }
    int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);
    mergeSort(arr, leftIndex, midIndex);
    mergeSort(arr, midIndex + 1, rightIndex);
    mergeArrays(arr, leftIndex, midIndex, rightIndex);
}

int main() {
    int arr[] = {4, 3, 2, 1};
    mergeSort(arr, 0, 4);
    for(int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
