#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int data;
	struct node *next ;
}node ;

node* create( int data ){

	node *tmp = (node*) malloc( sizeof( node ) ) ;
	tmp-> data = data ;
	tmp-> next = NULL ;

	return tmp ;
}

void display( node* head ){
	printf( "Elements in LL: " ) ;

	while( head != NULL ){
		printf( "%d ", head-> data ) ;
		head = head-> next ;
	}
	printf( "\n" ) ;
}

void add( node* head, int data ){
	
	node* tmp = create( data ) ;
	
	while( head-> next != NULL ){
		head = head-> next ;
	}
	
	head-> next = tmp ;
}

void del( node* head ){
//	Deletes next node
	
	node* tmp = head-> next ;
	
	head-> next = tmp-> next ;
	
	free( tmp ) ;
}

node* del_alt_node( node* head ){
	if( head == NULL ){
		printf( "\nLL is Empty" ) ;
		return head ;
	}

	node* trv = head ;
	while( trv != NULL ){
		
		del( trv ) ;
		trv = trv-> next ;
	}

	return head ;
}

int main(){

	node *head = NULL ;

	head = create( 1 ) ;

	add( head, 2 ) ;
	add( head, 3 ) ;
	add( head, 4 ) ;
	add( head, 5 ) ;
	add( head, 6 ) ;

	display( head ) ;
	
//	del( head-> next ) ;

	head = del_alt_node( head ) ;

	display( head ) ;

	return 0;
}
