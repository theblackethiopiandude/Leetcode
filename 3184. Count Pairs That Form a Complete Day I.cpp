int countCompleteDayPairs(vector<int>& hours) {
        int count = 0;
        for(int i = 0; i < hours.size(); i++)
            for(int j = i+1; j < hours.size(); j++)
                if((hours[i] + hours[j]) % 24 == 0)
                    count++;
        return count;
    }

 int countCompleteDayPairs(vector<int>& hours) {
        int count = 0;
        {
            unordered_map<int, int> umap;
            for (const int hour : hours){
                int rem = hour % 24;
                if(rem){
                    count += umap[24 - rem];
                }else{
                    count += umap[0];
                }
                umap[rem]++;
            }
        }
        return count;
    }
