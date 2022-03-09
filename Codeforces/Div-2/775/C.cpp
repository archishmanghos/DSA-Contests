int32_t main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N + 2, vector<int>(M + 2));
    set<int> colours;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            colours.insert(A[i][j]);
        }
    }

    int totalColours = *colours.rbegin();
    vector<vector<int>> colourX(totalColours + 2), colourY(totalColours + 2), prefColourX(
            totalColours + 2), prefColourY(totalColours + 2);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            colourX[A[i][j]].push_back(i);
            colourY[A[i][j]].push_back(j);
        }
    }

    for (int i = 1; i <= totalColours; i++) {
        if (colourX[i].size() == 0) {
            continue;
        }
        sort(colourX[i].begin(), colourX[i].end());
        sort(colourY[i].begin(), colourY[i].end());
    }

    for (int i = 1; i <= totalColours; i++) {
        if (colourX[i].size() == 0) {
            continue;
        }
        prefColourX[i].push_back(colourX[i][0]);
        for (int j = 1; j < colourX[i].size(); j++) {
            prefColourX[i].push_back(colourX[i][j] + prefColourX[i][j - 1]);
        }
        prefColourY[i].push_back(colourY[i][0]);
        for (int j = 1; j < colourY[i].size(); j++) {
            prefColourY[i].push_back(colourY[i][j] + prefColourY[i][j - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= totalColours; i++) {
        if (colourX[i].size() == 0) {
            continue;
        }
        int szX = colourX[i].size();
        for (int j = 0; j < szX; j++) {
            ans += prefColourX[i][szX - 1] - prefColourX[i][j] - (szX - j - 1) * colourX[i][j];
        }

        int szY = colourY[i].size();
        for (int j = 0; j < szY; j++) {
            ans += prefColourY[i][szY - 1] - prefColourY[i][j] - (szY - j - 1) * colourY[i][j];
        }
    }

    cout << ans;

    return 0;
}