#include <stdio.h>

int front = -1, rear = -1 ;

void display( int arr[], int n ){
    
    if( front == -1 ){
        printf( "\nQueue Empty\n" ) ;
        return ;
    }

    int f = front ; 
    do{
        printf( "%d ", arr[ f % n ] ) ;
        f++ ;
    }
    while( f <= rear ) ;    //  display all Elements b/w front and rear
    
    printf( "\n" ) ;
}

void push( int arr[], int n ){

    int val ;
    printf( "\nEnter Element to Insert: ") ;
    scanf( "%d", &val ) ;
    
    if( (rear +1) %n == front ){    //  if my rear +1( pos. where Element will be Inserted ) == front , then
                                    //      we can't Insert any more Elements in Queue
        printf( "\nQueue Full\n" ) ;
        return ;
    }
    
    if( rear == -1 ){  //  || rear == -1    //  Base Case   ( As front will be inc. Once when First Element is Inserted )
        
        front = 0 ;
    }
    rear++ ;
    arr[ rear % n ] = val ;     //  rear % n is used to Insert Elements at begenning of Queue if it is Empty

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
        scanf( "%d", &ch ) ;
        
        switch( ch ){
        
            case 1:     push( arr, n ) ;
                        break ;
                        
            case 2:     pop( arr ) ;
                        break ;
                        
            case 3:     display( arr, n ) ;
                        break ;
                        
            default:    n = -1 ;
        }
        
        if( n == -1 ){
            break ;
        }
    }


    return 0 ;
}
