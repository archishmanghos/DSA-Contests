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

<br>
<br>

<h2>121. Best Time to Buy and Sell Stock</h2>

[Link to Problem]https://leetcode.com/problems/best-time-to-buy-and-sell-stock)

<details><summary>Code</summary>

```java
package striver_sde_sheet.array1;

public class P6SBS {
    public int maxProfit(int[] prices) {
        int minStockPrice = prices[0], profit = 0;
        for (int i = 1; i < prices.length; i++) {
            profit = Math.max(profit, prices[i] - minStockPrice);
            minStockPrice = Math.min(minStockPrice, prices[i]);
        }

        return profit;
    }
}
```

</details>
