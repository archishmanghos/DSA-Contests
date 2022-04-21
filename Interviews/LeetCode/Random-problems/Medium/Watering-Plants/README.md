[Link to the problem](https://leetcode.com/problems/watering-plants/)


Optimal Solution: TC = O(N), SC = O(1)

* Traverse the array, if the water required is less than or equal to the capacity, deduct the capacity and increment the answer by 1. <br>
* If the water required is greater than the capacity, increment the answer by 2 times the current index, which is the number of steps required to go and fetch the water and another increment to make it to the current index. Also change the capacity to [original capacity - the current requirement by the plant.] <br>

Runtime: 9 ms, faster than 20.91%<br>
Memory Usage: 8.3 MB, less than 82.15%<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/2079.png)

</details>