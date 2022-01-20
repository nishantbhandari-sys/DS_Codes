#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data ;

} Stack ;


Stack* push( Stack *ptr, int *top, int val ){

// 	int val ;
// 	printf( "Enter Element in Stack: " ) ;
// 	scanf( "%d", &val ) ;

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
node* suc( node* root, int key, node* parent ){
    if( root == NULL || root-> data == key ){
        return root;
    }
    node* child = NULL, *ans = NULL;
    
    if( key < root-> data ){
        child = root-> left;
        ans = suc( root-> left, key, child ) ;
    }
    else{
        child = root-> right;
        ans = suc( root-> right, key, child ) ;
    }
    
    if( ans != NULL ){
        return ans;
    }
    // printf( "\nparent: %d", parent-> data );
    // printf( "\nchild: %d", child-> data );
    
    if( child != parent-> right ){  //  child is left child of its parent
        return parent;
    }
    
    return NULL;
}

node* successor( node* root, node* arb ){   //  Any arbitary node in tree
    //  returns next successor of arb node
    //  Or returns just next bigger element than arb node's element
    
    if( arb-> right != NULL ){
        return min( arb-> right ) ; //  If arb-> right != NULL then, successor is definitely min of right subtree
    }
    
    //  now as arb-> right == NULL... Therefore no successor exist below this node
    //  so we try to search above the tree
    
    
    //  IF any node above arb node is not a right child of its Parent
    //  then its parent is the next successor of arb node
    node* parent = suc( root, arb-> data, root );
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
// void delete( node** root, node* z ){
//     //  deletes zth node from tree
    
//     //  case 1: 
//         //  if z.left == NULL , if the node to delete has no left child
//     if( z-> left == NULL ){
//         replace( root, z, z-> right ) ;
//     }
        
//     //  case 2: 
//         //  if z.right == NULL , if the node to delete has no right child
//     else if( z-> right == NULL ){
//         replace( root, z, z-> left ) ;
//     }
    
//     //  case 3: 
//         //  if the node to delete has both left & right child
//     else{
//         node* y = successor( z ) ;
//         //  now as y is Successor/min so it's left will always be NULL
        
//         if( y != z-> right ){    //  If Successor != z.right
//             replace( root, y, y-> right ) ;
//             y-> right = z-> right ;
//             y-> right-> p = y ;
//         }
//         replace( root, z, y ) ;
//         y-> left = z-> left ;
//         y-> left-> p = y ;
//     }
// }




//  DFS on BST
int dfs( node* root, int key, Stack* stack, int top ){
    
    if( root == NULL )  return 0;
    
    if( root-> data == key ) return 1;
    
    stack = push( stack, &top, root-> data );
    
    if( dfs( root-> left, key, stack, top ) != 0 )
        return 1;
        
    stack = pop( stack, &top );
    
    stack = push( stack, &top, root-> data );
    
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
    Stack *stk = NULL;
    if( dfs( root, 14, stk, -1 ) )
        printf( "\nfound" );
    else
        printf( "\nNot Found" );
    
    
    
    
    
    //  Deletion
        // delete( &root, search( root, 5 ) ) ;
        // printf( "\nInOrder: " ) ;
        // inOrder( root ) ;
    
    //  Successor
        // x = root-> left ;
        // printf( "\n%d\n", x-> data );
        // x = successor( root, x ) ;
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
