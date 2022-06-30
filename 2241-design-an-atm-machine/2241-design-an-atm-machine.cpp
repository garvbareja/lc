class ATM {
public:
    vector<long long> notes;
    ATM() {
        notes.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++) notes[i]+=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        long long withdraw=amount; vector<int> res(5);
        for(int i=4;i>=0;i--){
                long long count;
                if(i==4){
                    count=amount/500;
                    count=min(notes[i],count);
                    amount-=(count*500);
                    res[i]=count;
                }else if(i==3){
                    count=amount/200;
                    count=min(notes[i],count);
                    amount-=(count*200);
                    res[i]=count;
                }else if(i==2){
                    count=amount/100;
                    count=min(notes[i],count);
                    amount-=(count*100);
                    res[i]=count;
                }else if(i==1){
                    count=amount/50;
                    count=min(notes[i],count);
                    amount-=(count*50);
                    res[i]=count;
                }else{
                    count=amount/20;
                    count=min(notes[i],count);
                    amount-=(count*20);
                    res[i]=count;
                }
        }
        if(amount) return {-1};
        for(int i=0;i<5;i++) notes[i]-=res[i];
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */