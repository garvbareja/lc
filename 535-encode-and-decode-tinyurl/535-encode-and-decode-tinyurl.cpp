class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> tinytolong;
    unordered_map<string,string> longtotiny;
    vector<int> nums={0,1,2,3,4,5,6,7,8,9};
    vector<int> chars={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    string makeurl(){
        string res="";
        res.push_back(nums[rand()%10]+'0');
        res.push_back(chars[rand()%26]+'a');
        res.push_back(nums[rand()%10]+'0');
        res.push_back(chars[rand()%26]+'a');
        res.push_back(chars[rand()%26]+'A');
        res.push_back(chars[rand()%26]+'a');
        return res;
    }
    
    string encode(string longUrl) {
        if(!longtotiny.count(longUrl)){
            string tinyurl=makeurl();
            while(tinytolong.count(tinyurl)) tinyurl=makeurl();
            tinytolong[tinyurl]=longUrl;
            longtotiny[longUrl]=tinyurl;
        }
        return "http://tinurl.com/"+longtotiny[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string tinyurl(shortUrl.end()-6,shortUrl.end());
        return tinytolong[tinyurl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));