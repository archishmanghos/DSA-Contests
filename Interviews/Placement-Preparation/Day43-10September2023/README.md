<h2>1359. Count All Valid Pickup and Delivery Options</h2>

[Link to Problem](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options)

<details><summary>Codes</summary>

```java
public class LC1359 {
    public int countOrders(int n) {
        long answer = 1, mod = (int) 1e9 + 7;
        for (int i = 1; i <= 2 * n; i++) {
            if (i % 2 == 0) answer = (answer * (i / 2)) % mod;
            else answer = (answer * i) % mod;
        }

        return (int) answer;
    }
}
```

</details>
