package specialnumbers;

public class DuckNumber {

    DuckNumber() {

    }

    DuckNumber(Number num) {
        String str1 = Integer.toString(num.getNumber());
        int len = str1.length();

        int temp= num.getNumber();
        int countZero = 0;
        char ch;
        for (int i = 0; i < len; i++) {

            ch = str1.charAt(i);
            if (ch == '0') {
                countZero++;
            }
        }

        char beginWithZero = str1.charAt(0);
        if (beginWithZero != '0' && countZero > 0) {
            System.out.println(temp + " is a Duck Number.\n");
            System.out.println("Duck Number");
            System.out.println("*************************");
            System.out.println("A Duck Number is a number which has zeroes present in it, but there should be no zero present in the beginning of the number.\n\n");
        }

    }
}
