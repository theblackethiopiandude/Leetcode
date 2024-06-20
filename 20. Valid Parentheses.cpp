bool isValid(string s) {
        stack<char> st;
        {
            unordered_map<char, char> umap;
            umap[')'] = '(';
            umap[']'] = '[';
            umap['}'] = '{';
            for(char ch: s)
                if(!umap.count(ch))
                    st.push(ch);
                else
                    if(!st.empty() && umap[ch] == st.top())
                        st.pop();
                    else
                        return false;
        }
        return st.empty();
    }
