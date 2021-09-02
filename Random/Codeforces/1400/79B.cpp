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

int N, M, K, T, U, V;
vector<pair<int, int>> A(mxN);

bool myComp(const pair<int, int> &a, const pair<int, int> &b)
{
	if(a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M >> K >> T;
	for(int i = 1; i <= K; i++)
		cin >> A[i].first >> A[i].second;

	sort(A.begin() + 1, A.begin() + K + 1, myComp);

	string pick[3] = {"Carrots", "Kiwis", "Grapes"};
	for(int i = 1; i <= T; i++)
	{
		cin >> U >> V;
		int wastesBefore = 0;
		bool printWaste = false;

		for(int j = 1; j <= K; j++)
		{
			if(A[j].first < U)
				wastesBefore += 1;
			else if(A[j].first == U && A[j].second < V)
				wastesBefore += 1;
			else if(A[j].first == U && A[j].second == V)
			{
				printWaste = true;
				break;
			}
			else
				break;
		}

		if(printWaste)
			cout << "Waste" << '\n';
		else
		{
			int cellsBefore = (U - 1) * M + (V - 1);
			cellsBefore -= wastesBefore;

			cout << pick[cellsBefore % 3] << '\n';
		}
	}

    return 0;
}