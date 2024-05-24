#ifndef PATRON_H
#define PATRON_H

using namespace std;

#include <vector>

class Patron{
public:
	Patron();
	Patron(int patron_id);
	void borrow_doc(int doc_id);
	bool return_doc(int doc_id);

	vector<int> get_borrowed_docs();

private:
	int id;
	vector<int> borrowed_docs;
};
#endif