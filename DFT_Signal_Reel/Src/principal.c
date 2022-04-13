
#include "DriverJeuLaser.h"
extern int DFT_ModuleAuCarre(short *, char) ;
extern short LeSignal ;
int mod ;
int tab[64] ;
short int dma_buf[64];
unsigned int Periode_ticks=360000 ;

void Callback_Systick(){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	
	for (int i=0; i<64 ;i++){
		tab[i]=DFT_ModuleAuCarre(dma_buf, i) ;
	}
}


int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

/*mod  = DFT_ModuleAuCarre(&LeSignal, 17) ;
	
	for (int i=0; i<64; i++){
		tab[i]=DFT_ModuleAuCarre(&LeSignal, i) ;
	}
*/
	Systick_Period_ff(Periode_ticks);
	Systick_Prio_IT(2, Callback_Systick) ;
	SysTick_On ;
	SysTick_Enable_IT ;
	Init_TimingADC_ActiveADC_ff( ADC1, 72 );
	Single_Channel_ADC( ADC1, 2 );
	Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
	Init_ADC1_DMA1( 0, dma_buf );
	

	

//============================================================================	
	
	
while	(1)
	{
	}
}

