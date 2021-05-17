#include <iostream>
#include "Node.h"
#include "Sll.h"

using namespace std;


int main()
{
    Sll linked ;

    linked.insertion(4) ;
    linked.insertion(5) ;
    linked.insertion(9) ;

    linked.print_while() ;
    cout << endl ;

    Node *node = nullptr ;

    node = linked.get_node( 8 ) ; // It will return null
    cout << node << endl ; // the output will be nullptr(0)

    node = linked.get_node( 3 ) ;
    cout << node->data << endl ; // The output will be #9

    cout << linked.get_index( 5 ) << endl ;

    linked.print_while() ; // 4 5 9
    cout << endl ;
    //linked.shift_one_left( 4 ) ;
    //linked.print_while() ; // 5 4 9

    int index = linked.improved_search(3) ;
    linked.print_while() ;
    cout << "\n" << index << "\n" << "********* \n" ;

    linked.delete_front() ;
    linked.insert_front(7) ;
    linked.print_while() ;

    node = linked.get_node_back(2) ;
    cout <<"\n" << node->data << "   " << linked.get_node(3)->data << endl ; // it will print 9 9

    linked.delete_last() ;
    linked.print_while() ;
    cout << endl ;

    linked.print_while() ; // 5 9

    linked.insert_front(4) ;//4 5 9

    linked.delete_last() ;
    linked.print_while() ;// 4 5

    linked.delete_last() ;
    linked.print_while() ;// 4

    linked.delete_front() ;
    linked.print_while() ;

    cout << "The length of list is " << linked.getLen() << endl ; // 0

    linked.insertion(4) ;
    linked.insertion(5) ;
    linked.insertion(9) ;

    linked.delete_node(4) ;
    linked.print_while() ;


}
