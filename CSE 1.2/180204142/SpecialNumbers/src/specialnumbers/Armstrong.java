package specialnumbers;

public class Armstrong {

    Armstrong() {

    }

    Armstrong(Number num) {

        int temp = num.getNumber();
        int y=num.getNumber();
        int x, sum = 0;
        while (y > 0) {
            x = y % 10;
            sum = sum + x * x * x;
            y = y / 10;
        }
        if (sum == temp) {
            System.out.println(temp + " is a Armstrong Number.\n");
            System.out.println("Armstrong Number");
            System.out.println("*************************");
            System.out.println("An Armstrong Number is a number that is the sum of its own digits each raised to the power of the number of digits.\n\n ");
            
        }
    }

}
