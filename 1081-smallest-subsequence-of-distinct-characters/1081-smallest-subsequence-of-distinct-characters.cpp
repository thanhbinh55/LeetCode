class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26, false);
        string st;

        for(int i = 0; i < s.size(); i++){
            last[s[i]-'a'] = i;
        }

        for(int i = 0; i < s.size(); i++){
            if(visited[s[i] - 'a'] == true){
                continue;
            }

            while(!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i){
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(s[i]);
            visited[s[i]-'a']=true;
        }
        return st;
    }
};