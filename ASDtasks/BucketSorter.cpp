#include "BucketSorter.h"

vector<long> BucketSorter::sort(vector<long>& array)
{
    int len = array.size();

    auto max_elem = *max_element(array.begin(), array.end());
    auto min_elem = *min_element(array.begin(), array.end());

    double d = (double) ((max_elem - min_elem + 1)) / BUCKET_SIZE;

    long divider = (long) ceil(d);

    vector<long> *buckets = new vector<long>[BUCKET_SIZE];

    for (long elem : array)
    {
        double index = (double) ((elem - min_elem) / divider);
        int intIndex = (int) floor(index);
        buckets[intIndex].push_back(elem);
    }

    vector<long> sorted_array{};

    for (int k = 0; k < BUCKET_SIZE; k++)
    {
        long n = buckets[k].size();

        for (long i = 0; i < n; i++)
        {
            long j = i - 1;
            long x = buckets[k][i];
            while (j >= 0 &&(buckets[k][j] > x ))
            {
                buckets[k][j + 1] = buckets[k][j];
                j -= 1;
            }
            buckets[k][j + 1] = x;
        }

        for (long elem : buckets[k])
        {
            sorted_array.push_back(elem);
        }
    }

    return sorted_array;
}