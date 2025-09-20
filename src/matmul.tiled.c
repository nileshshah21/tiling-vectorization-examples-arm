#include <math.h>
#define ceild(n,d)  (((n)<0) ? -((-(n))/(d)) : ((n)+(d)-1)/(d))
#define floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define M 512
#define N 512
#define K 512
#define alpha 1
#define beta 1

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

  int t1, t2, t3, t4, t5, t6, t7, t8, t9;
 register int lbv, ubv;
if ((K >= 1) && (M >= 1) && (N >= 1)) {
  for (t1=0;t1<=floord(M-1,128);t1++) {
    for (t2=0;t2<=floord(N-1,256);t2++) {
      for (t3=0;t3<=floord(K-1,128);t3++) {
        for (t4=16*t1;t4<=min(floord(M-1,8),16*t1+15);t4++) {
          for (t5=2*t2;t5<=min(floord(N-1,128),2*t2+1);t5++) {
            for (t6=16*t3;t6<=min(floord(K-1,8),16*t3+15);t6++) {
              for (t7=8*t4;t7<=(min(M-1,8*t4+7))-7;t7+=8) {
                for (t8=8*t6;t8<=(min(K-1,8*t6+7))-7;t8+=8) {
                  lbv=128*t5;
                  ubv=min(N-1,128*t5+127);
#pragma ivdep
#pragma vector always
                  for (t9=lbv;t9<=ubv;t9++) {
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][t8] * B[t8][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][t8] * B[t8][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][t8] * B[t8][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][t8] * B[t8][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][t8] * B[t8][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][t8] * B[t8][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][t8] * B[t8][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][t8] * B[t8][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+1)] * B[(t8+1)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+1)] * B[(t8+1)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+2)] * B[(t8+2)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+2)] * B[(t8+2)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+3)] * B[(t8+3)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+3)] * B[(t8+3)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+4)] * B[(t8+4)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+4)] * B[(t8+4)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+5)] * B[(t8+5)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+5)] * B[(t8+5)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+6)] * B[(t8+6)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+6)] * B[(t8+6)][t9];;
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][(t8+7)] * B[(t8+7)][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][(t8+7)] * B[(t8+7)][t9];;
                  }
                }
                for (;t8<=min(K-1,8*t6+7);t8++) {
                  lbv=128*t5;
                  ubv=min(N-1,128*t5+127);
#pragma ivdep
#pragma vector always
                  for (t9=lbv;t9<=ubv;t9++) {
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][t8] * B[t8][t9];;
                    C[(t7+1)][t9] = beta * C[(t7+1)][t9] + alpha * A[(t7+1)][t8] * B[t8][t9];;
                    C[(t7+2)][t9] = beta * C[(t7+2)][t9] + alpha * A[(t7+2)][t8] * B[t8][t9];;
                    C[(t7+3)][t9] = beta * C[(t7+3)][t9] + alpha * A[(t7+3)][t8] * B[t8][t9];;
                    C[(t7+4)][t9] = beta * C[(t7+4)][t9] + alpha * A[(t7+4)][t8] * B[t8][t9];;
                    C[(t7+5)][t9] = beta * C[(t7+5)][t9] + alpha * A[(t7+5)][t8] * B[t8][t9];;
                    C[(t7+6)][t9] = beta * C[(t7+6)][t9] + alpha * A[(t7+6)][t8] * B[t8][t9];;
                    C[(t7+7)][t9] = beta * C[(t7+7)][t9] + alpha * A[(t7+7)][t8] * B[t8][t9];;
                  }
                }
              }
              for (;t7<=min(M-1,8*t4+7);t7++) {
                for (t8=8*t6;t8<=min(K-1,8*t6+7);t8++) {
                  lbv=128*t5;
                  ubv=min(N-1,128*t5+127);
#pragma ivdep
#pragma vector always
                  for (t9=lbv;t9<=ubv;t9++) {
                    C[t7][t9] = beta * C[t7][t9] + alpha * A[t7][t8] * B[t8][t9];;
                  }
                }
              }
            }
          }
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
