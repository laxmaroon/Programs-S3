#include <iostream>
using namespace std;

template <typename T>
class SelectionSort {
private:
    T *arr;
    int size;

public:
    SelectionSort(T arr[], int size) {
        this->arr = arr;
        this->size = size;
    }

    void sort() {
        int minIndex;
        T temp;
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort<int> sorter(arr, n);
    sorter.sort();
    cout << "Sorted array: \n";
    sorter.print();
    return 0;
}
