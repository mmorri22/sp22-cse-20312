#ifndef MSTELEM_H
#define MSTELEM_H 

struct MSTElem{
	
	unsigned int index;
	int weight;
	
	MSTElem( ) : index( ), weight( ) {}
	
	MSTElem( unsigned int indexIn, int weightIn ) : index( indexIn ), weight( weightIn ) {}
	
	bool operator>=( const MSTElem& rhs ) const{
		return weight >= rhs.weight;
	}
	
	bool operator>( const MSTElem& rhs ) const{
		return weight > rhs.weight;
	}
	
	bool operator<=( const MSTElem& rhs ) const{
		return weight <= rhs.weight;
	}
	
	bool operator<( const MSTElem& rhs ) const{
		return weight < rhs.weight;
	}
	
	bool operator==( const MSTElem& rhs ) const{
		return weight == rhs.weight;
	}

	bool operator!=( const MSTElem& rhs ) const{
		return weight != rhs.weight;
	}
	
};

#endif