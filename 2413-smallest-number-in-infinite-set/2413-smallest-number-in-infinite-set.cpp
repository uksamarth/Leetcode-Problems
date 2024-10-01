class SmallestInfiniteSet {
    int curr = 1;
    bool removed[1001] = {};
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        while (removed[curr]) curr++;
        removed[curr] = true;
        return curr;
    }
    
    void addBack(int num) {
        if (num < curr) curr = num;
        removed[num] = false;
    }
};