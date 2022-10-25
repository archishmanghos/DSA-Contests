from queue import Queue
class Solution:
    def steppingNumbers(self, n, m):
        q, ans = Queue(), 1 if n == 0 else 0 
        for i in range(10):
            if i > 0: q.put(str(i))
        
        while q.qsize() > 0:
            num = q.get()
            if int(num) >= n: ans += 1
            if num[-1] > '0':
                x = num + str(ord(num[-1]) - 49)
                if int(x) <= m: q.put(x)
            if num[-1] < '9':
                x = num + str(ord(num[-1]) - 47)
                if int(x) <= m: q.put(x)
        
        return ans