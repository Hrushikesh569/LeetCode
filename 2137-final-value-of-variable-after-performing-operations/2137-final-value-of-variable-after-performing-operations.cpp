class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int x = 0;
        for(auto i: s){
        if(i=="--X" || i=="X--") x--;
        if(i=="++X" ||i== "X++") x++;
        }
        return x;
    }
};