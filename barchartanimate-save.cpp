// barchartanimate.h
// TO DO:  this file is responsible setting up the variables needed to display a frame .

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    int colorCount = 0;
    map<string, string> colorMap;
  
    string title;
    string xlabel;
    string source;
  
    void myGrowFunction() {
        BarChart* temp;
        temp = barcharts;
        barcharts = new BarChart[capacity*2];
        for (int i = 0; i < size; i++) {
            barcharts[i] = temp[i];
        }
        delete[] temp;
        capacity = capacity*2;
    }

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        // TO DO:  Write this constructor.
        capacity = 4;
        barcharts = new BarChart[capacity];
        size = 0;
      
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
       
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        
        // TO DO:  Write this destructor.
      
        delete[] barcharts;
       
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      
    	
      // TO DO:  Write this constructor.
      string temp, a, b, c, d, e;
      getline(file, temp);
      
      
      string barNum;
      getline(file, barNum);
      
      if(barNum == ""){
          return;
      }
      int barNumber = stoi(barNum);
      
      BarChart myBarChart(barNumber);
      for (int i = 0; i < barNumber; i++) {
          getline(file, a, ',');
          myBarChart.setFrame(a);
        
          getline(file, b, ',');
          getline(file, c, ',');
          getline(file, d, ',');
          int value = stoi(d);
          getline(file, e);
          
          myBarChart.addBar(b, value, e);
        
          if (!colorMap.count(e)) {
              colorMap[e] = COLORS[colorCount];
              colorCount = (colorCount+1) % 7;
          }
      }
      
      barcharts[size] = myBarChart;
      size++;
      
      if (size == capacity) {
          myGrowFunction();
      }
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
    
        if (endIter == -1) {
            endIter = size;
        }
      
        // TO DO:  Write this function.
        for(int i = 0; i < endIter; i++) {
            usleep(3*microsecond);
            output << CLEARCONSOLE;
            
            output << BLACK << title << endl;
            output << BLACK << source << endl;
          
//          graph(ostream &output, map<string, string> &colorMap, int top)
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
          
        }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  // TO DO:  update this, it is only here so code compiles.
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        // TO DO:  Write this function.
      
        if ((i >= size) || (i < 0)) {
            throw out_of_range ("BarChartAnimate: i out of bounds");
        }
        
        return barcharts[i]; // TO DO:  update this, it is only here so code compiles.
    }
};
