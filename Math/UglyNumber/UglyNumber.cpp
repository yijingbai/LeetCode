class Solution {
public:
    bool isUgly(int num) {
        if (1 == num) {
            return true;
        }
        if (num <= 0) {
            return false;
        }
        while(true){
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                break;
            }
        }
        return num < 5;
    }
};
