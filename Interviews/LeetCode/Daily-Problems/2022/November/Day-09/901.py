class StockSpanner:

    def __init__(self):
        self.st = []

    def next(self, price: int) -> int:
        crushed = 0
        while len(self.st) > 0 and self.st[-1][0] <= price:
            crushed += 1 + self.st[-1][1]
            self.st.pop()

        self.st.append([price, crushed])
        return 1 + crushed
