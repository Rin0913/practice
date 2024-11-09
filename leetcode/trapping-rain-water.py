class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        prefix = [0] * (n + 1)
        suffix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = max(prefix[i], height[i])
            suffix[-i - 2] = max(suffix[-i - 1], height[-i - 1])
        return sum(max(min(suffix[i], prefix[i]) - height[i], 0) for i in range(n))
