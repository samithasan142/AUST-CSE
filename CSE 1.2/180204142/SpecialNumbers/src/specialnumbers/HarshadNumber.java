package specialnumbers;

public class HarshadNumber {

    HarshadNumber() {

    }

    HarshadNumber(int num) {
        int temp = num, d, sum = 0;

        while (temp > 0) {
            d = temp % 10;
            sum = sum + d;
            temp = temp / 10;
        }

        if (num % sum == 0) {
            System.out.println(num + " is a Harshad Number.\n");
            System.out.println("Harshad Number");
            System.out.println("*************************");
            System.out.println("A Harshad Number in a given number base, is an integer that is divisible by the sum of its digits when written in that base.\n\n");
        }
    }
}
