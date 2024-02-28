#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
extern char **environ;

int _printf(const char *format, ...);

int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char op;
	int (*f)(va_list ptr);
} op_t;

int (*get_op_func(char s))(va_list);
int p_list_char(va_list ptr);
int p_list_str(va_list ptr);
int p_list_num(va_list ptr);

char **_spliter(char *str);
char *_getline(void);
void free_array(char **array);
int _execve(char *cmd[], char **argv);
char *_strdup(char *str);
#endif
