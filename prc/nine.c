#include <stdio.h>
#include <stdlib.h>

void display( int que[], int prorty[], int front, int rear ){
    if( rear == -1 ){
        printf( "QEmpty" ) ;
        return ;
    }

    printf( "\nQueue Elements: " ) ;
    int f = front ;

    while( f <= rear ){
        printf( "%d ", que[ f ]) ;
        f++ ;
    }
    printf( "\n" ) ;
    
    printf( "\nQueue Priority: " ) ;

    while( front <= rear ){
        printf( "%d ", prorty[ front ] ) ;
        front++ ;
    }
    printf( "\n" ) ;
}

void pop( int que[], int prorty[], int *f, int *r ){
    if( *r == -1 ){
        printf( "\nQEmpty" ) ;
        return ;
    }
    
    //  Calc highest priority index
    int hp = prorty[ 0 ] ;
    int idx = 0 ;

    for( int i = 1; i <= *r; i++ ){

        if( prorty[ i ] > hp ){

            hp = prorty[ i ] ;
            idx = i ;       //  saves index of highest priority
        }
    }
    
    printf("\nPopped: %d with priority: %d", que[ idx ], prorty[ idx ] );

    while( idx < *r ){

        que[ idx ] = que[ idx +1 ] ;
        prorty[ idx ] = prorty[ idx +1 ] ;

        idx++ ;
    }

    *r -= 1 ;
}

void push( int que[], int prorty[], int *f, int *r, int n ){
    //  BAse Case
    if( *r +1 == n ){
        printf("\nQueue Full, Can't push!!!") ;
        return ;
    }

    if( *r == -1 ){

        *f = 0 ;
    }
    *r += 1 ;

    printf( "\nEnter Data and priority: " ) ;

    scanf( "%d %d", &que[ *r ] , &prorty[ *r ] ) ;

    // printf("\nq: %d, p: %d\n", que[ *r ] , prorty[ *r ] );
}

int main(){

    printf( "1. push\n" ) ;
    printf( "2. pop\n" ) ;
    printf( "3. display\n" ) ;
    
    int n ;
    printf("\nEnter Sizeof Queue: ") ;
    scanf( "%d", &n ) ;

    int que[ n ], prorty[ n ] ;
    int front = -1 ;
    int rear = -1 ;
    
    int ch ;
    
    do{
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
            
            case 1: push( que, prorty, &front, &rear, n ) ;      break ;
            
            case 2: pop( que, prorty, &front, &rear ) ;      break ;
            
            case 3: display( que, prorty, front, rear ) ;      break ;
            
            default:    ch = -1 ;
        }
        if( ch == -1 ){
            break ;
        }
    } while( 1 ) ;
    
    printf( "\nExiting...\n" ) ;

    return 0;
}