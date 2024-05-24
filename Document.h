#ifndef DOCUMENT_H
#define DOCUMENT_H

using namespace std;

#include <string>

class Document{
public:
	Document();
	Document(string doc_name, int doc_id, int license_limit);
	bool borrow_out();
	void return_back();

	int get_id();
	void set_id(int new_id);

	string get_name();

private:
	string name;
	int id;
	int sum_of_copy;
	int cur_num_of_copy;
};
#endif