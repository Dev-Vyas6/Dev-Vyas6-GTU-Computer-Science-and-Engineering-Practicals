// Aim: Implementation of max-heap sort algorithm.

#include<stdio.h>

#include<conio.h>

#include<time.h>

#include<dos.h>

void main() {
  int arr[100], t, i, j, n;
  time_t start, end;
  double tc;
  clrscr();
  printf("Enter value of n: ");
  scanf("%d", & n);
  printf("Enter %d elements: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  start = clock();
  for (i = 0; i <= n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      if (arr[i] > arr[j]) {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        delay(100);
      }
    }
  }
  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  end = clock();
  printf("\nstart=%d\n", start);
  printf("end=%d\n", end);
  printf("clock per sec=%d\n", CLOCKS_PER_SEC);
  tc = (difftime(end, start) / CLOCKS_PER_SEC);
  printf("Time efficiency is %lf", tc);
  getch();
}
