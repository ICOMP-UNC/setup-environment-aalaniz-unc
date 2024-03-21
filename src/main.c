#include "greetings.h"
#include <stdio.h>

#include "static.h"
#include "dynamic.h"

int main(int argc, char* argv[])
{
    printf("Hello, OS II. Welcome to 2024 course!\n");
    greetings();
    printf("Calling dynamic lib from main program. I get '%d'\n", dynamic_lib_function("Hello, OS II"));
    printf("Calling static lib from main program. I get '%d'\n", static_lib_function("Bye, OS II"));
    return 0;
}