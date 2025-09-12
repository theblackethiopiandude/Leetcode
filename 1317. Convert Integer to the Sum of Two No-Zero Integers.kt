class Solution {
    fun getNoZeroIntegers(n: Int): IntArray {
        for (a in 1 until n) {
            val b = n - a;
            if (a.isNonZero() && b.isNonZero()) {
                return intArrayOf(a, b);
            }
        }
        
        return intArrayOf();
    }

    fun Int.isNonZero() = this.toString().none { it == '0' };
}
