#include <stdio.h>
#include <stdlib.h>

//  Nishant Bhandari
//  Queue using linkedList Without any UserDefined Data Type || Structure

void display( void **head ){
    
    if( head == NULL ) {     //  baseCase
        printf( "\nQueue Empty!!!\n" ) ;
        return ;   
    }
        
    printf( "\nQueue Elements are: " ) ;
    
    while( head != NULL ){
        printf( "%d ", *((int*) *head ) ) ;
        head = head[ 1 ] ;
    }
    
    printf( "\n" ) ;
}

void** enque( void **head ){
    printf( "\nEnter Data in Queue: " ) ;
        
    void** trv = head ;
    if( head == NULL ){
        trv = head = (void*) calloc( 2, sizeof( void* ) ) ;
    }
    
    else{
        while( trv[ 1 ] != NULL ) {
            trv = trv[ 1 ] ;
        }
        
        trv[ 1 ] = (void*) calloc( 2, sizeof( void* ) ) ;
        trv = trv[ 1 ] ;
    }
    
    *trv = (int*) malloc( sizeof( int ) ) ;
    scanf( "%d", (int*) *trv ) ;
        
    trv[ 1 ] = NULL ;
    return head ;
}

int peek( void **head ){
    if( head == NULL )
        return -1 ;
    
    return *( (int*) *head ) ;
}

void** deque( void **head ){
    
    if( head == NULL ) {     //  baseCase
    
        printf( "\nQueue Empty!!!\n" ) ;
        return head ;
    }
    
    void** temp = head ;
    head = head[ 1 ] ;  //  move head ahead
    
    printf( "\nPopped: %d", peek( temp ) ) ;
    
    free( *temp ) ;  //  Int memory in node
    // printf( "\nDE: %d \n", *((int*)   head[ 0 ]) ) ;     //  Check
    free( temp ) ;
    
    return head ;
}

void dealloc( void** head ){
    
    void ** tmp = NULL ;
    while( head != NULL ){
        
        tmp = head ;
        head = head[ 1 ] ;
        
        free( *tmp ) ;
        free( tmp ) ;
    }
}

int main() {
    
    void **head = NULL ;

    //  Implementing queue 
    printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    printf( "4: PEEK\n" ) ;
    
    while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;           
        
        switch( ch ){
        
            case 1:     //  1.  enque
                        head = enque( head ) ;                      break ;
                        
            case 2:     //  2.  deque
                        head = deque( head ) ;                      break ;
                        
            case 3:     //  3.  Display
                        display( head ) ;                           break ;
                        
            case 4:     //  4.  peek
                        printf( "\nPeek: %d \n", peek( head ) ) ;      break ;
            
            default:    ch = -1 ;
        }
        
        if( ch == -1 ){
            break ;
        }
    }

    dealloc( head ) ;
    printf( "\nExiting........\n" ) ;
    
    return 0;
}
