#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit){
	Document d = Document(name, id, license_limit);
	documents[id] = d;
	return;
}

void DocumentManager::addPatron(int patronID){
	Patron p = Patron(patronID);
	patrons[patronID] = p;
	return;
}

int DocumentManager::search(string name){
	for(auto iter = documents.begin(); iter != documents.end(); ++iter){
		if(iter->second.get_name() == name){
			return iter->second.get_id();
		}
	}

	return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID){


	auto iter_doc = documents.find(docid);
	auto iter_pat = patrons.find(patronID);

	if(iter_doc == documents.end() || iter_pat == patrons.end()){
		return false;
	}


	if(!documents[docid].borrow_out()){
		return false;
	}

	patrons[patronID].borrow_doc(docid);
	return true;
}

void DocumentManager::returnDocument(int docid, int patronID){

	auto iter_pat = patrons.find(patronID);

	if(iter_pat == patrons.end()){
		return;
	}


	for(int i=0; i < patrons[patronID].get_borrowed_docs().size(); i++){
		if(patrons[patronID].get_borrowed_docs()[i] == docid){
			patrons[patronID].return_doc(docid);
			documents[docid].return_back();
			return;
		}
	}

	return;
}

map <int, Document> DocumentManager::get_docs(){
	return documents;
}

map <int, Patron> DocumentManager::get_pats(){
	return patrons;
}