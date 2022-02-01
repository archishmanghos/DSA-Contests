#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct player {
    int attack, health;
};

void solve() {
    player monogon, monster;
    cin >> monogon.health >> monogon.attack >> monster.health >> monster.attack;
    int K, W, A;
    cin >> K >> W >> A;

    for (int i = 0; i <= K; i++) {
        int coinsOnWeapon = i, coinsOnArmor = K - i;
        int newHealth = monogon.health + coinsOnArmor * A;
        int newAttack = monogon.attack + coinsOnWeapon * W;
        int stepsByMon = (monster.health + newAttack - 1) / newAttack;
        int stepsByMons = (newHealth + monster.attack - 1) / monster.attack;

        if (stepsByMon <= stepsByMons) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}