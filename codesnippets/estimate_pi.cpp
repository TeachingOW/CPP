#include <cstdlib>
#include <iostream>
using namespace std;

#define PBSTR                                                                  \
  "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" \
  "||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 100
// hrref https://cplusplus.com/reference/cstdio/printf/
void print_progress(double percentage) {
  int val = (int)(percentage * 100);
  int lpad = (int)(percentage * PBWIDTH);
  int rpad = PBWIDTH - lpad;
  printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
  fflush(stdout);
}

double estimate(long long n, bool verbose = false) {
  long long inside_circle = 0;
  double fold = 0;
  for (long long i = 0; i < n; i++) {
    double x = ((double)rand() / RAND_MAX);
    double y = ((double)rand() / RAND_MAX);

    if (verbose) {
      double f = (double)i / n;
      if (fabs(f - fold) > 0.01) {
        fold = f;
        print_progress(f);
      }
    }
    if ((x * x + y * y) <= 1)
      inside_circle++;
  }
  if (verbose)
    print_progress(1.0);

  return (inside_circle * 4.0) / n;
}

double estimate2(long long n) {
  long long inside_circle = 0;
  const long long rand_max_2 = (long long)RAND_MAX * RAND_MAX;
  for (int i = 0; i < n; i++) {
    long long x = rand();
    long long y = rand();

    if ((x * x + y * y) <= rand_max_2)
      inside_circle++;
  }

  return (inside_circle * 4.0) / n;
}

double estimate3(long long n, bool verbose = false) {
  long long inside_circle = 0;
  const long long RAND_LIMIT = 1 << 16;
  const long long rand_max_2 = RAND_LIMIT * RAND_LIMIT;

  double fold = 0;
  for (long long i = 0; i < n; i++) {
    unsigned long long x = rand() & (RAND_LIMIT - 1);
    unsigned long long y = rand() & (RAND_LIMIT - 1);
    unsigned long long d2 = x * x + y * y;
    if (verbose) {
      double f = (double)i / n;
      if (fabs(f - fold) > 0.01) {
        fold = f;
        print_progress(f);
      }
    }
    if (d2 <= rand_max_2)
      inside_circle++;
  }
  if (verbose)
    print_progress(1.0);
  return (inside_circle * 4.0) / n;
}

int main(int argc, char *argv[]) {
  long long a = atoll(argv[1]);
  bool v = false;
  if (argc >= 4) {
    if (argv[3][0] == 't')
      v = true;
  }
  if (argc >= 3) {
    float pi = 0;
    if (argv[2][0] == '3')

      pi = estimate3(a, v);
    else
      pi = estimate(a, v);

    cout << "\n" << pi << endl;
  }
}
