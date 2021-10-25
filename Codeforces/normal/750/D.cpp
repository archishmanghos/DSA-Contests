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

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];
    
    if(N % 2 == 0)
    {
    	for(int i = 1; i <= N; i += 2)
    	{
    		int mul = abs(A[i] * A[i + 1]);
    		cout << mul / A[i] << ' ' << (mul / -A[i + 1]) << ' ';
    	}
    }
    else
    {
    	bool minus[N+5];
    	memset(minus, false, sizeof(minus));
    	int ans[N + 5];
    	vector<pair<int, int>> B(mxN);

    	for(int i = 1; i <= N; i++)
    	{
    		B[i].first = abs(A[i]);
    		B[i].second = i;
    		if(A[i] < 0)
    			minus[i] = true;
    		A[i] = abs(A[i]);
    	}
    	sort(B.begin() + 1, B.begin() + N + 1);
    	for(int i = 1; i <= (N - 3); i += 2)
    	{
    		int mul = B[i].first * B[i + 1].first;
    		if(!minus[B[i].second])
    			ans[B[i].second] = mul / B[i].first;
    		else
    			ans[B[i].second] = mul / -B[i].first;
    		if(!minus[B[i + 1].second])
    			ans[B[i + 1].second] = (mul / -B[i + 1].first);
    		else
    			ans[B[i + 1].second] = (mul / B[i + 1].first);
    	}
    	int lcmm = B[N - 2].first;
    	for(int i = N - 2; i <= N; i++)
    		lcmm = (B[i].first * lcmm) / (__gcd(B[i].first, lcmm));
    	int smallPart1 = lcmm, smallPart2 = (lcmm * 2);
    	for(int i = N - 2; i <= N - 1; i++)
    	{
    		if(!minus[B[i].second])
    			ans[B[i].second] = smallPart1 / B[i].first;
    		else
    			ans[B[i].second] = smallPart1 / -B[i].first;
    	}
    	
    	if(!minus[B[N].second])
    		ans[B[N].second] = smallPart2 / -B[N].first;
    	else
    		ans[B[N].second] = smallPart2 / B[N].first;

    	for(int i = 1; i <= N; i++)
    		cout << ans[i] << ' ';

    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}