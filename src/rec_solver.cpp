#include "rec_solver.h"

size_t str_pos = 0;

RecType GetG(const char* str_equation);
RecType GetE(const char* str_equation);
RecType GetT(const char* str_equation);
RecType GetP(const char* str_equation);
RecType GetN(const char* str_equation);

RecType RecCalculate(const char* str_equation){
    assert(str_equation != NULL);
    return GetG(str_equation);
}

RecType GetG(const char *str_equation)
{
    
    assert(str_equation != NULL);
    
    RecType val = GetE(str_equation);
    syntax_assert(str_equation[str_pos] == '\0', "Bad GetG last symbol!");
    return val;
}

RecType GetE(const char *str_equation)
{
    
    assert(str_equation != NULL);

    size_t old_str_pos = str_pos;
    
    static constexpr char operations[] = {'+', '-'};
    RecType val1 = GetT(str_equation);
    while(
        str_equation[str_pos] == operations[0] || 
        str_equation[str_pos] == operations[1]
    ){
        char op = str_equation[str_pos];
        str_pos++;
        RecType val2 = GetT(str_equation);
        switch (op)
        {
        case operations[0] /*+*/: val1 += val2;         break;
        case operations[1] /*-*/: val1 -= val2;         break;
        default: syntax_assert(false, "Bad opertion!"); break;
        }
    }
    syntax_assert(str_pos > old_str_pos, "Bad GetE exec!");
    return val1;
}

RecType GetT(const char *str_equation)
{
    
    assert(str_equation != NULL);

    size_t old_str_pos = str_pos;
    
    static constexpr char operations[] = {'*', '/'};
    RecType val1 = GetP(str_equation);
    while(
        str_equation[str_pos] == operations[0] || 
        str_equation[str_pos] == operations[1]
    ){
        char op = str_equation[str_pos];
        str_pos++;
        RecType val2 = GetP(str_equation);
        switch (op)
        {
        case operations[0] /***/: val1 *= val2;         break;
        case operations[1] /*/*/: val1 /= val2;         break;
        default: syntax_assert(false, "Bad opertion!"); break;
        }
    }

    syntax_assert(str_pos > old_str_pos, "Bad GetT exec!");
    return val1;
}

RecType GetP(const char *str_equation)
{
    
    assert(str_equation != NULL);

    RecType val = 0;

    static constexpr char operations[] = {'(', ')'};
    if(str_equation[str_pos] == operations[0]){
        str_pos++;
        val = GetE(str_equation);
        syntax_assert(str_equation[str_pos] == operations[1], "Incorrect closing brackets!");
        str_pos++;
    }
    else{
        val = GetN(str_equation);
    }
    return val;
}

RecType GetN(const char *str_equation)
{
    assert(str_equation != NULL);

    size_t old_str_pos = str_pos;

    RecType val = 0;
    while(str_equation[str_pos] >= '0' && str_equation[str_pos] <= '9'){
        val = val * 10 + str_equation[str_pos] - '0';
        str_pos++;
    }
    syntax_assert(str_pos > old_str_pos, "Bad GetN exec!");
    return val;
}
