#include <ctype.h>
#include <stdio.h>
// https://en.wikipedia.org/wiki/Lexical_analysis
// https://en.wikipedia.org/wiki/Finite-state_machine
/**
 * Checks a char and returns a string like SPACE or NEWLINE
 * @param c char
 * @return string
 */
const char *token(char c) {

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
  if (isgraph(c)) {
    printf("\n'%c' (ASCII value %d) is ", c, c);
  } else {

    printf("\n_ _ (ASCII value %d) is ", c);
  }
  if (isalpha(c)) {
    return "ALPHA";
  }
  if (isdigit(c)) {
    return "DIGIT";
  }

  if (isblank(c)) {
    return "SPACE";
  }

  switch (c) {
  case '=': {
    return "EQUAL";
  }
  case '.': {
    return "DOT";
  }
  case '(': {
    return "ROUND_PARENTHESIS_LEFT";
  }
  case ')': {
    return "ROUND_PARENTHESIS_RIGHT";
  }
  case '"': {
    return "DOUBLE_HYPHEN";
  }
  }
  const int is_cntrl = iscntrl(c);
  const int is_space = isspace(c);
  if (is_cntrl && is_space) {
    return "NEWLINE"; // return
  }
  if (is_cntrl && !is_space) {
    return "EOF";
  }
  return "UNDEFINED";
}
int main(int argc, char const *argv[]) {
  const char input[] = "name = \"Ulf\"\npi = 3.14\nlog(name)";
  const int input_length = sizeof(input);

  int i;
  char* symbolic[input_length][30];
  for (i = 0; i < input_length; i++) {
    // symbolic[i] = token(input[i]);
    printf("%s",  token(input[i]));
  }
  printf("%s", symbolic);
  return 0;
}
