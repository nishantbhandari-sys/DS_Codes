#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data ;
	struct node *next ;
}	Node ;

void display( Node* head ){

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

Node* add_End ( Node* head, int val ){

	//	create a new node
	Node* temp = create( val ) ;
	
	//	If List is Empty
	if( head == NULL ){
		return temp ;
	}
	
	//	Saving pointer to 1st node
	Node* ret = head ;
	
	//	point head at last position to add node
	while( head-> next != NULL ){
		head = head-> next ;
	}
	head-> next = temp ;
	
	return ret ;
}

Node* rem( Node* head ){
	Node* ret = head ;

	while( head-> next-> next != NULL ){
			head = head-> next ;
	}
	//	next node is the node which we have to delete
	free( head-> next ) ;
	head-> next = NULL ;
	
	return ret ;
}

Node* add_Beg( Node* head, int val ){

	//	create a new node
	Node* temp = create( val ) ;

	//	Point new node's next to current head
	temp-> next = head ;
	head = temp ;
	
	//	return new head
	return head ;
}

Node* add_Pos( Node* head, int pos, int val ){

	//	create new node for inserting data
	Node* new = create( val ) ;
	
	//	save the return head
	Node* reth = head ;
	
	//	if pos == 1 =>	Insert at Beginning of LL
	if( pos == 1 )
		return add_Beg( head, val ) ;
	
	//	point to the node after which new node has to be inserted
	while( pos > 2 ){
		head = head-> next ;
		pos-- ;
	}
	
	//	If pos == Last Node's position
	if( head-> next-> next == NULL ){
		add_End( head, val ) ;
		return reth ;
	}
	
	//	add next node's addr. to new node's next
	//	OR point new node's next to next node
	new-> next = head-> next ;
	
	//	point curr node's next to new node 
	head-> next = new ;
	
	//	return head 
	return reth ;
	
}

Node* sort( Node* head ){
    
    if( head == NULL ){  //  no node
        head = add_Beg( head ) ;
    }
    
}

int main(){

	Node *list1 = NULL ;
	Node *list2 = NULL ;
	
	printf( "\nList1: " ) ;
	list1 = add_End( list1, 23 ) ;
	list1 = add_End( list1, 43 ) ;
	list1 = add_End( list1, 53 ) ;
	
	display( list1 ) ;
	
	printf( "List2: " ) ;
	list2 = add_End( list2, 63 ) ;
	list2 = add_End( list2, 73 ) ;
	list2 = add_End( list2, 83 ) ;
	
	display( list2 ) ;

	return 0 ;
}
