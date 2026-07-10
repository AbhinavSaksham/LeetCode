class Solution {
    public boolean validPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;

        while (left < right) {
            if (s.charAt(left) == s.charAt(right)) {
                left++;
                right--;
            }
            else{
                return palindrome(s,left+1,right) || palindrome(s,left, right-1);
            }
        }
        return true; 
    }

    private static boolean palindrome(String s, int left, int right){
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}