// CheckPalinfrome 2
class Solution {
public:
    bool checkPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]){
               return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string& s) {
        int i = 0;
        int j = s.length()-1;
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                bool ans1 = checkPalindrome(s, i+1, j);
                bool ans2 = checkPalindrome(s, i, j-1);

                return ans1 || ans2;
            }
        }
        return true;
    }
};

// Palindromic Substring
class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int total = 0;
        for(int center = 0; center < s.length(); center++){
            int oddKaAns = expand(s, center, center);
            int EvenKaAns = expand(s, center, center+1);
            total = total+oddKaAns + EvenKaAns;
        }
        return total;
    }
};
