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

// Beats 100%
class Solution {
    fun maxFreqSum(s: String): Int {
        val freq = IntArray(26)

        for(c in s){
            freq[c - 'a']++
        }

        var maxVowelCount = 0
        var maxConsonantCount = 0

        for(i in freq.indices){
            if(('a' + i).isVowel())
                maxVowelCount = maxOf(maxVowelCount, freq[i])
            else
                maxConsonantCount = maxOf(maxConsonantCount, freq[i])
        }
        
        return maxVowelCount + maxConsonantCount
    }

    fun Char.isVowel(): Boolean = when(this){
        'a', 'e', 'i', 'o', 'u' -> true;
        else -> false;
    }
}
