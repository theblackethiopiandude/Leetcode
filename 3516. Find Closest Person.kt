class Solution {
    fun findClosest(x: Int, y: Int, z: Int): Int {
        val dx = abs(z - x)
        val dy = abs(z - y)

        return when {
            dx < dy -> 1
            dx > dy -> 2
            else -> 0
        }
    }
}
