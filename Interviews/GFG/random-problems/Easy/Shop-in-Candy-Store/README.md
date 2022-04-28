[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1)

Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

* Sort the given array. <br>
* For the 1st answer, greedily take the elements from the beginning of the array and decrease the right pointer by k, till left-pointer crosses right-pointer. <br>
* For the 2nd answer, greedily take the elements from the end of the array and increase the left pointer by k, till left-pointer crosses right-pointer. <br>

Total Time Taken: `0.04/1.92`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Shop%20in%20Candy%20Store.png)

</details>