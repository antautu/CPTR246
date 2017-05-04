/***********************************************
* Program:  Product.h                          *
* Author:   Autumn Anthony                     *
* Date:     4/21/2017                          *
*                                              *
* Abstract: To be used with the driver final1.C*
***********************************************/
#include <iostream>
#ifndef PRODUCT_H
#define PRODUCT_H
#include <ctime>
#include <iomanip>
#include "StringLinkedList.h" 
 
using namespace std;

/******************** Product ********************/
class Product {
friend ostream & operator << (ostream & os, Product prod);
friend double operator + (Product & prod, double increasePrice);
friend double operator - (Product & prod, double increasePrice);
	public:
		Product(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear);
		void setPrice(double newPrice);
		double getPrice();
		string getName();
		double markupOrReducePrice(double percentage);
		void addComment(string theComment);
	protected:
		long UPC;
		string name;
		double price;
		time_t secondsSince;
		StringLinkedList comment;
};

/******************** Fresh ********************/
class Fresh: public Product {
friend ostream & operator << (ostream & os, Fresh prod);
	public:
		Fresh(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig);
		string getDepartment();
		void setDepartment(string newDepartment);
		string pullDate();
	protected:
		string department;
		int shelfLife;
		string location;
		bool needsRefrig;
};

/******************** Bakery ********************/
class Bakery: public Fresh {
friend ostream & operator << (ostream & os, Bakery prod);
friend bool operator < (Bakery prod1, Bakery prod2);
	public:
		Bakery(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig, int thePackCount, int theNumCalories, bool ifGlutenFree);
		double getPrice();
		bool isGlutenFree();
	protected:
		int packCount;
		int numCalories;
		bool glutenFree;
};

/******************** Produce ********************/
class Produce: public Fresh {
friend ostream & operator << (ostream & os, Produce prod);
	public:
		Produce(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig, bool ifOrganic, double theWeight);
		double getPrice();
		bool isOrganic();
	protected:
		bool organic;
		double weight;
};

/******************** Packaged ********************/
class Packaged: public Product {
friend ostream & operator << (ostream & os, Packaged prod);
	public:
		Packaged(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theAisleName, char theAisleSide);
		void soldOne();
		int restocked(int numReceived);
		string whereIsIt();
	protected:
		int numInStock;
		string aisleName;
		char aisleSide;
};

/*********************************************************************/
/******************** Member Function Definitions ********************/
/*********************************************************************/

/******************** Product ********************/
Product::Product(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear)
{
	UPC = theUPC;
	name = theName;
	price = thePrice;
	tm dateStocked;
	dateStocked.tm_sec = 0;
	dateStocked.tm_min = 0;
	dateStocked.tm_hour = 12;
	dateStocked.tm_mon = theMonth - 1;
	dateStocked.tm_mday = theDay;
	dateStocked.tm_year = theYear - 1900;
	secondsSince = mktime(&dateStocked);
}

void Product::setPrice(double newPrice)
{
	price = newPrice;
}

double Product::getPrice()
{
	return price;
}

string Product::getName()
{
	return name;
}

double Product::markupOrReducePrice(double percentage)
{
	price = price + (percentage * price);
	return price;
}

void Product::addComment(string theComment)
{
	comment.InsertNode(theComment);
}

/******************** Fresh ********************/
Fresh::Fresh(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig)
	: Product(theUPC, theName, thePrice, theMonth, theDay, theYear)
{
	department = theDepartment;
	shelfLife = theShelfLife;
	location = theLocation;
	needsRefrig = ifNeedsRefrig;
}

string Fresh::getDepartment()
{
	return department;
}

void Fresh::setDepartment(string newDepartment)
{
	department = newDepartment;
}

string Fresh::pullDate()
{
	time_t dateToPull;
	dateToPull = secondsSince + ((shelfLife + 1) * 24 * 60 * 60);
	tm * date;
	date = localtime(&dateToPull);
	char buildDate[200];
	char formatDate[] = "%a %b %d, %Y";
	strftime(buildDate, 200, formatDate, date);
	return buildDate;
}

