class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        char mapping[300] = {0};
        for(auto ch: key){
            if(ch != ' ' && mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }

        string str = "";
        for(auto ch: message){
            if(ch == ' '){
                str.push_back(' ');
            }
            else{
                str.push_back(mapping[ch]);
            }
        }
        return str;

    }
};
