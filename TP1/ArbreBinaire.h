#ifndef ARBREBINAIRE_H__
#define ARBREBINAIRE_H__

#include <iostream>

template <class T>
class ArbreBinaire
{
public:
	ArbreBinaire();                         // Construit un arbre vide
	~ArbreBinaire();                        // Libere toute la memoire allouée

	void Ajouter(const T& valeur);          // Ajouter un item
	void Enlever(const T& valeur);          // Enlever un item
	bool Contient(const T& valeur) const;   // Retourne vrai si l'arbre contient l'item recherché
	int Nombre() const;                     // Retourne le nombre d'items dans l'arbre

	T Minimum() const;               // Retourne la plus petite valeur
	T Maximum() const;               // Retourne la plus grande valeur

	void AfficherCroissant() const;         // Affiche le contenu de l'arbre en ordre croissant (avec un espace entre chaque item)
	void AfficherDecroissant() const;       // Affiche le contenu de l'arbre en ordre décroissant (avec un espace entre chaque item)

private:
	struct Noeud
	{
		T valeur;

		Noeud* gauche;
		Noeud* droite;

		Noeud(const T& valeur, Noeud* gauche, Noeud* droite) : valeur(valeur), gauche(nullptr), droite(nullptr) {}
	};

	// Méthodes privées pour l'affichage.
	void AfficherCroissant(Noeud* n) const;
	void AfficherDecroissant(Noeud* n) const;

	void TrouverCle(Noeud*& n, const T& key, Noeud*& parent);
	struct ArbreBinaire<T>::Noeud* CleMinimum(Noeud* n);

	Noeud* m_debut;
	int m_count;
};

template<class T>
ArbreBinaire<T>::ArbreBinaire() : m_debut(nullptr), m_count(0)
{

}

template<class T>
ArbreBinaire<T>::~ArbreBinaire()
{
}

template<class T>
void ArbreBinaire<T>::Ajouter(const T& valeur)
{
	Noeud* n = m_debut;
	Noeud* p = nullptr;

	if (m_debut == nullptr)
	{
		Noeud* n = new Noeud(valeur, nullptr, nullptr);
		m_debut = n;
		m_count++;
	}

	while (n)
	{

		if (valeur > n->valeur)
		{
			p = n;
			n = n->droite;
		}
		else if (valeur == n->valeur)
		{
			return;
		}
		else
		{
			p = n;
			n = n->gauche;
		}
	}


	if (p != nullptr)
	{
		if (valeur > p->valeur)
		{
			p->droite = new Noeud(valeur, nullptr, nullptr);
		}
		else
		{
			p->gauche = new Noeud(valeur, nullptr, nullptr);
		}

		m_count++;
	}

}

template<class T>
void ArbreBinaire<T>::Enlever(const T& valeur)
{
	Noeud* p = nullptr;
	Noeud* n = m_debut;

	TrouverCle(n, valeur, p);

	if (n == nullptr)
		return;

	if (n->gauche == nullptr && n->droite == nullptr)
	{
		if (n != m_debut)
		{
			if (p->gauche == n)
			{
				p->gauche = nullptr;
			}
			else
			{
				p->droite = nullptr;
			}
		}
		else
		{
			m_debut = nullptr;
		}

		delete n;
		m_count--;
	}
	else if (n->droite && n->gauche)
	{
		Noeud* s = CleMinimum(n->gauche);

		T val = s->valeur;

		Enlever(s->valeur);

		n->valeur = val;
	}
	else
	{
		Noeud* enfant;

		if (n->gauche)
			enfant = n->gauche;
		else
			enfant = n->droite;

		if (n != m_debut)
		{
			if (n == p->gauche) {
				p->gauche = enfant;
			}
			else {
				p->droite = enfant;
			}
		}
		else {
			m_debut = enfant;
		}

		delete n;
		m_count--;
	}
}

template<class T>
bool ArbreBinaire<T>::Contient(const T& valeur) const
{
	Noeud* n = m_debut;

	while (n)
	{
		if (n->valeur == valeur)
			return true;
		else
		{
			if (valeur > n->valeur)
				n = n->droite;
			else
				n = n->gauche;
		}
	}
	return false;
}

template<class T>
int ArbreBinaire<T>::Nombre() const
{
	return m_count;
}

template<class T>
T ArbreBinaire<T>::Minimum() const
{
	Noeud* n = m_debut;
	Noeud* p = nullptr;

	if (!n)
		return T();

	if (m_debut != nullptr)
	{

		while (n)
		{
			p = n;
			n = n->gauche;
		}

		if (p != nullptr)
		{
			return p->valeur;
		}
	}
}

template<class T>
T ArbreBinaire<T>::Maximum() const
{
	Noeud* n = m_debut;
	Noeud* p = nullptr;

	if (!n)
		return T();

	if (m_debut != nullptr)
	{

		while (n)
		{
			p = n;
			n = n->droite;
		}

		if (p != nullptr)
			return p->valeur;
	}
}

template<class T>
void ArbreBinaire<T>::AfficherCroissant() const
{
	AfficherCroissant(m_debut);
	std::cout << std::endl;
}

template<class T>
void ArbreBinaire<T>::AfficherCroissant(Noeud* n) const
{

	if (!n)
		return;

	AfficherCroissant(n->gauche);
	std::cout << n->valeur << " ";
	AfficherCroissant(n->droite);

}

template<class T>
void ArbreBinaire<T>::AfficherDecroissant() const
{
	AfficherDecroissant(m_debut);
	std::cout << std::endl;
}
template<class T>
void ArbreBinaire<T>::AfficherDecroissant(Noeud* n) const
{
	if (!n)
		return;

	AfficherDecroissant(n->droite);
	std::cout << n->valeur << " ";
	AfficherDecroissant(n->gauche);
}

template<class T>
void ArbreBinaire<T>::TrouverCle(Noeud*& n, const T& key, Noeud*& parent)
{

	while (n != nullptr && n->valeur != key)
	{
		parent = n;

		if (key < n->valeur) {
			n = n->gauche;
		}
		else {
			n = n->droite;
		}
	}
}

template<class T>
struct ArbreBinaire<T>::Noeud* ArbreBinaire<T>::CleMinimum(Noeud* n)
{

	while (n->gauche != nullptr)
	{
		n = n->gauche;
	}
	return n;
}

#endif 