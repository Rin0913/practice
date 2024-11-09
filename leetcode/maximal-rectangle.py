class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        n, m = len(matrix), len(matrix[0])
        ans = 0
        height = [0] * m
        left = [0] * m
        right = [m] * m

        for i in range(n):
            cur_left, cur_right = 0, m

            for j in range(m):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
            
            for j in range(m):
                if matrix[i][j] == '1':
                    left[j] = max(left[j], cur_left)
                else:
                    left[j] = 0 # invalid, minimum number
                    cur_left = j + 1
 
            for j in range(m - 1, -1 , -1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], cur_right)
                else:
                    right[j] = m # invalid, maximum number
                    cur_right = j
            
            for j in range(m):
                ans = max(ans, (right[j] - left[j]) * height[j])
        return ans
