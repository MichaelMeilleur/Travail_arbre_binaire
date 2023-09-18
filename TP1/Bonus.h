#ifndef BONUS_H__
#define BONUS_H__

#include <iostream>
#include <bitset>
#include <string>

template <class T>
class Bonus
{
public:

	int CompterBit1(unsigned int valeur); // Retourne le nombre de bit settee a 1 dans la valeur recue
	bool EstPair(unsigned int valeur); // Retourne true si la valeur re¸cue est paire , false sinon
	bool EstPuissanceDeux(unsigned int valeur); // Retourne true si la valeur re¸cue est une puissance de 2, false sinon
	unsigned int InverseBit(unsigned int valeur); // Inverse l'ordre des bit de la valeur recue et retourne le resutlat

};


#endif 

template<class T>
int Bonus<T>::CompterBit1(unsigned int valeur)
{
	int cpt = 0;
	while (valeur > 0) {
		if (valeur & 1) {
			cpt++;
		}
		valeur >>= 1;
	}
	return cpt;
}

template<class T>
bool Bonus<T>::EstPair(unsigned int valeur)
{
	if ((valeur & 1) == 0)
		return true;
	else
		return false;
}

template<class T>
bool Bonus<T>::EstPuissanceDeux(unsigned int valeur)
{
	if ((valeur & (valeur - 1)) == 0)
	{
		return true;
	}
	else if (valeur <= 0)
		return false;
	else
		return false;
}

template<class T>
unsigned int Bonus<T>::InverseBit(unsigned int valeur)
{
	std::bitset<8> bit(valeur);

	std::string chiffre = bit.to_string();
	std::string inverse = "";

	for (int i = chiffre.length() - 1; i >= 0; i--)
	{
		inverse += chiffre[i];
	}

	int inverseint = std::stoi(inverse);

	return inverseint;
}
