#include <stdio.h>
#include <stdlib.h>
//	Stack using LL

typedef struct node {

	int data ;
	struct node *next ;
}	Node ;

void display( Node* head ){

	printf( "\nElements of Stack: " ) ;
	while( head != NULL ){
		
		printf( "%d ", head-> data ) ;
		head = head-> next ;
	}
	printf( "\n" ) ;
}

Node* create( int val ){

	Node* temp = (Node*) malloc( sizeof( Node ) ) ;
	temp-> next = NULL ;
	temp-> data = val ;

	return temp ;
}

Node* del_Beg( Node* head ){

	Node* tmp = head ;

	head = head-> next ;

	free( tmp ) ;

	return head ;
}

Node* add_Beg( Node* head, int val ){

	//	create a new node
	Node* temp = create( val ) ;

	if( head == NULL )
		return temp ;

	//	Point new node's next to current head
	temp-> next = head ;
	head = temp ;
	
	//	return new head
	return head ;
}

Node* push( Node* head, int val ){

	head = add_Beg( head, val ) ;
	return head ;
}

Node* pop( Node* head ){

	if( head == NULL ){
		printf("\nStack Empty!!!") ;
		return head ;
	}

	printf("\nPopped: %d", head-> data ) ;
	head = del_Beg( head ) ;

	return head ;
}

void peek( Node* head ){

	printf("\nTop ELement: %d", head-> data ) ;
}

int main(){

	Node *head = NULL ;
	printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    printf( "4: PEEK\n" ) ;
    printf( "5: EXIT...\n" ) ;
	
	while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
        
            case 1:     scanf( "%d", &ch ) ;
            			head = push( head, ch ) ;			break ;
                        
            case 2:     head = pop( head ) ;				break ;
                        
            case 3:     display( head ) ;					break ;
                        
            case 4:		peek( head ) ;						break ;
            			
            default:    ch = -1 ;
        }
        
        if( ch == -1 ){
            break ;
        }
    }
    
    printf( "\nExiting...\n" ) ;

	return 0 ;
}
