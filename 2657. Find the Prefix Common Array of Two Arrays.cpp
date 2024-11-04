vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> seen;
        vector<int> ans(A.size());
        for(int i = 0; i < A.size(); i++){
            seen.insert(A[i]);
            seen.insert(B[i]);
            
            ans[i] = ((i+1) * 2) - seen.size();
        }
        return ans;
    }
