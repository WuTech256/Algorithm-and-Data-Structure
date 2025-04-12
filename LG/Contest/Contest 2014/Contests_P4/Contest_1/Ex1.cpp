#include <bits/stdc++.h>
using namespace std;

int B;
string s16;
string sB;
string s;

void input() {
    cin >> B;
    cin >> s16;
    cin >> sB;
    cin >> s;
}

int convert(const string& binary, int g) {
    int decimal = 0;
    int base = 1; 
    for (int i = 0; i < g; ++i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; 
    }
    return decimal;
}

void solve() {
    unordered_map<char, int> hex_to_int;
    unordered_map<int, char> int_to_base_char;

    for (int i = 0; i < B; ++i) {
        int_to_base_char[i] = sB[i];
    }
    for (int i = 0; i < 16; ++i) {
        hex_to_int[s16[i]] = i;
    }
    
    vector<int> base16;
    for (char ch : s) {
        base16.push_back(hex_to_int[ch]);
    }

    int n = base16.size();
    int total_bits = n * 4;
    int g = (B == 32) ? 5 : 6;
    int m = ((total_bits + g - 1) / g) * g;

    string binary_representation(m, '0');
    for (int i = 0; i < total_bits; ++i) {
        if (base16[i / 4] & (1 << (3 - (i % 4)))) {
            binary_representation[m - 1 - i] = '1';
        }
    }

    vector<string> blocks;
    for (int i = 0; i < m; i += g) {
        blocks.push_back(binary_representation.substr(i, g));
    }

    string result;
    for (const auto& block : blocks) {
        int decimal_value = convert(block, g);
        result.push_back(int_to_base_char[decimal_value]);
    }

    reverse(result.begin(), result.end());
    cout << result << endl;
}

int main() {
    input();
    solve();
    return 0;
}
