int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto& opr : operations){
            if(opr == "D"){
                s.push(s.top() * 2);
            }else if(opr == "C"){
                s.pop();
            }
            else if(opr == "+"){
                int t = s.top();
                s.pop();
                int ans = t + s.top();
                s.push(t);
                s.push(ans);
            }else{
                s.push(stoi(opr));
            }
        }
        int ans = 0;

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
