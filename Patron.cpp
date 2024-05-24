#include "Patron.h"

Patron::Patron(){
	return;
}

Patron::Patron(int patron_id){
	id = patron_id;
	return;
}

void Patron::borrow_doc(int doc_id){
	borrowed_docs.push_back(doc_id);
	return;
}

bool Patron::return_doc(int doc_id){
	for(int i=0; i < borrowed_docs.size(); i++){
		if(borrowed_docs[i] == doc_id){
			borrowed_docs.erase(borrowed_docs.begin() + i);
			return true;
		}
	}

	return false;
}

vector<int> Patron::get_borrowed_docs(){
	return borrowed_docs;
}