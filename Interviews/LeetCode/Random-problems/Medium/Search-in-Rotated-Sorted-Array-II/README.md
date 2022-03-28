My Solution: TC ≈ `O(logN)` = `O(N)`, SC = `O(1)`

> My solution finds the position of the pivot which takes linear time if the array has 0 rotations. <br>
> It then finds target using binary search in the first part of the array till pivot and next part of the array after pivot. <br>
> The optimal solution is described [here](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C++-solution-(o(logn)-on-average-o(n)-worst-case)/112460)<br>

Runtime: `11 ms`, faster than `41.14%`<br>
Memory Usage: `13.9 MB`, less than `90.12%` 