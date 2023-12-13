package striver_sde_sheet.array2;

public class LC88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n >= 0) System.arraycopy(nums2, 0, nums1, m, n);

        int gap = m + n;
        do {
            gap = (gap + 1) / 2;
            int i = 0, j = i + gap;

            while (j < m + n) {
                if (nums1[i] > nums1[j]) {
                    nums1[i] = nums1[i] + nums1[j];
                    nums1[j] = nums1[i] - nums1[j];
                    nums1[i] = nums1[i] - nums1[j];
                }

                i++; j++;
            }
        } while (gap > 1);
    }
}
