#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    const char input[] = "name = \"Ulf\"\npi = 3.14\nlog(name)";
    const int input_length = sizeof(input);
    
    int i;
    for (i = 0; i < input_length; i++) {
     
        printf("\n'%c' (ASCII value %d) is ", input[i], input[i]);
        if (isalnum(input[i])) printf("alphanumeric ");
        if (isalpha(input[i])) printf("letter ");
        if (isblank(input[i])) printf("blank ");
        if (iscntrl(input[i])) printf("control ");
        if (isdigit(input[i])) printf("digit ");
        if (isdigit(input[i])) printf("digit ");

    }
    return 0;
}
