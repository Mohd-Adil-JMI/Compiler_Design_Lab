#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ff first
#define ss second
set<string> calcFirst(map<string, set<string>>&first, vector<vector<string>>&pro, map<string, vector<int>>&lhs, string curr){

    for(auto idx : lhs[curr]){
        int n = pro[idx].size();
        if(!isupper(pro[idx][1][0]) || pro[idx][1] == "#")first[curr].insert(pro[idx][1]);
        else if(pro[idx][1] != curr){

            set<string> ts = calcFirst(first, pro, lhs, pro[idx][1]);
            for(auto &c: ts)if(c != "#")first[curr].insert(c);
            int j = 1, cnt = 0;
            while(ts.count("#") && j< n){
                j++;
                cnt++;
                if(j<n){
                    if(pro[idx][j] == curr)break;
                    if(!isupper(pro[idx][j][0])){
                        first[curr].insert(pro[idx][j]);break;
                    }
                    ts = calcFirst(first, pro, lhs, pro[idx][j]);
                    for(auto &c: ts)if(c != "#")first[curr].insert(c);
                }
            }
            if(cnt == n-1)first[curr].insert("#");
        }
        
    }
    return first[curr];
}
set<string> calcFollow(map<string, set<string>>&follow, map<string, set<string>>&first, vector<vector<string>>&pro, map<string, vector<int>>rhs, string curr){
    if(follow.find(curr) != follow.end())return follow[curr];
    if(curr == pro[0][0])follow[curr].insert("$");
    for(auto idx : rhs[curr]){
        int n = pro[idx].size();
        for(int i = 1; i<n; i++){
            if(pro[idx][i]== curr){
                if(i+1 < n && !isupper(pro[idx][i+1][0])){
                    follow[curr].insert(pro[idx][i+1]);
                    break;
                }
                else{
                    int j = i+1;
                    set<string>ts;
                    if(j == n){
                        if(pro[idx][0] != curr)ts = calcFollow(follow,first, pro, rhs, pro[idx][0]);
                        for(auto &c: ts)if(c!="#")follow[curr].insert(c);
                        break;
                    }
                    ts = first[pro[idx][i+1]];
                    for(auto &c: ts)if(c!="#")follow[curr].insert(c);
                    while(ts.count("#") && j < n){
                        j++;
                        if(j < n){
                            if(pro[idx][j] == curr)break;
                            if(!isupper(pro[idx][j][0])){
                                follow[curr].insert(pro[idx][j]);break;
                            }
                            ts = first[pro[idx][j]];
                            for(auto &c: ts)if(c != "#")follow[curr].insert(c);
                        }
                        else if(curr != pro[idx][0]){
                            ts = calcFollow(follow, first, pro, rhs, pro[idx][0]);
                            for(auto &c: ts)if(c!="#")follow[curr].insert(c);
                            break;
                        }
                    }
                }
                
            }
        }
    }
    return follow[curr];
}
int main(){
    fstream cfg, out;
    cfg.open("CFG.txt", ios::in);
    vector<vector<string>>pro;
    while(!cfg.eof()){
        string s;
        getline(cfg, s);
        stringstream ss(s);
        vector<string>temp;
        while(ss){
            string t;
            ss>>t;
            temp.push_back(t);
        }
        temp.pop_back();
        pro.push_back(temp);
    } 
    cfg.close();
    map<string, vector<int>>lhs, rhs;
    int procnt = pro.size();
    for(int i= 0; i<procnt; i++){
        lhs[pro[i][0]].push_back(i);
        int n = pro[i].size();
        for(int j = 1; j<n; j++){
            if(isupper(pro[i][j][0]))rhs[pro[i][j]].push_back(i);
        }
    }
    map<string, set<string>>first, follow;
    // calcFirst(first, pro, lhs, pro[0][0]);
    for(auto var: lhs){
        calcFirst(first, pro, lhs, var.ff);
    }
    for(auto var: lhs){
        calcFollow(follow, first, pro, rhs, var.ff);
    }
    out.open("output.txt", ios:: out);
    out<<"First of the variables  :  "<<endl;
    for(auto &var : first){
        out<< var.ff<<" ----> ";
        for(auto &ter : var.ss)out<< ter<<" ";
        out<< endl;
    }
    out<<endl<<endl;
    out<<"Follow of the variables :  "<<endl;
    for(auto &var : follow){
        out<< var.ff<<" ----> ";
        for(auto &ter : var.ss)out<< ter<<" ";
        out<< endl;
    }
    out.close();

    return 0;
}



// S A b B
// S c S
// A B A 
// A a
// B b B
// B #