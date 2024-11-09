class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        total_size = len("".join(words))
        ans = []
        st = 0
        ed = total_size
        sss = {w: words.count(w) for w in words}
        while ed <= len(s):
            page = s[st:ed]
            ss = {w: sss[w] for w in sss}
            cnt = len(ss)
            r = ""
            for i in page:
                r += i
                if r in ss:
                    ss[r] -= 1
                    cnt -= ss[r] == 0
                    r = ""
                if len(r) > 30:
                    break
            if cnt == 0:
                ans.append(st)
            st += 1
            ed += 1
        return ans
