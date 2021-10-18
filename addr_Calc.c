#include <stdio.h>

int main()
{
    // 1 2 3 
    // 4 5 6      ( 6 ) = >     2, 3   =>  
    // 7 8 9
    
    //  base = 100 
    //  Adrr i, j = base + ( (i -1)*cols*(int) + j*(int) )
    
    int rows = 3 , cols = 3 ;
    printf( "\nEnter rows and cols: " ) ;
    scanf( "%d %d", &rows, &cols ) ;
    
    int mat[ rows ][ cols ] ;
    printf( "\nEnter matrix: \n" ) ;
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < cols; j++ ){
            scanf( "%d", &mat[ i ][ j ] ) ;
        }
    }
    
    int i , j , elm ;
    short flag = 0 ;
    printf( "\nEnter Element to find it's Address: " ) ;
    scanf( "%d", &elm ) ;
    // printf( "%d", elm ) ;
    
    for( i = 0; i < rows; i++ ){
        for( j = 0; j < cols; j++ ){
            
            // printf( "%d %d\n", elm, mat[ i ][ j ] ) ;
            if( elm == mat[ i ][ j ] ){
                flag = 1 ;
                break ;
            }
        }
        if( flag )
            break ;
    }
    
    // printf( "%d %d\n", i, j ) ;
    int base = 100 ;
    int ans = base + ( i*cols*4 + j*4 ) ;
    
    printf( "\nAddr of %d is: %d", elm, ans ) ;
    
    return 0;
}
