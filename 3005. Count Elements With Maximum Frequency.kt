class Solution {
    fun maxFrequencyElements(nums: IntArray): Int {
        val feq = nums.groupBy {it}.mapValues { it.value.size }

        var max = 0
        var ans = 0
        for((_, value) in feq){
            if(max == value){
                ans += value
            }

            if(value > max){
                max = value
                ans = value
            }

        }

        return ans
    }
}
