[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/matrix-exponentiation2711/1/)


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(logN)`, SC = `O(4logN)`

* Classic problem of Matrix exponentiation.<br>
* The equation gets reduced to `[[F(n)],[F(n - 1)]] = ([[1, 1], [1, 0]] ^ (n - 1)) x [[F(1)],[F(0)]]`.<br>
* We can find the part of `([[1, 1], [1, 0]] ^ (n - 1))` using binary exponentiation and somewhat Dynamic Programming and then we can find the value of F(n) from the expression. <br> 
* [Link to a Nice Video Tutorial if you are new to the topic](https://www.youtube.com/watch?v=EEb6JP3NXBI).<br>


Total Time Taken: `0.04/1.54`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Matrix-Exponentiation.png)

</details>

</details>