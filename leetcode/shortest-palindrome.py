class Solution:
    def shortestPalindrome(self, s: str) -> str:
        base = 31
        mod = 10**9 + 7
        
        n = len(s)
        left_hash, right_hash = 0, 0
        base_power = 1
        longest_palindrome_prefix = 0
        
        for i in range(n):
            left_hash = (left_hash * base + ord(s[i])) % mod
            right_hash = (right_hash + ord(s[i]) * base_power) % mod
            base_power = (base_power * base) % mod
            
            if left_hash == right_hash:
                longest_palindrome_prefix = i + 1
        
        add_suffix = s[longest_palindrome_prefix:][::-1]
        return add_suffix + s
