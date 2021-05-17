#include "Sll.h"
#include "Node.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std ;

Sll::Sll(){

     head = nullptr , tail = nullptr ;
     length = 0 ;
}

void Sll::insertion( int value ) {

          Node *new_element = nullptr ;
          new_element = new Node( value ) ;

          if( !head ){// head == nullptr
               head = tail = new_element ;
          }
          else{
               // copy and steal
               tail->next = new_element ;
               tail = new_element ;
          }

          length++ ;
     }

void Sll::print_while(){

          Node *first_head = head ;

          while( first_head ){

               cout << first_head->data << " " ;
               first_head = first_head->next ;
          }
          cout << endl ;
}

Node* Sll::get_node( int ind ){

     if( !( ind > 0 && ind <= length) )
          return nullptr ;

     Node *target = nullptr ;

     for( target = head ; ind-1 ; ind-- , target = target->next ){}

     return target ;
}

int Sll::get_index( int value ){

     int i = 0 ; // zero bassed

     for( Node *first = head ; first ; first = first->next , i++){

          if( (first->data) == value )
               return i ;
     }

     return -1 ;
}

void Sll::shift_one_left( int value ){

     int i = get_index( value ) ;
     if( i == -1 ){
          cout << " There is no value available \n" ;
          return;
     }
     if( i == 0 )cout << "The target value is at the beginning of list \n" ;

     int val1 = (get_node(i)->data) , val2 = (get_node(i-1)->data) ;
     Node *first = head  ;

     for( int j=0 ; j<=i ; j++ , first = first->next ){

          if( j == i-1 )(first->data) = val1 ;
          if( j == i )(first->data) = val2 ;
     }

}

int Sll::improved_search( int value ){

     int index = 0 ;
     Node* previous = nullptr ; // To carry the previous Node

     for( Node* current = head ; current ; current=current->next , index++){

          if( (current->data) == value ){

               if( !previous )
                    return index ;

               swap( previous->data , current->data) ;
               return index - 1 ;
          }
          previous = current ; // Assign to the previous element
     }

     return -1 ; // If the value wasn't found return -1
}

Node* Sll::get_tail_without_tail(){

     Node* current = head ;

     for( current ; current->next ; current=current->next ) ;

     return current ;
}

void Sll::insert_front( int value ){

     Node* front = new Node( value ) ;

     front->next = head ;
     length++ ;
     head = front ;

     delete front ;

}

Node* Sll::get_node_back( int ind ){

     assert( ind <= length && ind > 0 ) ;


     return get_node( length - ind + 1 ) ;

}

void Sll::delete_front(){

     Node* newHead = head->next ;
     head = nullptr ;
     head = newHead ;
     length-- ;

     if(!head)//we must consider if there is only just 1 element in list
          tail = nullptr ;
}

bool Sll::is_same( const Sll &linkedList ){

     if( length != linkedList.length )
          return false ;

     Node *first = head , *second = linkedList.head ;

     for( int i = 0 ; i < length ; first=first->next , second=second->next){

          if( first->data != second->data )
               return false ;
     }

     return true ;
}

void Sll::add_element_without_tail( int value ){

     insert_front( value ) ;
}

void Sll::delete_last(){

     if( length <= 1 ){

          delete_front() ;
          return;
     }

     tail = get_node_back(2) ;
     tail->next = nullptr ;

     length-- ;
}


void Sll::delete_node( int ind ){ // 1 base

     if( ind == 1){

          delete_front() ;

     }else if( ind > length || ind < 1 ){

          cout << "The number out of the range \n" ;

     }else{

          Node* previous = get_node( ind-1 ) ;
          Node* current = previous->next ;

          previous->next = current->next ;

          if( current == tail )
               tail = previous ;

          length-- ;
     }

}



Sll::~Sll(){

     cout << "\n\ndestructor \n" ;
     for( Node* current=head ; current ; current=current->next ){

          cout << "A deleted value : " << current->data << "\n" ;
          delete current ;
     }

}






