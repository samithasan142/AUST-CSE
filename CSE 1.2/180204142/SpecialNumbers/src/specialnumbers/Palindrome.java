package specialnumbers;

public class Palindrome {

    Palindrome() {

    }

    Palindrome(int n) {
        int rev = 0, x;
        int num = n;
        while (n > 0) {
            x = n % 10;
            rev = (rev * 10) + x;
            n = n / 10;
        }
        if (num == rev) {
            System.out.println(num + " is a Palindrome Number.\n");
            System.out.println("Paindrome Number");
            System.out.println("*************************");
            System.out.println("A Palindrome Number is a number that is same after reverse.\n\n");
        }
    }
}
