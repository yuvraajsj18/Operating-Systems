#include <stdio.h>

void greetings(char* name,  char*(*fn)())
{
    printf("%s, %s", (char*)(*fn)(), name);
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
    greetings("Harry", formal);
    printf("\n");
    greetings("Harry", informal);
    printf("\n");

    return 0;
}