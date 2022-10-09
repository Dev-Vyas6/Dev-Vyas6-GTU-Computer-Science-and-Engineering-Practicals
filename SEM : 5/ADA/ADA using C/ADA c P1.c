// Aim: Implementation and Time analysis of sorting algorithms. Bubble sort, Selection sort, Insertion sort, Merge sort, Quick sort.

// 1.1 Bubble Sort

#include <stdio.h>
#include <time.h>

void BubbleSort(int a[], int size);
int main() {
  int arr[50], n, i;
  time_t start, end;
  double timeDiff;
  printf("\nEnter the size of array:- ");
  scanf("%d", & n);
  printf("\nEnter the elements of array:- ");
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  start = clock();
  BubbleSort(arr, n);
  end = clock();
  timeDiff = (difftime(end, start) / CLOCKS_PER_SEC);
  printf("\nTime Complexity of Bubble sort is:- %lf", timeDiff);
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
  printf("\nThe sorted elements of an array is:- ");
  for (i = 0; i < size; i++) {
    printf("%d\t", a[i]);
  }
}

// 1.2:-Selection sort

#include <stdio.h>

#include <time.h>

void selectionsort(int a[], int size);
int main() {
  int arr[50], n, i;
  time_t start, end;
  double timeDiff;
  printf("\nEnter the size of array:- ");
  scanf("%d", & n);
  printf("\nEnter the elements of array:- ");
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }
  start = clock();
  selectionsort(arr, n);
  end = clock();
  timeDiff = (difftime(end, start) / CLOCKS_PER_SEC);
  printf("\nTime Complexity Selection sort is:- %lf", timeDiff);
}
void selectionsort(int a[], int size) {
  int i, j, temp, min_idx;
  for (i = 0; i < (size - 1); i++) {
    min_idx = i;
    for (j = i + 1; j < size; j++) {
      if (a[min_idx] > a[j]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      temp = a[i];
      a[i] = a[min_idx];
      a[min_idx] = temp;
    }
  }
  printf("\nThe sorted elements of an array is:- ");
  for (i = 0; i < size; i++) {
    printf("%d\t", a[i]);
  }
}

// 1.3:-Insertion sort

#include<stdio.h>

#include<time.h>

int main() {
  int n, a[100], i, j, key;
  time_t start, end;
  double t;
  printf("Enter the size of array:");
  scanf("%d", & n);
  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", & a[i]);
  }
  start = clock();
  for (i = 1; i < n; i++) {
    key = a[i];
    for (j = i - 1; j >= 0 && key < a[j]; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = key;
  }
  for (i = 0; i < n; i++) {
    printf("%4d", a[i]);
  }
  end = clock();
  t = (difftime(end, start) / CLOCKS_PER_SEC);
  printf("\nTime efficiency is :%lf", t);
}

// 1.4:-Merge sort:-

#include<stdio.h>

#include <time.h>

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
int main() {
  int a[50], n, i;
  time_t start, end;
  double timeDiff;
  printf("\nEnter the size of array:- ");
  scanf("%d", & n);
  printf("\nEnter the elements of array:- ");
  start = clock();
  for (i = 0; i < n; i++) {
    scanf("%d", & a[i]);
  }
  mergeSort(a, 0, n - 1);
  printf("\nThe sorted elements of an array is:- ");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  end = clock();
  printf("\ntime efficiency is %lf", difftime(end, start) / CLOCKS_PER_SEC);
}
void mergeSort(int a[], int low, int high) {
  int mid, i;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
void merge(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, k, index = low;
  int temp[50];
  while (i <= mid && j <= high) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i = i + 1;
    } else {
      temp[index] = a[j];
      j = j + 1;
    }
    index++;
  }
  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      index++;
      j++;
    }
  } else {
    while (i <= mid) {
      temp[index] = a[i];
      index++;
      i++;
    }
  }
  k = low;
  while (k < index) {
    a[k] = temp[k];
    k++;
  }
}

// 1.5:-Quick sort

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int * i, int * j);
void printArray(int n, int array[]);
int main() {
  int n, array[20], i;
  time_t start, end, high, low;
  double complexity;
  printf("Enter number of elements in the array : ");
  scanf("%d", & n);
  printf("Enter %d elements : ", n);
  for (i = 0; i < n; i++)
    scanf("%d", & array[i]);
  start = clock();
  quicksort(array, 0, n - 1);
  end = clock();
  printf("\nSorted Array : ");
  printArray(n, array);
  complexity = difftime(end, start) / CLOCKS_PER_SEC;
  printf("\nStart time : %ld \nEnd time : %ld \nClocks per second : %ld \nTime Complexity : %
    f ",start, end, CLOCKS_PER_SEC, complexity);
    return 0;
  }
  void quicksort(int array[], int low, int high) {
    if (low < high) {
      int pivot = partition(array, low, high);
      quicksort(array, low, pivot - 1);
      quicksort(array, pivot + 1, high);
    }
  }
  int partition(int array[],
    int low, int high) {
    int pivot = array[high], i;
    i = low - 1;
    for (int j = low; j < high; j++) {
      if (array[j] < pivot) {
        i++;
        swap( & array[i], & array[j]);
      }
    }
    swap( & array[i + 1], & array[high]);
    return i + 1;
  }
  void swap(int * i, int * j) {
    int temp = * i;
    * i = * j;
    * j = temp;
  }
  void printArray(int n, int array[]) {
      for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    }
    * j = temp;
}
void printArray(int n, int array[]) {
  for (int i = 0; i < n; i++)
    printf("%d ", array[i]);
}
