class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		head = start;
		tail = end;
		dict.erase(start);
		dict.erase(end);
		unordered_set<string> Head_set = { start };
		unordered_set<string> Tail_set = { end };
		unordered_map<string, vector<stack<string, vector<string> > > > hashMap = { { start, vector<stack<string, vector<string> > >(1, stack<string, vector<string> >(vector<string>(1, start))) },
		{ end, vector<stack<string, vector<string> > >(1, stack<string, vector<string> >(vector<string>(1, end))) } };
		vector<vector<string> > vvs;
		findLadders(Head_set, Tail_set, dict, hashMap, vvs);
		return vvs;
	}

protected:
	void findLadders(unordered_set<string> & head_set, unordered_set<string> & tail_set, unordered_set<string> & dict, unordered_map<string, vector<stack<string, vector<string> > > > & hashmap, vector<vector<string> > & vvs){
		if (head_set.empty())	return; 
		bool pathFound = false;
		unordered_set<string> set3; 
		for (auto word : head_set){
			auto originalWord = word;
			for (auto & ch : word){
				auto originalCh = ch;
				for (ch = 'a'; ch <= 'z'; ++ch){
					if (ch == originalCh) continue;
					if (tail_set.count(word)){
						pathFound = true;
						getPath(hashmap, vvs, originalWord, word);
					}
					else if(set3.count(word) || dict.count(word)){
						set3.insert(word);
						dict.erase(word);
						if (hashmap.find(word) == hashmap.end()){
							hashmap[word] = hashmap[originalWord];
							for (auto & path : hashmap[word]){
								path.push(word);
							}
						}
						else{
							for (auto path : hashmap[originalWord]){
								path.push(word);
								hashmap[word].push_back(path);
							}
						}
					}
				}
				ch = originalCh;
			}
		}
		if (!pathFound)
			set3.size() <= tail_set.size() ? findLadders(set3, tail_set, dict, hashmap, vvs) : findLadders(tail_set, set3, dict, hashmap, vvs);
	}

	void getPath(unordered_map<string, vector<stack<string, vector<string> > > > & hashmap, vector<vector<string> > & vvs, string & oword, string & nword){
		for (auto l1 : hashmap[oword]){
			for (auto l2 : hashmap[nword]){
				auto l3 = l1;
				while (!l3.empty()){
					l2.push(l3.top());
					l3.pop();
				}
				vector<string> path(l2.size());
				int st = 0, dir = 1;
				if (l2.top() == tail){
					st = l2.size() - 1, dir = -1;
				}
				while (!l2.empty()){
					path[st] = l2.top();
					l2.pop();
					st += dir;
				}
				vvs.push_back(path);
			}
		}
	}

protected:
	string head, tail;
};
