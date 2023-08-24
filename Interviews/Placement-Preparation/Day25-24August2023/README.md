<h2>68. Text Justification</h2>

[Link to Problem](https://leetcode.com/problems/text-justification/description/)

```c++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int i = 0;
        while (i < words.size()) {
            int sum = 0;
            vector<string> temporary_words;
            while (i < words.size() and sum + words[i].size() < maxWidth) {
                sum += words[i].size() + 1;
                temporary_words.push_back(words[i++]);
            }
            bool notLast = true;
            if (i < words.size() and sum + words[i].size() <= maxWidth) {
                sum += words[i].size();
                temporary_words.push_back(words[i++]);
                notLast = false;
            }

            if (notLast) sum--;

            if (i < words.size()) {
                int n = temporary_words.size(), space = n - 1;
                if (space == 0) {
                    string finalPush = temporary_words[0];
                    while (finalPush.size() < maxWidth) finalPush += ' ';
                    answer.push_back(finalPush);
                    continue;
                }

                int distribution = (maxWidth - sum) / space, remaining_space = (maxWidth - sum) % space;
                string finalPush = temporary_words[0];
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j <= distribution; j++) finalPush += ' ';
                    if (remaining_space) finalPush += ' ';
                    remaining_space = max(0, remaining_space - 1);
                    finalPush += temporary_words[i];
                }

                answer.push_back(finalPush);
            } else {
                string finalPush = temporary_words[0];
                for (int i = 1; i < temporary_words.size(); i++) {
                    finalPush += ' ';
                    finalPush += temporary_words[i];
                }
                while (finalPush.size() < maxWidth) finalPush += ' ';
                answer.push_back(finalPush);
            }
        }

        return answer;
    }
};

```

<br>
<br>

<h2>A. Gift Carpet</h2>

[Link to Problem](https://codeforces.com/contest/1862/problem/A)

```c++

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	char a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}

	int k = 0;
	string str = "vika";


	for (int i = 0; i < m; i++) {
		if (k == 4) {
			cout << "YES" << '\n';
			return;
		}
		for (int j = 0; j < n; j++) {
			if (a[j][i] == str[k]) {
				k++;
				break;
			}
		}
	}

	cout << (k == 4 ? "YES" : "NO") << '\n';
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

<br>
<br>

<h2>B. Sequence Game</h2>

[Link to Problem](https://codeforces.com/contest/1862/problem/B)

```c++

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> answer;
	for (int i = 0; i < n - 1; i++) {
		answer.push_back(a[i]);
		if (a[i] > a[i + 1]) answer.push_back(a[i + 1]);
	}

	answer.push_back(a[n - 1]);
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " \n"[i == answer.size() - 1];
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

<br>
<br>

<h2>C. Flower City Fence</h2>

[Link to Problem](https://codeforces.com/contest/1862/problem/C)

```c++

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}

	int sz = 0;
	for (int i = 0; i < n; i++) {
		int vertical = a[i];
		if (mp.find(i) != mp.end()) sz += mp[i];
		int horizontal = n - sz;
		if (vertical != horizontal) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
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