#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <chrono>
#include <conio.h>

#include "QuickSorter.h"
#include "MergeSorter.h"


#include "Corruption.h"
#include "Levenshtein.h"

using namespace std;

void printArray(vector<double> arr);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    QuickSorter qs;
    MergeSorter ms;
    //CountingSorter cs;

    Corruption cor;
    Levenshtein lev;

    string s1, s2;
   /* cout << "Give first string: ";
    cin >> s1;
    cout << "Give second string: ";
    cin >> s2;*/
    int ans = lev.lev_dist("hello", "here is hello");
    cout << "levenshtein distance is " << ans << endl;

   /* int numberOfIterations;
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

    /*{
        sum += n;
    }
    cout << "Before: " << sum << endl;*/
 
   /* auto begin = chrono::steady_clock::now();

    cout <<"After: "<< cor.func(arr1, commision);

    auto end = chrono::steady_clock::now();
    auto algTime = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << endl;

    cout << endl << "To sort this array " << algTime.count() << " mcs were spent";*/

}


void printArray(vector<double> array)
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ", ";
    }
}

