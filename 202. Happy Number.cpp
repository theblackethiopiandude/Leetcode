bool isHappy(int n) {
        unordered_set<int> us;
        int sum = 0;
        while(true){
            sum = 0;
            while(n){
                sum += ((n%10) * (n%10));
                n /= 10;
            }
            if(us.count(sum))
                break;
            us.insert(sum);
            n = sum;
        }

        return sum == 1;
    }
