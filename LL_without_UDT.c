#include <stdio.h>
#include <stdlib.h>

//  linkedList Without any UserDefined Data Type || Structure

void print( void **head ){
    
    while( head != NULL ){
        printf( "%d ", *((int*) *head ) ) ;
        head = head[ 1 ] ;
    }
}

void** linkedList( void **head, void** trv ){
    printf( "\nEnter value in LL: " ) ;
        
    if( head == NULL ){
        trv = head = (void*) calloc( 2, sizeof( void* ) ) ;
        trv[ 1 ] = head ;
    }
    
    else{
        trv[ 1 ] = (void*) calloc( 2, sizeof( void* ) ) ;
    }
    
    (*(void**)(trv[ 1 ])) = (int*) malloc( sizeof( int ) ) ;
    scanf( "%d", (int*) *((void**)(trv[ 1 ])) ) ;
        
    if( *( (int*) *((void**)(trv[ 1 ])) ) != 1 ){
        return linkedList( head, trv[ 1 ] ) ;
    }
        
    else{
        free( trv[ 1 ] ) ;
        trv[ 1 ] = NULL ;
        return head ;
    }
}

int main() {
    printf( "\nPress 1 to Exit" ) ;
    void **head = linkedList( NULL, NULL ) ;

    print( head ) ;
    // printf( "%d ", *((int*)   head[ 0 ]) ) ;
    // printf( "%d ", *((int*) *( (void**) head[ 1 ] ) ) ) ;

    free( head ) ;
    return 0;
}
