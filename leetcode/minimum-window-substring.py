class Solution:
    def minWindow(self, s: str, t: str) -> str:
        alphabets = 'abcdefghijklmnopqrstuvwxyz' + 'abcdefghijklmnopqrstuvwxyz'.upper()
        origin = {c: 0 for c in alphabets}
        current = {c: 0 for c in alphabets}
        counter = 0
        for c in t:
            if origin[c] == 0:
                counter += 1
            origin[c] += 1
            current[c] += 1
        
        st = 0
        ed = 0
        ans = ""
        while ed < len(s):
            c = s[ed]
            current[c] -= 1
            if current[c] == 0:
                counter -= 1
            while st < ed and (current[s[st]] < 0 or origin[s[st]] == 0):
                current[s[st]] += 1
                current[s[st]] = min(current[s[st]], origin[s[st]])
                st += 1
            # print(st, ed, s[st], s[ed], current[s[st]], origin[s[st]], ',', current['B'])
            if counter == 0:
                if not ans:
                    ans = s[st:ed + 1]
                elif ed - st + 1 < len(ans):
                    ans = s[st:ed + 1]
            ed += 1
        return ans
