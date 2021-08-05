// Created: 05-08-2021 21:47:49

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 55;
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

int N, M, A[mxN][mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> A[i][j];

    int B[N + 5][M + 5];
    memset(B, 0, sizeof(B));

    vector<pair<int, int>>ans;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(A[i][j] == 1)
            {
                bool check = true;
                check &= ((i + 1) <= N && A[i + 1][j] == 1);
                check &= ((j + 1) <= M && A[i][j + 1] == 1);
                check &= ((i + 1) <= N && (j + 1) <= M && A[i + 1][j + 1] == 1);
                if(check)
                {
                    B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
                    ans.push_back({i, j});
                }
            }
        }
    }

    bool check = true;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            check &= A[i][j] == B[i][j];

    if(check)
    {
        cout << ans.size() << '\n';
        for(auto it : ans)
            cout << it.first << ' ' << it.second << '\n';
    }
    else
        cout << -1 << '\n';

    return 0;
}