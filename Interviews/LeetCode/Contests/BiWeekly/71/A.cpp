int minimumSum(int num) {
    string n1 = integertostring(num);
    int answer = 100000;
    for (int i = 0; i < (1 << 4); i++) {
        string temp = "", tempN = "";

        for (int j = 0; j < 4; j++) {
            if ((i & (1 << j)) != 0) {
                temp += n1[j];
            } else {
                tempN += n1[j];
            }
        }

        sort(temp.begin(), temp.end());
        sort(tempN.begin(), tempN.end());
        int temp1 = stringtointeger(temp);
        int temp2 = stringtointeger(tempN);
        answer = min(answer, temp1 + temp2);

    }
    return answer;
}