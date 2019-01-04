#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(unsigned int &x, unsigned int &y) {
  int z = x;
  x = y;
  y = z;
}
void oddEvenSort(unsigned int* toSort, unsigned int length)
{
	bool sorted;
	while(!sorted){
		sorted = true;
		for(int i = 1; i<length-1; i+=2){
			if(toSort[i] > toSort[i+1]){
				sorted = false;
				swap(toSort[i], toSort[i+1]);
			}
		}

		for(int i=0; i<length-1; i+=2){
			if(toSort[i] > toSort[i+1]){
				sorted = false;
				swap(toSort[i], toSort[i+1]);
			}
		}
	}
}

void InitArrayWithRandomValues(unsigned int A[], unsigned long int n) {
  for (unsigned long int k = 0; k < n; k++)
    A[k] = rand();
}

unsigned int GetCurrentTime() { // in hundredths of second
  struct timeval time;
  gettimeofday(&time, NULL);
  return time.tv_sec%10000*100 + time.tv_usec/10000;
}

void TestAlgorithm() {
  unsigned int * A = (unsigned int *) malloc(30000L * sizeof(int));
  for (int cnt = 1; cnt <= 100; cnt++) { // cnt = number of experiments
    for (unsigned int k = 1; k <= 10; k++) {
      if (k > 1) printf("\t");
      unsigned long int n = 3000L * k; // n = actual array length
      InitArrayWithRandomValues(A,n);
      unsigned long int before = GetCurrentTime();
      oddEvenSort(A,n);
      unsigned long int after = GetCurrentTime();
      unsigned long int TimeElapsed = after - before; // in centiseconds
      // Not to be run about midnight!
      printf("%u", TimeElapsed);
    }
    printf("\n");
  }
  free(A);
}

int main() {
  TestAlgorithm();

  return 0;
}
