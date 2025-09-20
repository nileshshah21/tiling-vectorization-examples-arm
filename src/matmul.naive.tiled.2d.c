#include <math.h>
#define ceild(n,d)  (((n)<0) ? -((-(n))/(d)) : ((n)+(d)-1)/(d))
#define floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <arm_neon.h>
#define M 512
#define N 512
#define K 512
#define alpha 1
#define beta 1
unsigned Ti = 64;
unsigned Tj = 64;
unsigned Tk = 64;
#pragma declarations
double A[M][K];
double B[K][N];
double C[M][N];
#pragma enddeclarations

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array() {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      A[i][j] = (i + j);
      B[i][j] = (double)(i * j);
      C[i][j] = 0.0;
    }
  }
}

void print_array() {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      fprintf(stderr, "%lf ", C[i][j]);
      if (j % 80 == 79)
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
  }
}

double rtclock() {
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday(&Tp, &Tzp);
  if (stat != 0)
    printf("Error return from gettimeofday: %d", stat);
  return (Tp.tv_sec + Tp.tv_usec * 1.0e-6);
}
double t_start, t_end;

int main() {
  int i, j, k;

  init_array();

  IF_TIME(t_start = rtclock());

    for (int ii = 0; ii < N; ii += Ti) {
    for (int jj = 0; jj < N; jj += Tj) {
      for (int i = ii; i < min(ii + Ti, N); i++) {
        for (int j = jj; j < min(jj + Tj, N); j++) {
          for (int k = 0; k < N; k++) {
            C[i][j] += A[i][k] * B[k][j];
          }
        }
      }
    }
  }


  IF_TIME(t_end = rtclock());
  IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));
  IF_TIME(fprintf(stdout, "%0.2lf GFLOPS\n",
                  2.0 * M * N * K / (t_end - t_start) / 1E9));

  if (fopen(".test", "r")) {
#ifdef MPI
    if (my_rank == 0) {
      print_array();
    }
#else
    print_array();
#endif
  }

  return 0;
}
