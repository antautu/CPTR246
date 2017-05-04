/**********************************************
* Program:  final1.C                          *
* Author:   Eileen Peluso                     *
* Date:     04/15/2017                        *
*                                             *
* Abstract: Driver for the Product.h class    *
*           Used for part 1 of the final      *
**********************************************/
#include <iostream>
#include <cstdlib>
#include "Product.h"
 
using namespace std;

int main() {
	system("clear");
	Product fabricSoftener(112345543210, "Fluffin' Stuff", 5.50, 02, 10, 2017);
	
	Fresh planter(233445566770, "spring planter", 19.90, 04, 21, 2017, 
		"Garden Center", 21, "outside", false);
	Bakery donuts(9123450, "glazed donuts", .50, 04, 21, 2017, 
		"Ye Olde Bake Shop", 3, "by east door", false, 12, 250, false);
	Bakery veganCupcake(9543210, "vegan carrot cupcake", 2.00, 04, 21, 2017, 
		"Ye Olde Bake Shop", 5, "bakery cooler", true, 6, 375, true);
	Produce fujis(5123459, "Fuji apples", 1.99, 04, 15, 2017, 
		"Fresh from the Garden", 30, "apple bins", false, false, 5.25);
	Produce carrots(5940239, "organic carrots", .79, 04, 22, 2017, 
		"Fresh from the Garden", 21, "organic veggies", true, true, 2.0);
	Packaged cheerios(312345543210, "Cheerios", 3.79, 01, 31, 2017, 
		"11a", 'r');
	Packaged chipsAhoy(354321123459, "Chips Ahoy", 2.99, 02, 12, 2017,
		"12b", 'l');
	
	cout << endl << "The objects at the beginning of the program:" << endl;
	cout << fabricSoftener << endl; 
	
	cout << planter << endl;
	cout << donuts << endl;
	cout << veganCupcake << endl;
	cout << fujis << endl;
	cout << carrots << endl;
	cout << cheerios << endl;
	cout << chipsAhoy << endl;
	
	// Call the various member functions
	// Product class
	cout << endl << "The objects are being updated . . . " << endl;
	cout << fabricSoftener.getName() <<  " costs $" << fabricSoftener.getPrice() << "." << endl;
	fabricSoftener.setPrice(5.30);
	cout << "It now costs $" << fabricSoftener.getPrice() << "." << endl;
	cout << "It's been marked up to $" << fabricSoftener.markupOrReducePrice(.10) << "." << endl;
	fabricSoftener.addComment("Good stuff!");
	fabricSoftener.addComment("Two thumbs up.");
	fabricSoftener.addComment("I don't like the smell - yuck!");
	
	// Fresh class
	cout << "The planter should be pulled on " << planter.pullDate() << "." << endl;
	cout << "The planter originally costs $" << planter.getPrice() << "." << endl;
	cout << "It is reduced by 10%, resulting cost is $" << planter.markupOrReducePrice(-.10) << "." << endl;
	planter.setDepartment("Sale Center");
	
	// Bakery class
	cout << "The price of a dozen donuts is $" << donuts.getPrice() << "." << endl;
	cout << "We're marking the donuts down to $"<< donuts.markupOrReducePrice(-.10) << "." << endl;
	cout << "The price of a dozen donuts is now $" << donuts.getPrice() << "." << endl;
	cout << "Adding some comments to the donuts object. " << endl;
	donuts.addComment("A little on the dry side.");
	donuts.addComment("I'd only recommend these if you need some doorstops!");
	if (donuts.isGlutenFree())
		cout << "Oops!  Test 1 is NOT working." << endl;
	else
		cout << "Relax.  Test 1 is working." << endl;
	if (!veganCupcake.isGlutenFree())
		cout << "Oops!  Test 2 is NOT working." << endl;
	else
		cout << "Relax.  Test 2 is working." << endl;
	
	// Produce class
	cout << "The apples cost $" << fujis.getPrice() << "." << endl;
	cout << "The carrots cost $" << carrots.getPrice() << "." << endl;
	cout << "Pull the apples on " << fujis.pullDate() << " and the carrots on " <<
			carrots.pullDate() << "." << endl;
	cout << "The apples go on sale!" << endl;
	fujis.setPrice(1.69);
	cout << "Now the apples cost $" << fujis.getPrice() << "." << endl;
	
	// Packaged class
	cout << "Let's stock the shelves." << endl;
	cout << "We loaded up on Cheerios, adding " << cheerios.restocked(100) << " boxes." << endl;
	cout << "Then we added 50 more, giving " << cheerios.restocked(50) << " in all." << endl;
	cout << "Let's also stock up on cookies." << endl;
	chipsAhoy.restocked(50);
	cout << "Where can I find the cookies?  They're in " << chipsAhoy.whereIsIt() << "." << endl;
	cout << "The cookies cost $" << chipsAhoy.getPrice() << "." << endl;
	cout << "Let's sell 10 packages of cookies." << endl;
	for (int i = 0; i < 10; i++)
		chipsAhoy.soldOne();
	
	// Overloaded operators from Part 1
	if (donuts < veganCupcake)
		cout << "Test 3 is working." << endl;
	else
		cout << "Test 3 is NOT working." << endl;
	if (donuts < donuts)
		cout << "Test 4 is NOT working." << endl;
	else
		cout << "Test 4 is working." << endl;
	if (veganCupcake < donuts)
		cout << "Test 5 is NOT working." << endl;
	else
		cout << "Test 5 is working." << endl;
	cout << "The following demonstrates what may be an implementation dependent feature." << endl;
	cout << "The function calls are being resolved from right to left." << endl;
	cout << "Donuts go down in price from $" << donuts.getPrice() << " to $" <<
		(donuts - .05) << " each.  Making the package cost $" << 
		donuts.getPrice() << "." << endl;
	
	cout << "The resulting cost of the donuts is $" << donuts.getPrice() << "." << endl;
	cout << "The Chips Ahoy are going up in price, to $" << (chipsAhoy + .20) << "." << endl;
	
	
	cout << endl << "The objects at the end of part 1 of the final:" << endl;
	cout << fabricSoftener << endl; 
	
	cout << planter << endl;
	cout << donuts << endl;
	cout << veganCupcake << endl;
	cout << fujis << endl;
	cout << carrots << endl;
	cout << cheerios << endl;
	cout << chipsAhoy << endl;
	cout << "\nThe end!" << endl;
	
	return 0;
}

