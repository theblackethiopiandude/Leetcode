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
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        }while(slow != fast);

        return slow == 1;
    }
private:
    int digitSquareSum(int n){
        int sum = 0;
        while(n){
            sum += ((n%10) * (n%10));
            n /= 10;
        }
        return sum;
    }
};
