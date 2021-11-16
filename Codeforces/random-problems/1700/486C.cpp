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
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int N, P;
string S;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> P >> S;
	if(N == 1)
	{
		cout << 0;
		return 0;
	}

	P = min(P, N - P + 1);
	int ans = 0;
	int pos1 = P - 1, pos2 = P - 1;
	for(int i = 0; i < (N / 2); i++)
	{
		if(S[i] != S[N - i - 1])
		{
			pos1 = i;
			break;
		}
	}

	pos1 = min(P - 1, pos1);

	for(int i = (N / 2 - 1); i >= 0; i--)
	{
		if(S[i] != S[N - i - 1])
		{
			pos2 = i;
			break;
		}
	}

	pos2 = max(P - 1, pos2);

	int distt1;
	if(pos1 >= P - 1)
		distt1 = pos2 - (P - 1);
	else
		distt1 = pos2 - (P - 1) + (pos2 - pos1);
	int distt2;
	if(pos2 <= P - 1)
		distt2 = (P - 1) - pos1;
	else
		distt2 = (P - 1) - pos1 + pos2 - pos1;
	ans = min(distt1, distt2);

	int i = 0;
	while(i < (N / 2))
	{
		if(S[i] != S[N - i - 1])
		{
			int dist1 = (S[i] - 'a') - (S[N - i - 1] - 'a');
			if(dist1 < 0)
				dist1 += 26;
			int dist2 = (S[N - i - 1] - 'a') - (S[i] - 'a');
			if(dist2 < 0)
				dist2 += 26;
			ans += min(dist1, dist2);
		}
		i += 1;
	}

	cout << ans;

    return 0;
}