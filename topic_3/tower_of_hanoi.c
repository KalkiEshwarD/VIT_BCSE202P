// Including all packages for the program to work
#include <stdio.h>

int tower_of_hanoi(int disks, char from_rod, char aux_rod, char to_rod)
{
    /*
        INPUT:  --disks-- [It is the number of disks that are to be moved]; --from_rod-- [It is the rod from which the disks are being moved denoted by characters 'A', 'B' and 'C'];
                --aux_rod-- [It is the auxiliary rod that is used to move the disks from the from_rod to to_rod]; --to_rod-- [It is the rod to which all disks are to be moved.]; 
        OUTPUT: return integer 0 if the process works correctly.

        DEPENDENCIES: --headers--{stdio.h}
        DESCRIPTION: --{RECURSIVE}-- It is the main tower of hanoi function that is used to print out all moves to move the disks to the required rod. 
    */
    if (disks == 1) {
        printf("Shift %d from %c to %c\n", disks, from_rod, to_rod);
        
        return 0;
    }
    
    tower_of_hanoi(disks - 1, from_rod, to_rod, aux_rod);
    printf("Shift %d from %c to %c\n", disks, from_rod, to_rod);
    tower_of_hanoi(disks - 1, aux_rod, from_rod, to_rod);

    return 0;
}

// Taking in the input in the form of integer and using it to pass it to tower of hanoi.
int main() {
    
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'B', 'C');
    
    return 0;
}
