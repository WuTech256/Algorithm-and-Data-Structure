#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int res = 0;
    int n = c.size();
    int sum = 0;
    for(auto t : c) {
        sum += t;
    }
    if(k >= n) return sum; 
    sort(c.begin(), c.end(), greater<int> ());
    int cur = floor((double)n/k);
    cout << "cur: " << cur << endl;
    int g = n % k;
    int cnt = 0;
    int t = 0;
    for(int i = 0; i < cur * k; ++i) {
        cout << (t + 1) * c[i] << endl;
        res += (t + 1) * c[i];
        cnt++;
        if(cnt == k) {
            cnt = 0;
            t++;
        }
    }
    
    for(int i = 0; i < g; ++i) {
        res += (t + 1) * c[cur * k + i];
    }
    return res;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    fout << minimumCost << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
