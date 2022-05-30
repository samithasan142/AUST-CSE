package specialnumbers;

public class MersenneNumber {

    MersenneNumber() {

    }

    MersenneNumber(int num) {
        int n1 = num + 1;

        int power = 0;
        int ans = 0;
        for (int i = 0;; i++) {
            power = (int) Math.pow(2, i);
            if (power > n1) {
                break;
            } else if (power == n1) {
                System.out.println(num + " is a Mersenne number.\n");
                ans = 1;
                System.out.println("Mersenne Number");
                System.out.println("*************************");
                System.out.println("A number is said to be mersenne number if it is one less than a power of 2.\n\n");
            }
        }
        
    }
}
