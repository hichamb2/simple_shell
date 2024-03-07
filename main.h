#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
extern char **environ;

int _printf(const char *format, ...);

int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);

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
int _execve(char *cmd[], char **argv, int index);
char *_strdup(char *str);
char *get_env(char *str);
char *get_path(char *command);
#endif
