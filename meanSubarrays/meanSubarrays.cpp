#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int countKAverageSubarrays(int arr[], int n, int k){
    int iterSum = 0, count = 0;
    map<int, int> freq;

    for(int i=0; i<n; i++){
        iterSum+=arr[i]-k;
        if (iterSum == 0){
            count+=1;
        }

        if (freq.find(iterSum)!=freq.end()){
            count+=freq[iterSum];
            freq[iterSum]++;
        }
        else{
            freq[iterSum]=1;
        }
    }

    return count;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt","w",stdout);
    #endif

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int arr[n];

    for(int i=0; i<n; i++){
        getline(cin, n_temp);
        arr[i] = stoi(ltrim(rtrim(n_temp)));
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = countKAverageSubarrays(arr, n, k);
    
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
