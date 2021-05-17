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
     Node* get_node( int ind ) ; // get the value at index <<ind>> one base
     int get_index( int value ) ; // get index of given value zero base
     void shift_one_left( int value ) ; // According to it's name shift one element left
     int improved_search( int value ) ;
     //*********************
     void print_without_tail() ;
     void add_element_without_tail( int value ) ; // Adding elements will be in the reverse way
     Node* get_tail_without_tail() ;
     //********************
     void insert_front( int value ) ;
     void delete_front() ;
     Node* get_node_back( int ind ) ;
     bool is_same( const Sll& linkedList ) ;
     void delete_last() ;
     void delete_node( int ind ) ; // deleting using index 1 base

     ~Sll() ;
};


#endif // SLL_H
