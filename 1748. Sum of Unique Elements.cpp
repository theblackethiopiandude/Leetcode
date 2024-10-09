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
