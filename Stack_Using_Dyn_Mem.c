#include <stdio.h>
#include <stdlib.h>

// struct name{
// 	int datra ;
// } ;

// struct name varname[ 10 ] ;


typedef struct {
	int data ;

} Stack ;


Stack* push( Stack *ptr, int *top ){

	int val ;
	printf( "Enter Element in Stack: " ) ;
	scanf( "%d", &val ) ;

	if( ptr == NULL ){  //  || *top == -1
		ptr = ( Stack* ) malloc( sizeof( Stack ) * 1 ) ;

		(*top) ++ ;
		ptr[ *top ].data = val ;

		return ptr ;
	}

	(*top) ++ ;
	Stack *temp = ( Stack* ) malloc( sizeof( Stack ) * (*top +1) ) ;

	if( temp == NULL ){
		printf("\nMemory FULL...\n");
		return ptr ;
	}

	for( int i = 0; i < *top; i++ ){
		temp[ i ].data = ptr[ i ].data ;
	}
// 	(*top) ++ ;
	temp[ *top ].data = val ;

	free( ptr ) ;

	return temp ;
}

void display( Stack *ptr, int top ){

	if( top == -1 ){
		printf("\nStack is Empty\n") ;
		return ;
	}

	printf("\nElements in Stack are: ");

	while( top >= 0 ){

		printf("%d ", ptr[ top ].data );
		top-- ;
	}

	printf("\n");
}

Stack* pop( Stack *ptr, int *top ){

	if( *top == -1 ){
		printf("\nCan't POP....Stack is Empty\n");
		return ptr ;
	}

	printf("\nPopped Element is: %d\n", ptr[ *top ].data );

	//	When top == 0 that means now our stack will become empty
	if( *top == 0 ){
		free( ptr ) ;
		*top = -1 ;
		return ptr = NULL ;
	}

	Stack *temp = ( Stack* ) malloc( sizeof( Stack ) * (*top) ) ;

	for (int i = 0; i < *top ; ++i){

		temp[ i ].data = ptr[ i ].data ;
	}

	(*top) -- ;
	free( ptr ) ;

	return temp ;
}

int main(){

	printf("\n1.	Push\n");
	printf("\n2.	Pop\n");
	printf("\n3.	Display\n");

	int n ;
	Stack *sptr = NULL ;

	int top = -1 ;

	while( 1 ){
		printf("\nEnter Your Choice: ");
		scanf( "%d", &n ) ;

		switch( n ){

			case 1: sptr =  push( sptr, &top ) ;
					break ;

			case 2: sptr =  pop( sptr, &top ) ;
					break ;

			case 3: display( sptr, top ) ;
					break ;

			default:	n = -1 ;
		}

		if( n == -1 ){
			free( sptr ) ;

			printf("\nExiting...........\n");
			break ;
		}

	}

	return 0 ;
}

