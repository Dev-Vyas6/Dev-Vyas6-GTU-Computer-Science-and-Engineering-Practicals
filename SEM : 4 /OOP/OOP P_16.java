// AIM  : Write a program that prompts the user to enter a decimal number and displays the number in a fraction. Hint: Read the decimal number as a string, extract the integer part and fractional part from the string.

import java.util.*;
import java.math.BigInteger;

class Practical16 {
  int num, den;

  // num=numerator den=denominator
  public Practical16(double d) {
    String s = String.valueOf(d);
    int dec = s.length() - 1 - s.indexOf('.');
    int den = 1;
    for (int i = 0; i < dec; i++) {
      d *= 10;
      den *= 10;
    }
    int num = (int) Math.round(d);
    this.num = num;
    this.den = den;
  }

  public Practical16(int num, int den) {
    this.num = num;
    this.den = den;
  }

  public String toString() {
    return String.valueOf(num) + "/" + String.valueOf(den);
  }

  public static void main(String[] args) {
    Double n;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the decimal number:");
    n = sc.nextDouble();
    System.out.println(new Practical16(n));
  }
}
