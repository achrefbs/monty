#include "monty.h"
int value;
int main(int ac, char* av[])
{
    FILE *f;
    int n = 1;
    char *str, **s;
    size_t len;
    stack_t *stack = NULL;
    str = malloc(256);
    if (str == NULL)
    {
        fprintf(stderr,"Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if(ac != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    f = fopen(av[1],"r");
    if (!f)
    {
        fprintf(stderr,"Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&str, &len ,f) != -1)
    {
        s = split(str, " $");
        inst(s, &stack, n);
        free(s[1]);
        free(s[0]);
        free(s);
        n++;
    }
    free(str);
    fclose(f);
    return 0;
}