#include <ctype.h>
#include <stdio.h>
// https://en.wikipedia.org/wiki/Lexical_analysis
// https://en.wikipedia.org/wiki/Finite-state_machine
/**
 * Checks a char and returns a string like SPACE or NEWLINE
 * @param c char
 * @return string
 */
const char *token(char c)
{

  // On a newline:
  // - If there is a new word(symbol)
  // we need a "=" and then a value to infer the
  // type.
  // - If it is a mutable it's fine to write var int variable_name = and then
  // value is fine too.
  // - Constant_thing = "something_different" is fine at this
  // step (maybe) some_function(something, something else) is fine at this
  // step too (maybe)

  // LOWER//UPPER//ALPHA <-- not important at each step
  // DIGIT
  // SPACE - MIGHT not actually matter
  // PUNCTUATION - maybe NEWLINE/SEMICOLON are more or less the same
  // NEWLINE - KINDA JUST SPACE
  // maybe NEWLINE/SEMICOLON are more or less the same
  /**
   * Operators (+, -, *, /, =, ==, etc.)
    Separators (;, ,, (, ), {, }, etc.)
    Comments ( single-line and multi-line
    String literals (e.g., "Name")
    Keywords (e.g. "if", "while", "return", etc.)
    Identifiers (e.g., variable names, function names)
    Numbers (integers, floating-point, hexadecimal, etc.)
    White space (important for layout-sensitive languages)
    End of File (End of File)
   */

  // Word
  // Number
  // Float
  // Hexadecimal
  // Identifier/symbol - function, variable, value
  // Keyword (reserved)
  // Literal

  int code;
  // if (isalnum(c)) printf("alphanumeric ");
  const int is_alpha = isalpha(c);
  const int is_blank = isblank(c);
  const int is_cntrl = iscntrl(c);
  const int is_digit = isdigit(c);
  const int is_graph = isgraph(c);
  const int is_lower = islower(c);
  const int is_print = isprint(c);
  const int is_punct = ispunct(c);
  const int is_space = isspace(c);
  const int is_upper = isupper(c);
  if (is_graph)
    printf("\n'%c' (ASCII value %d) is ", c, c);
  else
    printf("\n_ _ (ASCII value %d) is ", c);
  // if (is_lower) printf("lower "); // return LOWER
  // if (is_upper) printf("upper "); // return UPPER
  if (is_alpha)
    return "ALPHA";
  if (is_digit)
    return "DIGIT";
  // if (is_blank) printf("blank ");

  // if (is_graph) printf("graph ");
  // if (is_print) printf("print ");
  // if (is_punct) printf("punct "); // return PUNCT
  if (is_cntrl)
    printf("control ");
  if (is_blank)
    return "SPACE";

  // if (!is_cntrl && is_space && is_blank) printf("SPACE "); // is_blank is
  // actually enough if (is_cntrl && is_space) printf("NEWLINE "); // return
  if (is_cntrl && !is_space)
    return EOF;
  return "UNDEFINED";
}
int main(int argc, char const *argv[])
{
  const char input[] = "name = \"Ulf\"\npi = 3.14\nlog(name)";
  const int input_length = sizeof(input);

  int i;
  for (i = 0; i < input_length; i++)
  {
    printf("%s", token(input[i]));
  }
  return 0;
}
