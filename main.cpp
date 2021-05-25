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

    linked.delete_node_using_index(4) ;
    linked.print_while() ;
    cout << "================== \n" ;

    Sll linked2 ;
    linked2.insertion(4) ;
    linked2.insertion(5) ;
    linked2.insertion(9) ;
    linked2.insertion(8) ;

    linked2.delete_first_node_exist(5) ;
    linked2.print_while() ; // 4 9 8

    linked2.swap_each_2value() ;
    linked2.print_while() ; // 9 4 8

    linked2.delete_even_pos() ;// 9 8
    linked2.print_while() ;

    linked2.insert_sorted(4) ;
    linked2.insert_sorted(15) ;
    linked2.insert_sorted(11) ;

    linked2.print_while() ; // 4 9 11 15

    linked2.insertion(9) ; // 4 9 11 15 9
    linked2.left_rotate(3) ; // 15 9 4 9 11
    linked2.print_while() ;

    linked2.remove_duplicates_notSorted() ;
    linked2.print_while() ;

    linked2.move_to_end_list(15) ;
    linked2.print_while() ;











/*
    Sll linked3 ;
    linked3.insert_sorted(4) ;
    linked3.insert_sorted(7) ;
    linked3.insert_sorted(4) ;
    linked3.print_while() ;
    cout << "reverse \n" ;
    linked3.Myreverse() ;
    linked3.print_while() ;
    linked3.add_at_index(3 , 0) ;
    linked3.print_while() ;

    linked3.add_at_index(3 , 0) ;
    linked3.print_while() ;

    cout << "\nThe addresses of each node \n"  << "Before swapping : " ;
    linked3.print_addresses() ;
    cout << "After swapping : " ;
    linked3.swap_head_tail() ;
    linked3.print_addresses() ; // 0 4 0 4 7

    linked3.left_rotate(6) ;
    linked3.print_while() ;

    //linked3.remove_duplicate_andKeep_theFitstOne() ;
    linked3.print_while() ;
    linked3.move_to_end_list( 4 ) ;
    linked3.print_while() ;

*/

}
