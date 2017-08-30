#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

CGlobale Application;


// _____________________________________________________________
int main() {
	 
    //_led1 = true;
	wait_ms(1);

    // Initialise le gestionnaire de temps
    _Global_Timer.start();

     Application.Run();
    
	 while(1) {
	 	// Ce code ne devrait jamais être atteint
		// car la  boucle infinie se trouve dans la méthode CGloble::Run()
         wait_ms(1);
	 }
}






