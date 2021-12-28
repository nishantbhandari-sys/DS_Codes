#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data ;
    struct node* left ;
    struct node* right ;
    struct node* p ;    //  Parent
    
} node ;

node* create( int key ){
    //  Creates an ideal node 
    
    node* tmp = (node*) malloc( sizeof( node ) ) ;
    tmp-> data = key ;
    tmp-> p = NULL ;
    tmp-> left = NULL ;
    tmp-> right = NULL ;
    
    return tmp ;
}
void inOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    inOrder( root-> left ) ;
    printf( "%d ", root-> data ) ;
    inOrder( root-> right ) ;
} 
node* search( node* root, int key ){
    //  returns addr of node == key, if present else NULL
    
    if( root == NULL || root-> data == key ){
        return root ;
    }
    
    if( key < root-> data )
        return search( root-> left, key ) ;
    
    return search( root-> right, key ) ;
}
node* min( node* root ){
    //  returns node with min element of tree
    if( root-> left == NULL )
        return root ;
    
    return min( root-> left ) ;
}
node* max( node* root ){
    //  returns node with max element of tree
    if( root-> right == NULL )
        return root ;
    
    return max( root-> right ) ;
}
node* successor( node* arb ){   //  Any arbitary node in tree
    //  returns next successor of arb node
    //  Or returns just next bigger element than arb node's element
    
    if( arb-> right != NULL ){
        return min( arb-> right ) ; //  If arb-> right != NULL then, successor is definitely min of right subtree
    }
    
    //  now as arb-> right == NULL... Therefore no successor exist below this node
    //  so we try to search above the tree
    
    //  IF any node above arb node is not a right child of its Parent
    //  then its parent is the next successor of arb node
    node* parent = arb-> p ;
    while( parent != NULL && arb == parent-> right ){
        arb = parent ;
        parent = parent-> p ;
    }
    
    return parent ;
}
void insert( node** root, node* z ){
    //  Inserts a new node z in tree
    
    node* parent = NULL ;
    node* child  = *root ;
    
    while( child != NULL ){
        
        parent = child ;
        
        if( z-> data < child-> data ){ //  if,  z.data < child.data
            child = parent-> left ;
        }
        else{                          //       z.data > child.data
            child = parent-> right ;
        }
    }
    
    z-> p = parent ;    //  z's new parent will be child's parent's
    
    if( parent == NULL ){   //  tree was empty
        *root = z ;
    }
    else if( z-> data < parent-> data ){
        parent-> left = z ;
    }
    else{
        parent-> right = z ;
    }
}
void replace( node** root, node* u, node* v ){
    //  puts vth node at uth node's place
    //  but doesn't take care of v's left and right
    
    if( u->p == NULL ){              //  u is the root node
        *root = v ;
    }
    else if( u == u-> p-> left ){    //  u is left child of it's parent
        u-> p-> left = v ;
    }
    else{                            //  u is right child of it's parent
        u-> p-> right = v ;
    }
    if( v != NULL )
        v-> p = u-> p ;              //  v's new parent is u's parent
}
void delete( node** root, node* z ){
    //  deletes zth node from tree
    
    //  case 1: 
        //  if z.left == NULL , if the node to delete has no left child
    if( z-> left == NULL ){
        replace( root, z, z-> right ) ;
    }
        
    //  case 2: 
        //  if z.right == NULL , if the node to delete has no right child
    else if( z-> right == NULL ){
        replace( root, z, z-> left ) ;
    }
    
    //  case 3: 
        //  if the node to delete has both left & right child
    else{
        node* y = successor( z ) ;
        //  now as y is Successor/min so it's left will always be NULL
        
        if( y != z-> right ){    //  If Successor != z.right
            replace( root, y, y-> right ) ;
            y-> right = z-> right ;
            y-> right-> p = y ;
        }
        replace( root, z, y ) ;
        y-> left = z-> left ;
        y-> left-> p = y ;
    }
}

int main(){
    
    node* root = NULL ;
    
    insert( &root, create( 5 ) ) ;
    insert( &root, create( 3 ) ) ;
    insert( &root, create( 7 ) ) ;
    insert( &root, create( 4 ) ) ;
    insert( &root, create( 6 ) ) ;
    insert( &root, create( 1 ) ) ;
    insert( &root, create( 8 ) ) ;

    printf( "\nInOrder: " ) ;
    inOrder( root ) ;
    
    node* x = NULL ;
    
    //  Deletion
        delete( &root, search( root, 5 ) ) ;
        printf( "\nInOrder: " ) ;
        inOrder( root ) ;
    
    //  Successor
        // x = successor( search( root, 8 ) ) ;
        // if( x != NULL )
        //     printf( "\nSuccessor: %d", x-> data );
        // else
        //     printf( "\nNo Successor" ) ;
        
    //  Maximum
        // x = max( root ) ;
        // if( x != NULL )
        //     printf( "\nMaximum: %d", x-> data );
        // else
        //     printf( "\nNot Found" ) ;
        
    //  Minimum
        // x = min( root ) ;
        // if( x != NULL )
        //     printf( "\nMinimum: %d", x-> data );
        // else
        //     printf( "\nNot Found" ) ;
        
    //  SEarching
        // if( (x = search( root, 7 ) ) != NULL )
        //     printf( "\nFound: %d", x-> data );
        // else
        //     printf( "\nNot Found" ) ;
        

    return 0;
}
