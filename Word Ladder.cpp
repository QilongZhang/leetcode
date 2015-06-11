class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict){
		unordered_set<string> Head_set = {beginWord};
		unordered_set<string> Tail_set = { endWord };
		return myladderLength(Head_set, Tail_set, wordDict, 1);
	}

private:
	int myladderLength(unordered_set<string> & set1, unordered_set<string> & set2, unordered_set<string> & wordDict, int level){
		if (set1.empty()){
			return 0;
		}
		unordered_set<string> set3;
		for (auto word : set1){
			for (auto & ch : word){
				auto originalCh = ch;
				for (ch = 'a'; ch <= 'z'; ++ch){
					if (ch != originalCh){
						if (set2.count(word)){
							return level + 1;
						}
						if (wordDict.count(word)){
							set3.insert(word);
							wordDict.erase(word);
						}
					}
				}
				ch = originalCh;
			}
		}
		return set3.size() <= set2.size() ? myladderLength(set3, set2, wordDict, level + 1) : myladderLength(set2, set3, wordDict, level + 1);
	}
};
