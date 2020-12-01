#pragma once
#include <vector>
#include <map>

using namespace std;

class Radix2Sorter
{
public:
    void eachDigitSort(vector<long>& arr, int n, int dig);
    vector<long> sort(vector<long>& arr);
};

