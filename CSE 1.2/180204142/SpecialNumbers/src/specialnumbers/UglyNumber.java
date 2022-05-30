package specialnumbers;

public class UglyNumber {

    UglyNumber() {

    }

    UglyNumber(int num) {

        int x = 0, temp=num;
        while (num != 1) {
            if (num % 5 == 0) {
                num /= 5;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 2 == 0) {
                num /= 2;
            } else {
                x = 1;
                break;
            }
        }
        if (x == 0) {
            System.out.print(temp + " is a Ugly Number.\n\n");
            System.out.println("Ugly Number");
            System.out.println("*************************");
            System.out.println("Ugly Numbers are positive numbers whose only prime factors are 2, 3 or 5.\n\n");
        }
        
    }
}
