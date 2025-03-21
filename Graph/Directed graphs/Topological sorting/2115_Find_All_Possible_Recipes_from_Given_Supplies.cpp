class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // Lưu trữ các nhà cung cấp
        unordered_set<string> availableSupplies;
        // map công thức sang number
        unordered_map<string, int> recipeToIndex;
        // tạo sự phụ thuộc giữa công thức và thành phần
        unordered_map<string, vector<string>> dependencyGraph;

        // Insert các thành phần đang có
        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        // Tạo map công thức -> idx
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        // Đếm số lượng thành phần chưa có
        vector<int> inDegree(recipes.size(), 0);

        // Xây dựng mối liên hệ giữa công thức và thành phần
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            for (string& ingredient : ingredients[recipeIdx]) {
                if (!availableSupplies.count(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                    // nếu mà không tồn tại thành phần thì tăng lên là công thức này còn thiếu x thành phần
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Tạo 1 queue cho công thức không bị thiếu thành phần nào cả
        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

        // thực hiện topo order
        vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            // Nếu mà không tìm thấy cái công thức mới là thành phần của cái nào thì continue
            if (!dependencyGraph.count(recipe)) continue;

            // xuống đến đây là ta đã tạo ra được thành phần mới
            // ta bỏ bớt `dependentRecipe` cái thằng thành phần mới này ra khỏi vì mình đã make được rồi
            for (string& dependentRecipe : dependencyGraph[recipe]) {
                if (--inDegree[recipeToIndex[dependentRecipe]] == 0) {
                    queue.push(recipeToIndex[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};
