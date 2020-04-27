#include <iostream>

#include "seq.hh"
#include "arrayseq.hh"
#include "dlinkseq.hh"

using namespace std;

template<typename E>
void print(SeqPtr<E>& Ptr)
{
	ConstIterPtr<E> begin = Ptr->cbegin();
	cout << "[ ";
	for(ConstIter<E> &b = *begin; b; ++b)
		cout << *b << " ";
	cout << "]" << endl;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "usage: ./seq-test ArraySeq|DLinkSeq" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		SeqPtr<string> list;
		string listType(argv[1]);
		//creation of doubly linked list;
		if(listType == "ArraySeq")
			list = ArraySeq<string>::make();
		//creation of fixed array list;
		else if(listType == "DLinkSeq")
			list = DLinkSeq<string>::make();
		else
		{
			cout << "usage: ./seq-test ArraySeq|DLinkSeq" << endl;
			exit(EXIT_FAILURE);
		}

		string cmd, value;
		int counter;
		cout << "[REPEAT] COMMAND [VALUE]\nCOMMAND is one of clear|unshift|shift|push|pop|help" << endl;
		while(true)
		{
			cout << ">> ";
			cin >> cmd;
			if(cmd == "clear")
			{
				list->clear();
				print(list);
			}
			else if(cmd == "unshift")
			{
				cin >> value;
				list->unshift(value);
				print(list);
			}
			else if(cmd == "shift")
			{
				value = list->shift();
				cout << value << endl;
				print(list);
			}
			else if(cmd == "push")
			{
				cin >> value;
				list->push(value);
				print(list);
			}
			else if(cmd == "pop")
			{
				value = list->pop();
				cout << value << endl;
				print(list);
			}
			else if(cmd == "help")
			{
				cout << "[REPEAT] COMMAND [VALUE]\nCOMMAND is one of clear|unshift|shift|push|pop|help" << endl;
			}
			else if(stoi(cmd))
			{
				counter = stoi(cmd);
				cin >> cmd;
				if(cmd == "clear")
				{
					for(; counter != 0; counter--)
						list->clear();
					print(list);
				}
				else if(cmd == "unshift")
				{
					cin >> value;
					for(; counter != 0; counter--)
						list->unshift(value);
					print(list);
				}
				else if(cmd == "shift")
				{
					for(; counter != 0; counter--)
					{
						value = list->shift();
						cout << value << endl;
					}
					print(list);
				}
				else if(cmd == "push")
				{
					cin >> value;
					for(; counter != 0; counter--)
						list->push(value);
					print(list);
				}
				else if(cmd == "pop")
				{
					for(; counter != 0; counter--)
					{
						value = list->pop();
						cout << value << endl;
					}
					print(list);
				}
			}
			else
			{
					cout << "COMMAND NOT FOUND" << endl;
					exit(EXIT_FAILURE);
			}
		}
	}
}