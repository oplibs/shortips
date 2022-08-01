class Solution {
	public:
		int checkIsPalidrome(std::string s, size_t& start, size_t& end){
			size_t i;
		  // for [bb]
			// corner case: i = 0(not 1)
			for(i=0;;i++){
				// No size_t for signed
				int head=start-i;
				int tail=end+i;
				// Using size() as strlen
				if(head<0 || tail>s.size()-1 || s[head]!=s[tail]){
					start = start-i+1;
					end = end+i-1;
					return end-start+1;
				}
			}
		}
		string longestPalindrome(string s) {
			if(s.length()<2){
				return s;
			}
			int maxlen = 1;
			string result=s.substr(0, 1);
			// another corner case: start = 0;
			for(size_t start=0; start < s.length(); start++){
				size_t from=start;
				size_t to=start;
				int cur = checkIsPalidrome(s, from, to);
				if(cur>maxlen){
					maxlen=cur;
					result = s.substr(from, maxlen);
				}
				if(s[start]==s[start+1]){
					from=start;
					to=start+1;
					cur = checkIsPalidrome(s, from, to);
					if(cur>maxlen){
						maxlen=cur;
						result = s.substr(from, maxlen);
					}
				}
			}
			return result;
		}
};
