class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Triee t = new Triee();
        for(var word : dictionary)
            t.insert(word);
        
        StringBuilder result = new StringBuilder();
        String []  input = sentence.split(" ");
        for(String i : input){
            result.append(t.search(i));
            result.append(" ");
        }
        return result.toString().trim();
    }
}
public class Triee {
    class Node{
        HashMap<Character, Node> children;
        char value = '\0';
        boolean isEnd;
        Node(){
            children = new HashMap<>();
            isEnd = false;
        }
        Node(char ch){
            this();
            value = ch;
        }
    }
    Node root = new Node();

    public void insert(String word){
        var current = root;
        for (var ch : word.toCharArray()){
            if(!current. children.containsKey(ch))
                current.children.put(ch, new Node(ch));

            current = current.children.get(ch);
        }
        current.isEnd = true;
    }
    
    public String search(String word){
        var current = root;
        int j = 0;
        for(char ch : word.toCharArray()){
            j++;
            if(!current.children.containsKey(ch)){
                return word;
            }else if(current.children.get(ch).isEnd){
                return word.substring(0, j);
            }else{
                current = current.children.get(ch);
            }
            
        }
        return word;

    }
}
