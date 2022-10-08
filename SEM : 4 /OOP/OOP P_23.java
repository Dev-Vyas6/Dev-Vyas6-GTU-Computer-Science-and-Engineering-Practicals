//AIM  : Write a generic method that returns the minimum elements in a two dimensional array.

import java.util.*;
class Practical23 {
    public static void main(String[] args) {
        Integer list[][] = new Integer[5][5];
        int value = 0;
        for (int i = 0; i < list.length; i++) {
            for (int j = 0; j < list[i].length; j++) {
                list[i][j] = (int)(Math.random() * 10);
                System.out.print(list[i][j] + " ");
                //list[i][j]=++value;
            }
            System.out.println("");
        }
        System.out.println("\nMinimum number is : " + (min(list)));
    }
    public static < E extends Comparable < E >> E min(E list[][]) //Generic Method.
    {
        E min = list[0][0];
        for (E[] elements: list) {
            for (E element: elements) {
                if (element.compareTo(min) < 0) {
                    min = element;
                }
            }
        }
        return min;
    }
}
