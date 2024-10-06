class Solution {
public:
    vector<string> splitwords(string sentence) {
        vector<string> ans;
        string word;
        for(int i = 0; i < sentence.size(); ++i) {
            if(sentence[i] != ' ') {
                word += sentence[i];
            } else {
                ans.push_back(word);
                word = "";
            }
        }

        if(!word.empty()) ans.push_back(word);
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> a = splitwords(sentence1);
        vector<string> b = splitwords(sentence2);

        int l = 0;
        int r = 0;

        while(l < a.size() && l < b.size() && a[l] == b[l]) {
            l++;
        }

        while(r < a.size()  && r < b.size() && a[a.size() - 1 - r] == b[b.size() - 1 - r]) {
            r++;
        }
        return l + r >= min(a.size(), b.size());
    }
};
