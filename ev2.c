#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTs */
int const LOOPBREAK = 99;
int const lastFloor = 15;
char const yes[] = "Yes";
char const no[] = "No\n";
int ASCIInum = 48;
 
//swap ints
void swap(int* x, int* a){
    int temp = *x;
    *x = *a;
    *a = temp;
}

//selection sort
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
    swap(&arr[min_idx], &arr[i]);
    }
}
  
//print array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main (){ 
    int const floors[ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 }; //floors
    int * goToFloors = (int*)malloc(0*sizeof(int)); //array of inputs
    int floor = 0, size = 1, input = 0, c; // floor, current input
    char inputC[4]; //char input
    char line[244];
    
    while ( input != LOOPBREAK )
    {
        size = 1;
        goToFloors = (int*)malloc(0*sizeof(int));
        /* ask change floor [Yes/No] */
        printf( "Would you like to go to a new floor? [ Yes or No ]\n" );
        fgets( inputC , 4 , stdin );
        input = strcmp( inputC , yes );
        /* yes */
        if ( input == 0 ) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            /* ask for floors */
            printf( "What floors would you like to go to? \nCurrent floor: %d \nTop floor: %d\nfloor: ", floor , floors[lastFloor] );
            fflush(stdin);
            fgets( line, sizeof(line) , stdin );
            /* read line and put them into int arrary */
            for( int i = 0 , j = 0 ; i < strlen(line) ; i++, size++, j++ ){
                inputC[i] = line[i];
                if( line[i+1] == ' ' || line[i+1] == '\n' ){
                    goToFloors[j] = inputC[i] - ASCIInum;
                    goToFloors = (int*)realloc(goToFloors, size * sizeof(int) );
                    i++;
                } else {
                    goToFloors[j] = inputC[i] - ASCIInum;
                    goToFloors[j] *= 10;
                    goToFloors[j] += line[i+1] - ASCIInum;
                    goToFloors = (int*)realloc(goToFloors, size * sizeof(int) );
                    i++; i++;
                }
            }
            //sort floors
            selectionSort(goToFloors, size);
            //printArray(goToFloors,size);
            for( int i = 1 ; i < size ; i++){
                //printf("floor: %d to: %d  ", floor, goToFloors[i]);
                /* Same Floor */
                if ( goToFloors[i] == floor ){
                    printf( "You are already on this floor!\n" );
                /* Invalid Floor */
                } else if ( goToFloors[i] < 0 || 15 < goToFloors[i] ){
                    printf( "Not a valid floor\n" );
                /* Going Up */
                } else if ( floor < goToFloors[i]){
                    while ( floor < goToFloors[i] )
                    {
                        printf( "%d, " , floor );
                        floor++;
                    }
                    printf( "%d, DING\n", floor );
                /* Going Down */
                } else if ( goToFloors[i] < floor){
                    while ( goToFloors[i] < floor ){
                        printf( "%d, " , floor );
                        floor--;
                    }

                    printf( "%d DING\n", floor );
                /* Or... */
                } else{
                    printf("\nwtf\n");
                }
                
                floor = goToFloors[i];
            }
            
            setbuf(stdin, NULL);
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
        //free goToFloors
        free(goToFloors);
    }
    
}
