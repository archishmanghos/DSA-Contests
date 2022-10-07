class Solution:
    def flatten(self, root):
        st = []
        st.append(root)
        
        while st:
            curNode = st.pop()
            if curNode.right:
                st.append(curNode.right)
            if curNode.left:
                st.append(curNode.left)
            
            if st:
                curNode.right = st[-1]
            curNode.left = None