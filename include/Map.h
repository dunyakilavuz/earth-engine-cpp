#ifndef MAP_H
#define MAP_H

namespace eEngine
{
	namespace Utils
	{
	//Template Declaration
		template<class K,class V> class Map
		{
			int size;
			int count;
			K *k;
			V *v;
			void resize();
		public:
			Map();
			void put(K k, V v);
			V get(K k);
		};

	//Template Definition

		template<class K,class V>
		Map<K,V>::Map()
		{
			size = 10;
			k = new K[size];
			v = new V[size];
			count = 0;
		}

		template<class K,class V>
		void Map<K,V>::resize()
		{
			if(count == size)
			{
				K *tempK = k;
				V *tempV = v;
				int oldSize = size;
				size = 2 * oldSize;
				k = new K[size];
				v = new V[size];

				for(int i = 0; i < oldSize; i++)
				{
					k[i] = tempK[i];
					v[i] = tempV[i];
				}
				delete [] tempK;
				delete [] tempV;
			}
		}

		template<class K,class V>
		void Map<K,V>::put(K key, V value)
		{
			k[count] = key;
			v[count] = value;
			count++;
			resize();
		}

		template<class K,class V>
		V Map<K,V>::get(K key)
		{
			for(int i = 0; i < count;i++)
			{
				if(k[i] == key)
				{
					return v[i];
				}
			}
			return -999; 
		}

	}
}

#endif