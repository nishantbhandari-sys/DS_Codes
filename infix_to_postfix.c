#include <stdio.h>
#include <stdlib.h>

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

// 	printf("\nPopped Element is: %c\n", ptr[ *top ].data );

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

char peek( Stack *p, int t ){
    if( t == -1 )
        return '\0' ;
        
    return p[ t ].data ;
}
int prcdnc( char c ){
    // if( top == -1 )
    //     return -1 ;
    
    switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;
        
        case '\0':
        case '(':   return -1 ; //  push_back
        case ')':   return -10 ; //  POP
        
        default :   return 0 ;  //  c is operand
    }

}

void itp( char s[], Stack *stk, int *top ){
    
    for( int i = 0; s[ i ] != '\0'; i++ ){
        
        int x = prcdnc( s[ i ] ) ;
        
        if( x == 0 ){    //  check for operand
            printf( "%c", s[ i ] ) ;
        }
        else if( x == -1 || x > prcdnc( peek( stk, *top ) ) ){   //  Direct push for '(' OR Prec is higher
            stk = push( stk, top, s[ i ] ) ;
        }
            
        else if( x == -10 ) { //  ')' is Encountered POP until '('
            
            while( peek( stk, *top ) != '(' ){
                printf( "%c", peek( stk, *top ) ) ;
                stk = pop( stk, top ) ;
            }
            stk = pop( stk, top ) ; //  POP '(' also
            // display( stk, *top ) ;
        }
        else{
             while( prcdnc( peek( stk, *top ) ) >= x  ){
                printf( "%c", peek( stk, *top ) ) ;
                stk = pop( stk, top ) ;
            }
            stk = push( stk, top, s[ i ] ) ;
            // display( stk, *top ) ;
        }
    }
    //  Clear remaining Operators from Stack
    while( *top != -1 ){
        printf( "%c", peek( stk, *top ) ) ;
        stk = pop( stk, top ) ;
    }
}

int main(){

	Stack *sptr = NULL ;

	int top = -1 ;

    char s[] = "a+b*(c^d-e)^(f+g*h)-i" ;
    
    // sptr = push( sptr, &top, '#' ) ;
    // printf( "%d", prcdnc( 'j' ) ) ;
    itp( s, sptr, &top ) ;

    // for( int i = 0; p[ i ] != '\0'; i++ ){
    //     printf( "%c", p[ i ] ) ;
    // }


	return 0 ;
}

