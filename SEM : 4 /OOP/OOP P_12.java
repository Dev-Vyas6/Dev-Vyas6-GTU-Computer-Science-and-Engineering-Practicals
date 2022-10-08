// AIM:- : Write a program that creates a Random object with seed 1000 and displays the first 100 random integers between 1 and 49 using the NextInt (49) method.

import java.util.Random;

class Practical12 {
  public static void main(String[] args) {
    Random rn = new Random(1000);
    System.out.println(" 100 Random numbers are :: ");
    for (int i = 0; i < 100; i++) {
      System.out.print(rn.nextInt(49) + " ");
    }
  }
}
