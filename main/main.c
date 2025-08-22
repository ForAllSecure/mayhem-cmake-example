#include <stdio.h>
#include "calculator.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int x, y;
  char op;
  x = y = op = 0;

  // Read in <op> <x> <y>, where <op> = +, -, *, /, or g for game.
  if (fscanf(file, "%c%d%d", &op, &x, &y) != 3) {
    printf("Invalid input\n");
    fclose(file);
    return 1;
  }

  fclose(file);

  switch (op) {
    case '+': printf("%d + %d = %d\n", x, y, add(x, y)); break;
    case '-': printf("%d - %d = %d\n", x, y, subtract(x, y)); break;
    case '*': printf("%d * %d = %d\n", x, y, multiply(x, y)); break;
    case '/': printf("%d / %d = %d\n", x, y, divide(x, y)); break;
    case 'g': 
      printf("%s\n", factor_game(x, y) == 1 ? "Win!" : "Lose\n"); 
      break;
    default: printf("%c not supported\n", op);
  }

  return 0;
}