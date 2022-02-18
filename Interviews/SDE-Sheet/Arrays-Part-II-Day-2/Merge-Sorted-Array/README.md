Brute Solution: TC = O(N + M), SC = O(N + M)

We can take a new array of size (N + M) and 2 pointers, first set to index 0 of first array and the second set to index 0 of second array. We can iterate till both i and j exceed m and n and add to the new array min(nums1[i], nums2[j]) and increase the corresponding pointer.

Optimal Solution: TC = O(logN), SC = O(1)

We copy the second array and append to the end of the first array. We then take 2 pointers, 1 pointing to index 0 of nums1 and another a gap of (m + n)/2. 

We then iterate till (gap > 0), and swap nums1[i] and nums1[j] and after j reaches end of nums1, we decrement gap by a factor of 2 and continue.
[Note: Decrement such that gap becomes ceil(gap/2)] 

Runtime: 3 ms, faster than 68.40%
Memory Usage: 9.1 MB, less than 72.74%