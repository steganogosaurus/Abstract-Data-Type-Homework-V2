#include <stdio.h>
int main() {
    int n, i, check = 0;
    printf("Enter an integer: ");
    scanf(" %d", &n);
    for (i = 1; i <= n; i++) {
      if (n % i == 0) {
        check++;
      }
    } if (check ==1){
        printf("%d is not a Prime number.",n);
    } else if (check == 2) {
        printf("%d is a Prime number.",n);
    } else {
        printf("%d is not a Prime number.",n);
  }
  return 0;
}
