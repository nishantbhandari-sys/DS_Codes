#include <stdio.h>
#include <stdlib.h>

void rev( int arr[], int i, int len ){
	if( i > len )
		return;
		
	int num = arr[ i ] ;
	
	rev( arr, i +1, len ) ;
	
	arr[ len -i ] = num ;
}

int main(){

	int n ;
	scanf( "%d", &n );
	
	int *arr = (int*) malloc( sizeof(int) *n ) ;
	for( int i = 0; i < n; i++ )
		scanf( "%d", arr +i ) ;
	
	rev( arr, 0, n -1 ) ;
	
	for( int i = 0; i < n; i++ )
		printf( "%d ", arr[ i ] );
	
	printf( "\n" );
	return 0;
}
