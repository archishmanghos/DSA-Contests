Optimal Solution: TC = O(N), SC = O(21)

> We traverse the array and the count the occurences of tops[i] and bottoms[i] and the elements which are same in both the arrays. <br>
> We run the loop from 1 to 6, if countA[i]+countB[i]-same[i] is equal to the size of the array, we return the answer <br>
> The answer is min(countA[i]+countB[i])-same[i]. <br>

Runtime: 120 ms, faster than 87.18% <br>
Memory Usage: 111.6 MB, less than 72.27%