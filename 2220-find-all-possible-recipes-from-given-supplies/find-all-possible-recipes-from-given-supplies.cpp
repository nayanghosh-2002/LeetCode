class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> ingToRecipe;
        unordered_map<string, int> inDegree;
        queue<string> q;

        for(int i = 0; i < recipes.size(); i++){
            string recipe = recipes[i];
            inDegree[recipe] = ingredients[i].size();
            for(string ing : ingredients[i]){
                ingToRecipe[ing].push_back(recipe);
            }
        }
        
        for(string supply : supplies){
            q.push(supply);
        }


        vector<string> ans;

        while(!q.empty()){
            string current = q.front();
            q.pop();

            for(string recipe : ingToRecipe[current]){
                inDegree[recipe]--;
                if(inDegree[recipe] == 0){
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;


    }
};