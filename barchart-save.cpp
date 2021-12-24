// barchart.h
// TO DO:  this file is responsible for initializing the bar name, value and category

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"
#include <vector>

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Codio (light/dark mode)
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;

    string frame;
  
  
    static bool mySortFunction(Bar x, Bar y) {
        if(x.getValue() == y.getValue()) {
            return x.getName() < y.getName();
        }
      
        return y < x;
    }
    
 public:
    
    // default constructor:
    BarChart() {
        // TO DO:  Write this constructor.
        bars = nullptr;
        capacity = 0;
        size = 0;
        
        
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        capacity = n;
        size = 0;
        bars = new Bar[n];
        // TO DO:  Write this constructor.
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {

        capacity = other.capacity;
        size = other.size;
        frame = other.frame;

        bars = new Bar[other.capacity];
        for( int i = 0; i < size; i++) {
            bars[i] = other.bars[i];
        }

        // TO DO:  Write this constructor.
        
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
       
        capacity = other.capacity;
        size = other.size;
        frame = other.frame;

        bars = new Bar[other.capacity];
        for( int i = 0; i < size; i++) {
            bars[i] = other.bars[i];
        }


        // TO DO:  Write this operator.
        
        return *this;   // TO DO:  update this, it is only here so code compiles.
        //a = b = c = 0;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        
        // TO DO:  Write this operator.
        capacity = 0;
        size = 0;
        delete[] bars;
        bars = nullptr;
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {

        // TO DO:  Write this destructor.
        delete[] bars;
        
    }
    
    // setFrame
    void setFrame(string frame) {
    	
        // TO DO:  Write this destructor.
        this->frame = frame;

    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        
        // TO DO:  Write this function.
        return frame;
        
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {

        if(size == capacity) {
            return false;
        }

        // TO DO:  Write this function.

        Bar newBar(name, value, category); 
        bars[size] = newBar;
        size ++;

        return true; // TO DO:  update this, it is only here so code compiles.
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        
        // TO DO:  Write this function.
        
        return size;  // TO DO:  update this, it is only here so code compiles.
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        if ((i >= size) || (i < 0)) {
            throw out_of_range ("BarChart: i out of bounds");
        }

        // TO DO:  Write this function.
        return bars[i];  // TO DO:  update this, it is only here so code compiles.
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here

    void dump(ostream &output) {

        // TO DO:  Write this function.
        Bar* a = new Bar[size];
        for (int i = 0; i < size; i++) {
            a[i] = bars[i];
        }
      
        sort(a, a+size, mySortFunction);

        output << "frame: " << frame << endl;
        for (int i = 0; i <size; i++) {
            output<< a[i].getName() << " " 
                << a[i].getValue() << " " 
                << a[i].getCategory() << endl;
        }

        delete[] a;
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {

        Bar* a = new Bar[size];

        for (int i = 0; i < size; i++) {
            a[i] = bars[i];
        }
        
        sort(a, a+size, mySortFunction);
      
        if ((top > size) || (top < 0)) {
          top = size;
        }

       int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output

        double max_val = a[0].getValue(); 
      
      

        for (int j = 0; j < top; j++) {

            string color;
            if (colorMap.empty() || !colorMap.count(a[j].getCategory())) {
                color = WHITE;
            }
            
            else {
                color = colorMap[a[j].getCategory()];  // you should get this from colorMap
            } 

            string barstr = "";

            int num_boxes = (a[j].getValue() / max_val) * lenMax;

            for (int i = 0; i < num_boxes; i++) {
                barstr += BOX;
            }

            output << color << barstr << " " << a[j].getName() << " " << a[j].getValue() << endl;
        }

        delete[] a;
    }

    
};
