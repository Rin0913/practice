class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stk = []
        for i in s:
            if i == '(':
                stk.append(['(', 0])
            elif i == ')':
                if stk and stk[-1][0] == '(':
                    item = stk.pop()
                    if stk and stk[-1][0] in ['(', '']:
                        stk[-1][1] += item[1] + 2
                    else:
                        stk.append(['', item[1] + 2])
                else:
                    stk.append([")", 0])
        ans = 0
        for i in stk:
            ans = max(ans, i[1])
        return ans
