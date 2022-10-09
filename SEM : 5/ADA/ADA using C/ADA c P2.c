// Aim: Implementation and Time analysis of linear and Binary search.

// 2.1:-Linear search:-

#include <stdio.h>
#include <time.h>

int main() {
  int arr[50], n, i, srch_elmt;
  time_t start, end;
  printf("\nEnter the size of array:- ");
  scanf("%d", & n);
  printf("\nEnter the elements of array:- ");
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  printf("Enter the element you want to search:- ");
  scanf("%d", & srch_elmt);
  start = clock();
  for (i = 0; i < n; i++) {
    if (arr[i] == srch_elmt) {
      printf("\n%d element is found at %d index", srch_elmt, i);
      break;
    }
  }
  if (i == n) {
    printf("\n%d element is not present in array", srch_elmt);
  }
  end = clock();
  printf("\nTime Complexity of Linear search is:- %lf", difftime(end, start) / CLOCKS_PER_SEC);
}

// 2.2:- Binary Search

#include <stdio.h>

#include <time.h>

int BinarySearch(int a[], int min, int max, int element);
void BubbleSort(int a[], int size);
int main() {
  int arr[50], n, i, srch_elmt, temp, j;
  time_t start1, end1, start2, end2;
  printf("\nEnter the size of array: ");
  scanf("%d", & n);
  printf("\nEnter the elements of array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  start1 = clock();
  BubbleSort(arr, n);
  end1 = clock();
  printf("\nTime Complexity of Bubble sort is: %lf", difftime(end1, start1) / CLOCKS_PER_SEC);
  printf("\nEnter the element you want to search: ");
  scanf("%d", & srch_elmt);
  start2 = clock();
  int result = BinarySearch(arr, 0, n - 1, srch_elmt);
  if (result == -1) {
    printf("Element is not present in array");
  } else {
    printf("Element is present at index %d", result);
  }
  end2 = clock();
  printf("\nTime Complexity of Binary Search is: %lf", difftime(end2,
    start2) / CLOCKS_PER_SEC);
}
void BubbleSort(int a[], int size) {
  int temp, i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size - 1; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("\nSorted array is: ");
  for (i = 0; i < size; i++) {
    printf("%d\t", a[i]);
  }
}
int BinarySearch(int a[], int min, int max, int element) {
  while (min <= max) {
    int mid = (min + max) / 2;
    if (a[mid] == element) {
      return mid;
    } else if (a[mid] < element) {
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  return -1;
}
