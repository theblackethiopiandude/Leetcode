class Router(val limit: Int) {
    val queue = ArrayDeque<Triple<Int, Int, Int>>()
    val set = mutableSetOf<String>()
    val packets = mutableMapOf<Int, MutableList<Int>>()

    private fun makeKey(source: Int, dest: Int, timestamp: Int) = "$source,$dest,$timestamp"
    fun addPacket(source: Int, destination: Int, timestamp: Int): Boolean {

        val key = makeKey(source, destination, timestamp)
        
        if(key in set){
            return false
        }

        if(queue.size == limit){
            forwardPacket()
        }


        queue.addLast(Triple(source, destination, timestamp))
        set.add(key)
        packets.computeIfAbsent(destination) { mutableListOf() }
            .add(timestamp)

        return true
    }

    fun forwardPacket(): IntArray {
        if(queue.isEmpty())
            return intArrayOf()

        val first = queue.removeFirst()
        set.remove(makeKey(first.first, first.second, first.third))

        val times = packets[first.second]!!
        times.removeAt(0)
        if (times.isEmpty()) packets.remove(first.second)

        return intArrayOf(first.first, first.second, first.third)
    }

    fun getCount(destination: Int, startTime: Int, endTime: Int): Int {
        val times = packets[destination] ?: return 0

        val startIndex = findFirstIndexGreaterThanOrEqual(times, startTime)
        val endIndex = findFirstIndexGreaterThanOrEqual(times, endTime + 1)
        
        return endIndex - startIndex

    }

    private fun findFirstIndexGreaterThanOrEqual(times: List<Int>, targetTimestamp: Int): Int {
        var low = 0
        var high = times.size
        while (low < high) {
            val mid = low + (high - low) / 2
            if (times[mid] < targetTimestamp) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        return low
    }

}

/**
 * Your Router object will be instantiated and called as such:
 * var obj = Router(memoryLimit)
 * var param_1 = obj.addPacket(source,destination,timestamp)
 * var param_2 = obj.forwardPacket()
 * var param_3 = obj.getCount(destination,startTime,endTime)
 */