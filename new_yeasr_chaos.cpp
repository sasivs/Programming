#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */


int merge(vector<pair<int, int>> &q, int i, int mid, int j){
    vector<pair<int, int>> temp;
    int l = i;
    int u = mid+1;

    while(l<(mid+1) && u<=j){
        if (q[l].first > q[u].first){
            q[l].second += j-u+1;
            if (q[l].second > 2){
                cout<<"Too chaotic"<<endl;
                return -1;
            }
            temp.push_back(q[l]);
            l++;
        }
        else{
            temp.push_back(q[u]);
            u++;
        }
    }

    while(l<=mid){
        temp.push_back(q[l++]);
    }
    while(u<=j){
        temp.push_back(q[u++]);
    }

    for(int k=0, l=i; l<=j; l++, k++){
        q[l] = temp[k];
    }
    return 0;
}

int mergesort(vector<pair<int, int>> &q, int i, int j){
    if (i<j){
        int mid = (i+j)/2;
        int result = mergesort(q, i, mid);
        if (result==-1) return -1;
        result = mergesort(q, mid+1, j);
        if (result==-1) return -1;
        result = merge(q, i, mid, j);
        if (result==-1) return -1;
    }
    return 0;
}
void minimumBribes(vector<int> q) {
    long long int bribes = 0;
    vector<pair<int, int>> q_pair;
    for (int i=0; i<q.size(); i++){
        q_pair.push_back({q[i], 0});
    }
    int result = mergesort(q_pair, 0, q.size()-1);
    if (result!=-1){
        for (int i=0; i<q.size(); i++){
            bribes+=q_pair[i].second;
        }
        cout<<bribes<<endl;
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
