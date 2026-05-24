class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size()) { //base case
            return -1;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {

            int j;

            for (j = 0; j < needle.size(); j++) {

                if (haystack[i + j] != needle[j]) { //mismatch mila toh break
                    break;
                }
            }

            if (j == needle.size()) {
                return i; // match ho gaya re baba
            }
        }

        return -1;
    }
};