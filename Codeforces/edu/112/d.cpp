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

int N, M, L, R;
string S, takeAway[10];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    // abc

    takeAway[1] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[1] += "abc";

    // cba

    takeAway[2] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[2] += "cba";

    // cab

    takeAway[3] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[3] += "cab";

    // bac

    takeAway[4] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[4] += "bac";

    // bca

    takeAway[5] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[5] += "bca";

    // acb

    takeAway[6] = "";
    for(int i = 0; i <= 200007; i += 3)
        takeAway[6] += "acb";

    cin >> N >> M >> S;

    int arr[10][N + 5];
    memset(arr, 0, sizeof(arr));

    for(int i = 1; i <= 6; i++)
    {
        string temp = takeAway[i].substr(0, N);
        
        int countNotEqual = 0;
        for(int j = 1; j <= N; j++)
        {
            countNotEqual += temp[j - 1] != S[j - 1];
            arr[i][j] = countNotEqual;
        }
    }
    
    for(int i = 1; i <= M; i++)
    {
        cin >> L >> R;

        if(L == R)
        {
            cout << 0 << '\n';
            continue;
        }

        int ans = INF;
        L -= 1;

        for(int j = 1; j <= 6; j++)
            ans = min(ans, arr[j][R] - arr[j][L]);

        cout << ans << '\n';
    }

    return 0;
}

//31-07-2021 13:55:31