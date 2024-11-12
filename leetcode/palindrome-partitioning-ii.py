class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        is_palindrome = [[0] * n for i in range(n)]
        for i in range(n):
            is_palindrome[i][i] = 1
        for k in range(n):
            for i in range(n):
                j = i + k
                if j >= n:
                    break
                if i + 1 <= j - 1:
                    is_palindrome[i][j] = is_palindrome[i + 1][j - 1] and s[i] == s[j]
                else:
                    is_palindrome[i][j] = s[i] == s[j]
                # print(s[i:j + 1], is_palindrome[i][j])
        dp = [float("inf")] * (n)
        dp[0] = 0
        for i in range(1, n):
            dp[i] = dp[i - 1] + 1
            for j in range(i):
                if is_palindrome[j][i]:
                    # print(s[i:j + 1], i, j, is_palindrome[i][j])
                    if j == 0:
                        dp[i] = 0
                    else:
                        dp[i] = min(dp[i], dp[j - 1] + 1)
        # print(dp)
        return dp[n - 1]
