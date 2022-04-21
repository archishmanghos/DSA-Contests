[Link to the problem on GFG](https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1) <br>


Optimal Solution: TC = `O(N)`, SC = `O(N)`

* Remove adjacent characters greedily. <br>
* If there was atleast one set of adjacent characters removed, call for the function with the new string again, else return the new string. <br>

Total Time Taken: `0.27/1.32`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Recursively%20remove%20all%20adjacent%20duplicates.png)

</details>