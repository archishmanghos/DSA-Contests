<h2>2483. Minimum Penalty for a Shop</h2>

[Link to Problem](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

<details><summary>Codes</summary>

```java

public class LC2483 {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] suffix = new int[n];

        suffix[n - 1] = customers.charAt(n - 1) == 'Y' ? 1 : 0;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (customers.charAt(i) == 'Y' ? 1 : 0);
        }

        int min_penalty = (int) 1e9, answer = -1, closed_shops = 0;
        for (int i = 0; i < n; i++) {
            int penalty = closed_shops + suffix[i];
            if (penalty < min_penalty) {
                min_penalty = penalty;
                answer = i;
            }

            closed_shops += customers.charAt(i) == 'N' ? 1 : 0;
        }

        if (closed_shops < min_penalty) return n;
        return answer;
    }
}

```

</details>