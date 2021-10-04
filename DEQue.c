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

int main()
{
    front_push( ) ;
    front_push( ) ;
    front_push( ) ;

    display( ) ;
    return 0;
}
