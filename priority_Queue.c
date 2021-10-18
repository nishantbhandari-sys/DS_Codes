#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int data ;
    int prty ;
    
} Que ;

void display( Que *qp, int front, int rear ){
    if( rear == -1 ){
        printf( "QEmpty" ) ;
        return ;
    }
    printf( "\nQueue Elements: " ) ;
    int f = front ;
    while( f <= rear ){
        printf( "%d ", qp[ f ].data ) ;
        f++ ;
    }
    printf( "\n" ) ;
    
    printf( "\nQueue Priority: " ) ;
    f = front ;
    while( f <= rear ){
        printf( "%d ", qp[ f ].prty ) ;
        f++ ;
    }
    printf( "\n" ) ;
}

Que* pop( Que* q, int *f, int *r ){
    if( *r == -1 ){
        printf( "\nQEmpty" ) ;
        return q ;
    }
    
    //  Calc lowest priority
    int pp = INT_MAX ;
    for( int i = 0; i <= *r; i++ ){
        if( q[ i ].prty < pp ){
            pp = q[ i ].prty ;
        }
    }
    
    Que* temp = (Que*) malloc( sizeof(Que) * (*r) ) ;
    
    int i = 0 ;
    while( q[ i ].prty != pp ){
        
        temp[ i ].data = q[ i ].data ;
        temp[ i ].prty = q[ i ].prty ;
        i++ ;
    }
    
    ++i ;   //  skip this element
    while( i <= *r ){
        
        temp[ i -1].data = q[ i ].data ;
        temp[ i -1].prty = q[ i ].prty ;
        i++ ;
    }
    
    (*r)-- ;
    free( q ) ;

    return temp ;
}

Que* push( Que* q, int *f, int *r ){
    
    int val , priority ;
    printf( "\nEnter Data and priority: " ) ;
    scanf( "%d %d", &val, &priority ) ;
    
    if( *r == -1 ){
        *f = 0 ;
    }
    
    Que* temp = (Que*) malloc( sizeof(Que) * (*r +2) ) ;
    for( int i = 0; i <= *r; i++ ){
        temp[ i ].data = q[ i ].data ;
        temp[ i ].prty = q[ i ].prty ;
    }
    (*r)++ ;
    //  Add new element and it's priority
    temp[ *r ].data = val ;
    temp[ *r ].prty = priority ;
    
    free( q ) ;
    return temp ;
}

int main()
{
    printf( "1. push\n" ) ;
    printf( "2. pop\n" ) ;
    printf( "3. display\n" ) ;
    
    Que* q = NULL ;
    int front = -1 ;
    int rear = -1 ;
    
    int ch ;
    do{
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
            
            case 1: q = push( q, &front, &rear ) ;      break ;
            
            case 2: q = pop( q, &front, &rear ) ;      break ;
            
            case 3: display( q, front, rear ) ;      break ;
            
            default:    ch = -1 ;
        }
        if( ch == -1 ){
            printf( "\nExiting" ) ;
            break ;
        }
    } while( 1 ) ;
    

    return 0;
}
