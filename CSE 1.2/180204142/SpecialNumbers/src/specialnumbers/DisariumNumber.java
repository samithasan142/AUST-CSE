package specialnumbers;

public class DisariumNumber {

    DisariumNumber() {

    }

    DisariumNumber(Number num) {
        int temp = num.getNumber(), d = 0, sum = 0;
        String s = Integer.toString(num.getNumber());
        int len = s.length();

        while (temp > 0) {
            d = temp % 10;
            sum = sum + (int) Math.pow(d, len);
            len--;
            temp = temp / 10;
        }

        if (sum == num.getNumber()) {
            System.out.println(num + " is a Disarium Number.\n");
            System.out.println("Disarium Number");
            System.out.println("*************************");
            System.out.println("A Disarium Number is a number if the sum of its digits powered with their respective position is equal to the original number.\n\n");
        } 
    }
}
