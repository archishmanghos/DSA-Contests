#include <bits/stdc++.h>
using namespace std;

int calOperations(int cycleLength) {
    int ans = 0;
    while (cycleLength > 0) {
        cycleLength /= 2;
        ans += 1;
    }

    return ans - 1;
}

int power(int x) {
    int ans = 1;
    while (x--) {
        ans *= 2;
    }

    return ans;
}

int main() {
    int P_count;
    cin >> P_count;
    vector<int> P(P_count + 1);
    for (int i = 1; i <= P_count; i++) {
        cin >> P[i];
    }
    int visited[P_count + 1], ans = 0;
    memset(visited, 0, sizeof visited);

    for (int i = 1; i <= P_count; i++) {
        if (!visited[P[i]]) {
            visited[P[i]] = 1;
            int cycleLength = 1, temp = P[P[i]];
            while (!visited[temp]) {
                visited[temp] = 1;
                cycleLength += 1;
                temp = P[temp];
            }

            int numberOperations = calOperations(cycleLength);
            int check = power(numberOperations);
            if (check != cycleLength) {
                cout << -1;
            }

            ans = max(ans, numberOperations);
        }
    }

    cout << ans;
}