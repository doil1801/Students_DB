#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Element {
private:
	T value;
	Element<T>* nextEl;
	Element<T>* prevEl;
public:
	Element() {
		nextEl = nullptr;
		prevEl = nullptr;
	}

	void SetValue(T val) {
		value = val;
	}

	void SetNextPtr(Element<T>* Ptr) {
		nextEl = Ptr;
	}

	void SetPrevPtr(Element<T>* Ptr) {
		prevEl = Ptr;
	}

	Element<T>* GetPrevPtr() const {
		return prevEl;
	}

	Element<T>* GetNextPtr() const {
		return nextEl;
	}

	T GetValue() const {
		return value;
	}
};

template<typename T>
class List {
private:
	unsigned int amount;
	Element<T>* firstEl;
	Element<T>* lastEl;
public:
	List() {
		amount = 0;
		firstEl = nullptr;
		lastEl = nullptr;
	}

	void Append(T val) {
		Element<T>* newElPtr = new Element<T>;
		newElPtr->SetValue(val);
		if (amount != 0) {
			newElPtr->SetPrevPtr(lastEl);
			lastEl->SetNextPtr(newElPtr);
		}
		else {
			firstEl = newElPtr;
		}
		lastEl = newElPtr;
		amount++;
	}

	void Insert(T rec, unsigned int idEl) {
		if (idEl > amount) {
			cout << "Insert error";
			return;
		}
		else {
			if (idEl == amount) {
				Append(rec);
				return;
			}
			Element<T>* idElement = firstEl;
			for (unsigned int i = 0; i < idEl; i++) {
				idElement = idElement->GetNextPtr();
			}
			Element<T>* newElPtr = new Element<T>;
			if (idEl == 0) {
				newElPtr->SetPrevPtr(nullptr);
				newElPtr->SetNextPtr(idElement);
				idElement->SetPrevPtr(newElPtr);
				newElPtr->SetValue(rec);
				firstEl = newElPtr;
			}
			else {
				newElPtr->SetPrevPtr(idElement->GetPrevPtr());
				newElPtr->SetNextPtr(idElement);
				idElement->GetPrevPtr()->SetNextPtr(newElPtr);
				idElement->SetPrevPtr(newElPtr);
				newElPtr->SetValue(rec);
			}
			amount++;
		}
	}

	void Edit(T rec, unsigned int idEl) {
		if (idEl > amount) {
			cout << "Edit error";
		}
		else {
			Element<T>* idElement = firstEl;
			if (amount > 0) {
				for (unsigned int i = 0; i < idEl; i++) {
					idElement = idElement->GetNextPtr();
				}
				idElement->SetValue(rec);
			}
		}
	}

	void Set(int val, unsigned int idEl) {
		if (idEl > amount) {
			std::cout << "Set error";
		}
		else {
			Element<T>* newElementPtr = new Element<T>;
			if (amount > 0) {
				Element<T>* idElement = firstEl;
				for (unsigned int i = 0; i < idEl - 1; i++) {
					idElement = idElement->GetNextPtr();
				}
				if (idEl == amount) {
					newElementPtr->SetPrevPtr(lastEl);
					lastEl->SetNextPtr(newElementPtr);
					lastEl = newElementPtr;
				}
				else if (idEl == 0) {
					newElementPtr->SetNextPtr(firstEl);
					firstEl->SetPrevPtr(newElementPtr);
					firstEl = newElementPtr;
				}
			}
			else {

			}
			amount++;
		}
	}



	T Pop() {
		int value = lastEl->GetValue();
		Element<T>* Ptr = lastEl;
		if (amount > 1) {
			lastEl = lastEl->GetPrevPtr();
			lastEl->SetNextPtr(nullptr);
		}
		else {
			firstEl = nullptr;
			lastEl = nullptr;
		}
		free(Ptr);
		amount--;
		return value;
	}

	void Delete(unsigned int idEl) {
		if (idEl >= amount || amount == 0) {
			std::cout << "Delete error";
		}
		else {
			Element<T>* idElement = firstEl;
			if (amount > 1) {
				for (unsigned int i = 0; i < idEl; i++) {
					idElement = idElement->GetNextPtr();
				}
				if (idElement == firstEl) {
					idElement->GetNextPtr()->SetPrevPtr(nullptr);
				}
				else if (idElement == lastEl) {
					idElement->GetPrevPtr()->SetNextPtr(nullptr);
				}
				else {
					idElement->GetNextPtr()->SetPrevPtr(idElement->GetPrevPtr());
					idElement->GetPrevPtr()->SetNextPtr(idElement->GetNextPtr());
				}
			}
			amount--;
			free(idElement);
		}
	}

	T Get(unsigned int idEl) {
		if (idEl >= amount) {
			std::cout << "Get error";
		}
		else {
			Element<T>* idElement = firstEl;
			for (unsigned int i = 0; i < idEl; i++) {
				idElement = idElement->GetNextPtr();
			}
			return idElement->GetValue();
		}
	}



	int Len(){
		return amount;
	}

	~List() {
		Element<T>* curEl;
		if (firstEl != nullptr) {
			curEl = firstEl;
		}
		else {
			return;
		}

		for (int i = 0; i < amount-1; i++) {
			Element<T>* nextEl = curEl->GetNextPtr();
			delete curEl;
			curEl = nextEl;
		}

		delete lastEl;
	}
};