long long minimumTime(vector<int> &time, int totalTrips) {
    long long minn = 1000000000;
    for (long long i: time) {
        minn = min(i, minn);
    }

    long long low = 1, high = minn * totalTrips;
    while (low < (high - 1)) {
        long long mid = low + (high - low) / 2;
        long long trips = 0;
        for (long long i: time) {
            trips += (mid / i);
        }
        if (trips < totalTrips) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    long long trips = 0;
    for (long long i: time) {
        trips += (low / i);
    }

    if (trips >= totalTrips) {
        return low;
    }
    return high;
}