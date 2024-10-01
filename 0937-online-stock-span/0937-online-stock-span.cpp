class StockSpanner {
    vector<int> v;
public:
    StockSpanner(){
        
    }
    
    int next(int price){
        int cnt=1;
        for(int i=v.size()-1; i>=0; i--){
            if(v[i]<=price) cnt++;
            else break;
        }
        v.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */