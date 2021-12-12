#include <stdio.h>
#include <stdlib.h>

void display( char *Stak, int top ){

	printf( "\nElements of Stack: " ) ;
	while( top >= 0 ){
	
		printf( "%c ", Stak[ top ] ) ;
		top-- ;
	}
	
	printf( "\n" ) ;
}

void push( char *Stak, int *top, char val ){
	
	*top += 1;
	Stak[ *top ] = val ;
}

void pop( char *Stak, int *top ){
	*top -= 1 ;
}

char peek( char *p, int top ){
        
    return p[ top ] ;
}

int prcdnc( char c ){
    
    switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;
        
        default :   return 0 ;   //  c is operand
    }
}

void itp( char s[], char *stk, int *top ){
    int j = 0 ;
    
    for( int i = 0; s[ i ] != '\0'; i++ ){
        
        int x = prcdnc( s[ i ] ) ;
        
        if( s[ i ] == '(' || x > prcdnc( peek( stk, *top ) ) ){   //  Direct push for '(' OR Prec of x is higher than stk[ top ]
            push( stk, top, s[ i ] ) ;
        }
            
        else if( s[ i ] == ')' ) {      //  ')' is Encountered POP until '('
            
            while( peek( stk, *top ) != '(' ){

            	s[ j ] = peek( stk, *top ) ;
                pop( stk, top ) ;
                j++ ;
            }
            pop( stk, top ) ; //  POP '(' also
        }
        
        else if( x == 0 ){    //  then s[ i ] is operand
            s[ j ] = s[ i ] ;
            j++ ;
        }
        
        //  Now. At this point s[ i ] is definitely a Operator
        else{

             while( prcdnc( peek( stk, *top ) ) >= x  ){
             	s[ j ] = peek( stk, *top ) ;
                pop( stk, top ) ;
                j++ ;
            }
            //	Insert operator in stack
            push( stk, top, s[ i ] ) ;
        }
    }
    //  Clear remaining Operators from Stack, If any!
    while( *top != -1 ){
    	s[ j ] = peek( stk, *top ) ;
        pop( stk, top ) ;
        j++ ;
    }
    
    s[ j ] = '\0' ;
}

int main(){

    //   = "a+b*(c^d-e)^(f+g*h)-i"

    char s[ 50 ] ;
    scanf( "%s", s ) ;
    
    int len = sizeof( s ) / sizeof( s[ 0 ] ) ;


    char sptr[ len ] ;
    int top = -1 ;

    itp( s, sptr, &top ) ;

    for( int i = 0; s[ i ] != '\0'; i++ ){
        printf( "%c", s[ i ] ) ;
    }
	printf( "\n" ) ;

	return 0 ;
}

