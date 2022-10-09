// AIM: Implementation of making a change problem using greedy algorithm.

#include<stdio.h>

# define max 100
int ans[max];
int findMinCoins(int coins[], int size, int value) {
  int i, count = 0;
  for (i = 0; i < size; i++) {
    while (value >= coins[i]) {
      value -= coins[i];
      ans[count] = coins[i];
      count++;
    }
    if (value == 0)
      break;
  }
  return count;
}
void main() {
  int coins[] = { 25, 20, 10, 5};
  int value = 105, i;
  int size = sizeof(coins) / sizeof(coins[0]);
  int MinCount = findMinCoins(coins, size, value);
  printf("Solution = { ");
  for (i = 0; i < MinCount; i++)
    printf("%d, ", ans[i]);
  printf("}");
  printf("\nNumber of Coins Required to pay an amount %d : %d\n", value, MinCount);
}
