// AIM:- : Write a program that generate 6*6 two-dimensional matrix, filled with 0’s and 1’s , display the matrix,check every raw and column have an odd number’s of 1’s.

import java.util.Scanner;
class Practical11 {
  public static int[][] create_matrix()
  {
    int[][] matrix = new int[6][6];
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        matrix[i][j] = (int) ((Math.random() * 5) % 2);
      }
    }
    return matrix;
  }
  public static void display(int[][] matrix)
  {
    System.out.print("\n Matrix is : \n");
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }
  public static void main(String[] args)
  {
    int matrix[][];
    int i, j, cnt;
    matrix = create_matrix();
    display(matrix);
    System.out.println("\n Rows having ODD Numbers of 1's:  ");
    for (i = 0; i < 6; i++)
    {
      cnt = 0;
      for (j = 0; j < 6; j++)
      {
        if (matrix[i][j] == 1)
        {
          cnt++;
        }
      }
      if (cnt % 2 != 0)
      {
        System.out.println("Row " + (i + 1) + " Have ODD numbers of 1's.");
      }
    }
    System.out.println("\n Rows having ODD Numbers of 1's:   ");
    for (i = 0; i < 6; i++)
    {
      cnt = 0;
      for (j = 0; j < 6; j++)
      {
        if (matrix[j][i] == 1)
        {
          cnt++;
        }
      }
      if (cnt % 2 != 0)
      {
        System.out.println("Column " + (i + 1) + "Have ODD numbers of 1's.");
      }
    }
  }
}
