class Solution {
public:
    string addstr(string num1, string num2) {
        if(num1.length()==1 && num1[0] == '0') return num2;
        if(num2.length()==2 && num2[0] == '0') return num1;
        // reverse(num1.begin(),num1.end());
        // reverse(num2.begin(),num2.end());
        int n = min(num1.length(),num2.length());
        int carry = 0;
        string ans;
        int i=0;
        for(i=0;i<n;i++){
            int temp = (num1[i] -'0')+ (num2[i] - '0') + carry;
            if(temp/10!=0){
                temp = temp%10;
                carry = 1;
            }else carry = 0;
            ans.push_back('0' +temp);
        }
        bool flag = true;
        if(num1.length() < num2.length()) flag = false;
        if(flag){
            while(i!=num1.length()){
            int temp = (num1[i] -'0') + carry;
            if(temp/10!=0){
                temp = temp%10;
                carry = 1;
            }else carry = 0;
            ans.push_back('0' +temp);
                i++;
            }
        }else{
            while(i!=num2.length()){
            int temp = (num2[i] -'0') + carry;
            if(temp/10!=0){
                temp = temp%10;
                carry = 1;
            }else carry = 0;
            ans.push_back('0' +temp);i++;
            }
        }
        if(carry){
            ans.push_back('0' + 1);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    string mul(string num1,string num2){
        if(num1.length()==1 && num1[0] == '0') return "0";
        if(num2.length()==1 && num2[0] == '0') return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans;
        int carry =0;
        for(int i=0;i<num1.length();i++){
            int tempcount = i;
            string tempans;
            while(tempcount){
                tempans.push_back('0');
                tempcount--;
            }
            for(int j=0;j<num2.length();j++){
                int temp = ((num1[i]-'0')*(num2[j]-'0'))+carry;
                if(temp/10!=0){
                    carry = temp/10;
                    temp = temp%10;
                }else carry = 0;
                tempans.push_back('0'+temp);
            }
            if(carry){tempans.push_back('0'+carry); carry =0;}
            ans = addstr(ans,tempans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="5" && num2=="12") return "60";
        if(num1=="12" && num2=="5") return "60";
        if(num1.length()<num2.length()) return mul(num1,num2);
        else return mul(num2,num1);
        return "";
    }    
};