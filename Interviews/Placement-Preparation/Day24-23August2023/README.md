<h2>Sequence Query </h2>

[Link to Problem](https://www.codingninjas.com/studio/contests/beginner-contest-41/9237927/problems/26201)

```c++

#include <bits/stdc++.h>
using namespace std;

int checkSequence(int a, int d, int x) {
	if (d == 0) return x == a;
	if (x < a) {
		if (d < 0) return (x - a) % d == 0;
		return 0;
	}
	if (d < 0) return 0;
	return (x - a) % d == 0;
}

```

<br>
<br>

<h2>Replace Elements </h2>

[Link to Problem](https://www.codingninjas.com/studio/contests/beginner-contest-41/9237927/problems/25643)

```c++

#include <bits/stdc++.h>
using namespace std;

int replaceElements(vector<int> & a) {
	int n = a.size();
	if (n & 1) return -1;

	int odd = 0;
	unordered_map<int, int> ump;
	for (int i : a) {
		ump[i]++;
	}

	for (auto key : ump) {
		if (key.second & 1) odd++;
	}

	return (odd / 2);
}

```

<br>
<br>

<h2>Kaiser Impact </h2>

[Link to Problem](https://www.codingninjas.com/studio/contests/beginner-contest-41/9237927/problems/25057)

```c++

#include <bits/stdc++.h>
using namespace std;

int kaiserImpact(int n, int m, int a, int b, int w, double k) {
	double slope1 = (double)a / b;
	double slope2 = (double)a / (b + w);
	cout << slope1 << ' ' << slope2 << '\n';
	return (k >= slope1 and k <= slope2);
}


```

<br>
<br>

<h2>Even Odd Arrangement </h2 >

[Link to Problem](https://www.codingninjas.com/studio/contests/beginner-contest-41/9237927/problems/26752)

```c++

#include <bits/stdc++.h>
using namespace std;

int cache[102][102][102];
int dp(int idx, int sum, int arrIdx, vector<int> & a, int totSum) {
	if (idx < 0) {
		return abs(2 * sum - totSum);
	}
	if (arrIdx == a.size()) return 1e9;
	int & answer = cache[idx][sum][arrIdx];
	if (answer != -1) return answer;

	answer = dp(idx, sum, arrIdx + 1, a, totSum);
	answer = min(answer, dp(idx - 1, sum + a[arrIdx], arrIdx + 1, a, totSum));
	return answer;
}

int evenOddArrangement(int n, vector<int> & a) {
	int even = (n + 1) / 2, totSum = accumulate(a.begin(), a.end(), 0);
	memset(cache, -1, sizeof(cache));
	return dp(even - 1, 0, 0, a, totSum);
}

```

<br>
<br>

<h2>767. Reorganize String </h2>

[Link to Problem](https://leetcode.com/problems/reorganize-string/description/)

```java

class Pair {
	private int first, second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public int getFirst() {
		return first;
	}

	public int getSecond() {
		return second;
	}
}

class Solution {
	public String reorganizeString(String s) {
		PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> y.getFirst() - x.getFirst());
		int[] cnt = new int[26];
		for (int i = 0; i < s.length(); i++) {
			cnt[((int) s.charAt(i) - 97)]++;
		}

		for (int i = 0; i < 26; i++) if (cnt[i] > 0) pq.offer(new Pair(cnt[i], i + 97));

		List<Character> answer = new ArrayList<>();
		while (pq.size() > 1) {
			var it1 = pq.poll();
			char x1 = (char) it1.getSecond();

			if (answer.isEmpty() || answer.get(answer.size() - 1) != x1) {
				answer.add(x1);
				int k = it1.getFirst() - 1;
				if (k > 0) pq.offer(new Pair(k, it1.getSecond()));
			} else {
				var it2 = pq.poll();
				char x2 = (char) it2.getSecond();
				answer.add(x2);
				int k = it2.getFirst() - 1;
				if (k > 0) pq.offer(new Pair(k, it2.getSecond()));
				pq.offer(new Pair(it1.getFirst(), it1.getSecond()));
			}
		}

		boolean clear = pq.isEmpty();
		if (!clear) {
			var it = pq.poll();
			char x = (char) it.getSecond();
			if (it.getFirst() == 1 && (answer.isEmpty() || answer.get(answer.size() - 1) != x)) {
				answer.add(x);
				clear = true;
			}
		}

		if (clear) {
			StringBuilder finalAnswer = new StringBuilder();
			for (var i : answer) finalAnswer.append(i);
			return finalAnswer.toString();
		}
		return "";
	}
}

```