#ifndef _INPUT_H_
#define _INPUT_H_
#include <conio.h>
#include <iostream>

enum class KeyCode
{
	BackSpace = 8,Tab
	,Clear = 12,Enter
	,Shift=16,Control,Alt
	,CapeLock=20
	,Esc=27
	,Space=32,PageUp,PageDown,End,Home,LeftArrow,UpArrow,RightArrow,DownArrow,
	
	A0=48,A1,A2,A3,A4,A5,A6,A7,A8,A9,
	
	A = 65,B, C, D,E, F, G,H, I, J,K, L, M,N
	,O, P,Q, R, S,T, U, V,W, X, Y,Z,

};

class Input
{
public:
	static Input& Instance();
	bool static GetKeyDown(KeyCode k);
};


#endif 

