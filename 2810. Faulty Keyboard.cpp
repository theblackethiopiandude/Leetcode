class Solution {
public:
    string finalString(string s) {
        string ans = "";

        for(const char& c : s){
            if(c == 'i'){
                reverse(ans);
            }else{
                ans += c;
            }
        }

        return ans;
    }
private:
    void reverse(string& s){
        for(int i = 0, j = s.length()-1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
