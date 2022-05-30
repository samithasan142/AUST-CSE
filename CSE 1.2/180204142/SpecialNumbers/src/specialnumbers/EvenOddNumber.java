package specialnumbers;

public class EvenOddNumber {

    EvenOddNumber() {

    }

    EvenOddNumber(int num) {
        if (num % 2 == 0) {
            System.out.println(num + " is a Even Number.\n");
            System.out.println("Even Number");
            System.out.println("*************************");
            System.out.println("An even number is an integer which is evenly divisible by two. This means that if the integer is divided by 2, it yields no remainder, so it has 0 parity. ");
        } else {
            System.out.println(num + " is a Odd Number.\n");
            System.out.println("Odd Number");
            System.out.println("*************************");
            System.out.println("An odd number is an integer which is not a multiple of two; A number that when divided by two, leaves a remainder.");
        }
    }
}
