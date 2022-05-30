package specialnumbers;

public class AutomorphicNumber {

    AutomorphicNumber() {

    }

    AutomorphicNumber(Number num) {
        
        int temp=num.getNumber();
        int sq_num = num.getNumber() * num.getNumber();

        String str_num = Integer.toString(num.getNumber());
        String square = Integer.toString(sq_num);

        if (square.endsWith(str_num)) {
            System.out.println(temp + " is a Automorphic Number.\n");
            System.out.println("Automorphic Number");
            System.out.println("*************************");
            System.out.println("An Automorphic Number is a number whose square ends in the same digits as the number itself.\n\n");
        }
    }
}
