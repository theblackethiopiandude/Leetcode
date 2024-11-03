vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> win;
        map<int, int> loss;
        for(const auto& match: matches){
            win.insert(match[0]);
            loss[match[1]]++;
        }
        
        vector<vector<int>> ans(2);
        for(const int player : win){
            if(!loss.count(player))
                ans[0].push_back(player);
        }

        for(const auto& [player, loss_count] : loss){
            if(loss_count == 1)
                ans[1].push_back(player);
        }

        return ans;
  }
