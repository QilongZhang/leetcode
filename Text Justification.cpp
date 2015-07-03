class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> vs;
		bool over = false;
		for (int i = 0, j = 0; !over; i = j){
			int len = maxWidth;
			int count = 0;
			for (j = i; j < words.size(); ++j){
				int wl = words[j].length();
				if (wl> len)
					break;
				count += words[j].length();
				len = len - words[j].length() - 1;
			}
			if (j == words.size()) over = true;
			vs.push_back(lineStr(words, i, j, maxWidth, count, over));
		}
		return vs;
	}

private:
	string lineStr(vector<string> & words, int st, int ed, int maxWidth, int charCount, bool over){
		int wordsNum = ed - st;
		int spaceNum = maxWidth - charCount;
		int n1, n2;
		if (over){
			n1 = 1;
			n2 = 0;
		}
		else if (wordsNum == 1){
			n1 = spaceNum;
			n2 = 0;
		}
		else if (spaceNum % (wordsNum - 1) == 0){
			n1 = spaceNum / (wordsNum - 1);
			n2 = 0;
		}
		else{
			n1 = spaceNum / (wordsNum - 1);
			n2 = spaceNum % (wordsNum - 1);
		}
		string str(""), s1(n1, ' '), s2(n1 + 1, ' ');
		for (int i = st; i < ed - 1; ++i){
			str += words[i];
			if (n2)
				str += s2, n2 -= 1, spaceNum -= n1 + 1;
			else
				str += s1, spaceNum -= n1;
		}
		str += words[ed - 1];
		string end(spaceNum, ' ');
		str += end;
		return str;
	}
};
