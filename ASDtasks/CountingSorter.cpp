#include "CountingSorter.h"

vector<long> CountingSorter::sort(vector<long>& arr) {
	int k = 100;
	int n = arr.size();
	vector<long> c(k + 1, 0);
	for (int i = 0; i < n; i++) {
		c[arr[i]] = c[arr[i]] + 1;
	}

	int b = 0;
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i]; j++) {
			arr[b] = i;
			b = b + 1;
		}
	}
	return arr;
}
