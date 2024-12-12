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

int calPoints(vector<string>& operations) {
        vector<int> s;
        for(auto& opr : operations){
            switch(opr[0]){
                case '+':
                    s.push_back(s.back() + *(s.end() - 2));
                    break;
                case 'D':
                    s.push_back(s.back() * 2);
                    break;
                case 'C':
                    s.pop_back();
                    break;
                default:
                    s.push_back(stoi(opr));
            }
        }

        return accumulate(s.begin(), s.end(), 0);
}
