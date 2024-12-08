def countPrefixes(self, words: List[str], s: str) -> int:
        ans = 0

        for word in words:
            valid = True
            for i in range(min(len(word), len(s))):
                if word[i] != s[i]:
                    valid = False
                    break
            
            if valid and len(word) <= len(s):
                ans += 1

        return ans
