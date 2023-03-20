import java.util.*;
import java.io.*;

public class Main {
  static Queue<Integer> q = new LinkedList<>();
  static int F, S, G, U, D;
  static int[] user;
  static boolean[] visited;
  
  public static void bfs() {
    while(!q.isEmpty()) {
      int now = q.peek();
      int nowT = user[now];
      q.poll();
      
      int next;
      
      next = now + U;
      if (0 < next && next <= F) {
        if (!visited[next]) {
          q.add(next);
          visited[next] = true;
          user[next] = nowT + 1;
        }
      }

      next = now - D;
      if (0 < next && next <= F) {
        if (!visited[next]) {
          q.add(next);
          visited[next] = true;
          user[next] = nowT + 1;
        }
      }
    }
  }
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    F = sc.nextInt();
    S = sc.nextInt();
    G = sc.nextInt();
    U = sc.nextInt();
    D = sc.nextInt();
    
    user = new int[F + 1];
    visited = new boolean[F + 1];
    
    Arrays.fill(visited, false);
    Arrays.fill(user, -1);
    
    q.add(S);
    visited[S] = true;
    user[S] = 0;
    bfs();
    
    if (user[G] == -1) {
      System.out.println("use the stairs");
    }
    else {
      System.out.println(user[G]);
    }
  }
}