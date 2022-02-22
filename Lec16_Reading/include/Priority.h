#ifndef PRIORITY_H
#define PRIORITY_H 

template<typename T>
struct Priority{
	
	private:
		T element;
		int weight;
	
	public:
	
		Priority( ) : element( ), weight( ) {}
		
		Priority( T elementIn, int weightIn ) : element( elementIn ), weight( weightIn ) {}
		
		~Priority(){}
		
		bool operator>=( const Priority<T>& rhs ) const{
			return weight >= rhs.weight;
		}
		
		bool operator>( const Priority<T>& rhs ) const{
			return weight > rhs.weight;
		}
		
		bool operator<=( const Priority<T>& rhs ) const{
			return weight <= rhs.weight;
		}
		
		bool operator<( const Priority<T>& rhs ) const{
			return weight < rhs.weight;
		}
		
		bool operator==( const Priority<T>& rhs ) const{
			return weight == rhs.weight;
		}
		
		friend std::ostream& operator<<( std::ostream& output, const Priority<T>& thePriority ){
			
			output << "{" << thePriority.element << ", " << thePriority.weight << "}";
			
			return output;
			
		}
	
};

#endif