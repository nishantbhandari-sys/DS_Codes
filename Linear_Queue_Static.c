#include <stdio.h>

int front = -1, rear = -1 ;

void display( int arr[] ){

    int f = front ; 
    while( f <= rear ){
        
        printf( "%d ", arr[ f ] ) ;
        f++ ;
    }
    
    printf( "\n" ) ;
}

void push( int arr[], int n ){

    int val ;
    printf( "\nEnter Element to Insert: ") ;
    scanf( "%d", &val ) ;
    
    if( rear +1 >= n ){
        printf( "\nQueue Full\n" ) ;
        return ;
    }
    
    if( rear == -1 ){  //  || rear == -1
        
        front = 0 ;
    }
    rear++ ;
    arr[ rear ] = val ;
}

void pop( int arr[] ){

    if( front == -1 ){
        printf( "\nQueue Empty\n" ) ;
        return ;
    }
    
    printf( "PoPed Element is: %d\n", arr[ front ] ) ;
    front++ ;
}

int main(){

    int n ;
    printf( "\nEnter size of Queue: ") ;
    scanf( "%d", &n ) ;
    
    printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    
    int arr[ n ] ;
    while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;                //  Worst Func. in all Languagues
                                            //  Goes to infinite Loop if a character is Entered
        
        switch( ch ){
        
            case 1:     push( arr, n ) ;
                        break ;
                        
            case 2:     pop( arr ) ;
                        break ;
                        
            case 3:     display( arr ) ;
                        break ;
                        
            default:    n = -1 ;
        }
        
        if( n == -1 ){
            break ;
        }
    }


    return 0 ;
}
