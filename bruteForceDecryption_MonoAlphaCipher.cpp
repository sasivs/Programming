#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool cmp(pair<int, float>& a, pair<int, float>& b){
    return a.second < b.second;
}

void getPermutations(map<int, vector<int>>& subMap, int current_key, vector<int>& currentPer, vector<vector<int>>& allPer){
    if (current_key==subMap.size()){
        allPer.push_back(currentPer);
        return;
    }
    vector<int>::iterator it;
    for (int ele: subMap[current_key]){
        it = find(currentPer.begin(), currentPer.end(), ele);
        if (it == currentPer.end()){
            currentPer.push_back(ele);
            getPermutations(subMap, current_key+1, currentPer, allPer);
            currentPer.pop_back();
        }
    }
}

string bruteForceBreakage(string cipherText){
    float statFreq[26] = {8.2, 1.5, 2.8, 4.2, 12.7, 2.2, 2.0, \
        6.1, 7, 0.1, 0.8, 4, 2.4, 6.7, 7.5, 1.9, 0.1, 6, 6.3, 9, 2.8, 1, 2.4, 2, 0.1, 0.1};
    
    vector<pair<int, float>> statFreqPair;
    vector<pair<int, float>> freqPair;

    cout<<cipherText<<endl;

    vector<float> freq(26,0);

    map<int, vector<int>> subMap;
    
    for(int i=0; i<26; i++){
        statFreqPair.push_back({i, statFreq[i]});
    }
    
    sort(statFreqPair.begin(), statFreqPair.end(), cmp);
    
    for(char c: cipherText){
        freq[c-'A']++;
    }

    for(int i=0; i<26; i++){
        freqPair.push_back({i, freq[i]});
        // cout<<i<<" "<<freq[i]<<" "<<(float)freq[i]/cipherText.length()<<endl;
    }

    sort(freqPair.begin(), freqPair.end(), cmp);

    for(int i=0; i<26; i++){
        cout<<freqPair[i].first<<" "<<freqPair[i].second<<" "<<statFreqPair[i].first<<" "<<statFreqPair[i].second<<endl;
    }

    // for (auto i=statFreqPair.begin(), j=freqPair.begin(); i!=statFreqPair.end(), j!=freqPair.end(); i++, j++){
    //     subMap[j->first].push_back(i->first);
    //     cout<<(char)(j->first+'A')<<" "<<(char)(i->first+'A')<<endl;
    // }

    int i=0, j=0;
    while(i<26){
        subMap[freqPair[i].first].push_back(statFreqPair[j].first);
        while((j+1)<26 && statFreqPair[j].second==statFreqPair[j+1].second){
            subMap[freqPair[i].first].push_back(statFreqPair[j+1].first);
            j++;
        }
        for(int k=i+1; k<=j; k++){
            subMap[freqPair[k].first] = subMap[freqPair[i].first];
        }
        j++;
        i = j;
    }

    for (auto const &kv : subMap) {
        cout << (char)(kv.first+'A') << " =>";
        for (auto const &i : kv.second)
            cout << " " << (char)('A'+i);
        cout << endl;
    }

    vector<vector<int>> allPer;
    vector<int> currPer;

    getPermutations(subMap, 0, currPer, allPer);

    cout<<allPer.size()<<endl;

    for (int i=0; i<allPer.size(); i++){
        
        string plainText = "";

        for (char ch : cipherText){
            plainText += 'A'+ allPer[i][ch-'A'];
        }
        cout<<plainText<<endl;
    }
    return "";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    ofstream fout("output.txt");

    string t_temp;
    getline(cin, t_temp);

    cout<<bruteForceBreakage(t_temp)<<endl;
    
    fout.close();

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
