#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int stories, users;
set<int> storyCreated[202], userFollowedBy[202], storiesFollowedBy[202], userFollowingStories[202];

int a(int Ui, int Uj) {
    if (userFollowedBy[Uj].find(Ui) != userFollowedBy[Uj].end()) {
        return 3;
    } else {
        for (int story: storyCreated[Uj]) {
            if (storiesFollowedBy[story].find(Ui) != storiesFollowedBy[story].end()) {
                return 2;
            }
        }
        for (int story: userFollowingStories[Uj]) {
            if (storiesFollowedBy[story].find(Ui) != storiesFollowedBy[story].end()) {
                return 1;
            }
        }
        return 0;
    }
}

int b(int Uj, int Sk) {
    if (storyCreated[Uj].find(Sk) != storyCreated[Uj].end()) {
        return 2;
    } else if (storiesFollowedBy[Sk].find(Uj) != storiesFollowedBy[Sk].end()) {
        return 1;
    } else {
        return 0;
    }
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> stories >> users;
    for (int i = 1; i <= stories; i++) {
        int userIndex;
        cin >> userIndex;
        storyCreated[userIndex].insert(i);
    }

    int userFollows, storyFollows;
    cin >> userFollows >> storyFollows;

    for (int i = 1; i <= userFollows; i++) {
        int follower, followed;
        cin >> follower >> followed;
        userFollowedBy[followed].insert(follower);
    }

    for (int i = 1; i <= storyFollows; i++) {
        int follower, storyFollowed;
        cin >> follower >> storyFollowed;
        storiesFollowedBy[storyFollowed].insert(follower);
        userFollowingStories[follower].insert(storyFollowed);
    }

    vector<pair<int, int>> score[users + 2],usablePeople;
    for (int i = 1; i <= users; i++) {
        for (int j = 1; j <= stories; j++) {
            if (storiesFollowedBy[j].find(i) == storiesFollowedBy[j].end()) {
                if (storyCreated[i].find(j) == storyCreated[i].end()) {
                    usablePeople.push_back({i,j});
                }
            }
        }
    }

    for(auto use: usablePeople){
        int ans = 0;
        for (int k = 1; k <= users; k++) {
            if (use.first != k) {
                ans += a(use.first, k) * b(k, use.second);
            }
        }
        score[use.first].push_back({ans, use.second});
    }

    for (int i = 1; i <= users; i++) {
        sort(score[i].begin(), score[i].end(), comp);
        for (int j = 0; j < 3; j++) {
            cout << score[i][j].second << ' ';
        }
        cout << '\n';
    }

    return 0;
}