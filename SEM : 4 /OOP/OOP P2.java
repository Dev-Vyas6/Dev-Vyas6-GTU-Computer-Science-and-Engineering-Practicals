// AIM:- Write a program that solves the following equation and displays the value x and y:  1) 3.4x+50.2y=44.5 2) 2.1x+.55y=5.9 (Assume Cramer’s rule to solve equation ax+by=e x=ed-bf/ad-bc cx+dy=f y=af-ec/ad-bc ) 

public class Practical2 {

  public static void main(String[] args)

  {

    System.out.println("Given Equation:");

    System.out.println("1. 3.4x+50.2y=44.5  \n2. 2.1x+.55y=5.9 ");

    double a = 3.4, b = 50.2, c = 2.1, d = 0.55, e = 44.5, f = 5.9, x, y;

    x = (e * d - b * f) / (a * d - b * c);

    y = (a * f - e * c) / (a * d - b * c);

    System.out.println("x = " + x);

    System.out.println("y = " + y);
  }
}
