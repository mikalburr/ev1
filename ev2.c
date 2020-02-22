#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTs */
int const LOOPBREAK = 99;
int const lastFloor = 15;
char const yes[] = "Yes";
char const no[] = "No\n";
int size = 0;

int main (){ 
    int const floors[ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 }; //floors
    int *goToFloors = (int*)malloc(size * sizeof(int)); //array of inputs
    int floor = 0, c = 0, input = 0; // floor, current input
    char inputC[4]; //char input
    char line[50];

    while ( input != LOOPBREAK ){
        /* Ask Floor [yes/no] */
        printf( "Would you like to go to a new floor? [ Yes or No ]\n" );
        fgets( inputC , 4 , stdin );
        input = strcmp( inputC , yes );
        setbuf(stdin, NULL);
        /* yes */
        if ( input == 0 ) {
            /* Ask for Floors */
            printf( "What floors would you like to go to? \nCurrent floor: %d \nTop floor: %d\nfloor: ", floor , floors[lastFloor] );

            fgets( line, sizeof(line) , stdin );
            printf( "%s", line );

            /* read line and put them into arrary */

        /* no */
        } else {

            input = strcmp( inputC , no );
            if ( input == 0 ){
                input = LOOPBREAK;
                printf("Bye.\n");
            } else {
                printf( "Not a valid input. Try Again [ Yes or No ]\n" );
            }

        }
    }
    //FREE MEMORY
    free(goToFloors);
}