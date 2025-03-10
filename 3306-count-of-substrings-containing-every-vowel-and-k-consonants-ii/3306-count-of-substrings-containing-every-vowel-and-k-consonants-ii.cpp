class Solution {
public:
    int isVowel(char ch) {
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }

    long long countOfSubstrings(string word, int k) {
        vector<int> map(26, 0);
        int vowels_c = 0;
        int con = 0;
        int j = 0;
        long long ans = 0;

        for (int i = 0; i < word.size(); i++) {
            if (isVowel(word[i])) {
                if (map[word[i] - 'a'] == 0) {
                    vowels_c++;
                }
                map[word[i] - 'a']++;
            } else {
                con++;
            }

            while (con > k) {
                if (isVowel(word[j])) {
                    map[word[j] - 'a']--;
                    if (map[word[j] - 'a'] == 0) {
                        vowels_c--;
                    }
                } else {
                    con--;
                }
                j++;
            }

            if (vowels_c == 5 && con == k) {
                vector<int> temp_map = map;
                int temp_vowels = 5;
                int t = 0;
                int pos = j;

                while (pos <= i && isVowel(word[pos])) {
                    char c = word[pos];
                    temp_map[c - 'a']--;
                    if (temp_map[c - 'a'] == 0) {
                        temp_vowels--;
                    }
                    if (temp_vowels == 5) {
                        t++;
                    } else {
                        break;
                    }
                    pos++;
                }
                ans = ans + 1;
            }
        }

        return ans;
    }
};