#include <iostream>

using namespace std;

void insertionSort(int* A, int n);
void printArray(int* A, int n);

int main()
{
    cout << "*****Insertion sort program*****" << endl;
    int sorted_array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sorted_array_length = sizeof(sorted_array)/sizeof(sorted_array[0]);
    int reverse_array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int reverse_array_length = sizeof(reverse_array)/sizeof(reverse_array[0]);
    int duplicate_array[] = { 7, 7, 3, 1, 8, 1, 9, 4, 1, 10, 7 };
    int duplicate_array_length = sizeof(duplicate_array)/sizeof(duplicate_array[0]);

    cout << "testing sorted array:" << endl;
    printArray(sorted_array, sorted_array_length);
    insertionSort(sorted_array, sorted_array_length);
    cout << "after sort: " << endl;
    printArray(sorted_array, sorted_array_length);

    cout << "testing reverse array:" <<endl;
    printArray(reverse_array, reverse_array_length);
    insertionSort(reverse_array, reverse_array_length);
    cout << "after sort: " << endl;
    printArray(reverse_array, reverse_array_length);

    cout << "testing duplicate array:" <<endl;
    printArray(duplicate_array, duplicate_array_length);
    insertionSort(duplicate_array, duplicate_array_length);
    cout << "after sort: " << endl;
    printArray(duplicate_array, duplicate_array_length);
}

void printArray( int* A, int n){
    cout << "[";
    cout << A[0];
    for(int i = 1; i < n; i++){
        cout << ", ";
        cout << A[i];
    }
    cout << "]" << endl;
}

void insertionSort(int* A, int n){
    for(int i = 1; i <= (n-1); i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j= j-1;
        }
        A[j+1] = v;
    }
}
