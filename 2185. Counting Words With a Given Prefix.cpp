def prefixCount(self, words: List[str], pref: str) -> int:
        ans = 0
        for word in words:
            valid = True
            for i in range(min(len(word), len(pref))):
                if word[i] != pref[i]:
                    valid = False
                    break
            
            if valid and len(word) >= len(pref):
                ans += 1

        return ans
