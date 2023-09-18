#include <iostream>
#include <string>
#include <bitset>
#include "ArbreBinaire.h"
#include "Bonus.h"

int main()
{
	ArbreBinaire<int> liste1;
	ArbreBinaire<std::string> liste2;


	// Tests avec int
	liste1.Ajouter(3);
	liste1.Ajouter(3);
	liste1.Ajouter(6);
	liste1.Ajouter(1);
	liste1.Ajouter(1);
	liste1.Ajouter(9);
	liste1.Ajouter(11);
	liste1.Ajouter(15);
	liste1.Ajouter(15);
	liste1.AfficherCroissant();
	liste1.AfficherDecroissant();
	std::cout << "Max: " << liste1.Maximum() << std::endl;
	std::cout << "Min: " << liste1.Minimum() << std::endl;
	std::cout << "Nombre: " << liste1.Nombre() << std::endl;
	liste1.Enlever(3);
	liste1.Enlever(9);
	liste1.Enlever(6);
	liste1.Enlever(15);
	liste1.AfficherCroissant();
	liste1.AfficherDecroissant();
	std::cout << "Max: " << liste1.Maximum() << std::endl;
	std::cout << "Min: " << liste1.Minimum() << std::endl;
	std::cout << "Nombre: " << liste1.Nombre() << std::endl;

	std::cout << "" << std::endl;

	// Tests avec string
	liste2.Ajouter("alpha");
	liste2.Ajouter("charlie");
	liste2.Ajouter("bravo");
	liste2.AfficherCroissant();
	liste2.AfficherDecroissant();
	std::cout << "Max: " << liste2.Maximum() << std::endl;
	std::cout << "Min: " << liste2.Minimum() << std::endl;
	std::cout << "Nombre: " << liste2.Nombre() << std::endl;
	liste2.Enlever("charlie");
	liste2.AfficherCroissant();
	liste2.AfficherDecroissant();
	std::cout << "Max: " << liste2.Maximum() << std::endl;
	std::cout << "Min: " << liste2.Minimum() << std::endl;
	std::cout << "Nombre: " << liste2.Nombre() << std::endl;


	std::cout << "" << std::endl;

	// Tests de la section bonus
	std::cout << "Tests de la section bonus:" << std::endl;

	Bonus<int> bonus;
	int cpt;
	int bitOriginal;
	int bitInverse;
	bool reponse;

	std::cout << "" << std::endl;
	std::cout << "Tests de la methode ComperBit1" << std::endl;
	cpt = bonus.CompterBit1(255);
	std::cout << cpt << std::endl;
	cpt = bonus.CompterBit1(7);
	std::cout << cpt << std::endl;
	cpt = bonus.CompterBit1(1063);
	std::cout << cpt << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Tests de la methode EstPair" << std::endl;
	reponse = bonus.EstPair(4);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPair(5);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPair(27);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPair(48);
	std::cout << reponse << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Tests de la methode EstPuissanceDeux" << std::endl;
	reponse = bonus.EstPuissanceDeux(16);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPuissanceDeux(10);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPuissanceDeux(1024);
	std::cout << reponse << std::endl;
	reponse = bonus.EstPuissanceDeux(244);
	std::cout << reponse << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Tests de la methode InverseBit" << std::endl;
	bitOriginal = 123;
	std::bitset<8> x(bitOriginal);
	std::cout << "Original: " << x << std::endl;
	bitInverse = bonus.InverseBit(bitOriginal);
	std::cout << "Inverse:  " << bitInverse << std::endl;
	bitOriginal = 7;
	std::bitset<8> x2(bitOriginal);
	std::cout << "Original: " << x2 << std::endl;
	bitInverse = bonus.InverseBit(bitOriginal);
	std::cout << "Inverse:  " << bitInverse << std::endl;
	bitOriginal = 97;
	std::bitset<8> x3(bitOriginal);
	std::cout << "Original: " << x3 << std::endl;
	bitInverse = bonus.InverseBit(bitOriginal);
	std::cout << "Inverse:  " << bitInverse << std::endl;

}