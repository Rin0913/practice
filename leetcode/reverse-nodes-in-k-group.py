# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverseGroup(head, k):
            group = [None] * k
            h = head
            for i in range(k):
                if h == None:
                    return None
                group[i] = h
                h = h.next
            group[0].next = group[-1].next
            for i in range(k - 1, 0, -1):
                group[i].next = group[i - 1]
            
            return group[-1]
        
        prevHead = None
        newHead = None
        while True:
            head = reverseGroup(head, k)
            if not head:
                break
            if prevHead:
                prevHead.next = head
            newHead = head if newHead == None else newHead
            for i in range(k):
                if head.next:
                    prevHead = head
                    head = head.next
                else:
                    break
            
        return newHead or head
