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

#include "Corruption.h"
#include "StringTask2.h"
<<<<<<< HEAD
#include "Levenshtein.h"
=======
>>>>>>> parent of ffcf74a... Merge branch 'main' of https://github.com/Hellamb/ASDtasks into main

using namespace std;

void printArray(vector<double> arr);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    QuickSorter qs;
    MergeSorter ms;
    CountingSorter cs;

    Corruption cor;
<<<<<<< HEAD
    Levenshtein lev;
    StringTask2 st;

    /*
    cout << "Maximum SubString is " << st.task1("Hello", "here is Hello") << endl;
    cout << "Minimum SubString is " << st.task2("Hello", "here is Hello") << endl;
    cout << "levenshtein distance is " << lev.lev_dist("Hello", "Here") << endl;
    */
=======
    StringTask2 ta2;

    string s1 = "helloHello";
    string s2 = "hello1Hello1hello1";
    cout << ta2.task1(s1, s2) << endl;


>>>>>>> parent of ffcf74a... Merge branch 'main' of https://github.com/Hellamb/ASDtasks into main

    
    int numberOfIterations;

    double commision;
    cout << "Give a number of bank accounts: ";
    cin >> numberOfIterations;
    cout << "Give an amount of commision(from 0 to 1): ";
    cin >> commision;

    vector<double> arr1 = {};
    for (int i = 0; i < numberOfIterations; i++)
    {
        arr1.push_back(rand() % 10000 + 1);
    }
<<<<<<< HEAD
    double sum = 0;
    for(double n : arr1)
=======

    double sum = 0;
    for (double n : arr1)
>>>>>>> parent of ffcf74a... Merge branch 'main' of https://github.com/Hellamb/ASDtasks into main
    {
        sum += n;
    }
    cout << "Before: " << sum << endl;
 

    //auto begin = chrono::steady_clock::now();

    cout <<"After: "<< cor.func(arr1, commision);

    //auto end = chrono::steady_clock::now();
    //auto algTime = chrono::duration_cast<chrono::microseconds>(end - begin);
    //cout << endl;
   // cout << endl << "To sort this array " << algTime.count() << " mcs were spent";
    
}


void printArray(vector<double> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}

