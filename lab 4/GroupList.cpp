//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include "GroupList.h"

GroupList::GroupList(){
  head = nullptr;
  return;
}

GroupList::~GroupList() {
  GroupNode* node = head;
  while (node != nullptr) {
    head = node->getNext();
    delete node;
    node = head;
  }
  return;
}
    
GroupNode* GroupList::getHead() const {
  return head;
}

void GroupList::setHead(GroupNode* ptr) {
  head = ptr;
  return;
}

void GroupList::insert(GroupNode* s){
  GroupNode* node = head;
  if(node == nullptr) {
    head = s;
    } else {
    while (node->getNext() != nullptr) {
      node = node-> getNext();
      }
    node->setNext(s);
    }
  return;
}

GroupNode* GroupList::remove(string name) {
  GroupNode* node = head;
  GroupNode* previous = nullptr;

  while(node!= nullptr) {
    if(name == node->getName()){
       if(previous == nullptr) {
         head = node->getNext();
      } else {
         previous->setNext(node->getNext());
      }
      node->setNext(nullptr);
      return node;
    }
    previous = node;
    node = node->getNext();
    }
  return nullptr;
  
  /*while(node->getName() != name) {
    previous = node;
    node = node->getNext();
      if(node == nullptr) {
        return nullptr;
      } 
    }
  if(previous == nullptr) {
    head = node->getNext();
  } else {
    previous->setNext(node->getNext());
  }
  return node;*/
}

void GroupList::print() const {
  GroupNode* node = head;
  while(node != nullptr) {
    node->print();
    node = node->getNext();
  }
  return;
}



