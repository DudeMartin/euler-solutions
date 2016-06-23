import java.math.BigInteger;

/**
 * Project Euler, problem 20.
 *
 * @author Martin Tuskevicius
 */
public class FactorialDigitSum {

    public static void main(String[] args) {
        BigInteger factorial = BigInteger.ONE;
        for (int i = 2; i <= 100; i++) {
            factorial = factorial.multiply(BigInteger.valueOf(i));
        }
        int sum = 0;
        for (char c : factorial.toString().toCharArray()) {
            sum += c - '0';
        }
        System.out.println("Solution: " + sum + ".");
    }
}
