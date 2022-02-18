void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = m; i < (m + n); i++) {
        nums1[i] = nums2[i - m];
    }

    int gap = (m + n);
    while (gap > 1) {
        gap = (gap + 1) / 2;
        int i = 0, j = gap;
        while (j < (m + n)) {
            if (nums1[i] > nums1[j]) {
                swap(nums1[i], nums1[j]);
            }
            i += 1, j += 1;
        }
    }
}