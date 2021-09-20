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

struct dragon
{
	int defense, attack;
};

int N, M;
vector<int> A(mxN);
dragon D;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	int sum = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
	}

	sort(A.begin(), A.begin() + N);
	cin >> M;
	while(M--)
	{
		cin >> D.defense >> D.attack;
		int index = upper_bound(A.begin(), A.begin() + N, D.defense) - A.begin();
		int ans = 0;
		if(index == N)
		{
			ans += (D.defense - A[N - 1]);
			if((sum - A[N - 1]) < D.attack)
				ans += (D.attack - (sum - A[N - 1]));
		}
		else if(index == 0)
		{
			if((sum - A[0]) < D.attack)
				ans += (D.attack - (sum - A[0]));
		}
		else
		{
			int ans1 = 0, ans2 = 0;

			if(A[index] < D.defense)
				ans1 += (D.defense - A[index]);
			if((sum - A[index]) < D.attack)
				ans1 += (D.attack - (sum - A[index]));

			if(A[index - 1] < D.defense)
				ans2 += (D.defense - A[index - 1]);
			if((sum - A[index - 1]) < D.attack)
				ans2 += (D.attack - (sum - A[index - 1]));

			ans = min(ans1, ans2);
		}

		cout << ans << '\n';
	}

    return 0;
}