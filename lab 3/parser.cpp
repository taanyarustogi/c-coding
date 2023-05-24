//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void maxShapes(istream &line);
void docreate(istream &line);
void domove(istream &line);
void rotate(istream &line);
void draw(istream &line);
void dodelete(istream &line);

bool morearguments(istream &line);
int checkname(string name, int l);
bool checktype(string type);

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if (command == "maxShapes") {
            maxShapes(lineStream);
        } else if (command == "create") {
            docreate(lineStream);
        } else if (command == "move") {
            domove(lineStream);
        } else if (command == "rotate") {
            rotate(lineStream);
        } else if (command == "draw") {
            draw(lineStream);
        } else if (command == "delete") {
            dodelete(lineStream);
        } else {
            cout << "Error: invalid command";
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << endl;
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

void maxShapes(istream &line) { 
  int shapes;
  line >> shapes;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (shapes < 0) {
    cout << "Error: invalid value";
    return;
  } else if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
  } else {
    max_shapes = shapes;
    shapesArray = new Shape *[max_shapes];
    for (int i = 0; i < max_shapes; i++) {
      shapesArray[i] = NULL;
    }
    cout <<  "New database: max shapes is " << max_shapes;
    return;
  }
}

void docreate(istream &line) { 
  string name, type;
  int locx, locy, sizex, sizey;
  line >> name;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (checkname(name, 1) == 1) {
    return;
  } 
  line >> type;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    } else {
      cout << "Error: invalid argument";
      return;
      }
  } else if (checktype(type)) {
    cout << "Error: invalid shape type";
    return;
    }
  line >> locx;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (locx < 0) {
    cout << "Error: invalid value";
    return;
    }
  line >> locy;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (locy < 0) {
    cout << "Error: invalid value";
    return;
    }
  line >> sizex;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (sizex < 0) {
    cout << "Error: invalid value";
    return;
    }
  line >> sizey;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (sizey < 0) {
    cout << "Error: invalid value";
    return;
  } else if (type == "circle" && sizex != sizey) {
    cout << "Error: invalid value";
  } else if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
  } else {
    shapesArray[shapeCount] = new Shape(name, type, locx, sizex, locy, sizey);
    shapeCount++;
    cout << "Created " << name << ": " << type << " " << locx << " " << locy << " " << sizex << " " << sizey;
    return;
  }
}

void domove(istream &line) {
  int movex, movey;
  string name;
  line >> name;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    }
    } else if (checkname(name, -1)==1) {
      return;
    }
  int i = checkname(name, 0);
  line >> movex;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (movex < 0) {
    cout << "Error: invalid value";
    return;
    }
  line >> movey;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    } 
  } else if (movey < 0) {
    cout << "Error: invalid value";
    return;
    } else if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
  } else {
    shapesArray[i] -> setXlocation(movex);
    shapesArray[i]->setYlocation(movey);
    cout << "Moved " << name << " to " << movex << " " << movey;
    return;
    }
}

void rotate(istream &line) {
  string name;
  int angle;
  line >> name;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    }
  } else if (checkname(name, -1)==1) {
      return;
    }
  int i = checkname(name, 0);
  line >> angle;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    }
  } else if (angle < 0 || angle > 360) {
    cout << "Error: invalid value";
    return;
    } else if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
  } else {
    shapesArray[i] -> setRotate(angle);
    shapeCount++;
    cout << "Rotated " << name << " by " << angle << " degrees";
    return;
  }
}

void draw(istream &line) {
  string name;
  int i=0;
  line >> name;
  if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    }
  } else if (name == "all") {
      if (morearguments(line)) {
        cout << "Error: too many arguments";
        return;
      } else {
         cout << "Drew all shapes";
        for (int k = 0; k < shapeCount; k++) {
            if (shapesArray[k]!= NULL) {
            cout<< endl;
           // cout << shapesArray[k]->getName();
            shapesArray[k]->draw();
            }
        }
        return;
      }
  } else if(checkname(name, -1)==1) {
      return;
    }
  i = checkname(name, 0);
  if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
    } else {
      cout << "Drew ";
        shapesArray[i]->draw();
    return;
    }
}
void dodelete(istream &line) {
    string name;
    line >> name;
    if (line.fail()) {
    if (line.eof()) {
      cout << "Error: too few arguments";
      return;
    }
    else {
      cout << "Error: invalid argument";
      return;
    }
  }
   if (morearguments(line)) {
    cout << "Error: too many arguments";
    return;
    }  
  if(name == "all") {
      cout << "Deleted: all shapes";
      for(int i=0; i < shapeCount; i++) {
          delete shapesArray[i];
      }
  } else if (checkname(name, -1) == -1) {
    for(int i=0; i < max_shapes; i++) {
    if(shapesArray[i]->getName()==name) {
      delete shapesArray[i];
      shapesArray[i] = NULL;
      cout << "Deleted shape " << name;
      return;
    } 
    }
  }
  }
  
bool morearguments(istream &line) {
  string loser;
  line >> loser;
  if (!line.fail()) {
    return true;
  } else {
    return false;
  }
}

int checkname(string name, int l) {
  for(int i=0; i < NUM_KEYWORDS; i++) {
    if (name == keyWordsList[i]) {
      cout << "Error: invalid shape name";
      return 1;
    } else if (name == shapeTypesList[i]) {
      cout << "Error: invalid shape name";
      return 1;
    } else if (name == "all") {
      cout << "Error: invalid shape name";
      return 1;
    }
  }
  for(int i=0; i < max_shapes; i++) {
    if(shapesArray[i] != NULL) {
      if (name == shapesArray[i]->getName()) {
        if (l == 1) {
          cout << "Error: shape name exists";
          return 1;
          } else if (l == -1) {
          return -1;
          } else if (l == 0) {
          return i;
          }
          }
        }
      }
  if (l == -1) {
    cout << "Error: shape " << name << " not found";
    return 1;
    }
  return -1;
}

bool checktype(string type) {
  for(int i = 0; i < NUM_TYPES; i++) {
    if (type == shapeTypesList[i]) {
      return false;
    }
  }
  return true;
}