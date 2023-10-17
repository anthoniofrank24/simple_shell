#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 12

extern char **environ;

int we_putchar(char character);
int we_puts(char *string);
int we_putstring(char *string);
int  myprinter(const char *format, ...);
int we_int(int digitseen);
int main(void);
void tokenize_input(char *input, char **args);
void execute_command(char *command, char **args);
void print_environment(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_h */
