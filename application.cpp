// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
#include <vector>
using namespace std;


int main() {
  
  vector<string> file;
  
  unsigned int num = 0;
  unsigned int num2 = 0;
  unsigned int num3 = 0;
  
  cout << "List of Categories" << endl;
  cout << "1. Baby names" << endl;
  cout << "2. Brands" << endl;
  cout << "3. Cities in USA" << endl;
  cout << "4. Cities in the World" << endl;
  cout << "5. Countries" << endl;
  cout << "6. End game" << endl;
  cout << "7. Football " << endl;
  cout << "8. Game of Thrones " << endl;
  cout << "9. Infinity War" << endl;
  
  cout << "Pick and enter the number of category you would like to open: ";
  cin >> num;
  
  file.push_back("baby-names.txt");
  file.push_back("brands.txt");
  file.push_back("cities-usa.txt");
  file.push_back("cities.txt");
  file.push_back("countries.txt");
  file.push_back("baby-names.txt");
  file.push_back("baby-names.txt");
  file.push_back("baby-names.txt");
  file.push_back("baby-names.txt");
  
  cout << "File: " << file[num-1] << " opened" << endl;
  
  cout << "Enter the number of bars you want to display: ";
  cin >> num2;
  
  cout << "Enter the number of frames you want to play: ";
  cin >> num3;
  
  
  if (num > file.size()) {
    cout << "File category not in range" << endl;
    return -1;
  }
  
  ifstream inFile(file[num-1]);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);



	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, num2, num3);
  return 0;
}
