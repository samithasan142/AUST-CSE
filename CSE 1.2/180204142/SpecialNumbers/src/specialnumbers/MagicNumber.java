package specialnumbers;

public class MagicNumber {

    MagicNumber() {

    }

    MagicNumber(int num) {
        int sum = 0, n = num;
        while (n > 9) {
            sum = n;
            int s = 0;
            while (sum != 0) {
                s = s + (sum % 10);
                sum = sum / 10;
            }
            n = s;
        }
        if (n == 1) {
            System.out.println(num + " is a Magic Number.\n");
            System.out.println("Magic Number");
            System.out.println("*************************");
            System.out.println("A number is said to be a Magic Number if the sum of its digits are calculated till a single digit is obtained by recursively adding the sum of its digits.\n" +
"If the single digit comes to be 1 then the number is a magic number.\n\n");
            
            
        }
    }

}
