#include <stdio.h>
#include <stdlib.h>

int main(){

	int n ;
	scanf( "%d", &n ) ;
	
	int *arr = (int*) malloc( sizeof(int) *n ) ;
	for( int i = 0; i < n; i++ )
		scanf( "%d", arr +i ) ;
	
	int non_rep = 0 ;
	for( int i = 0; i < n; i++ ){
	
		int  rep = 0 ;
		for( int j = 0; j < n; j++ ){
			
			if( arr[ i ] == arr[ j ] )
				rep++ ;
		}
		
		if( rep == 1 )
			non_rep++ ;
			
		if( non_rep == 2 ){
			non_rep = arr[ i ] ;
			break ;
		}
	}
	
	printf( "\n2nd Non-Rep: %d\n", non_rep ) ;
	
	return 0;
}
