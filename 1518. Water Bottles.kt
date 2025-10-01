class Solution {
    fun numWaterBottles(numBottles: Int, numExchange: Int): Int {
        var full = numBottles
        var empty = 0
        var totalDrunk = 0

        while(full > 0){
            empty += full
            totalDrunk += full            

            full = empty / numExchange
            empty = empty % numExchange
        }

        return totalDrunk
    }
}
