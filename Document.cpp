#include "Document.h"

Document::Document(){
	name = "NULL";
	sum_of_copy = 0;
	cur_num_of_copy = 0;
	return;
}

Document::Document(string doc_name, int doc_id, int license_limit){
	name = doc_name;
	id = doc_id;
	sum_of_copy = license_limit;
	cur_num_of_copy = sum_of_copy;
	return;
}

bool Document::borrow_out(){
	if(cur_num_of_copy > 0){
		cur_num_of_copy--;
		return true;
	}

	return false;
}

void Document::return_back(){
	cur_num_of_copy++;
	return;
}

int Document::get_id(){
	return id;
}

void Document::set_id(int new_id){
	id = new_id;
	return;
}

string Document::get_name(){
	return name;
}