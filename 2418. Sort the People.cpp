vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       vector<string> ans;

       { 
            map <int, string> m;

            const int n = heights.size();
            for(int i = 0; i < n; i++)
                m[heights[i]] = names[i];
            
            for(auto pair = m.rbegin(); pair != m.rend(); pair++)
                ans.push_back(pair->second);

        }

        return ans;
    }
