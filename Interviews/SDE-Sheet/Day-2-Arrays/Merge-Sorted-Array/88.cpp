void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    for(int i = 0; i < n; i++){
        nums1[i + m] = nums2[i];
    }
    
    int gap = m + n;
    while(gap > 1){
        gap = (gap + 1) >> 1;
        int i = 0, j = gap;
        while(j < m + n){
            if(nums1[i] > nums1[j]) swap(nums1[i], nums1[j]);
            i += 1, j += 1;
        }
    }
}