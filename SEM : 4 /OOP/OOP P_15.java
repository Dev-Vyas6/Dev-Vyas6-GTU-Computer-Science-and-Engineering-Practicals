// AIM  : Write the bin2Dec(string binary String) method to convert a binary string into a decimal number.Implement the bin2Dec method to throw a  NumberFormatException if the string is not a binary string.

// CODE : 1
import java.util.*;

class Practical15 {
  public static String ifBin(String y) {
    String bin = "01010";
    if (y == bin) {
      System.out.print("It is a binary string.");
    }
    return y;
  }

  public static int bin2Dec(String s) {
    int dec = Integer.parseInt(s, 2);
    return dec;
  }

  public static void main(String[] args) {
    String binaryString;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the binary string:");
    binaryString = sc.nextLine();
    System.out.println(ifBin(binaryString));
    System.out.println(bin2Dec(binaryString));
  }
}

// CODE : 2
import java.util.*;

class Practical15 {
  public static int bin2Dec(String binaryString) throws NumberFormatException {
    int decimal = 0;
    int strLength = binaryString.length();
    for (int i = 0; i < strLength; i++) {
      if (binaryString.charAt(i) < '0' || binaryString.charAt(i) > '1') {
        throw new NumberFormatException("The Input String is not Binary.");
      }

      decimal += (binaryString.charAt(i) - '0') * Math.pow(2, strLength - 1 - i);
    }
    return decimal;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter Binary Value : ");
    String str = input.nextLine();
    try {
      System.out.println("Value = " + bin2Dec(str));
    } catch (NumberFormatException e) {
      System.out.println(e);
    }
  }
}
