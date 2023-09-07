<h2>42. Trapping Rain Water</h2>

[Link to Problem](https://leetcode.com/problems/trapping-rain-water)

<details><summary>Codes</summary>

```java
class LC42 {
    public int trap(int[] height) {
        int water_trapped = 0, i = 0, j = height.length - 1, maxL = height[0], maxR = height[height.length - 1];
        while (i < j) {
            if (maxL <= maxR) {
                i++;
                water_trapped += Math.max(maxL - height[i], 0);
                maxL = Math.max(maxL, height[i]);
            } else {
                j--;
                water_trapped += Math.max(maxR - height[j], 0);
                maxR = Math.max(maxR, height[j]);
            }
        }

        return water_trapped;
    }
}
```

</details>
