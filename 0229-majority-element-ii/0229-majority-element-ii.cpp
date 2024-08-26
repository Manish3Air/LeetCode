class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v1;
	unordered_map<int,int> mp;
	int N=nums.size();
	int targ=N/3;
	for(int i=0;i<N;i++){
		mp[nums[i]]++;
	}
	for(auto x:mp){
		if(x.second>targ){
			v1.push_back(x.first);
		}
	}
	sort(v1.begin(),v1.end());
	return v1;
    }
};