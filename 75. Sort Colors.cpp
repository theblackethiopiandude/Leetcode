void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(auto value:nums)
            m[value]++;
        nums.clear();

        for(auto& pair: m)
            while(pair.second-- > 0)
                nums.push_back(pair.first);
}