/******************** Bakery ********************/
Bakery::Bakery(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig, int thePackCount, int theNumCalories, bool ifGlutenFree)
	: Fresh(theUPC, theName, thePrice, theMonth, theDay, theYear, theDepartment, theShelfLife, theLocation, ifNeedsRefrig)
{
	packCount = thePackCount;
	numCalories = theNumCalories;
	glutenFree = ifGlutenFree;
}

double Bakery::getPrice()
{
	return price * packCount;
}

bool Bakery::isGlutenFree()
{
	if (glutenFree)
		return true;
	else
		return false;
}

/******************** Produce ********************/
Produce::Produce(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theDepartment, int theShelfLife, string theLocation, bool ifNeedsRefrig, bool ifOrganic, double theWeight)
	: Fresh(theUPC, theName, thePrice, theMonth, theDay, theYear, theDepartment, theShelfLife, theLocation, ifNeedsRefrig)
{
	organic = ifOrganic;
	weight = theWeight;
}

double Produce::getPrice()
{
	return weight * price;
}

bool Produce::isOrganic()
{
	if (organic)
		return true;
	else
		return false;
}

/******************** Packaged ********************/
Packaged::Packaged(long theUPC, string theName, double thePrice, int theMonth, int theDay, int theYear, string theAisleName, char theAisleSide)
	: Product(theUPC, theName, thePrice, theMonth, theDay, theYear)
{
	aisleName = theAisleName;
	aisleSide = theAisleSide;
}

void Packaged::soldOne()
{
	numInStock --;
}

int Packaged::restocked(int numReceived)
{
	numInStock = numInStock + numReceived;
	return numInStock;
}

string Packaged::whereIsIt()
{
	string fullAisleSide;
	if (aisleSide == 'l')
		fullAisleSide = "-left";
	if (aisleSide == 'r')
		fullAisleSide = "-right";
	return aisleName + fullAisleSide;
}

/******************** Overloaded Operators ********************/

ostream & operator << (ostream & os, Product prod)
{
	tm * date;
	date = localtime(&prod.secondsSince);
	
	os << "UPC: " << prod.UPC / 10 << "-" << prod.UPC % 10 << "  Name: " << prod.name << "  " << fixed << setprecision(2) << "Price: $" << prod.price << endl;
	char buildDate[200];
	char formatDate[] = "    Date stocked: %a %b %d, %Y  ";
	strftime(buildDate, 200, formatDate, date);
	os << buildDate;
	
	if (prod.comment.Size() != 0)
		os << "Comments: ";
	
	prod.comment.Output(os);
	
	return os;
}

double operator + (Product & prod, double increasePrice)
{
	prod.price = prod.price + increasePrice;
	return prod.price;
}

double operator - (Product & prod, double decreasePrice)
{
	prod.price = prod.price - decreasePrice;
	return prod.price;
}

ostream & operator << (ostream & os, Fresh prod)
{
	os << (Product) prod << endl;
	os << "    Department: " << prod.department << "  Shelf life:" << prod.shelfLife << "  Location:" << prod.location << endl;
	if (prod.needsRefrig)
		os << "    *** keep refrigerated ***";
	else
		os << "    *** no refrigeration necessary ***";
	
	return os;
}

ostream & operator << (ostream & os, Bakery prod)
{
	os << (Fresh) prod << endl;
	os << "    per package:" << prod.packCount << "  calories:" << prod.numCalories;
	if (prod.glutenFree)
		os << "  *** gluten free ***";
	return os;
}

bool operator < (Bakery prod1, Bakery prod2)
{
	if (prod1.numCalories < prod2.numCalories)
		return true;
	else
		return false;
}

ostream & operator << (ostream & os, Produce prod)
{
	os << (Fresh) prod << endl;
	os << "    weight:" << prod.weight;
	if (prod.organic)
		os << "  *** organic ***";
	return os;
}

ostream & operator << (ostream & os, Packaged prod)
{
	os << (Product) prod << endl;
	os << "    Units on hand:" << prod.numInStock << "  location:" << prod.whereIsIt();
	return os;
}

#endif