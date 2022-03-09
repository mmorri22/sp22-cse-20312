#include "../include/Trie.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string

void checkWord( const Trie& theTrie, const STRING& theWord ){
	
	COUT << "The word " << theWord << " is";
	
	if( !theTrie.contains( theWord ) ){
		
		COUT << " not";
	}
	
	COUT << " in the Trie" << ENDL;
	
}


int main(){
	
	Trie theTrie;
	STRING BAT("BAT");
	STRING BAT_CAVE("BAT-CAVE");		STRING BAT_COMPUTER("BAT-COMPUTER");
	STRING BAT_DANCE("BAT-DANCE");		STRING BAT_DIAMOND("BAT-DIAMOND");
	STRING BAT_PHONE("BAT-PHONE");		STRING BAT_SHARK("BAT-SHARK");
	STRING BAT_SIGNAL("BAT-SIGNAL");	STRING BAT_TASER("BAT-TASER");
	STRING BAT_TRACER("BAT-TRACER");	STRING BATARANG("BATARANG");
	STRING BATGIRL("BATGIRL");			STRING BATMAN("BATMAN");
	STRING BATMOBILE("BATMOBILE");
	
	// Add Strings to the Trie
	theTrie.addString(BAT);				theTrie.addString(BAT_CAVE);
	theTrie.addString(BAT_COMPUTER);	theTrie.addString(BAT_DANCE);
	theTrie.addString(BAT_DIAMOND);		theTrie.addString(BAT_PHONE);
	theTrie.addString(BAT_SHARK);		theTrie.addString(BAT_SIGNAL);
	theTrie.addString(BAT_TASER);		theTrie.addString(BAT_TRACER);
	theTrie.addString(BATARANG);		theTrie.addString(BATGIRL);
	theTrie.addString(BATMAN);			theTrie.addString(BATMOBILE);
	
	// Print the Pre-Order Traversal
	theTrie.printTriePreOrder();
	
	// Test Contains
	checkWord(theTrie, STRING("BA") );
	checkWord(theTrie, STRING("BAT") );
	checkWord(theTrie, STRING("BATMAN") );
	checkWord(theTrie, STRING("BATMEN") );	
	checkWord(theTrie, STRING("BAT-SIGNAL") );
	checkWord(theTrie, STRING("BATGIRL") );
	checkWord(theTrie, STRING("RIDDLER") );
	checkWord(theTrie, STRING("BATMOBILE") );
	checkWord(theTrie, STRING("BAT-COMPUTER") );
	checkWord(theTrie, STRING("BAT-COMP") );
	checkWord(theTrie, STRING("JOKER") );
	checkWord(theTrie, STRING("BAT-CAVE") );
	checkWord(theTrie, STRING("BAT-CAVES") );	
	
	return 0;
}