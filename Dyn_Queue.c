#include <stdio.h>
#include <stdlib.h>

typedef struct{
    
    int data ;
} Queue ;

int front = -1, rear = -1 ;

void display( Queue *qp ){
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
}

Queue* push( Queue *ptr ){
    
    // if( rear +1 == front ){
    //     printf( "Queue Full" ) ;
    //     return ptr ;
    // }
    int val ;
    printf( "\nEnter Value: " ) ;   scanf( "%d", &val ) ;
    
    if( rear == -1 ){
        front = 0 ;
        rear++ ;
        
        Queue *temp = (Queue*) malloc( sizeof( Queue ) ) ;
        temp[ 0 ].data = val ;
        
        return temp ;
    }
    
    rear++ ;
    Queue *temp = (Queue*) malloc( sizeof( Queue ) * (rear +2) ) ;
    for( int i = 0; i < rear; i++ ){
        temp[ i ].data = ptr[ i ].data ;
    }
    free( ptr ) ;
    temp[ rear ].data = val ;
    
    return temp ;
}

Queue* pop( Queue *ptr ){
    if( rear == -1 ){
        printf( "\nQEmpty" ) ;
        return ptr ;
    }
    printf( "\nPoPed Element is: %d\n", ptr[ front ].data ) ;
    
    if( rear == 0 ){
        free( ptr ) ;
        rear = -1 ;
        
        return NULL ;
    }
    
    Queue *temp = (Queue*) malloc( sizeof( Queue ) * rear ) ;
    for( int i = 1; i <= rear; i++ ){
        temp[ i -1].data = ptr[ i ].data ;
    }
    free( ptr ) ;
    rear-- ;
    
    return temp ;
}

int main(){
    
	printf("\n1.	Push\n");
	printf("\n2.	Pop\n");
	printf("\n3.	Display\n");
    
    int n ;
    Queue *qp = NULL ;

	while( 1 ){
		printf("\nEnter Your Choice: ");
		scanf( "%d", &n ) ;

		switch( n ){

			case 1:     qp = push( qp ) ;   	break ;

			case 2:     qp = pop( qp ) ;		break ;

			case 3:     display( qp ) ;			break ;

			default:	free( qp ) ;
			            printf("\nExiting...........\n");
			            return 0;
		}
	}
    
}

