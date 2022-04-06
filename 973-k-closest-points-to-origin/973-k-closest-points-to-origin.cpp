class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
    priority_queue<pair<int,int>>pq;
    int distance=0;
    for(int i=0;i<k;i++)
    { 
        distance=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
        pq.push(make_pair(distance,i));
    }

    for(int i=k;i<points.size();i++)
    {
        distance=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
        if(distance<pq.top().first)
        {
            pq.pop();
            pq.push(make_pair(distance,i));
        }
    }
    
    while(!pq.empty())
    {
        int t=pq.top().second;
        vector<int>temp=points[t];
        ans.push_back(temp);
        pq.pop();
    }
    
    return ans;
    }
};