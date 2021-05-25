#ifndef SLL_H
#define SLL_H
#include "Node.h"


class Sll{

private:

     Node *head ;
     Node *tail ;
     int length ;

public:

     Sll() ;
     int getLen(){return length ; }
     void insertion( int value ) ;
     void print_while() ;
     void print_addresses() ; // print the address of each node
     Node* get_node( int ind ) ; // get the value at index <<ind>> one base
     int get_index( int value ) ; // get index of given value zero base
     void shift_one_left( int value ) ; // According to it's name shift one element left
     int improved_search( int value ) ;
     void delete_next_node( Node *node ) ;
     //*********************
     void add_element_without_tail( int value ) ; // Adding elements will be in the reverse way
     Node* get_tail_without_tail() ;
     //********************
     void insert_front( int value ) ;
     void insert_back( int value ) ;
     void delete_front() ;
     Node* get_node_back( int ind ) ;
     bool is_same( const Sll& linkedList ) ;
     void delete_last() ;
     void delete_node_using_index( int ind ) ; // deleting using index 1 base

     void add_at_index( int ind , int value ) ; // 1 based && It'll add specific value at specific position

     // 5_E
     void delete_first_node_exist( int value ) ;
     void swap_each_2value() ;
     void Myreverse() ;
     void delete_even_pos() ;
     void insert_sorted( int value ) ;
     // 5_M
     void swap_head_tail() ; // It'll swap the address of each node not only data which have
     void left_rotate(int times ) ;
     void remove_duplicates_notSorted() ;
     void remove_last_occurance( int value ) ;
     Node* move_to_tail( Node *curr , Node *prev ) ;
     void move_to_end_list( int key ) ;

     ~Sll() ;
};


#endif // SLL_H
