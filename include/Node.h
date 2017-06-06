#ifndef NODE_H
#define NODE_H

namespace eEngine
{
	namespace Utils
	{
	//Template Declaration

		template<class T> class Node
		{
		public:
			Node();
			T* data;	//For pointers to objects
			Node<T> *next;
		};

	//Template Definition

		template<class T>
		Node<T>::Node()
		{

		}
	}
	
}

#endif