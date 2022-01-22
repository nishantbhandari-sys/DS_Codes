#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data ;
    struct node* left ;
    struct node* right ;
    
} node ;



typedef struct{
    
    node* val ;
} Queue ;

int front = -1, rear = -1 ;

Queue* enQ( Queue *ptr, node* value ){
    
    if( rear == -1 ){
        front = 0;
        rear  = 0;
        
        Queue *temp = (Queue*) malloc( sizeof( Queue ) ) ;
        temp[ 0 ].val = value ;
        
        return temp ;
    }
    
    rear++ ;
    Queue *temp = (Queue*) malloc( sizeof( Queue ) * (rear +2) ) ;
    for( int i = 0; i < rear; i++ ){
        temp[ i ].val = ptr[ i ].val ;
    }
    free( ptr ) ;
    temp[ rear ].val = value ;
    
    return temp ;
}
node* peek( Queue *que ){
    return que[ front ].val;
}
Queue* deQ( Queue *ptr ){
    if( rear == -1 ){
        return ptr ;
    }
    
    if( rear == 0 ){
        free( ptr ) ;
        rear = -1 ;
        front = -1;
        
        return NULL ;
    }
    
    Queue *temp = (Queue*) malloc( sizeof( Queue ) * rear ) ;
    for( int i = 1; i <= rear; i++ ){
        temp[ i -1].val = ptr[ i ].val ;
    }
    free( ptr ) ;
    rear-- ;
    
    return temp ;
}
int isEmpty( Queue *q ){
    if( rear == -1 )
        return 1;
    return 0;
}


















node* create( int key ){
    //  Creates an ideal node 
    
    node* tmp = (node*) malloc( sizeof( node ) ) ;
    tmp-> data = key ;
    tmp-> left = NULL ;
    tmp-> right = NULL ;
    
    return tmp ;
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
    // printf( "in min" );
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

node* suc( node* root, int key, node* succ ){
    if( root == NULL )  return NULL;

    if( root-> data > key ){    //  if true, this can be a possible successor
        succ = root;
        return suc( root-> left, key, succ ) ;
    }
    else if( root-> data < key ) {  //  if true, as data in node is already < key, so successor not possible
        return suc( root-> right, key, succ ) ;
    }
    else{
        //  At this point, key == root-> data
        return succ;
    }
    // printf( "\nparent: %d", parent-> data );
    // printf( "\nchild: %d", child-> data );
}

node* successor( node* root, node* arb ){   //  Any arbitary node in tree
    //  returns inorder successor of arb node
    //  Or 
    //  returns just next bigger element than arb node's element
    
    printf( "\nIn Succ\n" );
    if( arb-> right != NULL ){
        return min( arb-> right ) ; //  If arb-> right != NULL then, successor is definitely min of right subtree
    }
    
    //  now as arb-> right == NULL... Therefore no successor exist below this node
    //  As, left part(if exists) will always be < current val.
    //  so we try to search above the tree
    
    return suc( root, arb-> data, NULL );
}

node* delete( node* root, int key ){
    
    //  case 1:
    if( root == NULL )     return NULL;
    
    else if( root-> data < key ){ 
        //  Assign right part of z to
        root-> right = delete( root-> right, key ) ;
        return root;
    }
        
    else if( root-> data > key ){ 
        //  Assign left part of z to
        root-> left = delete( root-> left, key ) ;
        return root;
    }
    
    //  At this point root-> data == key:
    node* tree = NULL;
    //  case 1: 
        //  if root.left == NULL , if the node to delete has no left child
    if( root-> left == NULL ){
        tree = root-> right;
        free( root );
        return tree;
    }

    //  case 2: 
        //  if root.right == NULL , if the node to delete has no right child
    else if( root-> right == NULL ){
        tree = root-> left;
        free( root );
        return tree;
    }

    //  case 3: 
        //  if the node to delete has both left & right child
        //  then,
        //  find inorder successor of root node, and replace it with root & delete successor
    else{
        //  As root node(which has to be deleted) has 2 children, so doesn't matter what val of root node is given
        //  Successor will always exist in right part of root node, so no need to go above current node
        node* s = successor( NULL, root ) ;

        root-> data = s-> data;

        root-> right = delete( root-> right, s-> data );
    } 
    return root;
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
    
    printf( "%d ", root-> data ) ;
    preOrder( root-> left ) ;
    preOrder( root-> right ) ;
}
void inOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    inOrder( root-> left ) ;
    printf( "%d ", root-> data ) ;
    inOrder( root-> right ) ;
}
void postOrder( node* root ){
    if( root == NULL ){
        return ;
    }
    
    postOrder( root-> left ) ;
    postOrder( root-> right ) ;
    printf( "%d ", root-> data ) ;
}



//  BFS traversal on BST:
void bfs( node* root ){

    Queue* que = enQ( que, root );
    
    while( !isEmpty( que ) ){
        
        root = peek( que );
        printf( "%d ", root-> data );
        que = deQ( que );
        
        if( root-> left  != NULL )      que = enQ( que, root-> left );
        if( root-> right != NULL )      que = enQ( que, root-> right );
    }
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
    
    insert( &root, create( 10 ) ) ;
    insert( &root, create( 5 ) ) ;
    insert( &root, create( 15 ) ) ;
    insert( &root, create( 2 ) ) ;
    insert( &root, create( 7 ) ) ;
    insert( &root, create( 12 ) ) ;
    insert( &root, create( 17 ) ) ;
    insert( &root, create( 11 ) ) ;
    insert( &root, create( 16 ) ) ;

    printf( "\nInOrder: " ) ;
    inOrder( root ) ;

    
    //  BFS
    printf( "\nbfs: " );
    bfs( root );
    
    
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
        // printf( "\nx-> data: %d\n", x-> data );
        // x = successor( root, x ) ;
        // if( x != NULL )
        //     printf( "\nSuccessor: %d\n", x-> data );
        // else
        //     printf( "\nNo Successor\n" ) ;
        
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
