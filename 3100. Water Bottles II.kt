class Solution {
    fun maxBottlesDrunk(numBottles: Int, numExchange: Int): Int {
        var full = numBottles
        var exchange = numExchange
        var empty = 0
        var totalDrunk = 0

        while(full > 0){
            empty += full
            totalDrunk += full

            full = 0
            while(empty >= exchange){
                full++
                empty -= exchange++
            }

        }

        return totalDrunk
    }
}
