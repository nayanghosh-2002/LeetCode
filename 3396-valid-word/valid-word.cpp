class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        
        //check length of string
        if(n < 3){
            return false;
        }

        //validates char
        bool isVowel = false, isConsonant = false;
        unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        for(char c : word){
            if(!isalnum(c)){
                return false;
            }
            if(vowels.count(c)){
                isVowel  =  true;
            }
            else if(isalpha(c)){
                isConsonant = true;
            }
        }
        return isVowel && isConsonant;

    }
};