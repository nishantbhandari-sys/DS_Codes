#include <stdio.h>
#include <stdlib.h>
//  Doubly LL; check if palindrome

typedef struct node {

	char data ;
	struct node *prev ;
	struct node *next ;
}	node ;

node* create( char val ){
    
    node* temp = (node*) malloc( sizeof( node ) ) ;
	temp-> next = NULL ;
	temp-> prev = NULL ;
	temp-> data = val ;

	return temp ;
}

void display( node* head ){

	while( head != NULL ){
		
		printf( "%c", head-> data ) ;
		head = head-> next ;
	}
	printf( "\n" ) ;
}

node* add_End( node* head, char data ){
    if( head == NULL )
        return create( data ) ;
        
    node* trv = head ;
    
    while( trv-> next != NULL ){
        trv = trv-> next ;
    }
    
    node* new = create( data ) ;
    
    trv-> next = new ;
    new-> prev = trv ;
    
    return head ;
}

int isPalin( node* head ){
    
    node* tail = head ;
    while( tail-> next != NULL ){
        tail = tail-> next ;
    }
    
    //  Now tail is at last node
    while( head != tail ){
        
        if( head-> data != tail-> data )
            return 0 ;
            
        head = head-> next ;
        tail = tail-> prev ;
    }
    
    return 1 ;
}

int main(){

    char s[ 50 ] ;
    scanf( "%s", s ) ;
    
    node* head = NULL ;

    for( int i = 0; s[ i ] != '\0'; i++ )
        head = add_End( head, s[ i ] ) ;
    
    // display( head ) ;

    int flag = isPalin( head ) ;
    
    if( flag )
        printf( "\nString is palindrome" ) ;
    else
        printf( "\nString is not palindrome" ) ;
        
    return 0;
}
