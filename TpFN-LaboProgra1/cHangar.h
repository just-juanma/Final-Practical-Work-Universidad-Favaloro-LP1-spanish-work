#ifndef CHANGAR_H
#define CHANGAR_H
#include "gbl.h"
#include "cListaAvion.h"

class cHangar
{
public:
	
	cHangar(short _cantTotal);
	~cHangar(); 
	void Almacenar(cAvion* avion); 
	cAvion* Despachar(short pos);
	int buscarAvion(string ID);
	int getCantActual();
	bool operator==(cAvion* avion);
	
private: 
	
	cListaAvion* almacenados;
	
};

#endif // !CHANGAR_H