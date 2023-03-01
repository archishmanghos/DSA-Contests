#include <bits/stdc++.h>
using namespace std;

class HeapSort {
public:
	void heapSort(vector<int> &A) {
		int N = A.size();
		buildMaxHeap(A, N);
		for (int i = N - 1; i >= 0; i--) {
			swap(A[0], A[i]);
			N -= 1;
			heapify(0, A, N);
		}
	}

private:
	void buildMaxHeap(vector<int> &A, int N) {
		for (int i = (N / 2) - 1; i >= 0; i--) {
			heapify(i, A, N);
		}
	}

	void heapify(int idx, vector<int> &A, int N) {
		int leftIdx = (idx << 1) + 1, rightidx = (idx << 1) + 2;

		int newIdx = idx;
		if (leftIdx < N and A[newIdx] < A[leftIdx]) {
			newIdx = leftIdx;
		}

		if (rightidx < N and A[newIdx] < A[rightidx]) {
			newIdx = rightidx;
		}

		if (newIdx != idx) {
			swap(A[idx], A[newIdx]);
			heapify(newIdx, A, N);
		}
	}
};

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		HeapSort hs;
		hs.heapSort(nums);
		return nums;
	}
};