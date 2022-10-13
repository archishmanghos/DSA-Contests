class Solution:
    def equalFrequency(self, word: str) -> bool:
        freq, finalList = [0 for i in range(26)], []
        for i in word:
            freq[ord(i) - 97] += 1
        for i in range(26):
            if freq[i] > 0:
                finalList.append(freq[i]);
        finalList.sort()
        if len(finalList) < 2:
            return True
        if finalList[0] == finalList[-2] and finalList[-2] + 1 == finalList[-1]:
            return True
        if (finalList[0] == finalList[-2] and finalList[-1] == 1) or (finalList[0] == 1 and finalList[1] == finalList[-1]):
            return True
        return False