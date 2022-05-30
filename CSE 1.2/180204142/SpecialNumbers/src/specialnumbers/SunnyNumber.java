package specialnumbers;

public class SunnyNumber {

    SunnyNumber() {

    }

    SunnyNumber(int num) {
        int c = 0;
        for (int i = 0; i < num; i++) {
            if ((i * i) - 1 == num) {
                c = 1;
                break;
            }

        }
        if (c == 1 || num == 0) {
            System.out.println(num + " is a Sunny Number.\n");
            System.out.println("Sunny Number");
            System.out.println("*************************");
            System.out.println("A number n is said to be Sunny Number if square root of(n+1) is an integer.\n\n");
        }
    }
}
