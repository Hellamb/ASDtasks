#include "BucketSorter.h"

vector<long> BucketSorter::sort(vector<long>& array)
{
    int len = array.size();

    auto max_elem = *max_element(array.begin(), array.end());
    auto min_elem = *min_element(array.begin(), array.end());

    long buckets_size = max_elem - min_elem + 1;

    vector<long> *buckets = new vector<long>[buckets_size];

    for (long elem : array)
    {
        buckets[elem - min_elem].push_back(elem);
    }

    vector<long> sorted_array{};

    for (int i = 0; i < buckets_size; i++)
    {
        for (long elem : buckets[i])
        {
            sorted_array.push_back(elem);
        }
    }

    return sorted_array;
}