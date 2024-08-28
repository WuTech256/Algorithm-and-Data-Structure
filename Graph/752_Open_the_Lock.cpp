// Với bài này ta cần xoay từng vòng 1 cho đến khi tìm được target. 
// Nó tương tự việc tìm đường có distance nhỏ nhất đến với đích -> ta sử dụng thuật toán loang BFS
// -> Việc này sẽ giúp khi tìm thấy đích lần đầu tiên thì nó cũng chính là đường ngắn nhất
// -> Lưu ý ở bài này là khi vặn thì push vào queue để xét tiếp thì phải tránh những th deadends và đã thăm rồi.


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        // Nếu trong deadends mà có trạng thái init ban đầu thì còn xoay làm gì nx
        if(deadends_set.count("0000"))
            return -1; 
        // q sẽ ứng với mã + số lần move 
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis;
        vis.insert("0000");
        while(!q.empty()) {
            auto cur = q.front();
            string cur_string = cur.first;
            int move = cur.second;
            q.pop();

            if(cur_string == target)
                return move;

            for(int i = 0; i < 4; ++i) {
                for(int diff : {-1, 1}) {
                    int new_digit =  (cur_string[i] - '0' + diff + 10) % 10;
                    string new_string = cur_string;
                    new_string[i] = new_digit + '0';
                    if(!vis.count(new_string) && !deadends_set.count(new_string)) {
                        vis.insert(new_string);
                        q.push({new_string, move  +1});
                    }
                }
            }
        }
        return -1;
    }
};
