#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <chrono>
#include <conio.h>

#include "QuickSorter.h"
#include "MergeSorter.h"

using namespace std;

void printArray(vector<long> arr);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    QuickSorter qs;
    MergeSorter ms;

    vector<long> arr1 = {};

    int numberOfIterations;
    cout << "Введіть кількість елементів в масиві: ";
    cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++)
    {
        arr1.push_back(rand() % 100 + 1);
    }
    cout << "Оберіть тип сортування" << endl << "1 - Швидке сортування" << endl << "2 - Сортування злиттям" << endl;
    int sortType;
    cin >> sortType;
    vector<long> newArray;

    cout << "Відсортувати відсортований масив?" << endl << "1 - так" << endl << "не 1 - ні" << endl;
    int isSorted;
    cin >> isSorted;
    if (isSorted == 1)
    {
        arr1 = qs.sort(arr1);
    }

    auto begin = chrono::steady_clock::now();
    if (sortType == 1)
    {
        newArray = qs.sort(arr1);
    }
    else if (sortType == 2)
    {
        newArray = ms.sort(arr1);
    }
    else
    {
        cout << "Error";
        return 0;
    }
    auto end = chrono::steady_clock::now();
    auto algTime = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << endl;
    printArray(newArray);

    cout << endl << "Час виконання: " << algTime.count() << " мс";


}


void printArray(vector<long> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}
