#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_

#include "seq.hh"
#include <iostream>
#include <memory>
#include <cassert>
#include <cstddef>
#include <utility>
using namespace std;

template<typename E> class DLinkSeqConstIter;

template<typename E>
class DLinkSeq: public Seq<E>
{
	public:
		static DLinkSeq<E>* head;
		DLinkSeq<E>* next;
		DLinkSeq<E>* prev;
		E data;
		friend class DLinkSeqConstIter<E>;

		//constructor;
		DLinkSeq(){next = prev = nullptr;}
		DLinkSeq(E e) : data(e){next = prev = nullptr;}

		//destructor;
		~DLinkSeq() {}

		static SeqPtr<E> make() 
		{
			return make_unique<DLinkSeq<E>>();
		}

		//frees up all memory;
		void clear()
		{
			if(head != nullptr)
				while(head->prev != nullptr)
				{
					head = head->prev;
					delete head->next;
				}
			head = nullptr;
		}

		void unshift(const E& item)
		{
			DLinkSeq<E>* temp = new DLinkSeq<E>(item);
			
			if(head == nullptr)
				head = temp;
			else
			{
				DLinkSeq<E>* curr = head;
				while(curr->prev != nullptr)
					curr = curr->prev;
				curr->prev = temp;
				temp->next = curr;
			}
		}

		void push(const E& item)
		{
			DLinkSeq<E>* temp = new DLinkSeq<E>(item);
			
			if(head == nullptr)
				head = temp;
			else
			{
				head->next = temp;
				temp->prev = head;
				head = temp;
			}
		}

		E shift()
		{
			if(head == nullptr)
			{
				cout << "Nothing in the DLinkSeq.\nExiting.\n";
				exit(EXIT_FAILURE);
			}
			else
			{
				DLinkSeq<E>* curr = head;
				E temp;
				while(curr->prev != nullptr)
					curr = curr->prev;
				temp = curr->data;
				if(curr->next != nullptr)
					curr->next->prev = nullptr;
				if(curr == head)
					head = nullptr;
				delete curr;
				return temp;
			}
		}

		E pop()
		{
			if(head == nullptr)
			{
				cout << "Nothing in the DLinkSeq.\nExiting.\n";
				exit(EXIT_FAILURE);
			}
			else
			{
				DLinkSeq<E>* curr = head;
				E temp = head->data;
				head = head->prev;
				if(head != nullptr)
					head->next = nullptr;
				delete curr;
				return temp;
			}
		}

		int size() const
		{
			int n = 0;
			DLinkSeq<E>* temp = head;
			while(temp != nullptr)
			{
				n++;
				temp = temp->prev;
			}
			return n;
		}

		//returns a pointer to the 'tail', or beginning element;
		ConstIterPtr<E> cbegin() const
		{
			DLinkSeq<E>* temp = head;
			if(head == nullptr)
				temp = nullptr;
			else
				while(temp->prev != nullptr)
					temp = temp->prev;

			return make_unique<DLinkSeqConstIter<E>>(temp);
		}
		
		//returns a pointer to head, or end element;
		ConstIterPtr<E> cend() const
		{
			return make_unique<DLinkSeqConstIter<E>>(head);
		}

		//tester function;
		void print()
		{	
			DLinkSeq<E>* temp = head;
			while(temp != nullptr)
			{
				cout << temp->data << endl;
				temp = temp->prev;
			}
		}
};

template<typename E>
DLinkSeq<E>* DLinkSeq<E>::head = nullptr;

template<typename E>
class DLinkSeqConstIter : public ConstIter<E>
{
	private:
		const DLinkSeq<E>* seq;
	public:
		DLinkSeqConstIter(const DLinkSeq<E>* initialSeq) : seq(initialSeq) {}
		DLinkSeqConstIter& operator++()
		{
			if(seq != nullptr)
				seq = seq->next;
			return *this;
		}
		DLinkSeqConstIter& operator--()
		{
			if(seq != nullptr)
				seq = seq->prev;
			return *this;
		}
		//a nullptr evaluates to false;
		operator bool()
		{
			if(seq != nullptr)
				return true;
			else
				return false;
		}
		const E& operator*()
		{
			if(seq != nullptr)
				return seq->data;
			else
				exit(EXIT_FAILURE);
		}
		const E* operator->()
		{
			if(seq != nullptr)
				return &seq->data;
			else
				exit(EXIT_FAILURE);
		}
};

#endif //ifndef DLINK_SEQ_HH_
