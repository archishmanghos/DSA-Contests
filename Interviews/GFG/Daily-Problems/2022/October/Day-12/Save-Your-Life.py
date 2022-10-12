class Solution:
    def maxSum (self, w, x, b, n):
        summ , maxSum, ans, s = 0, 0, "", ""
        for i in range(len(w)):
            val = ord(w[i])
            for j in range(n):
                if x[j] == w[i]:
                    val = b[j]
                    break
            
            summ += val
            s += w[i]
            if summ < 0:
                summ, s = 0, ""
            if summ > maxSum:
                maxSum, ans = summ, s
        
        if not ans:
            lowChar, minn = 'a', -1e9
            for i in range(n):
                if b[i] > minn:
                    minn = b[i]
                    lowChar = x[i]
            
            ans += lowChar
        
        return ans