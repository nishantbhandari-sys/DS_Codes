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
void inColor( node* root ){
    if( root == NULL ){
        return ;
    }
    
    inColor( root-> left ) ;
    printf( "%c ", root-> color ) ;
    inColor( root-> right ) ;
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



//  Written REf for L-R rotate
//  https://github.com/nishant-out/Problms/blob/main/Written_ref/IMG_20220123_141114.jpg
node* Lrotate( node** root, node* curr, node* x ){
    if( curr == NULL ){
        return NULL;
    }
    
    if( curr-> val < x-> val )
        curr-> right = Lrotate( root, curr-> right, x );
    else if( curr-> val > x-> val )
        curr-> left = Lrotate( root, curr-> left, x );
    else{
        node* y = x-> right;
        x-> right = y-> left;
        y-> left = x;
        if( x == *root ){
            *root = y;
        }
        
        return y;
    }
    return curr;
}
node* Rrotate( node** root, node* curr, node* y ){
    if( curr == NULL ){
        return NULL;
    }
    
    if( curr-> val < y-> val )
        curr-> right = Rrotate( root, curr-> right, y );
    else if( curr-> val > y-> val )
        curr-> left = Rrotate( root, curr-> left, y );
    else{
        node* x = y-> left;
        y-> left = x-> right;
        x-> right = y;
        if( y == *root ){
            *root = x;
        }
        
        return x;
    }
    return curr;
}


short correct( node** root, node* z, node* p, node* gp ){
    if( p == NULL || gp == NULL || p-> color == 'B' )       return 0;
    
    short ans = 0;
    node* y = NULL;
    
    //  Case 1: parent of z is a left child of it's grandparent
    if( p == gp-> left ){
        
        y = gp-> right; //  Here y is sibling of z's parent
        
        //  https://github.com/nishant-out/Problms/blob/main/Written_ref/IMG_20220123_141553.jpg
        //  Case 1.1:   sibling is of REd color,
                //  it doesn't matter z is a right child or left child of it's parent
                
                //  recolor parent & sibling as Black, and make grandparent REd
                //  now, correct the above tree by making grandparent as the new z
            
        if( y-> color == 'R' ){
            ans = 1;    //  tree is not correct, above tree also has to corrected
            p-> color = 'B';
            y-> color = 'B';
            gp-> color = 'R';
        }
        
        //  https://github.com/nishant-out/Problms/blob/main/Written_ref/IMG_20220123_141532.jpg
        //  Case 1.2:   sibling is of Black color,
        else{
            //  Case 1.2.1:  z is a right child of it's parent
                //  make it similar to Case 1.3:
            if( z == p-> right ){
                Lrotate( root, *root, p );
                p = z;  //  After 
            }
            
            //  Case 1.2.2:  z is a left child of it's parent
                //  make grandparent node as the sibling of z
                //  color grandparent as Red, and parent as Black
            Rrotate( root, *root, gp );
            gp-> color = 'R';
            p->  color = 'B';
        }
        //  Also no further correcting of tree is needed after Case 1.2.....
    }
    
    //  Case 2: parent of z is a right child of it's grandparent
    else{
        y = gp-> left; //  Here y is sibling of z's parent
        
        //  Case 2.1:   sibling is of REd color,
                //  it doesn't matter z is a right child or left child of it's parent
                
                //  recolor parent & sibling as Black, and make grandparent REd
                //  now, correct the above tree by making grandparent as the new z
            
        if( y-> color == 'R' ){
            ans = 1;    //  tree is not correct, above tree also has to corrected
            p-> color = 'B';
            y-> color = 'B';
            gp-> color = 'R';
        }
        //  Case 2.2:   sibling is of Black color,
        else{
            //  Case 2.2.1:  z is a right child of it's parent
                //  make it similar to Case 1.3:
            if( z == p-> left ){
                Rrotate( root, *root, p );
            }
            
            //  Case 2.2.2:  z is a left child of it's parent
                //  make grandparent node as the sibling of z
                //  color grandparent as Red, and parent as Black
            Lrotate( root, *root, gp );
            gp-> color = 'R';
            p->  color = 'B';
        }
        //  Also no further correcting of tree is needed after Case 2.2.....
    }
    
    
    (*root)-> color = 'B';
    return ans ;
}

node* insert( node** root, node* curr, node* z, node* p, node* gp ){
    //  Inserts a new node z in tree

    if( *root == NULL ){
        *root = z;
        z-> color = 'B';
        return z;
    }
    else if( (*root)-> left == NULL && z-> val < (*root)-> val ){
        (*root)-> left = z;
        return z;
    }
    else if( (*root)-> right == NULL && z-> val > (*root)-> val ){
        (*root)-> right = z;
        return z;
    }

    if( curr-> left == NULL || curr-> right == NULL ) {
        if( curr-> val < z-> val ){
            curr-> right = z;
        }
        else{
            curr-> left  = z;
        }
        
        if( correct( root, z, curr, p ) ){
            return p;
        }
        return NULL;
    }
    
    if( z-> val < curr-> val ){
        z = insert( root, curr-> left, z, curr, p );
    }
    else if( z-> val > curr-> val ) {
        z = insert( root, curr-> right, z, curr, p );
    }

    if( z == curr ){
        if( correct( root, z, p, gp ) )
            return gp;
    }
    return NULL;
}


int main(){
    
    node* root = NULL ;
    
    insert( &root, root, create( 11 ), NULL, NULL ) ;
    insert( &root, root, create( 2 ), NULL, NULL ) ;
    insert( &root, root, create( 14 ), NULL, NULL ) ;
    insert( &root, root, create( 1 ), NULL, NULL ) ;
    insert( &root, root, create( 7 ), NULL, NULL ) ;
    insert( &root, root, create( 5 ), NULL, NULL ) ;
    insert( &root, root, create( 8 ), NULL, NULL ) ;
    insert( &root, root, create( 15 ), NULL, NULL ) ;
    
    // node* x = create( 4 );
    insert( &root, root, create( 4 ), NULL, NULL ) ;


    printf( "\nInOrder: " ) ;
    inOrder( root );
    printf( "\nInColor: " ) ;
    inColor( root );
    
    // printf( "\n%d", root-> val );
    // insert( &root, root, create( 4 ), NULL, NULL ) ;
    
    
    // printf( "\n\nInOrder: " ) ;
    // inOrder( root );
    // printf( "\nInColor: " ) ;
    // inColor( root );
    
    
    
    
    
    
    
    
    // printf( "\n%d", root-> left-> val );
    // printf( "\n%d", root-> left-> left-> val );
    // Rrotate( &root, root, root-> left );
    // printf( "\n%d", root-> left-> val );
    // printf( "\n%d", root-> left-> right-> val );


    // printf( "\n\n%d", root-> left-> val );
    // printf( "\n%d", root-> left-> right-> val );
    // Lrotate( &root, root, root-> left );
    // printf( "\n%d", root-> left-> val );
    // printf( "\n%d", root-> left-> left-> val );
    
    
    
    
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
