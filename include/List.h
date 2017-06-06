#ifndef LIST_H
#define LIST_H

#include "Node.h"

namespace eEngine
{
	namespace Utils
	{

	//Template Declaration
		template<class T> class List
		{
			Node<T> *start;
			Node<T> *end;
		public:
			List();
			int count;
			
			int find(T *object);
			T* get(int index);
			void add(T *object);
			bool removeByRef(T *object);
			bool removeByIndex(int index);
			bool contains(T *object);
		};
	//Template Definition

		
		template<class T>
		List<T>::List()
		{
			start = nullptr;
			end = nullptr;
			count = 0;
		}

		//For pointers to objects.
		template<class T>
		int List<T>::find(T *object)
		{
			Node<T> *iterator;
			iterator = start;
			int counter = -1;

			while(counter < count)
			{
				counter++;
				if(*iterator->data == *object)
				{
					return count - counter - 1;
				}
				iterator = iterator->next;
			}
			return -1;
		}

		template<class T>
		T* List<T>::get(int index)
		{
			if(index < count && index >= 0)
			{
				Node<T> *iterator;
				int correctedIndex = count - index - 1;
				int counter = 0;
				iterator = start;

				while(counter != correctedIndex)
				{
					iterator = iterator->next;
					counter++;
				}
				return iterator->data;
			}
			else
			{
				return nullptr;
			}
		}

		template<class T>
		void List<T>::add(T *object)
		{
			Node<T>* node = new Node<T>();
			node->data = object;

			if(count == 0)
			{
				start = node;
				end = node;
			}
			else
			{
				node->next = start;
				start = node;
			}
			count++;
		}

		template<class T>
		bool List<T>::removeByRef(T *object)
		{
			Node<T> *iterator;
			Node<T> *prevNode;
			iterator = start;
			prevNode = start;
			int counter = -1;

			while(counter < count)
			{
				counter++;
				if(*iterator->data == *object)
				{
					if(iterator == start)
					{
						start = iterator->next;
					}
					else if(iterator == end)
					{
						end = prevNode;
						prevNode->next = nullptr;
					}
					else
					{
						prevNode->next = iterator->next;
					}
					count--;
					delete iterator;
					return true;
				}
				prevNode = iterator;
				iterator = iterator->next;
			}
			return false;
		}

		
		template<class T>
		bool List<T>::removeByIndex(int index)
		{
			if(index < count && index >= 0)
			{
				Node<T> *iterator;
				Node<T> *prevNode;
				int correctedIndex = count - index - 1;
				int counter = 0;
				iterator = start;
				prevNode = start;

				while(counter != correctedIndex)
				{	
					prevNode = iterator;
					iterator = iterator->next;
					counter++;
				}
				
				if(iterator == start)
				{
					start = iterator->next;
				}
				else if(iterator == end)
				{
					end = prevNode;
					prevNode->next = nullptr;
				}
				else
				{
					prevNode->next = iterator->next;
				}
				count--;
				delete iterator;
				return true;
			}
			else
			{
				return false;
			}
		}

		template<class T>
		bool List<T>::contains(T* object)
		{
			if(find(object) != -1)
				return true;
			else
				return false;
		}
	}
}


#endif