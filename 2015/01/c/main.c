#include <unistd.h>

#define BUF_SIZE 1024

void putchar(char c) {
  write(1, &c, 1);
}

void putnbr(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n < 10) {
    putchar(n + '0');
  } else {
    putnbr(n / 10);
    putchar(n % 10 + '0');
  }
}

void putnbrln(int n) {
  putnbr(n);
  putchar('\n');
}

int main() {
  int floor = 0;
  int current_index = 0;
  int first_basement_index = 0;
  char buffer[BUF_SIZE];
  ssize_t bytes_read;

  while ((bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE))) {
    for (int i = 0; i < bytes_read; i++) {
      char c = buffer[i];
      if (c == '(') floor++;
      if (c == ')') floor--;
      current_index++;
      if (floor == -1 && first_basement_index == 0) {
        first_basement_index = current_index;
      }
    }
  }

  putnbrln(floor);
  putnbrln(first_basement_index);
}
