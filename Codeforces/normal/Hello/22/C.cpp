#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    cin >> N;
    vector<int> P(N + 2, -1), doneIndices(N + 2, 0);

    auto query = [](int index)-> int {
        cout << '?' << ' ' << index << endl;
        int q;
        cin >> q;
        return q;
    };

    for(int i = 1; i <= N; i++){
        if(!doneIndices[i]){
            int pre = i;
            while(query(i) != i)
                continue;

            while(true){

                int Q = query(i);
                if(Q == i){
                    P[pre] = Q;
                    doneIndices[pre] = 1;
                    break;
                }

                P[pre] = Q;
                doneIndices[pre] = 1;
                pre = Q;
            }
        }
    }

    cout << '!';
    for(int i = 1; i <= N; i++){
        cout << ' ' << P[i];
    }

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}