vector<int> findOriginalArray(vector<int>& changed) 
{
    unordered_map<int,int> mp;
    sort(changed.begin(),changed.end());
    
    for(int i=0; i<changed.size(); i++)
        mp[changed[i]]+=1;
    
    vector<int> ans;
    bool done=true;
    for(int i=0; i<changed.size(); i++)
    {
        if(mp[changed[i]]>0)
        {
            if(mp[changed[i]*2]>0)
            {
                ans.push_back(changed[i]);
                mp[changed[i]*2]-=1;
                mp[changed[i]]-=1;
            }
            else
            {
                done=false;
                break;
            }
        }
    }
    int N=changed.size();
    N>>=1;
    if(!done||ans.size()!=N)
    {
        ans.clear();
        return ans;
    }
    else
        return ans;
}