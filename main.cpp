#include <stdio.h>
#include "src/rec_solver.h"

int main(void){
    const char* eq = "";
    RecType output = RecCalculate(eq);
    printf("calculated num = %lld\n", output);
}