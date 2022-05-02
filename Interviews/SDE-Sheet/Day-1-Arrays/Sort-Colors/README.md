[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/sort-colors/)


<details><summary>Hints</summary>

* Think of a 3-pointer approach. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* This problem uses [Dutch National Flag Algorithm](https://en.wikipedia.org/wiki/Dutch_national_flag_problem#:~:text=One%20algorithm%20is%20to%20have,top%20of%20the%20middle%20group.). <br>
* We take 3 pointers pointing to 0, 0 and N - 1. Let's name them low, mid and high. <br>
* We design the algorithm such that, [0 to low - 1] will contain 0s, [low to high] will contain 1s and [high + 1 to N - 1] will conatains 2s. <br>
* We handle 3 cases.<br>
 
> 1. `nums[mid] == 0`: We swap `nums[low]` and `nums[mid]` and increase both low and mid.<br>
> 2. `nums[mid] == 1`: We increase mid. <br>
> 3. `nums[mid] == 2`: We swap `nums[mid]` and `nums[high]` and decrease high. <br>
>

* Finally, we will have our sorted array. <br>

</details>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `8.3 MB`, less than `70.92%`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/75.png)

</details>