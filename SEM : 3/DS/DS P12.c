// • Aim : -Implement following types of sort
   // : (a)Queue Sort(b) Merge Sort(c) Bubble Sort

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
      int smallest(int arr[], int k, int n) {
  int pos = k, small = arr[k], i;
  for (i = k + 1; i < n; i++) {
    if (arr[i] < small) {
      small = arr[i];
      pos = i;
    }
  }
  return pos;
}
void selection_sort(int arr[], int n) {
  int k, pos, temp;
  for (k = 0; k < n; k++) {
    pos = smallest(arr, k, n);
    temp = arr[k];
    arr[k] = arr[pos];
    arr[pos] = temp;
  }
}
void insertion_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = arr[i];
    j = i - 1;
    while ((temp < arr[j]) && (j >= 0)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}
void merge(int arr[], int beg, int mid, int end) {
  int i = beg, j = mid + 1, index = beg, temp[10], k;
  while ((i <= mid) && (j <= end)) {
    if (arr[i] < arr[j]) {
      temp[index] = arr[i];
      i++;
    } else {
      temp[index] = arr[j];
      j++;
    }
    index++;
  }
  if (i > mid) {
    while (j <= end) {
      temp[index] = arr[j];
      j++;
      index++;
    }
  } else {
    while (i <= mid) {
      temp[index] = arr[i];
      i++;
      index++;
    }
  }
  for (k = beg; k < index; k++)
    arr[k] = temp[k];
}
void merge_sort(int arr[], int beg, int end) {
  int mid;
  if (beg < end) {
    mid = (beg + end) / 2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
  }
}
int partition(int a[], int beg, int end) {
  int left, right, temp, loc, flag;
  loc = left = beg;
  right = end;
  flag = 0;
  while (flag != 1) {
    while ((a[loc] <= a[right]) && (loc != right))
      right--;
    if (loc == right)
      flag = 1;
    else if (a[loc] > a[right]) {
      temp = a[loc];
      a[loc] = a[right];
      a[right] = temp;
      loc = right;
    }
    if (flag != 1) {
      while ((a[loc] >= a[left]) && (loc != left))
        left++;
      if (loc == left)
        flag = 1;
      else if (a[loc] < a[left]) {
        temp = a[loc];
        a[loc] = a[left];
        a[left] = temp;
        loc = left;
      }
    }
  }
  return loc;
}
void quick_sort(int a[], int beg, int end) {
  int loc;
  if (beg < end) {
    loc = partition(a, beg, end);
    quick_sort(a, beg, loc - 1);
    quick_sort(a, loc + 1, end);
  }
}
int main() {
  int ch;
  printf("Enter 1 for Bubble Sort \nEnter 2 for Selection Sort \nEnter 3 for "
         "Insertion Sort \nEnter 4 for Merge Sort \nEnter 5 for Quick Sort\n");
  printf("Enter Your Choice:");
  scanf("%d", &ch);
  switch (ch) {
  case 1: // Bubble Sort
  {
    int i, n, temp, j, arr[10];
    printf("\nYou have selected Bubble Sort:");
    printf("\nEnter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
    printf("\nThe array sorted in ascending order by Bubble sort is :\n");
    for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
    break;
  }
  case 2: // Selection sort
  {
    int arr[10], i, n;
    printf("\nYou have selected Selection Sort:");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("\nThe sorted array by Selection sort is: \n");
    for (i = 0; i < n; i++)
      printf(" %d\t", arr[i]);
    break;
  }
  case 3: // Insertion sort
  {
    int arr[10], i, n;
    printf("\nYou have selected Insertion Sort:");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("\nThe sorted array by Insertion sort is: \n");
    for (i = 0; i < n; i++)
      printf(" %d\t", arr[i]);
    break;
  }
  case 4: // Merge sort
  {
    int arr[10], i, n;
    printf("\nYou have selected Merge Sort:");
    printf("\nEnter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    printf("\nThe sorted array by Merge sort is: \n");
    for (i = 0; i < n; i++)
      printf(" %d\t", arr[i]);
    break;
  }
  case 5: // Quick Sort
  {
    int arr[10], i, n;
    printf("\nYou have selected Quick Sort:");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\nThe sorted array by Quick sort is: \n");
    for (i = 0; i < n; i++)
      printf(" %d\t", arr[i]);
    break;
  }
  }
  return 0;
}
