#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void convert(int arr[], int n) {
		vector<int> v;
		map<int, int> idx;
		for (int i = 0; i < n; i++) v.push_back(arr[i]);
		sort (v.begin(), v.end());
		for (int i = 0; i < n; i++) idx[v[i]] = i;
		for (int i = 0; i < n; i++) arr[i] = idx[arr[i]];
	}
};