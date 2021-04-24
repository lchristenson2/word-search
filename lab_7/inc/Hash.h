#ifndef Hash_h
#define Hash_h

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

struct Node{
	string word;
	Node* next;

	Node(){
		word = "";
		next = NULL;
	}

	Node(string str){
		word = str;
		next = NULL;
	}
};

struct HashTable{
    Node* head;
	Node* last;

    HashTable() {
        head = NULL;
		last = NULL;
    }

    void append(string str){
		if (head == NULL){
			head = new Node(str);
			last = head;
		}
		else {
			Node* theNode = new Node(str); 
			last->next = theNode;
			last = last->next;
		}
	}
};


#endif