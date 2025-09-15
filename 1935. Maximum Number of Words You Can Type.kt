class Solution {
    fun canBeTypedWords(text: String, brokenLetters: String): Int {
        val invalid = brokenLetters.toSet();
        var ans = 0;
        var valid = true;
        for(c in text){
            if(c == ' '){
                if(valid) ans++

                valid = true
            }else if(c in invalid){
                valid = false
            }
        }

        if(valid) ans++

        return ans
    }
}

---------------------------

class Solution {
    fun canBeTypedWords(text: String, brokenLetters: String): Int {

        return text.split(" ").count{word -> word.none { it in brokenLetters }}
    }
}
