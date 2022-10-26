class Solution:
    def getChar (self, a, b):
        if a == 'R':
            return 'B' if b == 'G' else 'G'
        elif a == 'G':
            return 'R' if b == 'B' else 'B'
        return 'R' if b == 'G' else 'G'
        
    def minFind (self, n, a):
        st, ans = [], 0
        for i in a:
            cur = i
            while st and st[-1] != cur:
                cur = self.getChar(st[-1], cur)
                st.pop()
            st.append(cur)
            
        ans = len(st)
        st.clear()
        for i in reversed(a):
            cur = i
            while st and st[-1] != cur:
                cur = self.getChar(st[-1], cur)
                st.pop()
            st.append(cur)
        
        ans = min(ans, len(st))
        return ans if ans % 2 == 0 else 1