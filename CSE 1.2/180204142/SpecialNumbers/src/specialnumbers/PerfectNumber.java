package specialnumbers;

public class PerfectNumber {

    PerfectNumber() {

    }

    PerfectNumber(int num) {
        int sum = 0, temp=num;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum = sum + i;
            }

        }
        if (sum == num) {
            System.out.println(temp + " is a Perfect Number.\n");
            System.out.println("Perfect Number");
            System.out.println("*************************");
            System.out.println("A Perfect Number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.\n\n");
        }
    }
}
