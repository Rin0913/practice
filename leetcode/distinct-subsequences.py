class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            # Once the t reachs the end, the substring is obtained.
            dp[i][m] = 1
        dp[0][0] = 0
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if s[i] == t[j]:
                    dp[i][j] += dp[i + 1][j + 1]
                dp[i][j] += dp[i + 1][j]
        return dp[0][0]
