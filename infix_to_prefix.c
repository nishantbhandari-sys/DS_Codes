#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//	printf("\nPopped Element is: %d\n", ptr[ *top ].data );

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

char peek( Stack *ptr, int top ){
    
    return ptr[ top ].data ;
}

short isEmpty( int top ){
    if( top == -1 )
        return 1 ;
    return 0 ;
}

int prcdnce( char c ){
     switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;

        case ')':   return 10;  //  non-zero val
        default :   return 0 ;
     }
}

//  prefix
void pre( char exp[]  ){

    //  reverse
    int len = strlen( exp ) ;
    for( int i = 0; i < len /2; i++ ){
        char t = exp[ i ] ;
        exp[ i ] = exp[ len -1 -i ] ;
        exp[ len -1 -i ] = t ;
    }
    
    //  correct '(' and ')'
    for( int i = 0; exp[ i ] != '\0'; i++ ){
        if( exp[ i ] == ')' )
            exp[ i ] = '(' ;
        else if( exp[ i ] == '(' )
            exp[ i ] = ')' ;
    }
    
     printf( "%s\n", exp ) ;
    int top = -1 ;
    Stack* stk = NULL ;
    int c = 0 ;
      
     for( int i = 0; exp[ i ] != '\0'; i++ ){
        int x = prcdnce( exp[ i ] ) ;
        
        if( exp[ i ] == '(' ){   //  Direct Push for Empty Stack OR id '(' is encountered
            stk = push( stk, &top, exp[ i ] ) ;
        }
        
        else if( !x ){  //  exp[ i ] is an operand

            exp[ c ] = exp[ i ] ;
            c++ ;
        }
            
        else if( exp[ i ] == ')' ){     //  ')' is encountered
        display( stk, top ) ;
            while( !isEmpty( top ) && peek( stk, top ) != '(' ){

                exp[ c ] = peek( stk, top ) ;
                c++ ;
                stk = pop( stk, &top ) ;
            }
            stk = pop( stk, &top ) ;    //  pop '(' also
        }
        else{       //  exp[ i ] is an operator

            while( !isEmpty( top ) && ( peek( stk, top ) != '(' && prcdnce( peek( stk, top ) ) >= x ) ){

                exp[ c ] = peek( stk, top ) ;
                c++ ;
                stk = pop( stk, &top ) ;
            }
            stk = push( stk, &top, exp[ i ] );
        }
// display( stk, top ) ;
// printf( "%s\n", exp ) ;
     }
     
     // pop all left elements from stack
     while( !isEmpty( top ) ){

        exp[ c ] =  peek( stk, top ) ;
        c++ ;
        stk = pop( stk, &top ) ;
     }
    exp[ c ] = '\0' ;
  
    len = strlen( exp ) ;
    //  reverse
    for( int i = 0; i < len /2; i++ ){
        char t = exp[ i ] ;
        exp[ i ] = exp[ len -1 -i ] ;
        exp[ len -1 -i ] = t ;
    }
    
    printf( "%s\n", exp ) ;
}

int main(){
    char s[] = "2*(5*(3+6))/5-2" ;
    
    pre( s ) ;

    return 0 ;
}
