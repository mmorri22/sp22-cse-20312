#ifndef DYNARR_H
#define DYNARR_H

#include <iostream>

template<class T>
class DynArr{
	
		private:
			unsigned int size; // Current number of elements
			unsigned int capac; // Current capacity
			T* data;
			

			void copy(T* destin, T* origin, int len){
				
				for(unsigned int iter = 0; iter < len; ++iter){
					
					*(destin+iter) = origin[iter];
				}
			}
		
		public:
		
			DynArr(const int sizeIn = 0) :
				size(sizeIn),
				capac(sizeIn ? sizeIn : 8),
				data(new T[capac]) {}
				
			~DynArr(){
				delete [] data;
			}
			
			DynArr(const DynArr<T>& C) : 
				size(C.size), capac(C.capac), data(new T[capac])
			{
				copy(data, C.data, C.size);
			}
			
			DynArr<T>& operator=(const DynArr<T>& assign){
				
				if(this != &assign){
					size = assign.size;
					capac = assign.capac;
					data = new T[capac];
					
					copy(data, assign.data, size);
				}
				
				return *this;
			}
			
			
			T& begin(){
				
				return data[0];
			}
			
			const T& begin() const{
				
				return data[0];
			}

			T& end(){
				
				return data[size - 1];
			}
			
			const T& end() const{
				
				return data[size - 1];
				
			}	
			
			unsigned int length() const{
				return size;
			}
			
			unsigned int capacity() const{
				return capac;
			}
			
			T& operator[](const unsigned int i){
				
				return data[i];
			}
			
			const T& operator[](const unsigned int i) const{
				
				return data[i];
			}
			
			
			void push_back(const T& value){
				
				if(size >= capac){
					capac = capac * 2;
					T* tmp = new T[capac];
					copy(tmp, data, size);
					delete [] data;
					data = tmp;
				}
				
				data[size] = value;
				size++;
				
			}
			
			
			void erase(unsigned int e){
				
				// Error checking on the bounds 
				if(e >= size){
					
					return;
				}
				
				// Reduce the size of the DynArr if
				// size is now less than half of the 
				// current capacity 
				if(size - 1 == capac / 2){
					capac = capac / 2;
				}
				
				T* tmp = new T[capac];
				
				unsigned int tmp_iter = 0;
				for(unsigned int data_iter = 0; data_iter < capac; ++data_iter){
					
					if( data_iter != e ){
						
						tmp[tmp_iter] = *(data + data_iter);
						++tmp_iter;
						
					}
				}
				
				delete [] data;
				data = tmp;
				--size;

			}
			
			friend std::ostream& operator<<(std::ostream& output, const DynArr<T>& array){
				
				output << "{";
				
				for(unsigned int iter = 0; iter < array.size; iter++){
					
					output << array[iter] << ", ";
				}
				
				output << "}";
				
				return output;
				
			}
			
	
};

#endif