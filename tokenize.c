#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    const char input[] = "name = \"Ulf\"\npi = 3.14\nlog(name)";
    const int input_length = sizeof(input);
    
    int i;
    for (i = 0; i < input_length; i++) {
        // on a newline
        // if there is a new word(symbol) we need a = and then a value to infer the type
        // if it is a mutable it's ok to write var int a; 
        // = and then value is ok too
        // constant_thing = "something_different" is ok at this step (maybe)
        // some_function(something, something else) is ok at this step too (maybe)
        

        // LOWER//UPPER//ALPHA <-- not important at each step
        // DIGIT
        // SPACE - MIGHT not actually matter
        // PUNCT - maybe NEWLINE/SEMICOLON are more or less the same
        // NEWLINE - KINDA JUST SPACE
        // maybe NEWLINE/SEMICOLON are more or less the same
    /**
     * Operators (+, -, *, /, =, ==, etc.)
Separators (;, ,, (, ), {, }, etc.)
Comments ( single-line and multi-line 
String literals (e.g., "Ulf")
Keywords (e.g., if, while, return, etc.)
Identifiers (e.g., variable names, function names)
Numbers (integers, floating-point, hexadecimal, etc.)
Whitespace (important for layout-sensitive languages)
End of File (EOF)
     */

        // word
        // number
        // float
        // hex
        // identifier/symbol - function, variable, value
        // keyword (reserved)
        // literal

        int code;
        // if (isalnum(input[i])) printf("alphanumeric ");
        const int is_alpha = isalpha(input[i]);
        const int is_blank = isblank(input[i]);
        const int is_cntrl = iscntrl(input[i]);
        const int is_digit = isdigit(input[i]);
        const int is_graph = isgraph(input[i]);
        const int is_lower = islower(input[i]);
        const int is_print = isprint(input[i]);
        const int is_punct = ispunct(input[i]);
        const int is_space = isspace(input[i]);
        const int is_upper = isupper(input[i]);
        if (is_graph) printf("\n'%c' (ASCII value %d) is ", input[i], input[i]);
        else printf("\n_ _ (ASCII value %d) is ", input[i]);
        // if (is_lower) printf("lower "); // return LOWER
        // if (is_upper) printf("upper "); // return UPPER
        // if (is_alpha) printf("letter ");
        // if (is_digit) printf("digit "); // return DIGIT
        // if (is_blank) printf("blank ");
        if (is_blank) code = 32; // SPACE return SPACE
        // if (is_graph) printf("graph ");  
        // if (is_print) printf("print ");
        // if (is_punct) printf("punct "); // return PUNCT
        if (is_cntrl) printf("control ");
        if (is_space) printf("space ");
        // if (!is_cntrl && is_space && is_blank) printf("SPACE "); // is_blank is actually enough
        // if (is_cntrl && is_space) printf("NEWLINE "); // return NEWLINE
        // if (is_cntrl && !is_space) printf("EOF? "); // END
        
    }
    return 0;
}
