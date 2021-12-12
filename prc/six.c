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

node* add( node* head, int data ){
	
	node* ret = head ;
	node* tmp = create( data ) ;
	
	if( head == NULL )
		return tmp ; 
	
	while( head-> next != NULL ){
		head = head-> next ;
	}
	
	head-> next = tmp ;
	
	return ret ;
}

int length( node* head ){
	int len = 0 ;

	while( head != NULL ){
		head = head-> next ;
		len ++ ;
	}
	return len ;
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
	
	int len = length( head ) ;
	len &= 1 ;		//	IF length is odd, len = 1 , else 0

	node* trv = head ;
	while( ( len == 0 && trv != NULL ) || ( len == 1 && trv-> next != NULL ) ){
		
		del( trv ) ;
		trv = trv-> next ;
	}

	return head ;
}

int main(){

	node *head = NULL ;
	int val ;

	printf("\nEnter Elements: " ) ;
	while( 1 ){

		scanf( "%d", &val ) ;
		if( val == -1 )
			break ;

		head = add( head, val ) ;
	}

	display( head ) ;

	head = del_alt_node( head ) ;

	display( head ) ;

	return 0;
}


