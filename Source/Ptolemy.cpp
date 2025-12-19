#include "stdafx.h"

#include "Ptolemy.h"
#include <iostream>
#include <cmath>

#define RADIUS 6371.0 // Rayon de la Terre en km
#define M_PI       3.14159265358979323846

double ptolomee::ptolomee_distance(double lat1, double lon1, double lat2, double lon2) {
    // Conversion des coordonnées en radians
    double lat1_rad = lat1 * M_PI / 180.0;
    double lon1_rad = lon1 * M_PI / 180.0;
    double lat2_rad = lat2 * M_PI / 180.0;
    double lon2_rad = lon2 * M_PI / 180.0;

    // Calcul des différences de longitude et de latitude
    double dlon = std::abs(lon2_rad - lon1_rad);
    double dlat = std::abs(lat2_rad - lat1_rad);

    // Calcul des termes de la formule de Ptolémée
    double term1 = std::cos(lat2_rad) * std::sin(dlon);
    double term2 = std::cos(lat1_rad) * std::sin(lat2_rad) - std::sin(lat1_rad) * std::cos(lat2_rad) * std::cos(dlon);
    double term3 = std::sin(lat1_rad) * std::sin(lat2_rad) + std::cos(lat1_rad) * std::cos(lat2_rad) * std::cos(dlon);

    // Calcul de la distance en kilomètres
    double distance = RADIUS * std::atan2(std::sqrt(term1 * term1 + term2 * term2), term3);

    return distance;
}

#include <cmath>

//// Fonction pour convertir degrés en radians
//double deg2rad(double deg) {
//    return deg * (M_PI / 180.0);
//}
//
//// Fonction pour calculer la distance de Ptolémée entre deux points en latitude/longitude
//double haversine(double lat1, double lon1, double lat2, double lon2) {
//    // Rayon de la Terre en kilomètres
//    constexpr double radius = 6371.0;
//
//    // Conversion des degrés en radians
//    lat1 = deg2rad(lat1);
//    lon1 = deg2rad(lon1);
//    lat2 = deg2rad(lat2);
//    lon2 = deg2rad(lon2);
//
//    // Calcul des différences de latitude et longitude
//    double dlat = lat2 - lat1;
//    double dlon = lon2 - lon1;
//
//    // Calcul de la formule haversine
//    double a = std::sin(dlat / 2) * std::sin(dlat / 2) +
//        std::cos(lat1) * std::cos(lat2) *
//        std::sin(dlon / 2) * std::sin(dlon / 2);
//    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
//
//    // Distance en kilomètres
//    double distance = radius * c;
//
//    return distance;
//}


//int ptolomee_main() {
//    double lat1 = 48.8584; // Latitude de Paris
//    double lon1 = 2.2945; // Longitude de Paris
//    double lat2 = 51.5072; // Latitude de Londres
//    double lon2 = -0.1276; // Longitude de Londres
//
//    double distance = ptolomee::ptolomee_distance(lat1, lon1, lat2, lon2);
//
//    std::cout << "Distance entre Paris et Londres: " << distance << " km" << std::endl;
//
//    return 0;
//}

