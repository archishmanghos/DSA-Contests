class Solution {
public:
  vector <int> max_of_subarrays(int *arr, int n, int k) {
    vector<int> ans(n - k + 1);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      while (!dq.empty() and arr[i] > arr[dq.back()]) dq.pop_back();
      dq.push_back(i);
      while (!dq.empty() and dq.front() < (i - k + 1)) dq.pop_front();
      if (i >= k - 1) ans[i - k + 1] = arr[dq.front()];
    }

    return ans;
  }
};