<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/delete-node-in-a-bst/)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(logN)`, SC = `O(1)`

- Find the node to be deleted. <br>
- If such a node doesn't exist, return the root, else find the node and its parent.
- Let the node to be deleted is X.
- If X is the root of the given tree, then, 

> - If X has no left and right child, return NULL.
> - If X has either of left or right child, return the other child.
> - If X has both left and right child, attach the right child to the right of the right-most child of the left child. Or we can also attach the left child to the left of the left-most child of the right child.
>

- If X is not the root of the given tree, then,

> - Let us take dirchild the child of the parent node which corresponds to X. For eg, if the left child of parent node is X, then dirchild is left and vice-versa.
> - If X has no left and right child, make the dirchild of parent NULL.
> - If X has either of left and right child, attach the non-NULL child to the dirchild of parent node.
> - If X has both left and right child, attach the right child to the right of the right-most child of the left child. Or we can also attach the left child to the left of the left-most child of the right child.
> - Connect the dirchild of parent node with the left child of X.
>

- Finally, return the root.


Runtime: `58 ms`, faster than `41.09%`<br>
Memory Usage: `32.8 MB`, less than `36.04%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/450.png)

</details>

</details>