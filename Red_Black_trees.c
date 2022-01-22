#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int val ;
    struct node* left ;
    struct node* right ;
    char color ;
    
} node ;

node* create( int key ){
    //  Creates an ideal node 
    
    node* tmp = (node*) malloc( sizeof( node ) ) ;
    tmp-> val = key ;
    tmp-> left = NULL ;
    tmp-> right = NULL ;
    tmp-> color = 'R';
    
    return tmp ;
}




//  DFS traversal on BST:
    //  3 types:
        //  1.  preOrder => Root-Left-Right
        //  2.  inOrder => Left-Root-Right
        //  3.  postOrder => Left-Right-Root
        
void preOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    printf( "%d ", root-> val ) ;
    preOrder( root-> left ) ;
    preOrder( root-> right ) ;
}
void inOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    inOrder( root-> left ) ;
    printf( "%d ", root-> val ) ;
    inOrder( root-> right ) ;
}
void postOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    postOrder( root-> left ) ;
    postOrder( root-> right ) ;
    printf( "%d ", root-> val ) ;
}


short correct( node** root, node* z, node* p, node* gp ){
    if( p == NULL || gp == NULL )       return 0;
    
    short ans = 0;
    node* y = NULL;
    
    if( p == gp-> left ){
        y = gp-> right;
        if( y-> color == 'R' ){
            ans = 1;
            p-> color = 'B';
            y-> color = 'B';
            gp-> color = 'R';
        }
    }
    // else{
        
    // }
    (*root)-> color = 'B';
    return ans ;
}

node* insert( node** root, node* z, node* p, node* gp ){
    //  Inserts a new node z in tree

    if( *root == NULL ){
        *root = z;
        return z;
    }

    if( (*root)-> left == NULL || (*root)-> right == NULL ) {
        if( (*root)-> val < z-> val ){
            (*root)-> right = z;
        }
        else{
            (*root)-> left  = z;
        }
        if( correct( root, z, *root, p ) ){
            return p;
        }
        return NULL;
    }
    
    if( z-> val < (*root)-> val ){
        z = insert( root, z, (*root)-> left, p );
    }
    else if( z-> val > (*root)-> val ) {
        z = insert( root, z, (*root)-> right, p );
    }
    
    short ans ;
    
    if( z == *root ){
        ans = correct( root, z, p, gp );
    }
    
    if( ans ){
        return gp;
    }
    return NULL;
}


int main(){
    
    node* root = NULL ;
    
    // insert( &root, create( 10 ) ) ;
    // insert( &root, create( 5 ) ) ;
    // insert( &root, create( 12 ) ) ;
    // insert( &root, create( 11 ) ) ;
    // insert( &root, create( 15 ) ) ;
    // insert( &root, create( 13 ) ) ;
    // insert( &root, create( 14 ) ) ;
    
    insert( &root, create( 7 ), NULL, NULL ) ;
    insert( &root, create( 5 ), NULL, NULL ) ;
    insert( &root, create( 8 ), NULL, NULL ) ;
    insert( &root, create( 4 ), NULL, NULL ) ;

    printf( "\nInOrder: " ) ;
    inOrder( root ) ;
    
    
    
    
    //  DFS
    //  preOrder( root );
    //  inOrder( root );
    //  postOrder( root );
    
    
    
    //  Deletion
        // delete( root, 10 ) ;
        // printf( "\nInOrder: " ) ;
        // inOrder( root ) ;
        // printf( "\n\n" );
        
        
    //  Successor
        // x = root-> right-> right ;
        // printf( "\nx-> val: %d\n", x-> val );
        // x = successor( root, x ) ;
        // if( x != NULL )
        //     printf( "\nSuccessor: %d\n", x-> val );
        // else
        //     printf( "\nNo Successor\n" ) ;
        
    //  Maximum
        // x = max( root ) ;
        // if( x != NULL )
        //     printf( "\nMaximum: %d", x-> val );
        // else
        //     printf( "\nNot Found" ) ;
        
    //  Minimum
        // x = min( root ) ;
        // if( x != NULL )
        //     printf( "\nMinimum: %d", x-> val );
        // else
        //     printf( "\nNot Found" ) ;
        
    //  SEarching
        // if( (x = search( root, 7 ) ) != NULL )
        //     printf( "\nFound: %d", x-> val );
        // else
        //     printf( "\nNot Found" ) ;
        

    return 0;
}
