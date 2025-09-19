class Solution {
    data class Rank(val rank: Int, val i: Int);
    fun findRelativeRanks(score: IntArray): Array<String> {
        var ans: Array<String> = Array(score.size){""}
        val pq = PriorityQueue<Rank>(compareByDescending { it.rank })
        for(i in 0 until score.size)
            pq.add(Rank(score[i], i))

        var i = 1
        while(pq.isNotEmpty()){
            val rank = pq.poll()
            when(i){
                1 -> ans[rank.i] = "Gold Medal"
                2 -> ans[rank.i] = "Silver Medal"
                3 -> ans[rank.i] = "Bronze Medal"
                else -> ans[rank.i] = "$i"
            }

            i++
        }

        return ans
    }
}
