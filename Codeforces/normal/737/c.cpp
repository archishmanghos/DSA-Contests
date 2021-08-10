// Created: 10-08-2021 20:44:01

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

int T, N, K;

const int mod = 1e9 + 7;

int add(int a, int b, int p = mod)
{
	int c = a + b;
	if (c >= p)
		c -= p;
	return c;
}

int sub(int a, int b, int p = mod)
{
	int c = a - b;
	if (c < 0)
		c += p;
	return c;
}

int mul(int a, int b, int p = mod)
{
	return (a * (int)1 * b) % p;
}

void solve()
{
    cin >> N >> K;

    int a = 1, b = 1;
    for(int i = 1; i <= N; i++)
        a = mul(a, 2);
    for(int i = 1; i <= N - 1; i++)
        b = mul(b, 2);

    int c = add(b, 1);
    b = sub(b, 1);

    if(N & 1)
    {
        int c1 = 1;
        for(int i = 1; i <= K; i++)
            c1 = mul(c1, c);
        cout << c1 << '\n';
    }
    else
    {
        int ans = 0;
        int b1 = 1;
        for(int i = 1; i <= K; i++)
            b1 = mul(b1, b);
        ans = add(ans, b1);

        b1 = 1;
        int a1 = 1, arr[K] = {0};
        arr[0] = 1;
        for(int i = 1; i <= K - 1; i++)
        {
            a1 = mul(a1, a);
            arr[i] = a1;
        }

        for(int i = 1; i <= K; i++)
        {
            int temp = mul(arr[K - i], b1);
            ans = add(ans, temp);

            b1 = mul(b1, b);
        }

        cout << ans << '\n';
    }
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