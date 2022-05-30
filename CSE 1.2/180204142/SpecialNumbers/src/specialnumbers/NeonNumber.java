package specialnumbers;

public class NeonNumber {

    NeonNumber() {

    }

    NeonNumber(int num) {
        int square = num * num;
        int sum = 0;
        while (square != 0)//Loop to find the sum of digits.
        {
            int a = square % 10;
            sum = sum + a;
            square = square / 10;
        }
        if (sum == num) {
            System.out.println(num + " is a Neon Number.\n");
            System.out.println("Neon Number");
            System.out.println("*************************");
            System.out.println("A Neon Number is a number where the sum of digits of square of the number is equal to the number.\n\n");
        }
    }

}
