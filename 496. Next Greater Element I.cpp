vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        {
            unordered_map<int, int> umap;
            stack<int> st;
            for(int R = nums2.size() -1; R >= 0; R--){
                if(st.empty()){
                    st.push(nums2[R]);
                    umap[nums2[R]] = -1;
                }
                else{
                    while(!st.empty() && st.top() < nums2[R]){
                        st.pop();
                    }
                    umap[nums2[R]] = (st.empty())? -1: st.top();
                    st.push(nums2[R]);
                }
            }

            for(int L = 0; L < nums1.size(); L++)
                ans[L] = umap[nums1[L]];
        }
        return ans;
    }
