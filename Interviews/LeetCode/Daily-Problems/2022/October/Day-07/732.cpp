class MyCalendarThree {
public:
    map<int, int> interval;
    MyCalendarThree() {
        interval.clear();
    }

    int book(int start, int end) {
        interval[start] += 1;
        interval[end] -= 1;

        int cur = 0, ans = 0;
        for (auto i : interval) {
            cur += i.second;
            ans = max(ans, cur);
        }

        return ans;
    }
};