vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        {
            unordered_map<int, int> umap;
            stack<int> st;
            for(int R = nums2.size() -1; R >= 0; R--){
                while(!st.empty() && st.top() < nums2[R])
                    st.pop();
                
                umap[nums2[R]] = (st.empty())? -1: st.top();
                st.push(nums2[R]);
            }

            for(int L = 0; L < nums1.size(); L++)
                ans[L] = umap[nums1[L]];
        }
        return ans;
    }


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        {
            unordered_map<int, int> umap;
            stack<int> st;

            for(int L = 0; L < nums1.size(); L++)
                umap[nums1[L]] = L;

            for(int R = nums2.size() -1; R >= 0; R--){
                while(!st.empty() && st.top() < nums2[R])
                    st.pop();
                
                if(umap.count(nums2[R]))         
                    ans[umap[nums2[R]]] = (st.empty())? -1: st.top();
                    
                st.push(nums2[R]);
            }

        }
        return ans;
    }
