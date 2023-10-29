<h2>75. Sort Colors</h2>

[Link to Problem](https://leetcode.com/problems/sort-colors)

<details><summary>Code</summary>

```java
package striver_sde_sheet.array1;

public class P5SA012 {
    private void swap(int[] a, int i, int j) {
        if (i == j) return;
        a[i] = a[i] + a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
    }

    public void sortColors(int[] nums) {
        int low = 0, mid = 0, high = nums.length - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums, mid, high);
                high--;
            }
        }
    }
}
```

</details>
