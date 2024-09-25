#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'downToZero' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int downToZero(int n) {
    vector<int> dist(n+1, 0);
    
    queue<int> q;
    q.push(n);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == 0) {
            break;
        }
        
        if(dist[cur-1] == 0) {
            q.push(cur-1);
            dist[cur-1] = dist[cur] + 1;
        }
        
        for(int i = sqrt(cur); i >= 2; --i) {
            if(cur%i == 0 && dist[cur/i] == 0) {
                dist[cur/i] = dist[cur] + 1;
                q.push(cur/i);
                
            }
        }
    }
    return dist[0];   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = downToZero(n);

        fout << result << "\n";
    }

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
