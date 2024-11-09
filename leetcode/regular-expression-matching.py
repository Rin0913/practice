class Solution:
    def check(self, i, j):
        if i < 0 or j < 0:
            return False
        if i == 0 and j == 0:
            self.dp[(i, j)] = True
            return True
        if (i, j) in self.dp:
            return self.dp[(i, j)]
        cur_c = self.s[i - 1] if i - 1 >= 0 else None
        cur_p = self.p[j - 1] if j - 1 >= 0 else None
        last_p = self.p[j - 2] if j - 2 >= 0 else None
        if cur_p == '*':
            self.dp[(i, j)] = self.check(i, j - 2) or (last_p in ['.', cur_c] and self.check(i - 1, j))
            return self.dp[(i, j)]
        if cur_p == '.':
            self.dp[(i, j)] = self.check(i - 1, j - 1)
            return self.dp[(i, j)]
        self.dp[(i, j)] = cur_c == cur_p and self.check(i - 1, j - 1)
        return self.dp[(i, j)]

    def isMatch(self, s: str, p: str) -> bool:
        self.s = s
        self.p = p
        self.dp = {}
        self.check(len(s), len(p))
        for i in self.dp:
            print(i, s[:i[0]], p[:i[1]], self.dp[i])
        return self.check(len(s), len(p))
