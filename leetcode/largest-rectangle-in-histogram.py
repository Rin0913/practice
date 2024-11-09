class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = [-1] # To make sure stack not empty.
        heights.append(0) # To make sure everything will be popped out and give stack[-1] an exact value.
        for i in range(len(heights)):
            # item in stack is increasing
            while stack and heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                width = i - stack[-1] - 1
                max_area = max(max_area, h * width)
            stack.append(i)
        return max_area
