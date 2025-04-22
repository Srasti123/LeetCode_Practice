class Solution:
    def __init__(self):
        self.dp = [[0]*10001 for _ in range(15)]
        self.pr = [[0]*10001 for _ in range(15)]
        self.tot = [0]*15
        self.mod = 10**9 + 7
        self.mx = 0
        self.n = 0

    def get(self, la, cn):
        self.tot[cn] += 1
        for p in range(2*la, self.mx+1, la):
            self.get(p, cn+1)

    def idealArrays(self, n, maxValue):
        self.n, self.mx = n, maxValue
        for i in range(1, 10001):
            self.dp[1][i] = 1
            self.pr[1][i] = i

        for i in range(2, 15):
            for j in range(i, 10001):
                self.dp[i][j] = self.pr[i-1][j-1]
                self.pr[i][j] = (self.dp[i][j] + self.pr[i][j-1]) % self.mod
                self.dp[i][j] %= self.mod

        ans = self.mx
        for i in range(1, self.mx + 1):
            self.get(i, 1)

        for i in range(2, 15):
            x = self.tot[i] * self.dp[i][n] % self.mod
            ans = (ans + x) % self.mod

        return ans