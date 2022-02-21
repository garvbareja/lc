class Solution {
public:
    int compress(vector<char>& chars) {
        int cur=0,i=0;
        while(i<chars.size()){
            int count=0,j=i;
            while(i<chars.size() && chars[i]==chars[j]){
                count++; i++;
            }
            chars[cur]=chars[j]; cur++;
            if(count>1){
                if(count/1000){
                    int digit=count/1000;
                    chars[cur]='0'+digit; cur++;
                    count=count-(1000*digit);
                    //
                    digit=count/100;
                    chars[cur]='0'+digit; cur++;
                    count=count-(100*digit);
                    //
                    digit=count/10;
                    chars[cur]='0'+digit; cur++;
                    count=count-(10*digit);
                    //
                    digit=count;
                    chars[cur]='0'+digit; cur++;
                    count=count-(digit);
                }
                else if(count/100){
                    int digit=count/100;
                    chars[cur]='0'+digit; cur++;
                    count=count-(100*digit);
                    //
                    digit=count/10;
                    chars[cur]='0'+digit; cur++;
                    count=count-(10*digit);
                    //
                    digit=count;
                    chars[cur]='0'+digit; cur++;
                    count=count-(digit);
                }
                else if(count/10){
                    int digit=count/10;
                    chars[cur]='0'+digit; cur++;
                    count=count-(10*digit);
                    //
                    digit=count;
                    chars[cur]='0'+digit; cur++;
                    count=count-(digit);
                }
                else if(count){
                    int digit=count;
                    chars[cur]='0'+digit; cur++;
                    count=count-(digit);
                }
            }
        }
        return cur;
    }
};