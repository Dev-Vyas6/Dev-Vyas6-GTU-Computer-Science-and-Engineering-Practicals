// AIM:- Write a program that reads an integer and displays all its smallest factors in increasing order. For example if input number is 120, the output should be as follows:2,2,2,3,5. 

import java.util.Scanner;
public class Practical8 {
  public static void main(String[] args)
  {
    int div = 2;
    Scanner input = new Scanner(System.in);
    System.out.print("Enter Integer Value : ");
    int number = input.nextInt();
    while (number > 1)
    {
      if (number % div == 0)
      {
        System.out.print(div + ",");
        number = number / div;
      }
      else
      {
        div++;
      }
    }
  }
}
