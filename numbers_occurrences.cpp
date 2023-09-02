#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

string numberOfInteger(int n, int m){
    if(n==1){
        return "1";
    }
    cout<<(long long int)(pow(10,n-1)*9)<<endl;
    cout<<(long long int)(pow(10,n-1)*9)<<endl;
    cout<<(long long int)(pow(9,n-1)*8)<<endl;
    cout<<(long long int)(pow(10,n-1)*9) - (long long int)(pow(9,n-1)*8)<<endl;
    cout<<to_string((long long int)(pow(10,n-1)*9) - (long long int)(pow(9,n-1)*8))<<endl;
    return to_string((long long int)(pow(10,n-1)*9) - (long long int)(pow(9,n-1)*8));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    getline(cin, n_temp);

    int m = stoi(ltrim(rtrim(n_temp)));
    
    string result = numberOfInteger(n,m);

    cout << result << "\n";

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
