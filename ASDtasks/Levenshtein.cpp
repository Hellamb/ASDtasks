#include "Levenshtein.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <chrono>
#include <conio.h>
using namespace std;

int Levenshtein::lev_dist(string s1, string s2)
{
    int size1 = s1.length();
    int size2 = s2.length();
    vector<vector<int> > d;
    vector<int> d1(size2 + 1);
    for (int i = 0; i <= size1; i++)
    {
        d.push_back(d1);
    }

    for (int i = 0; i <= size1; i++)
        d[i][0] = i;
    for (int i = 0; i <= size2; i++)
        d[0][i] = i;

    int cost = 0;
    for (int i = 1; i <= size1; i++)
        for (int j = 1; j <= size2; j++)
        {
            cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(min(d[i][j - 1] + 1, d[i - 1][j] + 1), d[i - 1][j - 1] + cost);
        }
    return d[size1][size2];
}
