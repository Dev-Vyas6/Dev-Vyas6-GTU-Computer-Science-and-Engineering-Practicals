// AIM  : Write a program to create a file name 123.txt, if it does not exist. Append a new data to it if it already exist. write 150 integers created randomly into the file using Text I/O. Integers are separated by space.

import java.util.*;
import java.io.*;
class P21_1 {
    public static void main(String[] args) {
        int i;
        try (PrintWriter pw = new PrintWriter(new FileOutputStream(new File("123.txt"), true));) {
            for (i = 0; i < 150; i++) {
                pw.print("\n" + (int)(Math.random() * 150) + " ");
            }
        } catch (FileNotFoundException fnfe) {
            System.out.println("Cannot create the file.");
            fnfe.printStackTrace();
        }
    }
}
