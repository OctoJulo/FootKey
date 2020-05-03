//////////////////////////////////////////////////////////////////////
// **************************************************************** //
// ***************************** Projet *************************** //
// **************************************************************** //
//////////////////////////////////////////////////////////////////////
/*                     description             */
/*                    description             */
/* **************************************************************** */
/*  Version: 0.1        ---       Date: 00/00/0000  */  
/*  OctoGeeK          ---           OctoJulo  */
/* **************************************************************** */
/*  REQUIS:   - teensy LC                     */
/*        - une matrice de bp 2*4               */
/* **************************************************************** */
//////////////////////////////////////////////////////////////////////
// **************************************************************** //
// ************************* Bibliothèque ************************* //
// **************************************************************** //
//////////////////////////////////////////////////////////////////////
#include <Keypad.h>

//////////////////////////////////////////////////////////////////////
// **************************************************************** //
// ********** Constantes, Variables, Fonctions Internes *********** //
// **************************************************************** //
//////////////////////////////////////////////////////////////////////
const byte ROWS = 2; // rows
const byte COLS = 4; // columns

char keys[ROWS][COLS] = {
	{KEY_ESC,KEY_A,KEY_E,KEY_PAGE_DOWN},
	{KEY_LEFT_SHIFT,KEY_TAB,KEY_SPACE,KEY_ENTER}  
};

byte rowPins[ROWS] = {7,8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9,10,11,12}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


//////////////////////////////////////////////////////////////////////
// **************************************************************** //
// *********************** Progamme Principal ********************* //
// **************************************************************** //
//////////////////////////////////////////////////////////////////////
void setup()
{

} 
//////////////////////////////////////////////////////////////////////
// **************************************************************** //
// ************************* Progamme Boucle ********************** //
// **************************************************************** //
//////////////////////////////////////////////////////////////////////
void loop()
{
	if (kpd.getKeys())
	{
		for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
		{
			if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
			{
				switch (kpd.key[i].kstate) 
				{
					case PRESSED:
						Keyboard.set_key1(kpd.key[i].kchar);
						Keyboard.send_now();
						if (kpd.key[i].kchar == char(KEY_LEFT_SHIFT)) 
						{
							Keyboard.set_modifier(MODIFIERKEY_SHIFT);
							Keyboard.send_now();
						}
						break;
					case HOLD:
						Keyboard.set_key1(kpd.key[i].kchar);
						Keyboard.send_now();
						break;
					case RELEASED:
						Keyboard.set_key1(0);
						Keyboard.send_now();
						if (kpd.key[i].kchar == char(KEY_LEFT_SHIFT)) 
						{
							Keyboard.set_modifier(0);
							Keyboard.send_now();
						}
						break;
				} 
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////
// **************************************************************** //
//////////////////////////////////////////////////////////////////////