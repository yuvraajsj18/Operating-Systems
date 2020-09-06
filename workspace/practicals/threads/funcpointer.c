#include <stdio.h>

void greetings(char* name,  char(*fn)())
{
    printf("%s, %s", (*fn)(), name);
}

char* formal()
{
    return "Hello";
}

char* informal()
{
    return "Hiya";
}

int main()
{
    greetings("Harry", &formal);
    greetings("Harry", &informal);

    return 0;
}