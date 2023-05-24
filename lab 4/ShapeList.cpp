//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include "ShapeList.h"
#include <iostream>
using namespace std;

ShapeList::ShapeList() {
  head = nullptr;
  return;
}

ShapeNode* ShapeList::find(string name) const {
  ShapeNode* node = head;
  while(node != nullptr) {
    if(name == node->getShape()->getName()){
      return node;
    }
    node = node->getNext();
  }
  return nullptr;
}

ShapeList::~ShapeList() {
  ShapeNode* node = head;
  while (node != nullptr) {
    head = node->getNext();
    delete node;
    node = head;
  }
  return;
}

void ShapeList::print() const {
  ShapeNode* node = head;
  while(node != nullptr) {
    node->print();
    //cout << endl;
    node = node->getNext();
  }
  return;
}

void ShapeList::setHead(ShapeNode* ptr) {
  head = ptr;
  return;
}

 ShapeNode* ShapeList::getHead() const {
   return head;
 }

void ShapeList::insert(ShapeNode* s) {
  ShapeNode* node = head;
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

ShapeNode* ShapeList::remove(string name) {
  ShapeNode* node = head;
  ShapeNode* previous = nullptr;
  
  while(node != nullptr) {
    if(name == node->getShape()->getName()){
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
}