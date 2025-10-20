class Solution {
    val map = mapOf("X++" to '+', "++X" to '+', "X--" to '-', "--X" to '-')
    
    fun finalValueAfterOperations(operations: Array<String>): Int {
        var x = 0

        for (op in operations) {
            if(map[op] == '+'){
                x++
            }else{
                x--
            }
        }

        return x
    }
}
