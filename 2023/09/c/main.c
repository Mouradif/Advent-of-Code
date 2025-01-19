#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to compute the linear difference of an array
void linearDiff(const int *xs, int *diff, int size) {
    for (int i = 0; i < size - 1; i++) {
        diff[i] = xs[i + 1] - xs[i];
    }
}

// Function to process a line of integers recursively
int processLine(int *line, int size) {
    if (size == 0 || (size == 1 && line[0] == 0)) {
        return 0;
    }

    int allZeros = 1;
    for (int i = 0; i < size; i++) {
        if (line[i] != 0) {
            allZeros = 0;
            break;
        }
    }

    if (allZeros) {
        return 0;
    }

    int *diff = (int *)malloc((size - 1) * sizeof(int));
    if (!diff) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    linearDiff(line, diff, size);
    int result = line[size - 1] + processLine(diff, size - 1);

    free(diff);
    return result;
}

// Function to parse a line of integers from a string
int parseLine(const char *str, int *line) {
    int count = 0;
    char *token;
    char buffer[MAX_LINE_LENGTH];
    strncpy(buffer, str, MAX_LINE_LENGTH);

    token = strtok(buffer, " ");
    while (token != NULL) {
        line[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {
    FILE *file = fopen("input", "r");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int totalSum = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int numbers[MAX_LINE_LENGTH / 2]; // Assuming space-separated numbers
        int size = parseLine(line, numbers);

        if (size > 0) {
            totalSum += processLine(numbers, size);
        }
    }

    fclose(file);

    printf("%d\n", totalSum);

    return 0;
}

