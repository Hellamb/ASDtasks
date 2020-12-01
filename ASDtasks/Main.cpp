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

using namespace std;

void printArray(vector<long> arr);

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

    vector<long> arr1 = {};

    int numberOfIterations;
    cout << "Give a number of elements: ";
    cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++)
    {
        arr1.push_back(rand() % 100 + 1);
    }

    cout << "Choose your sort: " << endl << "1 - Shell sort" << endl << "2 - Heap sort" << endl << "3 - Counting sort" << endl;
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
    //printArray(newArray);
    auto begin = chrono::steady_clock::now();
    if (sortType == 1)
    {
        newArray = shs.sort(arr1);
    }
    else if (sortType == 2)
    {
        newArray = hs.sort(arr1);
    }
    else if (sortType == 3)
    {
        newArray = cs.sort(arr1);
    }
    else
    {
        cout << "Error";
        return 0;
    }
    auto end = chrono::steady_clock::now();
    auto algTime = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << endl;
    //printArray(newArray);

    cout << endl << "To sort this array " << algTime.count() << " ms were spent";

}


void printArray(vector<long> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}
