class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        val m = mutableMapOf<Char, Int>()
        var maxw = 0
        var left = 0

        for((right, c) in s.withIndex()){
            if(c in m && m[c]!! >= left){
                left = m[c]!! + 1
            }
            
            m[c] = right

            maxw = max(maxw, right - left + 1)
        }

        return maxw
    }
}
