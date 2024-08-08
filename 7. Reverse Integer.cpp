int reverse(int x) {
        string num = to_string(x);

        {
            int L = 0;
            int R = num.length()-1;
            while(L < R){
                swap(num[L++], num[R--]);
            }
        }
        int ans = -1;
        try{
            ans = (x < 0)? stoi(num) * -1 : stoi(num);
        }catch(out_of_range& e){
            ans = 0;
        }

        return ans;
    }
