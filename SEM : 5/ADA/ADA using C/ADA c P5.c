// AIM: Implementation and Time analysis of Tower of Hanoi program using recursive method.

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

void Toh(int n, char source, char aux, char destination) {
  if (n == 1) {
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
  } else {
    Toh(n - 1, source, destination, aux);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    Toh(n - 1, aux, source, destination);
  }
}
void display(time_t start, time_t end) {
  double tc;
  tc = (double) difftime(end, start) / CLOCKS_PER_SEC;
  printf("\nExecution time : %lf", tc);
}
int main() {
  int e;
  time_t start, end;
  printf("Enter the number of disks: ");
  scanf("%d", & e);
  printf("\nFollowing are Move Sequence:\n");
  start = clock();
  Toh(e, 'A', 'B', 'C');
  end = clock();
  display(start, end);
  return 0;
}
