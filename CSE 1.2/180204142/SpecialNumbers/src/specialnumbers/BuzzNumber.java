package specialnumbers;

public class BuzzNumber {

    BuzzNumber() {

    }

    BuzzNumber(Number num) {
        int temp= num.getNumber(); 
        if (num.getNumber() % 10 == 7 || num.getNumber() % 7 == 0) {
            System.out.println(temp + " is a Buzz Number.\n");
            System.out.println("Buzz Number");
            System.out.println("*************************");
            System.out.println("A Buzz Number is a number if it ends with 7 or is divisible by 7.\n\n");
        }
    }

}
