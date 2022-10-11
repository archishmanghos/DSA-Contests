class Solution:
    def decodedString(self, s):
        v1, v2, ans, num, st, i = [], [], "", "", "", 0
        while i < len(s):
            if ord(s[i]) >= 48 and ord(s[i]) <= 57:
                if st:
                    if len(v1) < len(v2): v1.append(st)
                    else: v1[-1] += st
                st = ""
                num += s[i]
            elif s[i] == '[':
                v2.append(int(num))
                num = ""
            elif s[i] == ']':
                if st:
                    if len(v1) < len(v2): v1.append(st)
                    else: v1[-1] += st
                st, temp = "", ""
                for j in range(v2[-1]): temp += v1[-1]
                v1.pop()
                v2.pop()
                if v1: v1[-1] += temp
                else: v1.append(temp)
            else:
                st += s[i]
            i += 1
            if not v2 and v1:
                ans += v1[-1]
                v1.pop()
        
        return ans
