#pragma once
#include <iostream>


template<typename Type>
class Element {
private:
	Type value;
	Element<Type>* nextEl;
	Element<Type>* prevEl;
public:
	Element() {
		nextEl = nullptr;
		prevEl = nullptr;
	}

	void SetValue(Type _value) {
		value = _value;
	}

	void SetNextPtr(Element<Type>* _ptr) {
		nextEl = _ptr;
	}

	void SetPrevPtr(Element<Type>* _ptr) {
		prevEl = _ptr;
	}

	Element<Type>* GetPrevPtr() const {
		return prevEl;
	}

	Element<Type>* GetNextPtr() const {
		return nextEl;
	}

	Type GetValue() const {
		return value;
	}
};

template<typename Type>
class List {
private:
	unsigned int amount;
	Element<Type>* firstEl;
	Element<Type>* lastEl;
public:
	List() {
		amount = 0;
		firstEl = nullptr;
		lastEl = nullptr;
	}

	List(List<Type>& list) {
		amount = 0;
		firstEl = nullptr;
		lastEl = nullptr;
		for (int i = 0; i < list.amount; i++) {
			Append(list[i]);
		}
	}

	void Append(Type val) {
		Element<Type>* newElPtr = new Element<Type>;
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

	void Insert(Type rec, unsigned int idEl) {
		if (idEl > amount) {
			std::cout << "Insert error" << std::endl;
			return;
		}
		else {
			if (idEl == amount) {
				Append(rec);
				return;
			}
			Element<Type>* idElement = firstEl;
			for (unsigned int i = 0; i < idEl; i++) {
				idElement = idElement->GetNextPtr();
			}
			Element<Type>* newElPtr = new Element<Type>;
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

	void Edit(Type rec, unsigned int idEl) {
		if (idEl > amount) {
			std::cout << "Edit error" << std::endl;
		}
		else {
			Element<Type>* idElement = firstEl;
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
			std::cout << "Set error" << std::endl;
		}
		else {
			Element<Type>* newElementPtr = new Element<Type>;
			if (amount > 0) {
				Element<Type>* idElement = firstEl;
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

	Type Pop() {
		int value = lastEl->GetValue();
		Element<Type>* Ptr = lastEl;
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
			std::cout << "Delete error" << std::endl;
		}
		else {
			Element<Type>* idElement = firstEl;
			if (amount > 1) {
				for (unsigned int i = 0; i < idEl; i++) {
					idElement = idElement->GetNextPtr();
				}
				if (idElement == firstEl) {
					
					idElement->GetNextPtr()->SetPrevPtr(nullptr);
					firstEl = idElement->GetNextPtr();
				}
				else if (idElement == lastEl) {
					idElement->GetPrevPtr()->SetNextPtr(nullptr);
					lastEl = idElement->GetPrevPtr();
				}
				else {
					idElement->GetNextPtr()->SetPrevPtr(idElement->GetPrevPtr());
					idElement->GetPrevPtr()->SetNextPtr(idElement->GetNextPtr());
				}
			} else {
				firstEl = nullptr;
				lastEl = nullptr;
			}
			amount--;
			free(idElement);
		}
	}

	Type Get(unsigned int idEl) {
		if (idEl >= amount) {
			std::cout << "Get error" << std::endl;
		}
		else {
			Element<Type>* idElement = firstEl;
			for (unsigned int i = 0; i < idEl; i++) {
				idElement = idElement->GetNextPtr();
			}
			return idElement->GetValue();
		}
	}

	int Len() const {
		return amount;
	}

	void Swap(int firstElementId, int secondElementId) {
		if (firstElementId >= amount || secondElementId >= amount || Len() < 2) {
			std::cout << "Swap error" << std::endl;
		} else {
			Element<Type>* firstElement = firstEl;
			Element<Type>* secondElement = firstEl;
			Type buffer;

			for (unsigned int i = 0; i < firstElementId; i++) {
				firstElement = firstElement->GetNextPtr();
			}

			for (unsigned int i = 0; i < secondElementId; i++) {
				secondElement = secondElement->GetNextPtr();
			}

			buffer = firstElement->GetValue();
			firstElement->SetValue(secondElement->GetValue());
			secondElement->SetValue(buffer);
		}
	}

	Type operator[] (int i) {
		return Get(i);
	}

	~List() {
		Element<Type>* curEl;
		if (firstEl != nullptr) {
			curEl = firstEl;
		}
		else {
			return;
		}

		for (int i = 0; i < amount-1; i++) {
			Element<Type>* nextEl = curEl->GetNextPtr();
			delete curEl;
			curEl = nextEl;
		}

		delete lastEl;
	}
};