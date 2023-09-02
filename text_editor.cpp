#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void append(vector<char> &s, string a){
    for(char c: a){
        s.push_back(c);
    }
}

void delete_char(vector<char> &s, vector<char> &del_s, int k){
    while(!s.empty() && k--){
        del_s.push_back(s.back());
        s.pop_back();
    }
}

void undo(vector<char> &s, vector<char> &del_s, vector<pair<int,string>> &operations){
    if (operations.empty()){
        return;
    }
    int opn = operations.back().first;
    if (opn==1){
        int k = operations.back().second.size();
        while(!s.empty() && k--){
            s.pop_back();
        }
        operations.pop_back();
    }
    else if (opn==2){
        int k = stoi(operations.back().second);
        while(!del_s.empty() && k--){
            s.push_back(del_s.back());
            del_s.pop_back();
        }
        operations.pop_back();
    } 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    int queries, opn, k;
    string a;
    vector<char> s;
    vector<char> del_s;
    vector<pair<int, string>> operations;
    cin>>queries;
    for(int i=0; i<queries; i++){
        cin>>opn;
        if (opn==1){
            cin>>a;
            append(s, a);
            operations.push_back({opn, a});
        }
        else if(opn==2){
            cin>>k;
            delete_char(s, del_s, k);
            operations.push_back({opn, to_string(k)});
        }
        else if(opn==3){
            cin>>k;
            cout<<s[k-1]<<endl;
        }
        else{
            undo(s, del_s, operations);
        }
    }  
    return 0;
}
