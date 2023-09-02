#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long long int factorial(int n){
    if (n==0||n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    int x = nStairs/2;
    int y = nStairs%2;
    long long int fxy = factorial(x+y);
    long long int fx = factorial(x);
    cout<<fxy<<" "<<fx<<endl;
    long long int fy = 1, count = fxy/fx, prev = count;
    int curr;
    x-=1; y+=2;
    for(int i=0; i<(nStairs/2); i++){
        curr = (prev*(x+y)*(x+1))/(y*(y-1));
        prev = curr;
        count = (count+prev)%1000000007;
        x-=1;
        y+=2;
        cout<<count<<endl;
    }
    return count;
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
        cout<<countDistinctWays(n)<<endl;
        
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
