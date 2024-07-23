int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int L = 0;
        int sum = 0;
        for(int R = 0; R < arr.size(); R++){
            sum += arr[R];
            
            if(R - L + 1 == k){
                cout << "L: " << L << " , R: " << R << " , SUM: " << sum << " , AVG: "<< sum/k << endl;
                if(sum/k >= threshold) count++;
                sum -= arr[L++];
            }
        }
        return count;
    }
