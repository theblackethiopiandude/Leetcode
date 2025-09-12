class Solution {
    fun doesAliceWin(s: String): Boolean {
        for(c in s){
            if(c.isVowel())
                return true;
        }
        
        return false;
    }

    fun Char.isVowel() = when(this.lowercaseChar()){
        'a', 'e', 'i', 'o', 'u' -> true;
        else -> false;
    };
}


class Solution {
    fun doesAliceWin(s: String): Boolean {
        return s.any { it.isVowel() };
    }

    fun Char.isVowel() = when(this){
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U' -> true
        else -> false;
    };
}
