#include "MergeSorter.h"

vector<long> MergeSorter::merge(vector<long>& L, vector<long>& R)
{
    long n1 = L.size();
    long n2 = R.size();
    vector<long> arr(n1 + n2);
    long i = 0;
    long j = 0;
    long k = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return arr;
}

vector<long> MergeSorter::sort(vector<long>& arr)
{
    if (arr.size() <= 1) {
        return arr;
    }
    long l = 0;
    long r = arr.size() - 1;

    long m = (l + r - 1) / 2;
    long n1 = m - l + 1;
    long n2 = r - m;

    vector<long> L(n1);
    vector<long> R(n2);

    for (long i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    L = sort(L);
    R = sort(R);
    return merge(L, R);
}