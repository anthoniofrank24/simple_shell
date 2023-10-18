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
void handle_exit(char *buf);

#endif /* SHELL_h */
