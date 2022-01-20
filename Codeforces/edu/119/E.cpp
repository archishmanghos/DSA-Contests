#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, X, Y, type;
    cin >> Q;
    vector<int> ans;
    vector<pair<int, pair<int, int>>> A;
    map<int, int> mp;

    for(int i = 1; i <= Q; i++){
        cin >> type;
        if(type == 1){
            cin >> X;
            A.push_back({type, {X, -1}});
        }
        else{
            cin >> X >> Y;
            A.push_back({type, {X, Y}});
        }
    }

    for(int i = Q - 1; i >= 0; i--){
        if(A[i].first == 1){
            if(mp.find(A[i].second.first) != mp.end()){
                ans.push_back(mp[A[i].second.first]);
            }
            else{
                ans.push_back(A[i].second.first);
            }
        }
        else{
            if(mp.find(A[i].second.second) != mp.end()){
                mp[A[i].second.first] = mp[A[i].second.second];
            }
            else{
                mp[A[i].second.first] = A[i].second.second;
            }
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << ' ';
    }

    return 0;
}