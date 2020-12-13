class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<char> letters;
        for(int i = 0; i < 26; i++) {
            letters.insert('a' + i);
        }

        set<string> wordSet;
        for(auto& word : wordList) {
            wordSet.insert(word);
        }
        int res = 0;
        deque<string> dq({beginWord});
        while(!dq.empty()) {
            int len = dq.size();
            res++;
            while(len > 0){
                len--;
                string str = dq[0];
                if(str == endWord) return res;
                dq.pop_front();
                for(int i = 0; i < str.size(); i++) {
                    string tmpStr = str;
                    char tmpCh = tmpStr[i];
                    letters.erase(tmpCh);
                    for(auto& l : letters) {
                        tmpStr[i] = l;
                        if(wordSet.find(tmpStr) != wordSet.end()) {
                            wordSet.erase(tmpStr);
                            dq.push_back(tmpStr);
                        }
                    }
                    letters.insert(tmpCh);
                }
            }
        }
        return 0;
    }
};