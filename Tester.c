#include <stdint.h>
#include <stdio.h>
int subsetSum(uint8_t x[], uint8_t k, uint8_t v, uint8_t len) {
  printf("here %d %d %d\n",k,v,len);
  for(int i = 0; i < len; i++)
    if(v - x[i] == 0 && k == 1)
      return 1;
  if(k == 1)
    return 0;
  for(int i = 0; i < len; i++) {
    int hold = x[i];
    x[i] = 0;
    int check = subsetSum(x, k - 1, v - hold, len);
    x[i] = hold;
    if(check)
      return 1;
  }
  return 0;
}

int main(void) {
  uint8_t x[] = {1,8,6,4,3};
  uint8_t k = 1;
  uint8_t v = 9;
  uint8_t len = 5;
  printf("%s\n",subsetSum(x,k,v,len) == 1 ? "true" : "false");
}
