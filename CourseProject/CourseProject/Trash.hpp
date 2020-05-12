#pragma once

//
//  
//  Course Project
//  Created by Melina Chapkanova on 23/11/2019.
//  Copyright © 2019 MelinaCh. All rights reserved.

#include <string>
#include <iostream>

using std::string;

//
//
//
//BASE CLASS
//
class Trash
{
public:
	virtual void display() = 0;
	virtual void determinePriority() = 0;
};

//SECOND LEVEL INHERITANCE --- RECYCLABLE
class Recyclable : public Trash
{
private:
	int weight;
	int priority;
	const int basePriorityMultiplier = 1;

public:
	Recyclable();
	Recyclable(int);
	void display();
	void setWeight(int);
	void setPriority(int);
	void determinePriority();
	int getWeight() const;
	int getPriority() const; 
};

//CLASS NON-RECYCLABLE
class Non_Recyclable : public Recyclable
{
private:
	string name;
	int weight;
	int priority;
	const int basePriorityMultiplier = 1;

public:
	Non_Recyclable();
	Non_Recyclable(const string&, int);
	void display();
	void setWeight(int);
	void setPriority();
	void setName(const string&);
	void determinePriority();
	int getPriority() const;
	string getName() const;
};

//THIRTH LEVEL INHERITANCE
//
//
//
//CLASS PAPER
class Paper : public Recyclable
{
private:
	string name;
	int weight;
	int priority;
	const int baseMultiplierPriority = 1;

public:
	Paper();
	Paper(int, const string&);
	void setName(const string&);
	void setWeight(int);
	void display();
	void determinePriority();
	int getPriority() const;
	string getName() const;
};

//CLASS PLASTIC
class Plastic : public Recyclable
{
private:
	string name;
	string color;
	string plasticType;
	int weight;
	int priority;
	const int basePriorityMultiplier = 3;


public:
	Plastic();
	Plastic(int, const string&, const string&, const string&);
	void setName(const string&);
	void setColor(const string&);
	void setPlasticType(const string&);
	void setWeight(int);
	void determinePriority();
	void display();
	int getPriority() const;
	string getName() const;
	string getColor() const;
	string getPlasticType() const;
};

//Class METAL
class Metal : public Recyclable
{
private:
	string name;
	int priority;
	int weight;
	const int basePriorityMultiplier = 2;

public:
	Metal();
	Metal(int, const string&);
	void setWeight(int);
	void determinePriority();
	void setName(const string&);
	void display();
	int getPriority() const;
	string getName() const;
};

