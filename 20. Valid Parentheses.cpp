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

bool isValid(string s) {
        stack<char> st;
        for(char ch: s)
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else
                if(!st.empty() && abs(ch - st.top()) <= 2)
                    st.pop();
                else
                    return false;
        
        return st.empty();
}

bool isValid(string s) {
        stack<char> st;
        {
            unordered_map<char, char> cmap;
            unordered_set<char> oset({'[', '(', '{'});

            cmap = {{']', '['}, {')', '('}, {'}', '{'}};

            for(char ch: s){
                if(oset.count(ch))
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
