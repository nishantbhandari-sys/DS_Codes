#include <stdio.h>
#include <stdlib.h>

int main(){

	int n ;
	scanf( "%d", &n ) ;
	
	int *arr = (int*) malloc( sizeof(int) *n ) ;
	for( int i = 0; i < n; i++ )
		scanf( "%d", arr +i ) ;
	
	//	Xor a number with other numbers
	//	if it is 0 at any moment then it is a rep element in array
	
	int rep = 0 ;
	for( int i = 0; i < n; i++ ){
	
		int  count = 0 ;
		for( int j = i +1; j < n; j++ ){
			
			if( arr[ i ] == arr[ j ] )
				count++ ;
		}
		
		if( count > 1 )
			rep++ ;
			
		if( rep == 3 ){
			rep = arr[ i ] ;
			break ;
		}
	}
	/*
	int rep[ n ] ;
	
	for( int i = 0; i < n; i++ ){
	//	FOr array reaversal
	
		//	For already encountered
		for( int j = 0; j < n; j++ ){
			if( arr[ j ] == -1 )
				break;
			
		}
	}
	*/
	
	printf( "\n3rd Rep Element: %d\n", rep ) ;
	
	return 0;
}
