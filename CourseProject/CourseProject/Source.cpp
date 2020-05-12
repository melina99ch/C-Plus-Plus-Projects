//
//  
//  Course Project
//  Created by Melina Chapkanova on 23/11/2019.
//  Copyright © 2019 MelinaCh. All rights reserved.

#include <iostream>
#include "Trash.hpp"
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

//methods for sorting the vectors by Priority
bool sortByPriorityMetal(Metal* a, Metal* b) {
	return a->getPriority() > b->getPriority();
}
bool sortByPriorityPlastic(Plastic* a, Plastic* b) {

	return a->getPriority() > b->getPriority();
}
bool sortByPriorityPaper(Paper* a, Paper* b) {

	return a->getPriority() > b->getPriority();
}
bool sortByPriorityNon_Recyclable(Non_Recyclable* a, Non_Recyclable* b) {

	return a->getPriority() > b->getPriority();
}

int main()
{
	//creates the file to read from
	ifstream input;
	string fileName;

	//reads the file name
	cout << "Enter the name of the file: "; // input.txt
	cin >> fileName;

	input.open(fileName);

	if (input.fail())
	{
		cerr << "Error opening file!\n";
		return -1;
	}

	//crate  vectors that will store all the kinds of trash
	vector<Paper*> papers;
	vector<Plastic*> plastics;
	vector<Metal*> metals;
	vector<Non_Recyclable*> non_rec;

	//temporary variables
	string isRecyclable, name, color, type, plasticType;
	int weight = 0;

	//loop to read the lines of the file
	while (!input.eof())
	{
		//read and save the data in the temp vars
		input >> isRecyclable >> name;

		//checks of which type is the trash and creates the particular type with all its parameters
		if (isRecyclable == "R")
		{
			input >> type >> weight;

			if (type == "plastic") {

				input >> color >> plasticType;

				Plastic* trash = new Plastic(weight, name, color, plasticType);
				plastics.push_back(trash);

			}
			else if (type == "paper") {

				Paper* trash = new Paper(weight, name);
				papers.push_back(trash);
			}
			else if (type == "metal") {
				Metal* trash = new Metal(weight, name);
				metals.push_back(trash);
			}

		}
		else if (isRecyclable == "N") {
			input >> weight;
			Non_Recyclable* trash = new Non_Recyclable(name, weight);
			non_rec.push_back(trash);
		}
	}


	//sorts the elements in vectors
	sort(papers.begin(), papers.end(), sortByPriorityPaper);
	sort(metals.begin(), metals.end(), sortByPriorityMetal);
	sort(plastics.begin(), plastics.end(), sortByPriorityPlastic);
	sort(non_rec.begin(), non_rec.end(), sortByPriorityNon_Recyclable);


	//prints the sorted vectors 
	for (const auto& i : plastics)
	{
		i->display();
	}
	cout << "\n";
	for (const auto& i : metals)
	{
		i->display();
	}

	cout << "\n";
	for (const auto& i : papers)
	{
		i->display();
	}

	cout << "\n";
	for (const auto& i : non_rec)
	{
		i->display();
	}

	cout << "\n";
	return 0;
}