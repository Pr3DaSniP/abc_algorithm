#define _USE_MATH_DEFINES
#include "OptUHA.h"
#include <cmath>

//
//	à modifier pour les benchmarks
//
double OptUHA::fct_obj(vector<double>& coords) const {
	return Griewank(coords);
}

//
// GEILLER Valentin
//
vector<FoodSource> OptUHA::GenerateRandomPop() {
    vector<FoodSource> pop;
    for (int i = 0; i < pop_size; ++i) {
        FoodSource FS = create_new_individual();
        pop.push_back(FS);
    }
	return pop;
}

//
// MUHIRWA GABO Oreste
//
double OptUHA::generate_random_double()
{
    return rand() * 1.0 / RAND_MAX;
}

//
// MUHIRWA GABO Oreste
//
double OptUHA::generate_random_double(double lower, double upper) {
	return lower + rand() / (RAND_MAX / (upper - lower));
}


//
//	GEILLER Valentin
//
int OptUHA::generate_random_int(int from, int to)
{
    return rand() % (to - from) + from;
}

//
//	GEILLER Valentin
//
double OptUHA::newCoords(double X, double XPartner) {
	double phi = generate_random_double(-1, 1);
	double Xnew = X + phi * (X - XPartner);
	return Xnew;
}

//
// MUHIRWA GABO Oreste & GEILLER Valentin
//
double OptUHA::Sphere(const vector<double>& S) const {
	double somme = 0;
	int bias = -450;
	for (int i = 0; i < S.size(); ++i) {
		somme = somme + (S[i] * S[i]);
	}
	return somme + bias;
}

//
// MUHIRWA GABO Oreste & GEILLER Valentin
//
double OptUHA::Rosenbrock(const vector<double>& S) const {
	int bias = 390;
	double somme = 0;

	for (int i = 0; i < S.size() - 1; ++i) {
		somme = somme + 100 * pow((S[i + 1] - pow((S[i]), 2.0)), 2.0) + pow((S[i] - 1), 2.0);
	}

	return somme + bias;
}

//
// MUHIRWA GABO Oreste & GEILLER Valentin
//
double OptUHA::Rastrigin(const vector<double>& S) const {
	int bias = -330;
	double somme = 0;

	for (int i = 0; i < S.size(); ++i) {
		somme = somme + (pow(S[i], 2.0) - 10 * cos(2 * M_PI * S[i]) + 10);
	}

	return somme + bias;
}

//
// MUHIRWA GABO Oreste & GEILLER Valentin
//
double OptUHA::Griewank(const vector<double>& S) const {
	int bias = -180;
	double sommeTotal = 0, Somme = 0, Produit = 1;

	for (int i = 0; i < S.size(); ++i) {
		Somme = Somme + pow((S[i]), 2.0);
		Produit = Produit * cos((((S[i]) / sqrt(static_cast<double>(i + 1))) * M_PI) / 180);

	}
	sommeTotal = (1 / 4000.0) * Somme - Produit + 1;

	return sommeTotal + bias;
}

//
// GEILLER Valentin
//
double OptUHA::fitness(double objectifValue) const {
	if (objectifValue >= 0)
		return 1 / (1 + objectifValue);
	else
		return 1 + abs(objectifValue);
}

//
// MUHIRWA GABO Oreste
//
FoodSource OptUHA::create_new_individual()
{
    vector<double> coords;
    for (int i = 0; i < dimension; ++i) {
		coords.push_back(
			generate_random_double(LOWER_LIMIT, UPPER_LIMIT)
        );
    }
    double objValue = fct_obj(coords);
	double fitnessValue = fitness(objValue);

	return { coords, objValue, fitnessValue };
}

//
// MUHIRWA GABO Oreste
//
void OptUHA::print_solution(const FoodSource& FS) const {
	for (int i = 0; i < dimension; ++i) {
		cout << "X" << i << " : " << FS.getCoordAt(i) << " , ";
	}
	cout << "Objectif Value : " << FS.getObjectifValue() << endl;
	cout << "Fitness Value : " << FS.getFitnessValue() << endl;
}

//
//	GEILLER Valentin
//
void OptUHA::verifLimit(double& Xnew) {
	if (Xnew >= UPPER_LIMIT) {
		Xnew = UPPER_LIMIT;
	}
	else if (Xnew <= LOWER_LIMIT) {
		Xnew = LOWER_LIMIT;
	}
}

//
//	GEILLER Valentin
//
bool OptUHA::greedySelection(double oldFit, double newFit) {
	return oldFit > newFit ? false : true;
}