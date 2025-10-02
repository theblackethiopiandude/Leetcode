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

//-------------------

class Solution {
    fun maxBottlesDrunk(numBottles: Int, numExchange: Int): Int {
        var exchange = numExchange
        var empty = numBottles
        var totalDrunk = numBottles

        while(empty >= exchange){
            empty -= exchange++
            totalDrunk++
            empty++
        }

        return totalDrunk
    }
}
