class Solution {

	bool checkCycle(vector<vector<int>>& prerequisites, vector<int>& vi,  vector<vector<int>>& adj, int numCourses, int curr){

		if(vi[curr]==2){
			return true;
		}

		vi[curr]=2;

		for(int i=0;i<adj[curr].size();i++){
			if(vi[adj[curr][i]]!=1){
				bool temp=checkCycle(prerequisites, vi, adj, numCourses, adj[curr][i]);
				if(temp==true)
					return true;
			}
		}

		vi[curr]=1;

		return false;
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  		vector<int> vi(numCourses,0);

  		vector<vector<int>> adj(numCourses);

  		for(int i=0;i<prerequisites.size();i++){
            vector<int> t;
            // t.push_back(prerequisites[i][1]);
  			adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
  		}

  		for(int i=0;i<numCourses;i++){
  			if(vi[i]==0){
  				bool temp=checkCycle(prerequisites, vi, adj, numCourses, i);
  				if(temp==true){
  					return false;
  				}
  			}
  		}

  		return true;      
    }
};