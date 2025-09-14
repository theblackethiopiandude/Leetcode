class Solution {
    fun spellchecker(wordlist: Array<String>, queries: Array<String>): Array<String> {
        val exact = wordlist.toSet()
        val caseMap = wordlist.groupBy { it.lowercase() }.mapValues { it.value[0] }
        val vowelMap = wordlist.groupBy { it.normalize() }.mapValues { it.value[0] }
        
        return queries.map{ query ->
            when {
                query in exact -> query
                query.lowercase() in caseMap -> caseMap[query.lowercase()]!!
                query.normalize() in vowelMap -> vowelMap[query.normalize()]!!
                else -> ""
            }
        }.toTypedArray()
    }

    fun Char.isVowel(): Boolean = when(this){
        'a', 'e', 'i', 'o', 'u' -> true
        else -> false
    }

    fun String.normalize() = this.lowercase().map { if (it.isVowel()) '*' else it }.joinToString("")

}
----
class Solution {
    fun spellchecker(wordlist: Array<String>, queries: Array<String>): Array<String> {
        val words = wordlist.toSet()
        val grouped = wordlist.groupBy { it.lowercase() }
        val ans: Array<String> = Array(queries.size) { "" }

        for((i, query) in queries.withIndex()){
            if(query in words){
                ans[i] = query
            }else{
                val q = query.lowercase()
                if(q in grouped){
                    ans[i] = grouped[q]!![0]
                }else{
                    for((k, v) in grouped){
                        if(q.length == k.length){
                            var valid = true

                            for(j in 0 until q.length){
                                if((k[j] != q[j]) && !(q[j].isVowel() && k[j].isVowel())){
                                    valid = false
                                    break
                                }
                            }

                            if(valid){
                                val rep = v[0].lowercase()
                                for(j in 0 until q.length){
                                    if(((rep[j] != q[j]) && !(rep[j].isVowel() && q[j].isVowel()))){
                                        valid = false
                                        break
                                    }
                                }

                                ans[i] = if (valid) v[0] else ""
                                break
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }

    fun Char.isVowel(): Boolean = when(this){
        'a', 'e', 'i', 'o', 'u' -> true;
        else -> false;
    }

}
