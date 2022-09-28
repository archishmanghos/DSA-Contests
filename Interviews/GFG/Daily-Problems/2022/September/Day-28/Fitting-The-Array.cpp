bool isFit(int arr[], int brr[], int n) {
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        ms.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        auto ub = ms.upper_bound(brr[i]);
        if (ub == ms.begin()) return false;
        ub--;
        int x = *ub;
        ms.erase(ub);
    }

    return true;
}