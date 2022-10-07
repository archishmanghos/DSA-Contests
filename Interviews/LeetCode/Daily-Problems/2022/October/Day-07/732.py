class MyCalendarThree:
    def __init__(self):
        self.interval = {}

    def book(self, start: int, end: int) -> int:
        self.interval[start] = self.interval.get(start, 0) + 1
        self.interval[end] = self.interval.get(end, 0) - 1
            
        cur, ans = 0, 0
        for i in sorted(self.interval):
            cur += self.interval[i]
            ans = max(ans, cur)
        
        return ans