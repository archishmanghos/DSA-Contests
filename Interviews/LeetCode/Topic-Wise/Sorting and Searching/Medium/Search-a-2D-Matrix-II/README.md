<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/search-a-2d-matrix-ii/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(NlogM)`, SC = `O(1)` 

- For every row, perform binary search on it and check if target exists or not.


Runtime: `524 ms`, faster than `8.44%`<br>
Memory Usage: `14.9 MB`, less than `21.86%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/240-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N + M)`, SC = `O(1)`  

- Search from the top-right element and reduce the search space by one row or column at each time.
- Suppose we want to search for 12 in the above matrix. compare 12 with the top-right element nums[0][4] = 15.
- Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that column are greater than or equal to 15. Now we reduce the search space by one column (the last column).
- We further compare 12 with the top-right element of the remaining matrix, which is nums[0][3] = 11.
- Since 12 > 11, 12 cannot appear in the row of 11 since all elements in this row are less than or equal to 11 (the last column has been discarded). 
- Now we reduce the search space by one row (the first row).
- We move on to compare 12 with the top-right element of the remaining matrix, which is nums[1][3] = 12. 
- Since it is equal to 12, we return true.

[Editorial Credits](https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66139/C%2B%2B-search-from-top-right)


Runtime: `193 ms`, faster than `41.73%`<br>
Memory Usage: `14.8 MB`, less than `88.55%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/240-B.png)

</details>

</details>