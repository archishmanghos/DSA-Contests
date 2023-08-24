<h2>459. Repeated Substring Pattern </h2>

[Link to Problem](https://leetcode.com/problems/repeated-substring-pattern/description/)

```java

// Solution 1 using Divisors

public class LC459 {
	private boolean checkCycle(String s, int cycle) {
		int n = s.length();
		for (int i = 0; i < n; i++) if (s.charAt(i % cycle) != s.charAt(i)) return false;
		return true;
	}

	public boolean repeatedSubstringPattern(String s) {
		int n = s.length();
		if (n == 1) return false;
		if (checkCycle(s, 1)) return true;

		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				if (checkCycle(s, i)) return true;
				if (n / i != i && checkCycle(s, n / i)) return true;
			}
		}

		return false;
	}
}

// Solution 2 using concatenation

class Solution {
	public boolean repeatedSubstringPattern(String s) {
		StringBuilder concatenated_s = new StringBuilder();
		int n = s.length();
		for (int i = 1; i < n; i++) concatenated_s.append(s.charAt(i));
		for (int i = 0; i < n - 1; i++) concatenated_s.append(s.charAt(i));

		return concatenated_s.toString().contains(s);
	}
}

```

<br>
<br>

<h2>2828. Check if a String Is an Acronym of Words </h2>

[Link to Problem](https://leetcode.com/contest/weekly-contest-359/problems/check-if-a-string-is-an-acronym-of-words/)

```c++

#include <bits/stdc++.h>
using namespace std;

	class Solution {
public:
	bool isAcronym(vector<string>& words, string s) {
		string w = "";
		for (string c : words) w += c[0];
		return w == s;
	}
};

```

<br>
<br>

<h2>2829. Determine the Minimum Sum of a k - avoiding Array </h2>

[Link to Problem](https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/)

```c++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumSum(int n, int k) {
		int answer = 0, sz = 0;
		unordered_map<int, bool> ump;
		for (int i = 1; sz < n; i++) {
			if (ump.find(k - i) == ump.end()) {
				answer += i;
				ump[i] = true;
				sz++;
			}
		}

		return answer;
	}
};

```

<br>
<br>

<h2>2830. Maximize the Profit as the Salesman </h2>

[Link to Problem](https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/)

```c++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximizeTheProfit(int n, vector<vector<int>>& offers) {
		vector<vector<pair<int, int>>> adj(n);
		for (auto i : offers) {
			adj[i[0]].push_back({i[1], i[2]});
		}

		vector<int> cache(n, -1);
		function<int(int)> dp = [&](int idx) {
			if (idx == n) return 0;
			if (cache[idx] != -1) return cache[idx];

			int answer = dp(idx + 1);
			for (auto i : adj[idx]) {
				answer = max(answer, dp(i.first + 1) + i.second);
			}

			return cache[idx] = answer;
		};

		return dp(0);
	}
};

```

<br>
<br>

<h2>2831. Find the Longest Equal Subarray </h2>

[Link to Problem](https://leetcode.com/contest/weekly-contest-359/problems/find-the-longest-equal-subarray/)

```c++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestEqualSubarray(vector<int>& nums, int k) {
		int answer = 0, maxFreq = 0, n = nums.size();
		set<pair<int, int>> s;
		vector<int> count(n + 2, 0);

		for (int i = 0, j = 0; j < n; j++) {
			count[nums[j]]++;
			if (s.find({1e9, nums[j]}) != s.end()) {
				auto it = s.find({1e9, nums[j]});
				s.erase(it);

			}

			s.insert({count[nums[j]], nums[j]});
			maxFreq = max(maxFreq, (*s.rbegin()).first);
			int deletions = (j - i + 1) - maxFreq;
			if (deletions > k) count[nums[i++]]--;
			else answer = max(answer, maxFreq);
		}

		return answer;
	}
};

```