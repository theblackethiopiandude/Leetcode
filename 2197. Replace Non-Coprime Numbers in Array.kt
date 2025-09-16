class Solution {
    fun replaceNonCoprimes(nums: IntArray): List<Int> {
        if (nums.size == 1) return nums.toList()
        val stack = ArrayDeque<Int>()
        
        for (num in nums) {
            var current = num
            while (stack.isNotEmpty() && notCoPrime(stack.last(), current)) {
                current = lcm(stack.removeLast(), current)
            }
            stack.addLast(current)
        }
        
        return stack.toList()
    }

    fun notCoPrime(a: Int, b: Int): Boolean {
        return gcd(a, b) > 1
    }

    fun gcd(a: Int, b: Int): Int {
        return if (b == 0) a else gcd(b, a % b)
    }

    fun lcm(a: Int, b: Int): Int {
        return a / gcd(a, b) * b
    }
}
