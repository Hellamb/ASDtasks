#pragma once
#include <vector>

using namespace std;

class MergeSorter
{
public:
    vector<long> sort(vector<long>& arr);
    vector<long> merge(vector<long>& L, vector<long>& R);
};

