class MyCalendar {
private:
    map<int, int> interval;
public:
    MyCalendar() {
        interval.clear();
        interval[-1] = -1;
    }

    bool book(int start, int end) {
        if (interval.find(start) != interval.end()) return false;
        if (interval.size() == 0) {
            interval[start] = end;
            return true;
        }

        auto it = interval.lower_bound(start);
        int nextStartTime = INT_MAX, prevStartTime = -1;
        if (it == interval.end()) {
            it--;
            prevStartTime = (*it).first;
        } else if (it == interval.begin()) {
            nextStartTime = (*it).first;
        } else {
            nextStartTime = (*it).first;
            it--;
            prevStartTime = (*it).first;
        }
        if (interval[prevStartTime] <= start and end <= nextStartTime) {
            interval[start] = end;
            return true;
        }
        return false;
    }
};