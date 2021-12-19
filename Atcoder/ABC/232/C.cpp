#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, M, U, V;
set<int> adj1[10], adj2[10];

bool checkPermutation(vector<int> v)
{
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			if(adj1[i + 1].count(j + 1) && !adj2[v[i]].count(v[j]))
				return false;
			if(adj2[v[i]].count(v[j]) && !adj1[i + 1].count(j + 1))
				return false;
		}
	}

	return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
    	cin >> U >> V;
    	adj1[U].insert(V);
    	adj1[V].insert(U);
    }
    for(int i = 1; i <= M; i++)
    {
    	cin >> U >> V;
    	adj2[U].insert(V);
    	adj2[V].insert(U);
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++)
    	ans.push_back(i);

    do{
    	if(checkPermutation(ans))
    	{
    		cout << "Yes";
    		return 0;
    	}
    } while(next_permutation(ans.begin(), ans.end()));

    cout << "No";

    return 0;
}