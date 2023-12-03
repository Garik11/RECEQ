#include <stdio.h>
#include "src/rec_solver.h"

int main(void){
    const char* eq = "100+100*200+(1000/7)+(1000/((700+300)/70))";
    RecType output = RecCalculate(eq);
    printf("calculated num = %lld\n", output);
}