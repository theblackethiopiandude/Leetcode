int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid = 1;

        while(l < r){
            mid = l + (r - l)/2;

            if(isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;            
        }
        if(mid < l)
            mid++;
        return mid;
    }
