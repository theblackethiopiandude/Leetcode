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



int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> st;
        {
            vector<float> time(target+1, -1);
            for(int i = 0; i < position.size(); i++)
                time[position[i]] = (target - position[i]) / (float)speed[i];
            
            for(int i = target; i >= 0; i--){
                if(time[i] == -1)
                    continue;
                st.push_back(time[i]);
                if(st.size() > 1 && st.back() <= *(st.end()-2))
                    st.pop_back();     
            }
        }
        return st.size();
    }
