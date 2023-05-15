#include <stdio.h>

int print_name(char* name[])
{
  /*
    INPUT: char pointer to array name;
    OUTPUT: {0} if the function is completed successfully.
    
    DESCRIPTION: It takes in input in the form of a character pointer to an array and prints the contents of the array until it encounters a null byte.
  */
    printf("Your name is: %s", name);

    return 0;
}

int main()
{
    char* name[20];
    scanf("%s", &name);
    print_name(name);    


    return 0; 
}
