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

<br>
<br>

<h2>36. Valid Sudoku</h2>

[Link to Problem](https://leetcode.com/problems/valid-sudoku/description/)

<details><summary>Codes</summary>

```java

public class LC36 {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            boolean[] row = new boolean[10];
            boolean[] column = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && row[((int) board[i][j] - 48)]) return false;
                if (board[j][i] != '.' && column[((int) board[j][i] - 48)]) return false;
                if (board[i][j] != '.') row[((int) board[i][j] - 48)] = true;
                if (board[j][i] != '.') column[((int) board[j][i] - 48)] = true;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                boolean[] check = new boolean[10];
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        if (check[((int) board[k][l] - 48)]) return false;
                        check[((int) board[k][l] - 48)] = true;
                    }
                }
            }
        }

        return true;
    }
}

```

</details>

<br>
<br>

<h2>238. Product of Array Except Self</h2>

[Link to Problem](https://leetcode.com/problems/product-of-array-except-self/description/)

<details><summary>Codes</summary>

```java

public class LC238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        int current_product = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = current_product;
            current_product *= nums[i];
        }

        current_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= current_product;
            current_product *= nums[i];
        }

        return answer;
    }
}

```

</details>