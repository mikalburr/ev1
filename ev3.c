#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LL.C */
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void append(struct Node **head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
        new_node->data = new_data;
        new_node->next = NULL;
    if(*head == NULL){
            *head = new_node;
    return;
        }
    while(last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
}
void print_list(struct Node *n)
{
    while(n != NULL){
    printf("pl: %d\n", n->data);
            n = n->next;
    }
}
void clear_list(struct Node** n)
{
    struct Node* current = *n;
    struct Node* next;
    while(current != NULL){
            next = current->next;
    free(current);
            current = next;
        }
    //Dangling Pointer cleanup
        *n = NULL;
}

/* CONSTs */
int const LOOPBREAK = 99;
int const lastFloor = 15;
int const firstFloor = 0;
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
    int * goToFloors = (int*)malloc(0*sizeof(int)); //array of inputs
    int size = 1, input = 0, a = 0, c;
    char inputC[4]; //char input
    char line[244];
    /* DECLARE LINKED LIST OF FLOORS*/
    struct Node* head = NULL;
    while(a < 16){
        append(&head,a); a++;
    }
    struct Node* currentFloor = head;
    //print_list(head);//printf("%d", a);//return 0;
    while ( input != LOOPBREAK ){
        size = 1;
        goToFloors = (int*)malloc(0*sizeof(int));
        /* ask floor [Yes/No] */
        printf( "Would you like to go to a new floor? [ Yes or No ]\n" );
        fgets( inputC , 4 , stdin );
        input = strcmp( inputC , yes );
        if ( input == 0 ) { //yes
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf( "What floors would you like to go to? \nCurrent floor: %d \nTop floor: %d\nfloor: ", currentFloor->data , lastFloor );
            fflush(stdin);
            fgets( line, sizeof(line) , stdin );
            printf("good");
            /* read line and put values into int arrary */
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
            selectionSort(goToFloors, size); //sort floors  //printArray(goToFloors,size);
            for( int i = 1 ; i < size ; i++){               //printf("floor: %d to: %d  ", floor, goToFloors[i]);
                if ( goToFloors[i] == currentFloor->data ){ // same floor
                    printf( "You are already on this floor!\n" );
                } else if ( goToFloors[i] < firstFloor || lastFloor < goToFloors[i] ){ //bad floor
                    printf( "Not a valid floor\n" );
                } else if ( currentFloor->data < goToFloors[i]){ // going up
                    while( currentFloor->data != goToFloors[i] ){
                        currentFloor = currentFloor->next;
                        printf("... %d\n", currentFloor->data);
                    } printf( "DING\n" );
                } else if ( goToFloors[i] < currentFloor->data){ // going down
                    while( currentFloor->data != goToFloors[i] ){
                        currentFloor = currentFloor->prev;
                        printf("... %d\n", currentFloor->data);
                    } printf( "DING\n" );
                } else{ // else
                    printf("\nwtf\n");
                }
            }
        } else { //no
            input = strcmp( inputC , no );
            if ( input == 0 ){
                input = LOOPBREAK;
                printf("Bye.\n");
            } else {
                printf( "Not a valid input. Try Again [ Yes or No ]\n" );
            }
        }
        setbuf(stdin, NULL);
    }
    //free
    free(goToFloors);
    clear_list(&head);
    free(currentFloor);
}
