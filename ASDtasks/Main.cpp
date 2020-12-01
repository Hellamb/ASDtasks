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

using namespace std;

void printArray(vector<long> arr);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    QuickSorter qs;
    MergeSorter ms;
    ShellSorter shs;
    HeapSorter hs;

    vector<long> arr1 = {};

    int numberOfIterations;
    cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½: ";
    cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++)
    {
        arr1.push_back(rand() % 100 + 1);
    }
    cout << "Îáåð³òü òèï ñîðòóâàííÿ" << endl << "1 - Shell sort" << endl << "2 - Heap sort" << endl;
    int sortType;
    cin >> sortType;
    vector<long> newArray;

    cout << "Â³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½?" << endl << "1 - ï¿½ï¿½ï¿½" << endl << "ï¿½ï¿½ 1 - ï¿½ï¿½" << endl;
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
        newArray = hs.sort(arr1);
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

    cout << endl << "ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½: " << algTime.count() << " ï¿½ï¿½";

}


void printArray(vector<long> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}
