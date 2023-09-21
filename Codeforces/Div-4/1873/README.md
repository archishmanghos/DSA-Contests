<h2>A. Short Sort</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/A)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string s; cin >> s;
	if (s == "bca" or s == "cab") cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>B. Good Kid</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/B)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int answer = a[0] + 1;
	for (int i = 1; i < n; i++) answer *= a[i];
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>C. Target Practice</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/C)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c; cin >> c;
			int pointi = i < 5 ? i + 1 : 5 - (i % 5);
			int pointj = j < 5 ? j + 1 : 5 - (j % 5);
			if (c == 'X') answer += min(pointi, pointj);

		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>D. 1D Eraser</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/D)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {
			answer += 1;
			i += k - 1;
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>E. Building an Aquarium</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/E)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int low = 1, high = 1e10, answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto f = [&]() {
			int waterUsed = 0;
			for (int i = 0; i < n; i++) {
				waterUsed += max(0ll, mid - a[i]);
			}

			return waterUsed <= x;
		};

		if (f()) {
			answer = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>F. Money Trees</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/F)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) a[i] += a[i - 1];
	}
	int h[n]; for (int i = 0; i < n; i++) cin >> h[i];

	int answer = 0, l = 0;
	for (int i = 0; i < n - 1;) {
		if (h[i] % h[i + 1] == 0) {
			int sum = a[i] - (l - 1 >= 0 ? a[l - 1] : 0);
			while (sum > x) sum -= a[l++];
			answer = max(answer, i - l + 1);
			i++;
		} else {
			int sum = a[i] - (l - 1 >= 0 ? a[l - 1] : 0);
			while (l <= i) {
				if (sum <= x) answer = max(answer, i - l + 1);
				sum -= a[l++];
			}
			i++;
			l = i;
		}
	}

	int sum = a[n - 1] - (l - 1 >= 0 ? a[l - 1] : 0);
	while (l < n) {
		if (sum <= x) answer = max(answer, n - l);
		sum -= a[l];
		l++;
	}
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>

<br>
<br>

<h2>G. ABBC or BACB</h2>

[Link to Problem](https://codeforces.com/contest/1873/problem/G)

<details><summary>Codes</summary>

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string s; cin >> s;
	int answer = 0;

	vector<int> a;
	int cntb = 0, cnta = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') cnta++;
		else {
			if (cnta) a.push_back(cnta);
			cnta = 0;
			cntb++;
		}
	}
	if (cnta) a.push_back(cnta);

	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < min(cntb, (int)a.size()); i++) answer += a[i];

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
```

</details>