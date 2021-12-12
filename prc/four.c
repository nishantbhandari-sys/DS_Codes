#include<stdio.h>
#include<stdlib.h>

void display( int *Stak, int top ){

	printf( "\nElements of Stack: " ) ;
	while( top >= 0 ){
	
		printf( "%d ", Stak[ top ] ) ;
		top-- ;
	}
	
	printf( "\n" ) ;
}

void push( int *Stak, int *top, int n ){
	if( *top == n -1 ){
	
		printf( "\nCan't Insert STack FUll\n" ) ;
		return;
	}
	
	*top += 1;
	printf( "\nEnter DAta: " ) ;
	scanf( "%d", &Stak[ *top ] ) ;
}

void pop( int *Stak, int *top ){
	printf( "\nPoPPed: %d", Stak[ *top ] ) ;
	*top -= 1 ;
}

void peek( int *Stak, int top ){
	printf( "\nTop Element: %d", Stak[ top ] ) ;
}

int main(){

	int n;
	printf( "\nEnter size of Stack: " ) ;
	scanf( "%d", &n ) ;
	
	int *stak = (int*) malloc( sizeof(int) *n ) ;
		
	printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    printf( "4: PEEK\n" ) ;
    printf( "5: EXIT...\n" ) ;
	
	int top = -1 ;
	
	while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
        
            case 1:     push( stak, &top, n ) ;			break ;
                        
            case 2:     pop( stak, &top ) ;				break ;
                        
            case 3:     display( stak, top ) ;			break ;
                        
            case 4:		peek( stak, top ) ;				break ;
            			
            default:    ch = -1 ;
        }
        
        if( ch == -1 ){
            break ;
        }
    }
    
    printf( "\nExiting...\n" ) ;
	return 0;
}
