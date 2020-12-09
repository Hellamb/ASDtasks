#include "CountingSorter.h"

vector<double> CountingSorter::sort(vector<double>& arr) {
	double k = 0;
	double n = arr.size();
	for (int i = 0; i < n; i++) {
		if (arr[i] > k)
			k = arr[i];
	}
	vector<double> c(k + 1, 0);
	for (int i = 0; i < n; i++) {
		c[arr[i]] = c[arr[i]] + 1;
	}

	vector<double> ans(n);
	int b = 0;
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i]; j++) {
			ans[b] = i;
			b = b + 1;
		}
	}
	return ans;
}
