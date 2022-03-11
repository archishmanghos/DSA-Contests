double champagneTower(int poured, int query_row, int query_glass) {
    double ans = 0.0;
    vector <vector<double>> ansAll(query_row + 2, vector<double>(query_row + 2));
    ansAll[0][0] = (double) poured;
    for (int i = 0; i <= query_row; i++) {
        for (int j = 0; j <= i; j++) {
            double x = (ansAll[i][j] - 1) / 2.0;
            if (x > 0) {
                ansAll[i + 1][j] += x;
                ansAll[i + 1][j + 1] += x;
            }
        }
    }

    return min(1.0, ansAll[query_row][query_glass]);
}