def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, word in enumerate(sentence.split(" ")):
            if len(searchWord) > len(word):
                continue
            
            for j in range(min(len(searchWord),  len(word))):
                if searchWord[j] != word[j]:
                    break
                
                if j == len(searchWord) - 1:
                    return i + 1

        return -1
