#include "FoodSource.h"

FoodSource::FoodSource() : d_coords{}, d_objectifValue{ 0 }, d_fitnessValue{ 0 }, d_trial{ 0 } {}

FoodSource::FoodSource(vector<double> coords, double objectifValue, double fitnessValue, int trial) :
	d_coords{ coords }, d_objectifValue{ objectifValue }, d_fitnessValue{ fitnessValue }, d_trial{ trial }
{}


//
//	GEILLER Valentin
//
double FoodSource::getCoordAt(int i) const {
	return d_coords[i];
}


//
// MUHIRWA GABO Oreste
//
vector<double> FoodSource::getCoords() const {
	return d_coords;
}

//
//	GEILLER Valentin
//
double FoodSource::getObjectifValue() const {
	return d_objectifValue;
}

//
//	GEILLER Valentin
//
double FoodSource::getFitnessValue() const {
	return d_fitnessValue;
}

//
// GEILLER Valentin
//
int FoodSource::getTrial() const {
	return d_trial;
}

//
//	GEILLER Valentin
//
void FoodSource::setCoordAt(int i, double valeur) {
	d_coords[i] = valeur;
}

//
//	GEILLER Valentin
//
void FoodSource::setObjectifValue(double objectifValue) {
	d_objectifValue = objectifValue;
}

//
//	GEILLER Valentin
//
void FoodSource::setFitnessValue(double fitnessValue) {
	d_fitnessValue = fitnessValue;
}

//
//	GEILLER Valentin
//
void FoodSource::incrementeTrial() {
	d_trial++;
}

//
//	GEILLER Valentin
//
void FoodSource::resetTrial() {
	d_trial = 0;
}

//
// MUHIRWA GABO Oreste
//
void FoodSource::printFoodSource() const {
	std::cout << "Objectif Value : " << d_objectifValue << std::endl;
	std::cout << "Fitness Value : " << d_fitnessValue << std::endl;
}