Optimal Solution: TC = `O(C x C x R)`, SC = `O(R)`

* Use an extra column.<br>
* Set L = 0 to C and set R = L to C nested within L. <br>
* Initialise the extra column to 0 before entering the R loop. <br>
* Find the maximum sum using Kadane's algo in the extra column. <br>
* Do this for every R from L to C, while adding the columns that come to the extra column. <br>
* When the loop for L = 0 comes to an end, initialise the extra column to 0 and start again. <br>
* Finally the answer is the maximum over every maximum column value for all iterations, found using Kadane's Algo. <br>

Total Time Taken: `0.21/1.16`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG-Maximum-sum-Rectangle.png)

</details>