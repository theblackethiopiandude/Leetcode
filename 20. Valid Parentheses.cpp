bool isValid(string s) {
        stack<char> st;
        {
            unordered_map<char, char> omap, cmap;
            omap = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
            cmap = {{']', '['}, {')', '('}, {'}', '{'}};

            for(char ch: s){
                if(omap.count(ch))
                    st.push(ch);
                else{
                    if(st.empty() || cmap[ch] !=  st.top())
                        return false;
                    st.pop();
                }      
            }
        }
        
        return st.empty();
    }
