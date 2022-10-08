// AIM : Write a recursive method that returns the smallest integer in an array. Write a test program that prompts the user to enter an integer and display its product.

import java.util.*;
class P22_1 {
    // recursive function (calling itself) 
    public static int findMinimum(int A[], int n) {
        if (n == 1) return A[0];
        return Math.min(A[n - 1], findMinimum(A, n - 1));
    }
    public static void main(String args[]) {
        int A[] = { 23, 56, 89, 12, 45, 78 };
        int n = A.length;
        System.out.println("The minimum number from the array is :  "+findMinimum(A, n));
        }
    }

import java.util.Scanner;
class P22_2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int product = 1;
        System.out.print("Enter five integers: ");
        int[] list = new int[5];
        for (int i = 0; i < list.length; i++) {
            list[i] = input.nextInt();
            product *= list[i];
        }
        System.out.println("The Product of elements is " + product);
    }
}
