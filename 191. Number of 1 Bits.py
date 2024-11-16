def hammingWeight(self, n: int) -> int:
        ans = 0
        for bit in bin(n)[2:]:
            if bit == '1':
                ans += 1
        
        return ans
