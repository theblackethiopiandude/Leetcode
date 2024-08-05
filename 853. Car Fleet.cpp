int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> st;
        {
            map<int, int> mp;
            for(int i = 0; i < position.size(); i++)
                mp[position[i]] = speed[i];
            
            for(auto curr = mp.rbegin(); curr != mp.rend(); curr++){
                st.push_back((target - curr->first) / (float)curr->second);
                if(st.size() > 1 && st.back() <= *(st.end()-2))
                    st.pop_back();     
            }
        }
        return st.size();
    }
