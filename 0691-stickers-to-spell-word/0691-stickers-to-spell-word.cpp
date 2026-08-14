class Solution {
public:
string get_modified(string target, string sticker){
    string modified = "";
    unordered_map<char,int> mp;

    for(int i = 0; i < sticker.size(); i++){
        mp[sticker[i]]++;
    }

    for(int i = 0; i < target.size(); i++){
        if(mp.find(target[i]) != mp.end()){
            mp[target[i]]--;
            if(mp[target[i]] == 0) mp.erase(target[i]);
        }else{
            modified = modified + target[i];
        }
    }

    return modified;
}

int solve(vector<string>& stickers, string target,unordered_map<string,int>& memo) {
    if(target.empty())
        return 0;

        if(memo.find(target) != memo.end()) return memo[target];

    int mini = INT_MAX;

    for(int i = 0; i < stickers.size(); i++) {

        string m_str = get_modified(target, stickers[i]);

        // Sticker didn't contribute anything
        if(m_str.size() == target.size())
            continue;

        int count = 1 + solve(stickers, m_str,memo);

        mini = min(mini, count);
    }

    return memo[target] = mini;
}

    int minStickers(vector<string>& stickers, string target) {
        set<char> s1;
        for(int i = 0; i < stickers.size(); i++){
            string temp = stickers[i];
            for(int j = 0; j < temp.size(); j++){
                s1.insert(temp[j]);
            }
        }
        // Match target

        for(int i = 0; i < target.size(); i++){
            if(s1.find(target[i]) == s1.end()) return -1;
        }

        unordered_map<string,int> memo;

        return solve(stickers,target,memo);
    }
};