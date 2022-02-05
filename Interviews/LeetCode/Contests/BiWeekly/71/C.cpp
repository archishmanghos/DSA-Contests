int cost(string s, int &startAt, int &moveCost, int &pushCost) {
    int ans = 0, start = startAt;
    for (int i = 0; i < s.size(); i++) {
        if (start != (s[i] - '0')) {
            ans += (moveCost + pushCost);
        } else {
            ans += pushCost;
        }
        start = (s[i] - '0');
    }
    return ans;
}

int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    int minutes = targetSeconds / 60;
    int seconds = targetSeconds % 60;

    if (minutes == 100) {
        minutes = 99;
        seconds += 60;
    }

    if (minutes == 0) {
        string ans = integertostring(seconds);
        return cost(ans, startAt, moveCost, pushCost);
    }

    string possibility = integertostring(minutes);
    string secondS = integertostring(seconds);
    if (secondS.size() == 1) {
        possibility += '0';
    }
    possibility += secondS;
    int ans = cost(possibility, startAt, moveCost, pushCost);

    if (seconds + 60 < 100) {
        minutes -= 1;
        seconds += 60;
    }

    if (minutes > 0) {
        possibility = integertostring(minutes);
    } else {
        possibility = "";
    }
    secondS = integertostring(seconds);

    if (secondS.size() == 1) {
        possibility += '0';
    }
    possibility += secondS;
    ans = min(ans, cost(possibility, startAt, moveCost, pushCost));

    return ans;
}