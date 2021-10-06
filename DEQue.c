#include <stdio.h>

#define siz 5
int arr[ siz ] ;
int front = -1, rear = -1 ;

void display( ){
    if( front == -1 ){
        printf( "\nQueue Empty" ) ;
        return ;
    }
    printf( "\nDEque Elements are: " ) ;
    int f = front, r = rear ;
    
    if( f <= r ){
        
        while( f <= r ){
            printf( "%d ", arr[ f ] ) ;
            f++ ;
        }
    }
    else{
        while( f <= siz -1 ){
            printf( "%d ", arr[ f ] ) ;
            f++ ;
        }
        
        f = 0 ;
        while( f <= r ){
            printf( "%d ", arr[ f ] ) ;
            f++ ;
        }
    }
    
}
void front_push( void ){
    
    int val ;
    printf( "\nEnter val to insert: " ) ;
    scanf( "%d", &val ) ;
    
    if( (front == 0 && rear == siz -1) || front == rear +1 ){
        printf( "\nQueue Full" ) ;
        return ;
    }
    
    if( front == -1 ){
        front = 0 ;
        rear  = 0 ;
    }
    else{
        if( front == 0 )
            front = siz -1 ;
            
        else
            front -- ;
    }
    
    arr[ front ] = val ;
}
void rear_push( void ){
    int val ;
    printf( "\nEnter val to insert: " ) ;
    scanf( "%d", &val ) ;
    
    if( (front == 0 && rear == siz -1) || front == rear +1 ){
        printf( "\nQueue Full" ) ;
        return ;
    }
    
    if( rear == -1 ){
        front = 0 ;
        rear  = 0 ;
    }
    else{
        if( rear == siz -1 )
            rear = 0 ;
        else
            rear ++ ;
    }
    arr[ rear ] = val ;
}
void front_del( void ){
    if( front == -1  ){ // Stack is Empty
        printf( "\nDEque Empty" ) ;
        return ;
    }
    if( front == rear ){
        front = -1 ;
        rear  = -1 ;
    }
    else if( front == siz -1 ){
        front = 0 ;
    }
    else{
        front ++ ;
    }
}
void rear_del( void ){
    if( front == -1  ){ // Stack is Empty   or      rear == -1
        printf( "\nDEque Empty" ) ;
        return ;
    }
    if( rear == front ){    //  check for last Element
        front = -1 ;
        rear  = -1 ;
    }  
    else if( rear == 0 ){
        rear = siz -1 ;
    }
    else
        rear -- ;
}

int main()
{
    int n ;
    printf( "\nSize of DEQue = 5\n" ) ;
    printf("\n1.	front Push\n");
	printf("\n2.	front Pop\n");
    printf("\n3.	rear  Push\n");
	printf("\n4.	rear  Pop\n");
	printf("\n5.	display\n");
	printf("\n6.	Exiting\n");
	
    while( 1 ){
		printf("\nEnter Your Choice: ");
		scanf( "%d", &n ) ;

		switch( n ){

			case 1:     front_push() ;   	break ;
			case 2:     front_del () ;		break ;
			case 3:     rear_push () ;   	break ;
			case 4:     rear_del  () ;   	break ;

			case 5:     display( ) ;		break ;

			default:	printf("\nExiting...........\n");
			            return 0;
		}
	}
    // rear_push( ) ;
    // printf( "\nfront = %d, rear = %d\n", front, rear ) ;
    // display( ) ;
    
    return 0;
}
