// AIM  : Write a program for calculator to accept an expression as a string in which the operands and operator are separated by zero or more spaces. For ex: 3+4 and 3 + 4 are acceptable expressions.

import java.util.*;

class Practical13 {
  public static void main(String args[]) {
    String input = "";
    double result = 0;
    Scanner scan = new Scanner(System.in);

    System.out.print("Enter expression : ");
    input = scan.nextLine();

    if (input.indexOf("+") != -1) {
      String operands[] = input.split("\\+");
      int numbers[] = new int[operands.length];
      for (int i = 0; i < operands.length; i++) {
        numbers[i] = Integer.parseInt(operands[i].trim());
      }
      result = numbers[0] + numbers[1];
      System.out.println("Result of expression is : " + result);
    } else if (input.indexOf("-") != -1) {
      String operands[] = input.split("\\-");
      int numbers[] = new int[operands.length];
      for (int i = 0; i < operands.length; i++) {
        numbers[i] = Integer.parseInt(operands[i].trim());
      }
      result = numbers[0] - numbers[1];
      System.out.println("Result of expression is : " + result);
    } else if (input.indexOf("*") != -1) {
      String operands[] = input.split("\\*");
      int numbers[] = new int[operands.length];
      for (int i = 0; i < operands.length; i++) {
        numbers[i] = Integer.parseInt(operands[i].trim());
      }
      result = numbers[0] * numbers[1];
      System.out.println("Result of expression is : " + result);
    } else if (input.indexOf("/") != -1) {
      String operands[] = input.split("\\/");
      int numbers[] = new int[operands.length];
      for (int i = 0; i < operands.length; i++) {
        numbers[i] = Integer.parseInt(operands[i].trim());
      }
      result = numbers[0] / numbers[1];
      System.out.println("Result of expression is : " + result);
    } else {
      System.out.println("Enter a valid expression next time.");
    }
  }
}
