class Solution {
  public:
  int ct=0;
  Node* start = NULL;
    void getParent(Node* root, Node* par,unordered_map<Node*,Node*> &m, int target)
    {
        if(!root)return;
        ct++;
        m[root]=par;
        if(target==root->data)
        {
            start=root;
        }
        getParent(root->left,root,m,target);
        getParent(root->right,root,m,target);
        return;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>m;
        getParent(root,NULL,m,target);
        //solve(root,m,timeTaken,0);
        queue<pair<Node*,int>>timeQ;
        unordered_map<Node*,bool>timeTaken;
        int ans=-1;
        timeQ.push({start,0});
        while(!timeQ.empty())
        {
            auto currnode = timeQ.front();
            timeQ.pop();
            Node* temp = currnode.first;
            int currTime=currnode.second;
            ans=max(ans,currTime);
            if(temp->left!=NULL && timeTaken[temp->left]==false)
            {
                timeTaken[temp->left]=true;
                timeQ.push({temp->left,currTime+1});
            }
            if(temp->right!=NULL && timeTaken[temp->right]==false)
            {
                timeTaken[temp->right]=true;
                 timeQ.push({temp->right,currTime+1});
            }
            if(m[temp]!=NULL && timeTaken[m[temp]]==false)
            {
                timeTaken[m[temp]]=true;
                timeQ.push({m[temp],currTime+1});
            }
        }
        return ans;
    }
};
