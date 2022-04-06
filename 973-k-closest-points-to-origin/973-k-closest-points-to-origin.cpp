class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
    priority_queue<pair<double, vector<int>>> pq;
    for(auto v:points){
        double dist=pow(pow(v[0],2)+pow(v[1],2),0.5);
        pq.push({dist,v});
        if(pq.size()>k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;   
    }
};