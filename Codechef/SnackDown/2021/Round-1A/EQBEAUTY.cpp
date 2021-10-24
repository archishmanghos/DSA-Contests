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

    if(N == 2)
    {
        cout << 0 << '\n';
        return;
    }

    sort(A + 1, A + N + 1);
    int minn = INF;
    if(N == 3)
    {
        for(int i = 2; i <= N; i++)
            minn = min(minn, A[i] - A[i - 1]);
        cout << minn << '\n';
        return;
    }

    int i = 2, j = N - 1;
    while(i < j)
    {
        int diff1 = A[N] - A[i];
        int diff2 = A[j] - A[1];
        minn = min(minn, abs(diff1 - diff2));

        if(diff1 == diff2)
        {
            cout << 0 << '\n';
            return;
        }
        else if(diff1 < diff2)
            j -= 1;
        else
            i += 1;
    }

    int median1 = ((N - 1) % 2 == 0 ? A[(N - 1) / 2] : A[((N - 1) / 2) + 1]);
    int median2 = ((N - 1) % 2 == 0 ? A[(N - 1) / 2 + 1] : median1);

    int diff11 = 0, diff12 = 0;
    for(int j = 1; j <= N - 1; j++)
        diff11 += abs(A[j] - median1);
    for(int j = 1; j <= N - 1; j++)
        diff12 += abs(A[j] - median2);
    int diff1 = min(diff11, diff12);
    minn = min(minn, diff1);

    median1 = ((N - 1) % 2 == 0 ? A[1 + ((N - 1) / 2)] : A[((N - 1) / 2) + 2]);
    median2 = ((N - 1) % 2 == 0 ? A[(N - 1) / 2 + 2] : median1);
    int diff21 = 0, diff22 = 0;
    for(int j = 2; j <= N; j++)
        diff21 += abs(A[j] - median1);
    for(int j = 2; j <= N; j++)
        diff22 += abs(A[j] - median2);
    int diff2 = min(diff21, diff22);
    minn = min(minn, diff2);

    cout << minn << '\n';

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