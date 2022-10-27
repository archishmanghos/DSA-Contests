class Solution:
	def leafNodes (self, arr, N):
		st, ans, i, j = [], [], 0, 1
        while j < N:
            if arr[j] < arr[i]:
                st.append(arr[i])
            else:
                leaf = 0
                while len(st) and arr[j] > st[-1]:
                    st.pop()
                    leaf = 1
                if leaf: ans.append(arr[i])
            i, j = i + 1, j + 1
        
        ans.append(arr[-1])
        return ans