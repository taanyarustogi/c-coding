//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "GroupList.h"
#include "GroupNode.h"
#include "Shape.h"
#include "ShapeList.h"
#include "ShapeNode.h"
#include "globals.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList *gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void doshape(istream &line);
void dogroup(istream &line);
void domove(istream &line);
void dodraw(istream &line);
void dodelete(istream &line);

bool checkname(string name);
bool checknametwo(string name);
ShapeList* checkshapename(string name);
GroupNode* checkgroupname(string name);

int main() {
  // Create the groups list
  gList = new GroupList();
  // Create the pool group and add it to the group list
  GroupNode *poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS - 1]);
  gList->insert(poolGroup);

  string line;
  string command;

  cout << "> ";       // Prompt for input
  getline(cin, line); // Get a line from standard input

  while (!cin.eof()) {
    // Put the line in a linestream for parsing
    // Making a new sstream for each line so flags etc. are cleared
    stringstream lineStream(line);

    // Read from string stream into the command
    // The only way this can fail is if the eof is encountered
    lineStream >> command;

    // Check for the command and act accordingly
    // ECE244 Student: Insert your code here

    if (command == "shape") {
      doshape(lineStream);
    } else if (command == "group") {
      dogroup(lineStream);
    } else if (command == "draw") {
      dodraw(lineStream);
    } else if (command == "move") {
      domove(lineStream);
    } else if (command == "delete") {
      dodelete(lineStream);
    }

    // Once the command has been processed, prompt for the
    // next command
    cout << endl << "> "; // Prompt for input
    getline(cin, line);

  } // End input loop until EOF.

  return 0;
}

void doshape(istream &line) {
  string name, type;
  int locx, locy, sizex, sizey;

  line >> name;
  if (checkname(name)) {
    return;
  }
  if (checknametwo(name)) {
      return;
  }
  line >> type;
  line >> locx;
  line >> locy;
  line >> sizex;
  line >> sizey;

  Shape *shape = new Shape(name, type, locx, locy, sizex, sizey);
  ShapeNode *shapenode = new ShapeNode;
  shapenode->setShape(shape);
  
  gList->getHead()->getShapeList()->insert(shapenode);

  cout << name << ": " << type << " " << locx << " " << locy << " " << sizex
       << " " << sizey;
  return;
}

void dogroup(istream &line) {
  string name;

  line >> name;
  if (checkname(name)) {
    return;
  }
  if (checknametwo(name)) {
      return;
  }

  GroupNode* g = new GroupNode(name);
  gList->insert(g);
  cout << name << ": group ";
  return;
}

void domove(istream &line) {
  string shape, group;
  line >> shape;
  line >> group;
  
  ShapeList* shapelist = checkshapename(shape);
  GroupNode* groupnode = checkgroupname(group);
  
  if(checkname(shape)){
      return;
  }
  
  if (shapelist == nullptr) {
      cout << "error: shape " << shape << " not found" << endl;
    return;
  }
  
  if(checkname(group)){
      return;
  }
  
  if (groupnode == nullptr) {
      cout << "error: group " << group << " not found" << endl;
    return;
  }
  
  ShapeNode* shapenode = shapelist->remove(shape);
  groupnode-> getShapeList()->insert(shapenode);
  
  cout << "moved " << shape << " to " << group;
  return;
}

void dodraw(istream &line) {
  cout << "drawing:";
  gList->print();
  return;
}

void dodelete(istream &line) {
  string name;
  line >> name;
  
  if(checkname(name)){
      return;
  }
  
  ShapeList* shapelist = checkshapename(name);
  GroupNode* groupnode = checkgroupname(name);
  
  if (checkshapename== nullptr && checkgroupname== nullptr) {
    cout << "error: shape " << name << " not found" << endl;
    return;
  } else if(shapelist != nullptr) {
      ShapeNode* shape = shapelist->remove(name);
      delete shape;
  } else {
      ShapeNode* head = groupnode->getShapeList()->getHead();
      gList->getHead()->getShapeList()->insert(head);
      groupnode = gList->remove(name);
      groupnode->getShapeList()->setHead(NULL);
      delete groupnode;
      groupnode = nullptr;
  }

  cout << name << ": deleted ";
  return;
}

bool checkname(string name) {
  for (int i = 0; i < NUM_KEYWORDS; i++) {
    if (name == keyWordsList[i]) {
      cout << "error: invalid name";
      return true;
    }
  }
  for (int i = 0; i < NUM_TYPES; i++) {
    if (name == shapeTypesList[i]) {
      cout << "error: invalid name";
      return true;
    }
  }
  return false;
}
  
 bool checknametwo(string name) {
  // CHECKING IF SHAPE EXISTS
  GroupNode *p1 = gList->getHead();
  ShapeNode *p2 = nullptr;
  while (p1 != nullptr) {
    p2 = p1->getShapeList()->find(name);
    if (p2 == NULL) {
      p1 = p1->getNext();
    } else {
      cout << "error: name " << name << " exists";
      return true;
    }
  }
  // CHECKING IF GROUP EXISTS
  p1 = gList->getHead();
  while (p1 != nullptr) {
    if (p1->getName() == name) {
      cout << "error: name " << name << " exists";
      return true;
    } else {
      p1 = p1->getNext();
    }
  }
  return false;
 }

ShapeList* checkshapename(string name) {
  GroupNode *p1 = gList->getHead();
  ShapeNode *p2 = nullptr;
  while (p1 != nullptr) {
    p2 = p1->getShapeList()->find(name);
    if (p2 != NULL) {
       return p1->getShapeList();
    } else {
      p1 = p1->getNext(); 
    }
  }
  return NULL;
}

GroupNode* checkgroupname(string name) {
    GroupNode *p1 = gList->getHead();
    while (p1 != nullptr) {
        if (p1->getName() == name) {
            return p1;
        } else {
            p1 = p1->getNext();
        }
    }
    return NULL;
}