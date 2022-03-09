#ifndef SORDYNARR_H
#define SORDYNARR_H

#include <iostream>
#include "DynArr.h"

template<class T>
class SorDynArr : public DynArr<T>{
	
	private:
	
	
	public:
	
		SorDynArr(const int sizeIn = 0) : DynArr<T>(sizeIn) {}
		
		~SorDynArr(){
			
			// Do Nothing 
		}
		
		void Insert(const T& value){
			
			if(this->size >= this->capac){
				
				if(this->capac == 0){
					
					this->capac = 1;
				}
				else{
					
					this->capac = this->capac * 2;
					
				}
			}
			
			T* tmp = new T[this->capac];
			
			unsigned int sort_iter = 0, iter = 0;
			
			while( iter < this->size && value > this->data[iter] ){
				
				tmp[sort_iter++] = this->data[iter++];
				
			}
			
			tmp[sort_iter++] = value;
			
			while( iter < this->size ){
				tmp[sort_iter++] = this->data[iter++];
			}
			
			this->size++;
			delete [] this->data;
			this->data = tmp;
			
		}
			
		/********************************************
		* Function Name  : operator<<
		* Pre-conditions : std::ostream& output, const SorDynArr<T>& theList 
		* Post-conditions: std::ostream&
		* 
		* Overloaded friend ostream operator for SorDynArr 
		********************************************/
		friend std::ostream& operator<<( std::ostream& output, const SorDynArr<T>& theList ){
			
			for(unsigned int iter = 0; iter < theList.size; iter++){
				
				std::cout << theList.data[iter] << " ";
			}
			
			return output;
		}
			
};
	

#endif