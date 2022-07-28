/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int> hash;
    int dfs(vector<Employee*> emp,int id){
        int res=0; int index=hash[id];
        for(int i=0;i<emp[index]->subordinates.size();i++) res+=dfs(emp,emp[index]->subordinates[i]);
        return emp[index]->importance+res;
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        for(int i=0;i<emp.size();i++){
            hash[emp[i]->id]=i;
        }
        return dfs(emp,id);
    }
};