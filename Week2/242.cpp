class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> m;
        for(auto& ch : s) {
            if(m.find(ch) == m.end()) m[ch] = 1;
            else m[ch]++;
        }
        for(auto& ch : t) {
            if(m.find(ch) == m.end() || m[ch] == 0) return false;
            else m[ch]--;
        }
        return true;
    }
};