#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data ;
	struct node *next ;
}	Node ;

void display( Node* front, Node* rear ){
    if( rear == NULL ){
        printf( "QEmpty" ) ;
        return ;
    }

    while( front != rear ){
        printf( "%d ", front-> data ) ;
        front = front-> next ;
    }
    
    printf( "%d \n", rear-> data ) ;
}

Node* create( int val ){

	Node* temp = (Node*) malloc( sizeof( Node ) ) ;
	temp-> next = NULL ;
	temp-> data = val ;

	return temp ;
}

Node* add_next( Node* head, int val ){
    //  Adds a new node after head
    
    Node* tmp = create( val ) ;
    if( head == NULL )
        return tmp ;
    
    head-> next = tmp ;
    
    return tmp ;
}

void del_nxt( Node* pos, Node** front, Node** rear ){
//	Deletes next node
	
	Node* tmp = NULL ;
	
	//  If pos == 1st Node to delete
	if( pos == *front ){

	    *front = (*front)-> next ;  //  Move front ahead
	}
	
	//  if pos == Last node to delete
	else if( pos-> next == *rear ){
	    
	    tmp = *rear ;
	    
	    *rear = pos ;   //  new rear
	    
	    pos = tmp ;
	}
	
	//  Some node in mid to delete
	else{
	    
	    tmp = pos-> next ;  //  the node to delete
	    
	    pos-> next = tmp-> next ;
	    
	    pos = tmp ;
	}
		    
	free( pos ) ;
}


//  For PQueue
Node* enque( Node** front, Node* rear, int ins ){
    
    Node* tmp = add_next( rear, ins ) ;
    
    if( rear == NULL ){
        *front = rear = tmp ;
    }
    else
        rear = tmp ;
    
    return rear ;
}

Node* deque( Node** que_f, Node** que_r, Node** prty_f, Node** prty_r ){
    
    //  Initial priority of Pque
    int pp = (*prty_f)-> data ;

    Node* q = *que_f, *p = *prty_f ;
    
    Node* ptrv = *prty_f ;       //  FOr traversal of priority
    Node* qtrv = *que_f ;       //   FOr traversal of Queue
    
    //  Finding node with highest priority
    while( ptrv != *prty_r ){
        
        if( ptrv-> next-> data > pp ){
            
            pp = ptrv-> next-> data ;
            p = ptrv ;           //  Mark pos of previous node with current highest priority node
            q = qtrv ;
        }
        
        qtrv = qtrv-> next ;
        ptrv = ptrv-> next ;
    }
    
    //  Now p and q are pointing 1 node before the node with highest priority
    del_nxt( q, que_f, que_r ) ;  //  deletes nxt Node
    del_nxt( p, prty_f, prty_r ) ;  //      ||
    
}

int main(){

	Node *que_f = NULL ;
	Node *que_r = NULL ;
	
	Node *prty_f = NULL ;
	Node *prty_r = NULL ;
	
	int val, priority ;
	
	int ch ;
    do{
        printf( "\nEnter Your Choice: " ) ;
        scanf( "%d", &ch ) ;
        
        switch( ch ){
            
            case 1:
                    printf( "\nEnter Data and priority: " ) ;
                    scanf( "%d %d", &val, &priority ) ;
            
                    que_r  = enque( &que_f, que_r, val ) ; 
                    prty_r = enque( &prty_f, prty_r, priority ) ;          
                    
                    break ;
            
            case 2: 
                    deque( &que_f, &que_r, &prty_f, &prty_r ) ;          
                    
                    break ;
            
            case 3: printf( "\nQueue Elements: " ) ; 
                    display( que_f , que_r ) ;
                    printf( "\nQueue priority: " ) ;
                    display( prty_f , prty_r ) ;
                    
                    break ;
            
            default:    ch = -1 ;
        }
        if( ch == -1 ){
            printf( "\nExiting" ) ;
            break ;
        }
    } while( 1 ) ;

	return 0 ;
}
