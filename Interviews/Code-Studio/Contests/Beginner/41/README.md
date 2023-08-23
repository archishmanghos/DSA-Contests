# Code Studio Beginner Contest 41

> *Stats Corner*
>
> *Date* -> August 23, 2023
>
> *Rank* -> 7
> *Participants / Showed Interest* -> 9002
>
> *Points* -> 240
> *Maximum Points* -> 240
>
> *Remarks* -> C is pure math, D is good.

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

int replaceElements(vector<int> &a) {
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

<h2>Even Odd Arrangement </h2>

[Link to Problem](https://www.codingninjas.com/studio/contests/beginner-contest-41/9237927/problems/26752)

```c++

#include <bits/stdc++.h>
using namespace std;

int cache[102][102][102];
int dp(int idx, int sum, int arrIdx, vector<int> &a, int totSum) {
	if (idx < 0) {
		return abs(2 * sum - totSum);
	}
	if (arrIdx == a.size()) return 1e9;
	int &answer = cache[idx][sum][arrIdx];
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