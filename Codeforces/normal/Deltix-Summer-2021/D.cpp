#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.ff);cerr << ",";_print(p.ss);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int N, K;

tuple<int, int, int> calculateABC(int sum1, int sum2, int sum3)
{
	int aPlusB = sum1, bPlusC = sum2, aPlusC = sum3;

	int aMinusC = aPlusB - bPlusC;
	int a = (aPlusC + aMinusC) / 2;
	int c = (aPlusC - aMinusC) / 2;
	int b = bPlusC - c;

	tuple<int, int, int> ans = {a, b, c};
	return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> K;
	int ans[N + 5];

	int temp = (N / 3) * 3;
	int rem = N % 3;

	for(int i = 1; i <= temp; i += 3)
	{
		int aPlusB = 0, bPlusC = 0, aPlusC = 0;
		pair<int, int> firstTerm, secondTerm, thirdTerm;

		cout << "or" << ' ' << i << ' ' << i + 1 << endl;
		cin >> firstTerm.first;
		cout << "and" << ' ' << i << ' ' << i + 1 << endl;
		cin >> firstTerm.second;
		aPlusB = firstTerm.first + firstTerm.second;

		cout << "or" << ' ' << i + 1 << ' ' << i + 2 << endl;
		cin >> secondTerm.first;
		cout << "and" << ' ' << i + 1 << ' ' << i + 2 << endl;
		cin >> secondTerm.second;
		bPlusC = secondTerm.first + secondTerm.second;

		cout << "or" << ' ' << i << ' ' << i + 2 << endl;
		cin >> thirdTerm.first;
		cout << "and" << ' ' << i << ' ' << i + 2 << endl;
		cin >> thirdTerm.second;
		aPlusC = thirdTerm.first + thirdTerm.second;

		tuple<int, int, int> abc = calculateABC(aPlusB, bPlusC, aPlusC);

		ans[i] = get<0>(abc);
		ans[i + 1] = get<1>(abc);
		ans[i + 2] = get<2>(abc);
	}

	for(int i = 1; i <= rem; i++)
	{
		int aPlusB = 0;
		pair<int, int> firstTerm;

		cout << "or" << ' ' << temp << ' ' << temp + i << endl;
		cin >> firstTerm.first;
		cout << "and" << ' ' << temp << ' ' <<  temp + i << endl;
		cin >> firstTerm.second;
		aPlusB = firstTerm.first + firstTerm.second;

		ans[temp + i] = aPlusB - ans[temp];
	}

	sort(ans + 1, ans + N + 1);
	cout << "finish" << ' ' << ans[K] << endl;

    return 0;
}