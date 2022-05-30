package specialnumbers;

public class SpyNumber {

    SpyNumber() {

    }

    SpyNumber(int num) {
        int pro, sum, digit;
        int temp=num;
        pro = 1;
        sum = 0;
        
        while(num != 0)
        {
            digit = num % 10;
            pro = pro * digit;
            sum = sum + digit;
            num = num / 10;
        }
        if(sum == pro)
        {
            System.out.println(temp + " is a Spy Number.\n");
            System.out.println("Spy Number");
            System.out.println("*************************");
            System.out.println("A number is said to be a Spy Number if the sum of all the digits is equal to the product of all digits.\n\n");
           
        }
        
    }

}

