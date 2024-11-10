# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def calc(root):
            """
            return (single longest path, all pathes with disconnected included)
            """
            if root.left is None and root.right is None:
                return (root.val, root.val)
            if root.left is None and root.right:
                r1, r2  = calc(root.right)
                v1 = max(r1 + root.val, root.val)
                return (v1, max(v1, r2))
            if root.left and root.right is None:
                l1, l2  = calc(root.left)
                v2 = max(l1 + root.val, root.val)
                return (v2, max(v2, l2))
            l1, l2  = calc(root.left)
            r1, r2  = calc(root.right)
            v1 = max(r1 + root.val, root.val)
            v2 = max(l1 + root.val, root.val)
            return (max(v1, v2), max(v1, v2, r2, l2, v1 + v2 - root.val))
        return calc(root)[1]
