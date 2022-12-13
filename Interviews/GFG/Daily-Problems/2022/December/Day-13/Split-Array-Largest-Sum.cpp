#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(int arr[] , int N, int K) {
        int low = 1, high = 1e9, ans = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int minSplits = 1, sum = 0;

            for (int i = 0; i < N; i++) {
                if (sum + arr[i] > mid) {
                    minSplits += 1;
                    sum = arr[i];
                    if (arr[i] > mid) {
                        minSplits = (int)1e7;
                    }
                } else {
                    sum += arr[i];
                }
            }

            if (minSplits <= K) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};