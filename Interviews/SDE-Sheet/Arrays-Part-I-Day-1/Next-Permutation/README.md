The brute method can be calculating every permutaion
and then manually selecting the permutation given in the problem.
The better method is using the STL function next_permutation().
However, the interviewer may not entertain that method lol.

The most optimal and the one that should satisfy the interviewer
follows 4 steps: TC = O(N), SC = O(1)

-> Find the position in the vector, where nums[position] is less than nums[position+1],
  or in other words, the position where the vector is first ascending.
  If such a position, doesn't exist, reverse the vector
  since we have reached the last permutation.

-> If we find a breakpoint, traverse from the back
   and find the position where the element is greater than nums[breakpoint],
   or, nums[position]>nums[breakpoint]. 
   Since, breakpoint exist, this position will always exist.

-> Swap the elements at the breakpoint and the position where the element is greater than nums[breakpoint].

-> Reverse the subarray starting from breakpoint+1 till the end of the vector.