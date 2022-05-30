
package specialnumbers;

import java.util.Scanner;

/**
 *
 * @author S.M. Tasnimul Hasan
 */

public class SpecialNumbers {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an Integer Number: ");
        int num1 = sc.nextInt();
        
        Number object=new Number(num1);
        
        Armstrong a=new Armstrong(object);
        AutomorphicNumber am=new AutomorphicNumber(object);
        BuzzNumber b=new BuzzNumber(object);
        DisariumNumber d=new DisariumNumber(object);
        DuckNumber dd=new DuckNumber(object);
        
        EvenOddNumber eo=new EvenOddNumber(num1);
        HarshadNumber h=new HarshadNumber(num1);
        MagicNumber m=new MagicNumber(num1);
        MersenneNumber mm=new MersenneNumber(num1);
        NeonNumber n=new NeonNumber(num1);
        Palindrome p=new Palindrome(num1);
        PerfectNumber pp=new PerfectNumber(num1);
        SpyNumber s=new SpyNumber(num1);
        SunnyNumber ss=new SunnyNumber(num1);
        UglyNumber u=new UglyNumber(num1);
    }
    
}
