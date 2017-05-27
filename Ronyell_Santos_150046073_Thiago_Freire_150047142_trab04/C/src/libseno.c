#include <stdio.h>
#include <stdlib.h>
#include "libseno.h"


double seno(double angulo){
    double term, total_so_far;
    int i;

    term = angulo;  /* First term in the expansion. */
    total_so_far = 0.0;
    for (i = 1; i <= 100; i++) {
      /* Add current term to sum. */
      total_so_far += term;
      /* Compute next term from the current one. */
      term *= -(angulo * angulo) / (2*i) / (2*i + 1);
    }
    return total_so_far;

}

double arc_seno(double seno){
  return 3.0 + 5.0;
}
