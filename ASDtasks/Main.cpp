#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <chrono>
#include <conio.h>

#include "QuickSorter.h"
#include "MergeSorter.h"
#include "ShellSorter.h"
#include "HeapSorter.h"
#include "CountingSorter.h"
#include "RadixSorter.h"
#include "BucketSorter.h"

using namespace std;

void printArray(vector<long> arr);
void printArray(long array[], long arraySize);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    QuickSorter qs;
    MergeSorter ms;
    ShellSorter shs;
    HeapSorter hs;
    CountingSorter cs;
    RadixSorter rs;
    BucketSorter bs;



    int numberOfIterations;
    cout << "Give a number of elements: ";
    cin >> numberOfIterations;

    vector<long> arr1 = {};
    long* arr2 = new long[numberOfIterations];
    for (int i = 0; i < numberOfIterations; i++)
    {
        arr1.push_back(rand() % 100 + 1);
    }
    for (int i = 0; i < numberOfIterations; i++)
    {
        arr2[i] = rand() % 100 + 1;
    }


    cout << "Choose your sort: " << endl << "1 - Shell sort" << endl << "2 - Heap sort" << endl << "3 - Counting sort" << endl << "4 - Radix sort" << endl << "5 - Bucket sort" << endl;
    int sortType;
    cin >> sortType;
    vector<long> newArray;

    cout << "Sorted or unsorted array?" << endl << "1 - sorted" << endl << "not 1 - unsorted" << endl;
    int isSorted;
    cin >> isSorted;
    if (isSorted == 1)
    {
        arr1 = qs.sort(arr1);
    }
 
    auto begin = chrono::steady_clock::now();
    if (sortType == 1)
    {
        newArray = shs.sort(arr1);
    }
    else if (sortType == 2)
    {
        arr2 = hs.sort(arr2, numberOfIterations);
    }
    else if (sortType == 3)
    {
        newArray = cs.sort(arr1);
    }
    else if (sortType == 4)
    {
        newArray = rs.sort(arr1);
    }
    else if (sortType == 5)
    {
        newArray = bs.sort(arr1);
    }
    else
    {
        cout << "Error";
        return 0;
    }
    auto end = chrono::steady_clock::now();
    auto algTime = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << endl;
    //printArray(newArray);
    printArray(arr2, numberOfIterations);

    cout << endl << "To sort this array " << algTime.count() << " mcs were spent";

}


void printArray(vector<long> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}

void printArray(long array[],long arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}
