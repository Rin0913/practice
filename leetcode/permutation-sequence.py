class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        fac = [1, 1]
        for i in range(2, 10):
            fac.append(fac[-1] * i)
        digits = [i for i in range(1, n + 1)]
        ans = ""
        for i in range(n - 1, -1, -1):
            j = 0
            while k - fac[i] > 0:
                k -= fac[i]
                j += 1
            # print(j, k, fac[i])
            ans += str(digits[j])
            del digits[j]
        return ans
