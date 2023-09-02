#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

const int maxn = 1000, maxm = 1000, M = 1000000007;

long long G[maxm+1][maxn+1];


void initialize(){
    G[1][0]=1; G[1][1]=1; G[1][2]=2; G[1][3]=4; G[1][4]=8;
    for (int i=5; i<=maxn; i++){
        G[1][i] = G[1][i-1]+G[1][i-2]+G[1][i-3]+G[i][i-4];
        G[1][i] %= M;
    } 

    for (int i=2; i<=maxm; i++){
        for(int j=1; j<=maxn; j++){
            G[i][j] = G[i-1][j]*G[1][j];
            G[1][i] %= M;
        }
    }
}

int legoBlocks(int n, int m) {
    long long H[maxm+1];
    H[1] = G[n][1];
    long long value;
    for(int i=2; i<=m; i++){
        value = G[i][1];
        for(int j=i; j>=2; j--){
            value = (value%M) * ((G[n][j] - H[i-j+1])%M);
        }
        H[i] = value;
    }
    return H[m];
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
    
    initialize();

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        cout << result << "\n";
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
