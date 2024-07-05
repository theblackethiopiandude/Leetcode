vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++)
            if(i % 3 == 0 && i % 5 == 0)
                ans.push_back("FizzBuzz");
            else if(i % 3 == 0)
                ans.push_back("Fizz");
            else if(i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        return ans;
    }

vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 1; i <= n; i++)
            ans[i-1] =  (i % 15 == 0) ? "FizzBuzz" :
                        (i % 5 == 0)  ? "Buzz" :
                        (i % 3 == 0)  ? "Fizz" :
                                        to_string(i);
        return ans;
    }
