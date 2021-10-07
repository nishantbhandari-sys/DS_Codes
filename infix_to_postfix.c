#include <stdio.h>
#include <stdlib.h>




















// struct name{
// 	int datra ;
// } ;

// struct name varname[ 10 ] ;


typedef struct {
	char data ;

} Stack ;


Stack* push( Stack *ptr, int *top, char val ){

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

		printf("%c ", ptr[ top ].data );
		top-- ;
	}

	printf("\n");
}

Stack* pop( Stack *ptr, int *top ){

	if( *top == -1 ){
		printf("\nCan't POP....Stack is Empty\n");
		return ptr ;
	}

	printf("\nPopped Element is: %c\n", ptr[ *top ].data );

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
int prcdnc( char c ){
    
    switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;
        
        default :   return 0 ;  //  c is operand
    }

}

void itp( char s[], Stack *stk, int *top ){
    
    for( int i = 0; s[ i ] != '\0'; i++ ){
        
        if( !prcdnc( s[ i ] ) ){    //  check for operand
            
            printf( "%c", s[ i ] ) ;
        }
        else{
            if( prcdnc( s[ i ] ) > prcdnc( stk[ *top ].data ) ){  //  If precedence of ( expression's )current char  is greater  stack's top element
                stk = push( stk, top, s[ i ] ) ;
            }
            else if( s[ i ] == '(' ) {
                stk = push( stk, top, s[ i ] ) ;
            }
            
            else{   //  now precedence is lower so we have to pop until '(' OR top != -1 OR prcdnc( top ) > prcdnc( s[ i] )
                
                while( stk[ *top ].data != '(' && *top != -1 && prcdnc( stk[ *top ].data ) > prcdnc( s[ i ] ) ){\
                    printf( "%c", stk[ *top ].data ) ;
                    stk =  pop( stk, top ) ;
                    
                }
                stk[ ++(*top) ].data = s[ i ] ;
            }
        }
        
    }
}





int main(){

	Stack *sptr = NULL ;

	int top = -1 ;

    char s[] = "a+b*(c^d-e)^(f+g*h)-i" ;
    
    itp( s, sptr, &top ) ;

    // for( int i = 0; p[ i ] != '\0'; i++ ){
    //     printf( "%c", p[ i ] ) ;
    // }


	return 0 ;
}
