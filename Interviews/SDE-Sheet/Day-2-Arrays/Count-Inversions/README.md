[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Code Studio](https://www.codingninjas.com/codestudio/problems/count-inversions_615)


<details><summary>Hints</summary>

* Try thinking from the back and come up with a solution that involves ordered set. <br>
* Now try to modify the solution with a merge sort algo. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(NlogN)`, SC = `O(N)`

* Implement merge sort algorithm as it is. <br>
* Now, when merging 2 arrays, if we are taking an element of the 2nd array, it means, every element from the current position of 1st array till the end of the 1st array is greater than the current element of the 2nd array. <br>
* Hence, we add to our answer the count of elements to the right of current element of the 1st array. <br>
* Adding up all such instances, we get our answer. <br>

</details>


Runtime: `487ms`. <br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Code-Studio/Count-Inversions.png)

</details>