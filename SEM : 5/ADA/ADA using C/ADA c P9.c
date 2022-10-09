// AIM: Implementation of a knapsack problem using greedy algorithm.

#include<stdio.h>
#include<time.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
  float x[20], tp = 0;
  int i, j, u;
  u = capacity;
  for (i = 0; i < n; i++) {
    x[i] = 0.0;
  }
  for (i = 0; i < n; i++) {
    if (weight[i] > u) {
      break;
    } else {
      x[i] = 1.0;
      tp = tp + profit[i];
      u = u - weight[i];
    }
  }
  if (i < n) {
    x[i] = u / weight[i];
  }
  tp = tp + (x[i] * profit[i]);
  printf("\nSolution : [ ");
  for (i = 0; i < n; i++) {
    printf("%.2f ", x[i]);
  }
  printf("]\nValue : %f\n", tp);
  printf("\nObjects in solution:\n");
  printf("Object_no   weight          value\n");
  printf("------------------------------------\n");
  for (i = 0; i < n; i++) {
    if (x[i] == 1) {
      printf("%d           %.2f           %.2f\n", i + 1, weight[i], profit[i]);
    } else {
      printf("%d           %.2f           %.2f\n", i + 1, (x[i] * weight[i]), (x[i] * profit[i]));
    }
  }
  printf("------------------------------------\n");
  printf("           %.2f           %.2f\n", capacity, tp);
}
void display(time_t start, time_t end) {
  double tc;
  printf("\nstart=%d\n", start);
  printf("end=%d\n", end);
  printf("clock per sec=%d\n", CLOCKS_PER_SEC);
  tc = (double) difftime(end, start) / CLOCKS_PER_SEC;
  printf("Time efficiency is %lf", tc);
}
int main() {
  float weight[20], profit[20], capacity;
  int num, i, j;
  float ratio[20], temp;
  time_t start, end;
  printf("\nEnter the no. of objects: ");
  scanf("%d", & num);
  printf("\nEnter the weights and profits of each object\n");
  for (i = 0; i < num; i++) {
    scanf("%f %f", & weight[i], & profit[i]);
  }
  printf("\nEnter the capacity of knapsack: ");
  scanf("%f", & capacity);
  for (i = 0; i < num; i++) {
    ratio[i] = profit[i] / weight[i];
  }
  for (i = 0; i < num; i++) {
    for (j = i + 1; j < num; j++) {
      if (ratio[i] < ratio[j]) {
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;
        temp = weight[j];
        weight[j] = weight[i];
        weight[i] = temp;
        temp = profit[j];
        profit[j] = profit[i];
        profit[i] = temp;
      }
    }
  }
  start = clock();
  knapsack(num, weight, profit, capacity);
  end = clock();
  display(start, end);
  return (0);
}
