[Link to problem](https://leetcode.com/problems/minimum-falling-path-sum/)


Optimal Solution: TC = `O(N x N)`, SC = `O(N x N)`

* We devise a recursive DP solution. <br>
* For every cell in top row, we send the cell to the recursive function. <br>
* The function checks if the cell is valid or not. <br>

> * If the cell is valid, we check if the sum has already been calculated or not, if calculated return the sum. Else, call the function for the 3 paths that we can go to and take the minimum of the paths. Return the minimum after storing the value in our cache array. <br>
> * If the cell is invalid, we check if the index has reached the last row or not, if it has, we return 0, else we return a high enough number to not get considered. <br>
>
* The minimum over all values of the 1st row will give our answer. <br>

Runtime: `19 ms`, faster than `51.04%`<br>
Memory Usage: `10.3 MB`, less than `44.67%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/931.png)

</details>