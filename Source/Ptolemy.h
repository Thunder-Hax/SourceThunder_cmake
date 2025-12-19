#pragma once
namespace ptolomee
{
	extern double ptolomee_distance(double lat1, double lon1, double lat2, double lon2);
	//extern int ptolomee_main();
}

//#include <iostream>
//#include <string> // Pour std::string
//
//// Classe ou fonction Log avec une méthode statique Msg
//class Log {
//public:
//    static void Msg(const char* msg) {
//        std::cout << msg << std::endl;
//    }
//};
//
//class MaClasse {
//public:
//    void maFonction() {
//        Log::Msg("Fonction membre de MaClasse");
//    }
//};
//
//int main() {
//    // Création d'un objet de la classe MaClasse
//    MaClasse obj;
//
//    // Déclaration d'un pointeur de fonction membre de MaClasse
//    void (MaClasse:: * ptr)() = &MaClasse::maFonction;
//
//    // Obtention de l'adresse de la fonction membre et affichage
//    void* addr = *(void**)(&ptr);
//    // Convertir l'adresse en chaîne de caractères
//    std::string addrStr = "Adresse de maFonction : " + std::to_string(reinterpret_cast<std::uintptr_t>(addr));
//
//    // Utilisation de c_str() pour convertir std::string en const char*
//    Log::Msg(addrStr.c_str());
//
//    // Appel de la fonction membre à travers le pointeur
//    (obj.*ptr)(); // Appelle obj.maFonction()
//
//    return 0;
//}
