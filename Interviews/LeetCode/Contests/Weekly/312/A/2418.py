class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        ans = [[]]
        for i in range(len(names)):
            temp = [heights[i], names[i]]
            ans.append(temp)
        ans.sort(reverse = True)
        finalAns = []
        for j in range(len(names)):
            finalAns.append(ans[j][1])
        return finalAns