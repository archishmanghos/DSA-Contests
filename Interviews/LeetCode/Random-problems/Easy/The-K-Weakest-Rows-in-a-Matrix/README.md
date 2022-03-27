Optimal Solution: TC = O(N x M x log(NM)), SC = O(1)

> One of algos included say to apply Heap + BS. I have done using sorting. <br>
> We can take an the idea that when a vector is sorted, it is done on the basis of the 1st element and if they are equal, the second element is chosen. <br>
> We can append the index of the row to their corresponding rows in the matrix. <br>
> The rest is simple sorting, the vectors sort lexicographically and hence, automatically the lesser the count of 1, the more closer to the start of the vector, the row appears. <br>
> After sorting, we just take the last elements of the first k rows of the matrix into our answer vector. <br>
> The idea is originally from [this leetcode post](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/1201679/C%2B%2B-Python3-No-Heap-No-BS-Simple-Sort-99.20). So full credits to the author for such an unique solution!<br>

Runtime: `12 ms`, faster than `83.53%`<br>
Memory Usage: `10.4 MB`, less than `91.37%`