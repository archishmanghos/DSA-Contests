[Link to problem on Leetcode](https://leetcode.com/problems/paint-house-iii/)


<details><summary>Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(M x N x M)`, SC = `O(M x N x M)`  

- Okay, so I will guide you how I thought about it.
- When I read the words minimise the cost->
- Possible topics -> DP, Binary Search, Graph
- But it does not look like graph. So Graph X
- Constraints gave me idea of trying DP.

- In DP, only those parameters should be there which are necessary for making answer of a state unique.
- What I mean by it is :- If I decide the value of parameters, my answer should be unique.
- It does not matter where I come from, If I reach that state with those parameters, my answer is unique.

- For deciding which parameters to keep in DP State,
- For every index, if it is not already colored last summer, we are deciding
- Should we pick this color or not.
- This gives a Knapsack DP Pattern in which we have to make a decision for every index.
- => Index will be a parameter of DP

- What color to choose or not choose also depends on the color of last house.
- If the color is same, new neighbourhood is not formed otherwise new neighbourhood is formed.
- => Color of parent is also a parameter of DP

- Our choice of color for a house also depends on value of target,
- If Target is big, we will give different color than parent.
-Otherwise same color as parent
- => Target will also be a parameter of DP

- So, by now we have done 2 steps
- -> (i) Identify DP Pattern
- -> (ii) Make DP State (Which parameters will be there in DP )

[Editorial Credits](https://leetcode.com/problems/paint-house-iii/discuss/2252875/EASIEST-DP-GUARANTEE-Beginner-Friendly)

Runtime: `158 ms`, faster than `39.89%`<br>
Memory Usage: `18.3 MB`, less than `25.80%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1473.png)

</details>

</details>