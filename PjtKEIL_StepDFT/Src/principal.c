

#include "DriverJeuLaser.h"
extern int DFT_ModuleAuCarre(short *, char) ;
extern short LeSignal ;
int mod ;
int tab[64] ;
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();

mod  = DFT_ModuleAuCarre(&LeSignal, 17) ;
	
	for (int i=0; i<64; i++){
		tab[i]=DFT_ModuleAuCarre(&LeSignal, i) ;
	}
	

//============================================================================	
	
	
while	(1)
	{
	}
}

