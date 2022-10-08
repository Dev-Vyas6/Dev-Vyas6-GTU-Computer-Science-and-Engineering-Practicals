// AIM  : Write a program that creates an Array List and adds a Loan object , a Date object , a string, and a Circle object to the list, and use a loop to display all elements in the list by invoking the object’s to String() method.

import java.util.ArrayList;
import java.util.Date;

class Practical14 {
  public static void main(String[] args) {
    ArrayList<Object> arr = new ArrayList<Object>();
    arr.add(new Loan(6900));
    arr.add(new Date());
    arr.add(new String("Welcome to Java"));
    arr.add(new Circle(15));

    for (int i = 0; i < arr.size(); i++) {
      System.out.println((arr.get(i)).toString());
    }
  }
}

class Circle {
  double radius;

  Circle(double r) {
    this.radius = r;
  }

  public String toString() {
    return "Circle with Radius " + this.radius;
  }
}

class Loan {
  double amount;

  Loan(double amt) {
    this.amount = amt;
  }

  public String toString() {
    return "Loan with Amount " + this.amount;
  }
}
