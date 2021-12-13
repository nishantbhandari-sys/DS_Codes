#include <stdio.h>

void display( int arr[], int f, int r ){

    while( f <= r ){
        
        printf( "%d ", arr[ f ] ) ;
        f++ ;
    }
    
    printf( "\n" ) ;
}

void push( int arr[], int *front, int *rear, int n ){

    if( *rear +1 == n ){
        printf( "\nQueue Full\n" ) ;
        return ;
    }

    if( *rear == -1 ){  //  || rear == -1
        
        *front = 0 ;
    }
    *rear += 1 ;

    printf( "\nEnter Element to Insert: ") ;
    scanf( "%d", &arr[ *rear ] ) ;
}

void pop( int arr[], int *front ){

    if( *front == -1 ){
        printf( "\nQueue Empty\n" ) ;
        return ;
    }
    
    printf( "PoPed Element is: %d\n", arr[ *front ] ) ;
    *front += 1 ;
}

int main(){

    int n ;
    printf( "\nEnter size of Queue: ") ;
    scanf( "%d", &n ) ;
    
    printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    
    int arr[ n ] ;
    int front = -1, rear = -1 ;

    while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;     
        
        switch( ch ){
        
            case 1:     push( arr, &front, &rear, n ) ;
                        break ;
                        
            case 2:     pop( arr, &front ) ;
                        break ;
                        
            case 3:     display( arr, front, rear ) ;
                        break ;
                        
            default:    n = -1 ;
        }
        
        if( n == -1 ){
            break ;
        }
    }


    return 0 ;
}

