class Solution {
public:

    int climbStairs(int n) {

        if(n <= 2) {
            return n; //base case 
        }
        int a = 1;
        int b = 2;  //

        for(int i = 3; i <= n; i++) { // i = 4

            int c = a + b; // 1+2=3         2 +3=5

            a = b;          // 1 = 2        2 =3
            b = c;          // 2 = 3        3= 5
        }

        return b; //3
    }
};