#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class BucketSorter
{
public:
    vector<long> sort(vector<long>& array);

private:
    const static int BUCKET_SIZE = 5000;
};