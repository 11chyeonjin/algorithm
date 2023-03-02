import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int target = sc.nextInt();
    int num = sc.nextInt();
    int x, y;
    int tmp = 0;
    for (int i = 0; i < num; i++) {
      x = sc.nextInt(); y = sc.nextInt();
      tmp += x * y;
    }
    if (target == tmp)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}