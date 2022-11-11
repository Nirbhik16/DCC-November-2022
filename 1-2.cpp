//Q1. 1706. Where Will the Ball Fall
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i>=grid.size()){
            return j;
        }        
        //left to right
        if(grid[i][j]==1 && j+1<grid[0].size() && grid[i][j+1]==1){
            return dfs(i+1,j+1,grid);
        }

        //right to left
        else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1){
            return dfs(i+1,j-1,grid);
        }
        else if(grid[i][j]==1 && j+1>=grid[0].size()){
            return -1;
        }
        else{
            return -1;
        }
    }


    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> ans(col);
        for(int j=0;j<col;j++){
            ans[j]=dfs(0,j,grid);
        }
        return ans;
    }
};


//Q2. 433. Minimum Genetic Mutation
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
         queue<string>q;
        unordered_set<string>visited;
        
        q.push(startGene);
        visited.insert(startGene);
        
        int count = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string node = q.front();
                q.pop();
                
                if(node == endGene)
                {
                    return count;
                }
                
                for(char ch :"ACGT")
                {
                    for(int j=0;j<node.size();j++)
                    {
                        string adjNode = node;
                        adjNode[j] = ch;
                       if(!visited.count(adjNode) &&  find(bank.begin(),bank.end(),adjNode)!= bank.end())
            {
                q.push(adjNode);
                visited.insert(adjNode);
            }
                    }
                }
            }
             count++;
        }
       return -1; 
    }
};
