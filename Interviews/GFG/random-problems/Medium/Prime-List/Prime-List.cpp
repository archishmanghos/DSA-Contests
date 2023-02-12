#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node(int num) {
		val = num;
		next = NULL;
	}
};

class Solution {
public:
	void SOE (vector<int> &primes) {
		int mxn = 1e4 + 7;
		bool isPrime[mxn];
		memset (isPrime, true, sizeof(isPrime));
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i <= mxn; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j <= mxn; j += i) {
					isPrime[j] = false;
				}
			}
		}

		for (int i = 2; i <= mxn; i++) {
			if (isPrime[i]) {
				primes.push_back(i);
			}
		}
	}
	Node *primeList(Node *head) {
		vector<int> primes;
		SOE (primes);
		Node *dummy = head;
		while (dummy) {
			int data = dummy->val;
			int index = lower_bound (primes.begin(), primes.end(), data) - primes.begin();
			int nextPrime = primes[index];
			if (index > 0) {
				int prevPrime = primes[index - 1];
				if (data - prevPrime <= nextPrime - data) dummy->val = prevPrime;
				else dummy->val = nextPrime;
			} else {
				dummy->val = nextPrime;
			}

			dummy = dummy->next;
		}

		return head;
	}
};