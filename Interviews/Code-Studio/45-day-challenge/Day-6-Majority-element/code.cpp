#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	sort(arr, arr + n);
	for (int i = 0; i + (n / 2) < n; i++) if (arr[i] == arr[i + (n / 2)]) return arr[i];
	return -1;
}