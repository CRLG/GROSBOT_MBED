#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

CGlobale Application;
  



// _____________________________________________________________
int main() {
	 
    //_led1 = 1;

     Application.Run();
    
	 while(1) {
	 	// Ce code ne devrait jamais être atteint
		// car la  boucle infinie se trouve dans la méthode CGloble::Run()
	 }    
}





