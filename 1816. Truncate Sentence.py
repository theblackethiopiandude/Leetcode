def truncateSentence(self, s: str, k: int) -> str:
        ans = ""
        words = s.split(" ")
        for i in range(k):
            ans += (words[i] + " ")
        
        return ans.strip()
