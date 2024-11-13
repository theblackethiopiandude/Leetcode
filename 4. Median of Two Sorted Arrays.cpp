double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int n1 = nums1.size(), n2 = nums2.size(); 
        int i = 0, j = 0;
        for(; i < n1 && j < n2;)
            if(nums1[i] < nums2[j])
                nums.push_back(nums1[i++]);
            else
                nums.push_back(nums2[j++]);
        
        while(i < n1)
            nums.push_back(nums1[i++]);
    
        while(j < n2)
            nums.push_back(nums2[j++]);

        int d = nums.size() % 2;
        double med = nums[nums.size() / 2];
        
        if(!d)
            med = (med + nums[(nums.size() / 2) - 1] )/ 2;
        
        return med;
        
}
