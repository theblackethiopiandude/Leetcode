int sumOfUnique(vector<int>& nums) {
        set<int> n, tobe;

        for(int num: nums){
            if(n.count(num)){
                n.erase(num);
                tobe.insert(num);
                continue;
            }
            n.insert(num);
        }

        for(int num: tobe)
            if(n.count(num))
                n.erase(num);

        return accumulate(n.begin(), n.end(), 0);
    }

int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(int num: nums)
            umap[num]++;

        auto accumulate_unique_keys = [](int sum, const std::pair<int, int>& pair) {
            return sum + ((pair.second == 1)? pair.first : 0);
        };

        return accumulate(umap.begin(), umap.end(), 0, accumulate_unique_keys);
    }
