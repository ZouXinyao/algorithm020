class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(auto& bill : bills) {
            switch(bill) {
                case 20:
                    if(ten == 0) five -= 2;
                    else ten--;
                    if((--five) < 0) return false;
                    break;
                case 10:
                    if((--five) < 0) return false;
                    ten++;
                    break;
                default:
                    five++;
            }
        }
        return true;
    }
};