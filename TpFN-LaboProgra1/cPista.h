#ifndef CPISTA_H
#define CPISTA_H
#include "gbl.h"
#include "cAvion.h"

class cPista
{
public:

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_largo">: Largo admitido por la pista (en km)</param>
	/// <param name="_ancho">: Ancho admitido por la pista (en km)</param>
	cPista(float _largo = MAX_PISTA, float _ancho = MAX_PISTA);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cPista();

	/// <summary>
	/// Checkeo si el avion puede aterrizar
	/// </summary>
	/// <param name="avion">Avion que intenta aterrizar</param>
	/// <returns>True en caso de poder aterrizar, false en caso contrario</returns>
	bool operator==(cAvion* avion);

	/// <summary>
	/// Cambia el estado de libre a ocupado e ingresa el avion al hangar
	/// </summary>
	/// <param name="avion"></param>
	void operator=(cAvion* avion);

	/// <summary>
	/// Debido a la velocidad inicial, y aceleracion del avion este metodo utiliza MRUV 
	/// para calcular el tiempo que tardara en aterrizar el avion y luego su posicion final
	/// </summary>
	/// <param name="avion">: Avion a obtener su posicion final</param>
	/// <returns>Posicion final del avion</returns>	
	float getPosicionFinal(cAvion* avion);
	
	bool getLuO() const;
	
	void switchLuO();
	
private:
	
	/// <summary>
	/// Convierte la velocidad en km/h a m/s
	/// </summary>
	/// <param name="avion">: Avion a calcular su velocidad</param>
	/// <returns></returns>
	float conversor(cAvion* avion) const;
	
	/// <summary>
	/// Obtiene el tiempo ideal en el que deberia aterrizar el avion
	/// </summary>
	/// <param name="avion">: Avion a obtener su tiempo en aterrizar</param>
	/// <returns>Tiempo que tardara el avion en aterrizar (idealmente)</returns>
	float getTiempoIdeal(cAvion* avion) const;

	const float largo;
	const float ancho;	
	bool LuO; // Libre u Ocupado
	
};

inline float cPista::conversor(cAvion* avion) const { return (avion->getVelocidad() * 0.277778); }

inline float cPista::getTiempoIdeal(cAvion* avion) const { return this->conversor(avion) / avion->getAceleracion(); }

inline bool cPista::getLuO()const {return this->LuO;}

inline void cPista::switchLuO() { if (this->LuO == true) { this->LuO = false; } else { this->LuO = true; } }

inline void cPista::operator=(cAvion* avion) { switchLuO(); }

#endif // !CPISTA_H