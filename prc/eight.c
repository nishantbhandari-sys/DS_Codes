#include <stdio.h>
#include <stdlib.h>

//	Queue using LL

typedef struct node {

	int data ;
	struct node *next ;
}	node ;

node* create( int val ){

	node* temp = (node*) malloc( sizeof( node ) ) ;
	temp-> next = NULL ;
	temp-> data = val ;

	return temp ;
}

node* del_Beg( node* head ){

	node* tmp = head ;

	head = head-> next ;

	free( tmp ) ;

	return head ;
}

node* push( node** front, node* rear, int val ){

	//	If 1st node
	if( rear == NULL ){

		rear = create( val ) ;
		*front = rear ;

		return rear ;
	}
	rear-> next = create( val ) ;
	rear = rear-> next ;

	return rear ;
}
node* pop( node* front, node** rear ){
	if( front == NULL ){
		printf("\nNo Element, To pop!!!") ;
		return front ;
	}

	printf("\nPopped: %d", front-> data ) ;

	//	If last element to pop
	if( front-> next == NULL ){
		*rear = NULL ;
		return front = NULL ;
	}

	front = del_Beg( front ) ;

	return front ;
}
void display( node* front, node* rear ){
	if( front == NULL ){

		printf("\nNo Element, To display!!!") ;
		return ;
	}

	while( front != rear ){

		printf("%d ", front-> data ) ;
		front = front-> next ;
	}

	printf("%d \n", rear-> data ) ;
}

int main( ){
	
	node *front = NULL ;
	node *rear = NULL ;

	printf( "1: PUSH\n" ) ;
    printf( "2: POP\n" ) ;
    printf( "3: DISPLAY\n" ) ;
    printf( "4: PEEK\n" ) ;
    printf( "5: EXIT...\n" ) ;
	
	while( 1 ){
    
        int ch ;
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
        
            case 1:     scanf( "%d", &ch ) ;
            			rear = push( &front, rear, ch ) ;		break ;
                        
            case 2:     front = pop( front, &rear ) ;			break ;
                        
            case 3:     display( front, rear ) ;				break ;
            			
            default:    ch = -1 ;
        }
        
        if( ch == -1 ){
            break ;
        }
    }
    
    printf( "\nExiting...\n" ) ;

	return 0;
}
