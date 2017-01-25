/*
 * TestQueue.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: VienVonVan
 */


#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q1;
	cout << "Should print out an empty line: " << endl;
	q1.print();

	q1.enqueue("Vien");
	cout << "Should print out 'Vien'" << endl;
	q1.print();
	q1.enqueue("Van");
	cout << "Should print out 'Vien Van'" << endl;
	q1.print();

	cout << "Should print out 'Vien' : " << q1.get_front() << endl;
	cout << "Should print out 2: " << q1.get_size() << endl;

	Queue q2(q1);
	cout << "Should print out 'Vien Van' " << endl;
	q2.print();

	cout << "Should print out 'Deep copies'" << endl;
	(q2==q1) ? cout << "Deep copies \n" : cout << "Shallow copies \n";

	cout << "Should print out False: " << endl;
	if(q1.is_empty())
		cout << "True" << endl;
	else
		cout << "False" << endl;

	q1.dequeue();
	cout << "Should print out 'Van' " << endl;
	q1.print();

}
