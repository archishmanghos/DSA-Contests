Optimal Solution: TC = O(N), SC = O(1)

> We store the end indices of each character of the string after traversing the string once. <br>
> We then traverse the string and maintain 2 pointers, start and end. <br>
> We extend the end pointer using the last index of the current character being traversed. <br>
> When the end equals i, it means we can end the partition here, hence we push [end - start + 1] to our answer vector. <br>

Runtime: 0 ms, faster than 100.00% <br>
Memory Usage: 6.7 MB, less than 64.08%