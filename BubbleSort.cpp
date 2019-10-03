#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main() {
    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Enter a seed:";
    cin >> seed;
    cout << "Enter desired vector length: ";
    cin >> length;
    srand(seed);

    int array[length]; // array to be sorted
    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    /* your code here */

    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    for (int i = 0; i < length; i++) {
        array[i] = v.at(i);
        cout << array[i] << '\t';
    }

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }


    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(array, length);
    clock_t end_bubbleSort = clock();

    // check output, make sure vector is sorted after bubbleSort
    for(int i = 1; i < length; i++) {
        assert(array[i-1] <= array[i]);
    }


    // print sorted vector after mergeSort
    cout << endl << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    cout << "Sorted:" << endl;
    for (int i = 0; i < length; i++) {
        cout << array[i] << '\t';
    }
    cout << endl;

    // print elapsed time for mergeSort and bubbleSort
    cout << "Time cost using mergesort/bubblesort: ";
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }
    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    int j = 1;
    while ((j - 1) < n) {
        for (int i = 1; i < (n - j + 1); i++) {
            if (*(a + i) < *(a + (i - 1))) {
                swap(*(a + i), *(a + (i - 1)));
            }
        }
        j++;
    }
}