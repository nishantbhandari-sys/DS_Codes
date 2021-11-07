#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data ;

} Stack ;

int read( void ){
	int val ;
	printf( "Enter Element in Stack: " ) ;
	scanf( "%d", &val ) ;
	
	return val ;
}

Stack* push( Stack *ptr, int *top, int val ){

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
	
int peek( Stack *ptr, int top )	{
    return ptr[ top ].data ;
}

int isEmpty( int top ){
    return ( top == -1 ) ;
}
	
Stack* insert( Stack* ptr, int *top, int x ){
    
    if( isEmpty( *top ) || x <= peek( ptr, *top ) ){
        ptr = push( ptr, top, x ) ;
        return ptr ;
    }
    
    int tmp = peek( ptr, *top ) ;
    ptr = pop( ptr, top ) ;
    ptr = insert( ptr, top, x ) ;
    
    //  push the previous Element
    ptr = push( ptr, top, tmp ) ;
    return ptr ;
}
	
void sort( Stack *ptr, int top ){
    
    if( !isEmpty( top ) ){
        
        int x = peek( ptr, top ) ;
        
        ptr = pop( ptr, &top ) ;
        sort( ptr, top ) ;
        
        ptr = insert( ptr, &top, x ) ;
    }
}
	
int main(){
    
    Stack *sptr = NULL ;
    int top = -1 ;

    sptr =  push( sptr, &top, read( ) ) ;  
    sptr =  push( sptr, &top, read( ) ) ; 
    sptr =  push( sptr, &top, read( ) ) ; 
    sptr =  push( sptr, &top, read( ) ) ; 
    sptr =  push( sptr, &top, read( ) ) ; 

    display( sptr, top ) ;

    sort( sptr, top ) ;
    display( sptr, top ) ;

    return 0;
}
