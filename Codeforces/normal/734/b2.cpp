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

int T, N, K, A[mxN];

bool compare1(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

void solve()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    int mp[N + 5] = {0};
    for(int i = 1; i <= N; i++)
        mp[A[i]] += 1;

    vector<pair<int, int>> v;
    set<int> s;

    for(int i = 1; i <= N; i++)
        s.insert(A[i]);

    for(int i : s)
        v.push_back({mp[i], i});

    sort(v.begin(), v.end(), compare1);

    vector<int> putItAll;

    int i;
    for(i = 0; i < v.size(); i++)
    {
        if(v[i].first >= K)
            putItAll.push_back(v[i].second);
        else
            break;
    }
    debug(putItAll)
    debug(i)
    vector<pair<int, int>> v1;
    for(int j = i; j < v.size(); j++)
    {
        debug(v[j].second)
        v1.push_back(v[j]);
    }

    sort(v1.begin(), v1.end(), compare1);
    int count = 0;

    vector<pair<int, int>> putItTogether;
    for(int i = 1; i <= N; i++)
    {
        if(mp[A[i]] < K)
            putItTogether.push_back({A[i], i});
    }   

    for(int i : s)
    {
        if(mp[i] < K)
            count += mp[i];
    }

    count = (count / K) * K;
    debug(count)
    sort(putItTogether.begin(), putItTogether.end());

    int mp1[N + 5] = {0}, mp2[N + 5] = {0};
    for(auto it : putItAll)
        mp1[it] += 1;

    int ans[N + 5];
    memset(ans, -1, sizeof(ans));

    for(int i = 1; i <= N; i++)
    {
        mp2[A[i]] += 1;
        if(mp1[A[i]])
            ans[i] = (mp2[A[i]] > K ? 0 : mp2[A[i]]);
    }

    memset(mp2, 0, sizeof(mp2));
    memset(mp1, 0, sizeof(mp1));
    int k = 1, cnt = 0;

    for(int i = 0; i < putItTogether.size(); i++)
    {

        if(cnt == count)
            break;
        cnt += 1;
        ans[putItTogether[i].second] = k;

        k = (k + 1 > K ? 1 : k + 1);
    }


    for(int i = 1; i <= N; i++)
        cout << (ans[i] == -1 ? 0 : ans[i]) << ' ';
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

//23-07-2021 21:31:43