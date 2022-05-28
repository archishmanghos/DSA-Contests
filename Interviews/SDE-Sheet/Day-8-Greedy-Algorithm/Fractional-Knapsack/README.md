[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogN + N)`, SC = `O(1)`

* Notice, that higher the value per weight value of an item, the more optimal it is to take that weight in our knapsack. <br>
* We sort the array in descending order of value per weight values. This is because we are allowed to take a fraction of a weight instead of the whole weight. <br>
* Then we take the minimum of the weight of the item and the remaining weight in knapsack and take the product of the weight and the value per weight and add to our answer. <br>
* The sum of values over all the elements is our answer. <br>


Total Time Taken: `0.46 / 1.58`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Fractional-Knapsack.png)

</details>

</details>
