/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/ */

class StockSpanner {
    private:
        vector<pair<int, int>> priceArray;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int count = 1;
        for(int i = priceArray.size() - 1; i >= 0; ){
            if(priceArray[i].first <= price){
                count += priceArray[i].second;
                i = i - priceArray[i].second;
            }
            else{
                break;
            }
        }
        priceArray.push_back(make_pair(price, count));
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
