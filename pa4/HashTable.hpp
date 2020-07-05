#pragma once
#include<regex>
#include<iostream>
using namespace std;
template<typename T>
class LinkedHashEntry {
private:
      int key;
      T value;
      LinkedHashEntry<T> *next;
public:
      LinkedHashEntry(int key, T value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }
      int getKey() {
            return key;
      }
      T getValue() {
            return value;
      }
      void setValue(T value) {
            this->value = value;
      }
      LinkedHashEntry<T> *getNext() {
            return next;
      }
      void setNext(LinkedHashEntry<T>*next) {
            this->next = next;
      }
};
template<typename T>
class HashTable {
private:
	int size;
	//IMPLEMENT	  
	LinkedHashEntry<T> **test;
    int hash(const int _key) { 
        return _key % size;
    }
public:
    HashTable(const int _size) {
		//IMPLEMENT
	    this->size = _size;
		test = new LinkedHashEntry<T>*[size];
		for(int i = 0; i < size; i++){
			test[i] = nullptr;
		}
    }

	~HashTable(){
		for (int i = 0; i < size; i++)
		{
			if(test[i] != nullptr){
				LinkedHashEntry<T> *prev = nullptr;
				LinkedHashEntry<T> *entry = test[i];
				while(entry !=nullptr){
					prev = entry;
					entry = entry->getNext();
					delete prev;
				}
			}
		}
        delete[] test;
	}
    
    void insert(const int _key, T _value) {
	    int loc = hash(_key);
		if(test[loc] == nullptr){
			test[loc] = new LinkedHashEntry<T>(_key,_value);
		} else{
			LinkedHashEntry<T> *entry = test[loc];
			while (entry->getNext() != nullptr)
			{
				entry = entry->getNext();
			}
			entry->setNext(new LinkedHashEntry<T>(_key,_value));
		}
    }
	
	int minChainLen(){
		int min = 9999;
		int count = 0;
		for(int i = 0; i<size; i++){
			if(test[i] != nullptr){
				LinkedHashEntry<T> *entry = test[i];
				while(entry!=nullptr){
					entry = entry->getNext();
					count ++;
				}
				if(count < min){
					min = count;
				}
				count =0;
			} 
		}
		return min;
	}
	
	int maxChainLen(){
		int max = -9999;
		int count = 0;
		for(int i = 0; i<size; i++){
			if(test[i] != nullptr){
				LinkedHashEntry<T> *entry = test[i];
				while(entry!=nullptr){
					entry = entry->getNext();
					count ++;
				}
				if(count > max){
					max = count;
				}
				count = 0;
			} 
		}
		return max;
	}
	
	double averageChainLen(){
		double sum;
		double count = 0;
		for(int i = 0; i<size; i++){
			if(test[i] != nullptr){
				LinkedHashEntry<T> *entry = test[i];
				while(entry!=nullptr){
					entry = entry->getNext();
					sum++;
				}
				count ++;
			} 
		}
		return sum/count;
	}
    T search(int _key) {
		int loc = (_key%size);
		if(test[loc] != nullptr){
			LinkedHashEntry<T> *entry = test[loc];
			while(entry->getNext() !=nullptr && entry->getKey()!=_key){
				entry = entry->getNext();
			}
			if(entry->getKey() == _key){
				return entry->getValue();
			} 
		}
		return T();
	}
};
