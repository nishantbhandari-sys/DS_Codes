#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data ;

} Stack ;


Stack* push( Stack *ptr, int *top, int val ){

	if( ptr == NULL ){  //  || *top == -1
		ptr = ( Stack* ) malloc( sizeof( Stack ) * 1 ) ;

		(*top) ++ ;
		ptr[ *top ].data = val ;

		return ptr ;
	}

	(*top) ++ ;
	Stack *temp = ( Stack* ) malloc( sizeof( Stack ) * (*top +1) ) ;

	if( temp == NULL ){
		printf("\nMemory FULL...\n");
		return ptr ;
	}

	for( int i = 0; i < *top; i++ ){
		temp[ i ].data = ptr[ i ].data ;
	}
// 	(*top) ++ ;
	temp[ *top ].data = val ;

	free( ptr ) ;

	return temp ;
}

void display( Stack *ptr, int top ){

	if( top == -1 ){
// 		printf("\nStack is Empty\n") ;
		return ;
	}

// 	printf("\nElements in Stack are: ");

	while( top >= 0 ){

		printf("%d ", ptr[ top ].data );
		top-- ;
	}

	printf("\n");
}

Stack* pop( Stack *ptr, int *top ){

	if( *top == -1 ){
// 		printf("\nCan't POP....Stack is Empty\n");
		return ptr ;
	}

// 	printf("\nPopped Element is: %d\n", ptr[ *top ].data );

	//	When top == 0 that means now our stack will become empty
	if( *top == 0 ){
		free( ptr ) ;
		*top = -1 ;
		return ptr = NULL ;
	}

	Stack *temp = ( Stack* ) malloc( sizeof( Stack ) * (*top) ) ;

	for (int i = 0; i < *top ; ++i){

		temp[ i ].data = ptr[ i ].data ;
	}

	(*top) -- ;
	free( ptr ) ;

	return temp ;
}














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


// void replace( node** root, node* u, node* v ){
//     //  puts vth node at uth node's place
//     //  but doesn't take care of v's left and right
    
//     if( u == *root ){              //  u is the root node
//         *root = v ;
//     }
//     else if( u-> data < *root-> data ){    //  u is left child of it's parent
//         u-> p-> left = v ;
//     }
//     else{                            //  u is right child of it's parent
//         u-> p-> right = v ;
//     }
//     if( v != NULL )
//         v-> p = u-> p ;              //  v's new parent is u's parent
// }

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




//  DFS on BST
int dfs( node* root, int key, Stack* stack, int top ){
    
    if( root == NULL )  return 0;
    
    if( root-> data == key ) return 1;
    
    stack = push( stack, &top, root-> data );
    
    if( dfs( root-> left, key, stack, top ) != 0 )
        return 1;
    
    if( dfs( root-> right, key, stack, top ) != 0 )
        return 1;
        
    stack = pop( stack, &top );
    
    return 0;
}
//  BFS on BST






int main(){
    
    node* root = NULL ;
    
    insert( &root, create( 10 ) ) ;
    insert( &root, create( 5 ) ) ;
    insert( &root, create( 12 ) ) ;
    insert( &root, create( 11 ) ) ;
    insert( &root, create( 15 ) ) ;
    insert( &root, create( 13 ) ) ;
    insert( &root, create( 14 ) ) ;

    printf( "\nInOrder: " ) ;
    inOrder( root ) ;
    
    node* x = NULL ;
    
    //  DFS
    // Stack *stk = NULL;
    // if( dfs( root, 14, stk, -1 ) )
    //     printf( "\nfound" );
    // else
    //     printf( "\nNot Found" );
    
    
    
    
    
    //  Deletion
        delete( root, 10 ) ;
        printf( "\nInOrder: " ) ;
        inOrder( root ) ;
        printf( "\n\n" );
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
