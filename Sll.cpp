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

void Sll::print_addresses(){

     Node *first_head = head ;

          while( first_head ){

               cout << first_head << " " ;
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

//without a tail stating point
Node* Sll::get_tail_without_tail(){

     Node* current = head ;

     for( current ; current->next ; current=current->next ) ;

     return current ;
}

void Sll::add_element_without_tail( int value ){

     insert_front( value ) ;
}
// without a tail ending point


void Sll::insert_front( int value ){

     Node* first = new Node( value ) ;


     first->next = head ;
     length++ ;
     head = first ;

     if(length == 1)
          tail = head ;

}


void Sll::insert_back( int value ){

     length++ ;
     Node *item = new Node( value ) ;

     if( !head )
          head = tail = item ;

     else {

          tail->next = item ;
          tail = item ;
          tail->next = nullptr ;
     }
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

void Sll::delete_last(){

     if( length <= 1 ){

          delete_front() ;
          return;
     }

     tail = get_node_back(2) ;
     tail->next = nullptr ;

     length-- ;
}


void Sll::delete_node_using_index( int ind ){ // 1 base

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


void Sll::delete_next_node( Node *node ){

     Node *next_node = node->next ;
     node->next = next_node->next ;
     bool is_tail = tail = next_node ;

     if(is_tail)
          tail = node ;

     delete next_node ;

}

void Sll::delete_first_node_exist( int value ){// delete with the key

     if( head->data == value ){
          delete_front() ;
          return;
     }
     else{

          for( Node *curr = head->next, *prev = head ; curr ; prev = curr , curr = curr->next ){

               if( curr->data == value ){

                  delete_next_node( prev ) ;
                  return;
               }
          }
     }

     cout << "Invalid value \n" ;
}


void Sll::swap_each_2value(){ // So imp

     if( length <= 1 )
          return;
                         // At here
     for(Node *curr = head ; curr ; curr = curr->next->next ){ // So imp bug it must be << curr not curr->next >> because it will work only when the length is odd and it will crash when the length is even, just try it

          if( curr->next ){

               swap( curr->data , curr->next->data ) ;
          }else break ;
     }
}


void Sll::Myreverse(){// The idea is as following : shift(link) every node to the left side instead of (link)shift to the right side

     if( length <= 1 )
          return;

     tail = head ;
     Node *prev = head ;
     head = head->next ;

     while( head ){

          Node *next_node = head->next ;
          head->next = prev ;

          prev = head ;
          head = next_node ;
     }
     head = prev ;
}


void Sll::delete_even_pos(){

    if( length <= 1 )return;

    for( Node *curr = head->next , *prev = head ; curr ; prev=prev->next , curr = prev->next ){

          delete_next_node( prev ) ;

          if( !prev->next )
               break ;
    }

}


void Sll::insert_sorted( int value ){

     if( !head || length<1 || value <= head->data )
          insert_front( value ) ;
     else if( value >= tail->data )
          insert_back( value ) ;
     else{

          for( Node *curr = head->next , *prev = head ; curr ; prev = curr , curr = curr->next ){

               if( value <= curr->data ){

                    Node *item = new Node( value ) ;
                    prev->next = item ;
                    item ->next = curr ;

                    break ;
               }
          }
     }


}

void Sll::add_at_index( int ind , int value ){

     Node *target = new Node( value ) ;

     if( ind == 1){

          target->next = head ;
          head = target ;

     }else if( ind == length){

          tail->next = target ;
          tail = target ;
          tail->next = nullptr ;

     }else{

          Node *curr =head ;
          for( int i = 1 ; i < length ; i++ ){

               if( i+1 == ind){

                    Node *Mynext = curr->next ;
                    curr->next = target ;
                    target->next = Mynext ;
                    break ;
               }
               curr = curr->next ;

          }
     }
     length++ ;

}

void Sll::swap_head_tail(){

     Node *next_head = head->next , *prev_tail = get_node_back(2) , *new_head = head ;

     tail->next = next_head ;
     head = tail ;
     prev_tail->next = new_head , tail = new_head , tail->next = nullptr ;

}

void Sll::left_rotate( int times ){

     times = times % length ; // To reduce  the number of iterations

     Node *nth_node = get_node( times ) ;
     tail->next = head ;
     head = nth_node->next ;
     tail = nth_node ;
     tail->next = nullptr ;

}

void Sll::remove_duplicates_notSorted(){

     for( Node *curr = head ; curr ; curr=curr->next ){
          for( Node *curr2 = curr->next , *prev = curr ; curr2 ; ){

               if( curr->data == curr2->data ){

                    delete_next_node( prev ) ;
                    curr2 = prev->next ;

               }else prev = curr2 , curr2 = curr2->next ;
          }
     }

}

void Sll::remove_last_occurance( int value ){

     if( !head || length < 1 )return;

     Node *my_prev = nullptr ;
     bool exist = 0 ;

     for( Node *curr = head , *prev = nullptr ; curr ; prev = curr , curr= curr->next ){

          if( curr->data == value )exist = 1 , my_prev = prev ;
     }

     if( exist = 1 ){

          if( my_prev )
               delete_next_node(my_prev) ;
          else delete_front() ;
     }

}

Node *Sll::move_to_tail( Node *curr , Node *prev ){

     Node *next = curr->next ;
     tail->next = curr ;

     if( prev )
          prev->next = next ;
     else
          head = next ;

     tail = curr  ;
     tail->next = nullptr ;
     curr = next ;
}

void Sll::move_to_end_list( int key ){

     if( length <= 1)
          return;


     int len = length ;


     for( Node *curr = head , *prev = nullptr ; len-- ; ){

          if( curr->data == key ){
               move_to_tail( curr , prev ) ;
          }
          else{
               prev = curr ;
               curr = curr->next ;
          }
     }
}

Sll::~Sll(){

     cout << "\n\ndestructor \n" ;
     for( Node* current=head ; current ; current=current->next ){

          cout << "A deleted value : " << current->data << "\n" ;
          delete current ;
     }

}






