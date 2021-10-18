#include <stdio.h>

typedef struct{
    int data ;
    int prty ;
} Que ;

Que* push( Que* q, int *f, int *r ){
    
    int val , priority ;
    printf( "\nEnter Data and priority" ) ;
    scanf( "%d %d", &val, &priority ) ;
    
    
}

int main()
{
    printf( "1. push" ) ;
    printf( "2. pop" ) ;
    printf( "3. display" ) ;
    
    Que* q = NULL ;
    int front = -1 ;
    int rear = -1 ;
    
    int ch ;
    do{
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
            
            case 1: push( q, &front, &rear ) ;      break ;
            
            case 1: push( q, &front, &rear ) ;      break ;
            
            case 1: push( q, &front, &rear ) ;      break ;
            
            default:    ch = -1 ;
        }
        if( ch == -1 ){
            printf( "\nExiting" ) ;
            break ;
        }
    } while( 1 ) ;
    

    return 0;
}
