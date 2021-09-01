#include "String.h"
#include <stdio.h>

int main()
{
    String *firstname = CreateString("John");
    String *lastname = CreateString("Malkovich");

    int comp = CompareString(firstname, lastname);

    printf("%d\n", comp);

    AppendCString(firstname, "hello");
    
    

	return 0;
}