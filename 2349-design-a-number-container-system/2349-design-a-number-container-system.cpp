class NumberContainers {
    map<int,int>indexx;
    map<int,set<int>>numberr;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexx.find(index)!=indexx.end()){
            int prev=indexx[index];
            numberr[prev].erase(index);
           
        }
        indexx[index]=number;
        numberr[number].insert(index);
    }
    
    int find(int number) {
        if(numberr.find(number)==numberr.end()  || numberr[number].empty()){
            return -1;
        }
        return *(numberr[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */