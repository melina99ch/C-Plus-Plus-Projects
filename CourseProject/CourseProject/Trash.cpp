//
//  
//  Course Project
//  Created by Melina Chapkanova on 23/11/2019.
//  Copyright © 2019 MelinaCh. All rights reserved.

#include "Trash.hpp"
#include <math.h>

using std::string;


//Constructors for RECYCLABLE
Recyclable::Recyclable()
{
	setWeight(0);
	setPriority(0);
}

Recyclable::Recyclable(const int weight)
{
	setWeight(weight);
	determinePriority();
}


//Functions of Recyclable
void Recyclable::display()
{
}

void Recyclable::setWeight(int weight)
{
	this->weight = weight > 0 ? weight : 0;
}

void Recyclable::setPriority(int priority)
{
	this->priority = priority > 0 ? priority : 0;
}

int Recyclable::getWeight() const
{
	return weight;
}

int Recyclable::getPriority() const
{
	return priority;
}

//An overridden virtual Function that determines the priority of each item 
//based on its weight and priority
void Recyclable::determinePriority()
{
	priority = ((basePriorityMultiplier * weight) / 2);
}


//Constructors of NON_Recyclable

Non_Recyclable::Non_Recyclable()
{
	setWeight(0);
	setPriority();
}

Non_Recyclable::Non_Recyclable(const string & name, int weight)
{
	setName(name);
	setWeight(weight);
	determinePriority();
}

//Functions of NON-Recyclable
void Non_Recyclable::display()
{
	std::cout << "Non-Recyclable " << name << " | weight: " << weight << " | PRIORITY:" << priority << " | " << "\n";
}

void Non_Recyclable::setWeight(int weight)
{
	this->weight = weight > 0 ? weight : 0;
}

void Non_Recyclable::setPriority()
{
	this->priority = 0;
}

void Non_Recyclable::setName(const string & name)
{
	this->name = !name.empty() ? name : "Empty";
}

void Non_Recyclable::determinePriority()
{
	priority = 0;
}

int Non_Recyclable::getPriority() const
{
	return priority;
}

string Non_Recyclable::getName() const
{
	return name;
}

//Constructors of METAL
Metal::Metal()
{
}

Metal::Metal(int weight, const string & name)
{
	setName(name);
	setWeight(weight);
	determinePriority();
}


//Functions of METAL
void Metal::setWeight(int weight)
{
	this->weight = weight > 0 ? weight : 0;

}

void Metal::determinePriority()
{
	priority = ((basePriorityMultiplier * weight) / 2);
}

void Metal::setName(const string & name)
{
	this->name = !name.empty() ? name : "Empty";
}

void Metal::display()
{
	std::cout << "Recyclable " << "Metal "<< name << " | weight: " << weight << " | PRIORITY:" << priority << " | " << "\n";
}

int Metal::getPriority() const
{
	return priority;
}

string Metal::getName() const
{
	return name;
}

//
//
//Constructors of PAPER
Paper::Paper()
{
	setWeight(0);
	setPriority(0);
}

Paper::Paper(int weight, const string & name)
{
	setName(name);
	setWeight(weight);
	determinePriority();
}
//
//
//Functions of Paper
void Paper::setName(const string & name)
{
	this->name = !name.empty() ? name : "Empty";
}

void Paper::setWeight(int weight)
{
	this->weight = weight > 0 ? weight : 0;
}

string Paper::getName() const
{
	return name;
}

void Paper::display()
{
	std::cout << "Recyclable Paper " << name << " | weight: " << weight << " | PRIORITY: " << priority << " | " << "\n";
}


void Paper::determinePriority()
{
	priority = (int)((baseMultiplierPriority * weight) / 2 );
}

int Paper::getPriority() const
{
	return priority;
}

//
//
//Constructors of PLASTIC
Plastic::Plastic()
{
	setWeight(0);
	setPriority(0);
	setColor("NULL");
	setPlasticType("NULL");
}

Plastic::Plastic(int weight, const string & name, const string & type, const string & color)
{
	setWeight(weight);
	setName(name);
	setPlasticType(type);
	setColor(color);
	determinePriority();
}
//
//
//Functions of PLASTIC
void Plastic::setName(const string & name)
{
	this->name = !name.empty() ? name : "Empty";
}

void Plastic::setColor(const string& color)
{
	this->color = !color.empty() ? color : "Empty";
}

void Plastic::determinePriority()
{
	priority = (basePriorityMultiplier * weight) / 2;
}

void Plastic::display()
{
	std::cout << "Recyclable Plastic " << name << " | weight: " << 
		weight << " | color: " << color << " | type of Plastic " << plasticType << " | PRIORITY: " << priority << " | " << '\n';
}

int Plastic::getPriority() const
{
	return priority;
}

string Plastic::getName() const
{
	return name;
}

string Plastic::getColor() const
{
	return color;
}

string Plastic::getPlasticType() const
{
	return plasticType;
}


void Plastic::setPlasticType(const std::string& type) {

	this->plasticType = !type.empty() ? type : "Empty";
}

void Plastic::setWeight(int weight)
{
	this->weight = weight > 0 ? weight : 0;

}
