class Solution {
    fun maxFreqSum(s: String): Int {
        val count = s.groupingBy { it }.eachCount()
        
        val maxVowel = count.filter { it.key.isVowel() }
            .maxByOrNull { it.value }?.value ?: 0

        val maxConsonant = count.filter { !it.key.isVowel() }
            .maxByOrNull { it.value }?.value ?: 0

        return maxVowel + maxConsonant
    }

    fun Char.isVowel(): Boolean = when(this){
        'a', 'e', 'i', 'o', 'u' -> true;
        else -> false;
    }
}
