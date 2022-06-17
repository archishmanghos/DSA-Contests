[Link to problem on Leetcode](https://leetcode.com/problems/product-of-array-except-self/)

My Solution: TC = `O(N)`, SC = `O(N)`

* Take 2 arrays. Let them be array1 and array2. <br>
* We store the prefix products in array1 and suffix products in array2.<br>
* Then we traverse from start to end and multiply the prefix product till the current index - 1 and the suffix product till the current index + 1. <br>
* This final array will the answer. <br>

Runtime: `34 ms`, faster than `58.61%` <br>
Memory Usage: `25.1 MB`, less than `25.70%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/238-A.png)

</details>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* We can delete the arrays portion totally. <br>
* We take 2 variables instead which stores the product from start and the product from end. <br>
* While traversing, we multiply the current elemet by the product from start and the element at a similar position from the back by the end product. <br>
* At the end of the cycle, the final vector will contain the actual product values. <br>

Runtime: `27 ms`, faster than `84.39%` <br>
Memory Usage: `24.1 MB`, less than `56.86%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/238-B.png)

</details>