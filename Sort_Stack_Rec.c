#include <stdio.h>
#include <stdlib.h>

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
	
int peek( Stack *ptr, int top )	{
    return ptr[ top ].data ;
}

void swap( Stack *ptr , int i, int j ){
    
	int t = peek( ptr, i ) ;
	ptr[ i ].data = ptr[ j ].data ;
	ptr[ j ].data = t ;
}

void bubble( Stack *ptr, int i, int j ){
	    
	if( i == 0 )
	   return ;
	        
    if( j < i ){
	        
	   if( peek( ptr, j ) < peek( ptr, j +1) ){     //  Condition for Element checking in bubble Sort
	       swap( ptr, j, j +1 ) ;
	   }
	         
	   bubble( ptr, i, j +1 ) ;         //  Traversing Stack while keeping i pointer const
 	}
	else
	   bubble( ptr, i -1, 0 ) ;         //  Changing ith pointer to not check the last Element again
}
	
int main(){
    
    Stack *sptr = NULL ;
    int top = -1 ;

    sptr =  push( sptr, &top ) ;  
    sptr =  push( sptr, &top ) ; 
    sptr =  push( sptr, &top ) ; 
    sptr =  push( sptr, &top ) ; 
    sptr =  push( sptr, &top ) ; 

    display( sptr, top ) ;

    bubble( sptr, top, 0 ) ;

    display( sptr, top ) ;

    return 0;
}
