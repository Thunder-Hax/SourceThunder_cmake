#pragma once
#include "nlohmann/json.hpp"

#include "reclass\GTAV-Classes\script\scrThreadContext.hpp"
#include "reclass\GTAV-Classes\script\scriptHandlerNetComponent.hpp"

#include <chrono>

namespace Features {
	extern bool NeverWantedAllbool;
	extern int NeverWantedAll();
	extern float LaserHeight;
	extern float LaserWidth;
	extern float LaserEyesX;
	extern float LaserEyesY;
	extern std::string LaserEyesString;
	extern bool LaserEyesBool;
	extern void LaserEyes(bool toggle);

	extern bool LoadLocationID;
	extern int cocainetimer;
	/*extern bool Stealthcash;
	void stealthCash(bool toggle);*/

	extern bool forceog;
	extern void force(bool toggle);

	extern bool activebool[32];
	/*extern bool clearlevel;*/
	extern bool AirStrike;
	extern void AirStrike1(bool toggle);

	extern bool AirStrike2;
	extern void AirStrike22(bool toggle);

	//extern bool blackoutbool;
	//void blackout(bool toggle);

	extern bool Gravity;
	extern void GravityGun(bool toggle);

	extern bool Orbital;
	extern void Orbi(bool toggle);

	extern bool Drift;
	extern void DriftMode(bool toggle);

	extern bool alwaysdrift;
	extern void driftalways(bool toggle);

	extern int espint1;
	extern int espint2;
	extern int espint3;
	extern int espint4;

	extern int espintsha1;
	extern int espintsha2;
	extern int espintsha3;
	extern int espintsha4;
	extern int espintsha5;

	extern float nameespsize;
	extern bool NameESP;
	extern void NameTagESP(bool toggle);

	extern bool Superr;
	extern void SuperDooper(bool toggle);

	extern bool ForceField2;
	extern void ForceField22(bool toggle);

	extern bool AIRSTRIKER;
	extern void AIRSTRIKER2(bool toggle);

	extern bool AIRSTRIKER22;
	extern void AIRSTRIKER222(bool toggle);

	extern bool UltraJ;
	extern void UltraJumpp(bool toggle);

	extern bool ShootWeaponT;
	extern void ShootWeaponTank(bool toggle);

	extern bool allped;
	extern void allpeds(bool toggle);

	extern bool allped2;
	extern void allpeds2(bool toggle);

	extern bool allped3;
	extern void allpeds4(bool toggle);

	extern bool object2;
	extern void objects2(bool toggle);
	extern bool object3;
	extern void objects3(bool toggle);

	extern bool moneygun;
	extern void moneyguns(bool toggle);
	//extern bool moneyguninf;
	//void moneygunsinf(bool toggle);
	extern bool moneygunweed;
	extern void moneygunsweeds(bool toggle);
	extern bool moneygunegg;
	extern void moneygunseggs(bool toggle);
	extern bool moneygunm;
	extern void moneygunsm(bool toggle);

	extern bool pickupweapon;
	extern void pickupweapons(bool toggle);
	extern bool pickupweapon2;
	extern void pickupweapons2(bool toggle);

	extern bool pickuplayer;
	extern void pickuplayers(bool toggle);

	extern bool pickupvehicle;
	extern void pickupvehicles(bool toggle);

	extern int objects222;

	extern bool allobject;
	extern void allobjects(bool toggle);

	extern bool allanimal;
	extern void allanimals(bool toggle);

	extern bool alllastped;
	extern void alllastpeds(bool toggle);

	extern bool allcar;
	extern void allcars(bool toggle);

	extern bool afterhourss;
	extern void afterhoursss(bool toggle);

	extern bool souternsan;
	extern void souternsans(bool toggle);

	extern bool doomsday;
	extern void doomsdays(bool toggle);

	extern bool smuglersrun;
	extern void smuglersrunn(bool toggle);

	extern bool gunrunning;
	extern void gunrunningg(bool toggle);

	extern bool cunningstunt;
	extern void cunningstuntt(bool toggle);

	extern bool importexport;
	extern void importexportt(bool toggle);

	extern bool boat;
	extern void boats(bool toggle);

	extern bool commercial;
	extern void commercials(bool toggle);

	extern bool compact;
	extern void compacts(bool toggle);

	extern bool coupe;
	extern void coupes(bool toggle);

	extern bool cycle;
	extern void cycles(bool toggle);

	extern bool emergency;
	extern void emergencies(bool toggle);

	extern bool plane;
	extern void planes(bool toggle);

	extern bool chopper;
	extern void choppers(bool toggle);

	extern bool motorcycle;
	extern void motorcycles(bool toggle);

	extern bool super;
	extern void supers(bool toggle);

	extern bool sport;
	extern void sports(bool toggle);

	extern bool offroad;
	extern void offroads(bool toggle);

	extern bool sportsclassic;
	extern void sportsclassics(bool toggle);

	extern bool suv;
	extern void suvs(bool toggle);

	extern bool sedan;
	extern void sedans(bool toggle);

	extern bool muscle;
	extern void muscles(bool toggle);

	extern bool van;
	extern void vans(bool toggle);

	extern bool military;
	extern void militaries(bool toggle);

	extern bool utility;
	extern void utilities(bool toggle);

	extern bool train;
	extern void trains(bool toggle);

	extern bool service;
	extern void services(bool toggle);

	extern bool industrial;
	extern void industrials(bool toggle);

	extern bool trailer;
	extern void trailers(bool toggle);

	extern bool ShootWeaponxTstrikeforce;
	extern void ShootWeaponstrikeforce(bool toggle);

	extern bool ShootWeaponxTblimp;
	extern void ShootWeaponxThank(bool toggle);

	extern bool ShootDump;
	extern void ShootDumpTruck(bool toggle);

	extern bool ShootHydra;
	extern void Shootthehydra(bool toggle);

	extern bool ShootBuz;
	extern void ShootBuzzard(bool toggle);

	extern bool para;
	extern void paranormal(bool toggle);

	extern bool Seat;
	extern void SeatBelt(bool toggle);

	extern bool Rainb;
	extern void Rainbow(bool toggle);

	extern bool rlbool;
	extern void HasPaintLoop(bool toggle);
	extern bool rlbool2;
	extern void HasPaintLoop2(bool toggle);

	extern bool rlbool3;
	extern void HasPaintLoop3(bool toggle);

	extern bool toBank1;
	extern void StealthDropintee1(bool toggle);
	extern bool toBank2;
	extern void StealthDropintee2(bool toggle);
	extern bool toBank3;
	extern void StealthDropintee3(bool toggle);
	extern bool toBank4;
	extern void StealthDropintee4(bool toggle);
	extern bool toBank5;
	extern void StealthDropintee5(bool toggle);
	extern bool toBank6;
	extern void StealthDropintee6(bool toggle);
	extern bool toBank7;
	extern void StealthDropintee7(bool toggle);
	extern bool toBank8;
	extern void StealthDropintee8(bool toggle);
	extern bool toBank9;
	extern void StealthDropintee9(bool toggle);
	extern bool toBank15;
	void StealthDropintee15(bool toggle);

	extern bool toBank1w;
	extern void StealthDropintee1w(bool toggle);
	extern bool toBank2w;
	extern void StealthDropintee2w(bool toggle);
	extern bool toBank3w;
	extern void StealthDropintee3w(bool toggle);
	extern bool toBank4w;
	extern void StealthDropintee4w(bool toggle);
	extern bool toBank5w;
	extern void StealthDropintee5w(bool toggle);
	extern bool toBank6w;
	extern void StealthDropintee6w(bool toggle);
	extern bool toBank7w;
	extern void StealthDropintee7w(bool toggle);
	extern bool toBank8w;
	extern void StealthDropintee8w(bool toggle);
	extern bool toBank9w;
	extern void StealthDropintee9w(bool toggle);
	extern bool toBank15;
	//void StealthDropintee15();
	extern bool toBankw15;
	extern void StealthDropinteew(bool toggle);
	extern void StealthDropinteew15(bool toggle);
	extern bool AsteroidShowerToggle;
	extern void AsteroidShower(bool toggle);
	extern bool AsteroidShowerToggleclear;
	extern void AsteroidShowerclear(bool toggle);
	extern bool AsteroidShowerToggleClearing;
	extern void AsteroidShowerClearing(bool toggle);
	extern bool AsteroidShowerToggleRain;
	extern void AsteroidShowerRain(bool toggle);
	extern bool AsteroidShowerToggleSnow;
	extern void AsteroidShowerSnow(bool toggle);
	extern bool AsteroidShowerToggleSnowlight;
	extern void AsteroidShowerSnowlight(bool toggle);
	extern bool AsteroidShowerToggleNeutral;
	extern void AsteroidShowerNeutral(bool toggle);
	extern bool AsteroidShowerToggleBlizzard;
	extern void AsteroidShowerBlizzard(bool toggle);
	extern bool AsteroidShowerToggleOvercast;
	extern void AsteroidShowerOvercast(bool toggle);
	extern bool AsteroidShowerToggleFoggy;
	extern void AsteroidShowerFoggy(bool toggle);
	extern bool AsteroidShowerToggleSmog;
	extern void AsteroidShowerSmog(bool toggle);
	extern bool AsteroidShowerToggleClouds;
	extern void AsteroidShowerClouds(bool toggle);
	extern bool AsteroidShowerTogglehalloween;
	extern void AsteroidShowerhalloween(bool toggle);
	extern bool AsteroidShowerToggleXmas;
	extern void AsteroidShowerXmas(bool toggle);

	/*extern bool Crash;*/
	extern void crash(Player selectedPed);
	extern void crashall(Player selectedPed);

	/*extern bool anticrashplayer;
	extern void anticrash(bool toggle);*/

	extern bool freecam;
	extern void freecams(bool toggle);

	extern bool Rneon;
	extern void RainbowNeon(bool toggle);

	extern DWORD WeapVehShootLastTime;

	extern bool ShootR;
	extern void ShootRocket(bool toggle);
	extern bool DisplayFPS;
	extern void featureDisplayFPS(bool toggle);
	extern bool phonedisable;
	extern void disablephone();

	extern bool timesenable;
	extern void enabletimes();

	extern float xzerovingt;
	extern float yzerodix;

	extern bool MobileRadio;
	extern void Radio();

	extern bool hidehud;
	extern void hide();
	extern bool disabled;
	extern void transaction();
	extern bool TeleportGun;
	extern void featureTeleportGun(bool toggle);

	extern bool dirtyloop;
	extern void dirty(bool toggle);

	extern float torquefloat;
	extern bool torqueloop;
	extern void tor(bool toggle);

	extern float powerfloat;
	extern bool powerloop;
	extern void power(bool toggle);

	extern bool ShootT;
	extern void ShootTanks(bool toggle);

	extern bool ShootTankR;
	extern void ShootTankRounds(bool toggle);

	extern bool ShootBall;
	extern void ShootBalls(bool toggle);


	extern bool ShootMini;
	extern void ShootMiniGun(bool toggle);


	extern void UpdateLoop();

	//void TPtoWaypoint();
	extern void riskyOptins(bool toggle);


	//Ped getLocalPlayerPed();

	extern int Levels[8000];

	extern void PlaceObjectByHash(Hash hash, float xa, float ya, float za, float pitcha, float rolla, float yawa, float headinga, int ida);
	extern void PlaceObjectByHashball(Hash hash, float xa, float ya, float za, float pitcha, float rolla, float yawa, float headinga, int ida);
	void Freezer(Player target);
	extern bool freezed[32];

	extern bool expmeel;
	extern bool fireammo;
	extern bool expammo;
	extern bool expammo2;
	extern bool rbgun;

	extern float centvingt;
	extern float zeroundeuxtrois;
	extern float zerotroiscentsoixantequinze;

	/*void anti(bool toggle);
	void anti1(bool toggle);
	void anti2(bool toggle);
	void anti3(bool toggle);
	void anti4(bool toggle);
	void anti5(bool toggle);
	void anti00(bool toggle);*/

	//void spawn_vehicle(char* toSpawn);
	//void spawn_vehicle2(char* toSpawn, Vector3 ourCoords);
	extern float weaponsdamagefloat;
	extern bool weaponsdamage;
	extern void weaponsdamage1(bool toggle);

	extern bool vehicledamage;
	extern void vehicledamage1(bool toggle);

	extern bool meleedamage;
	extern void meleedamage1(bool toggle);
	extern bool Forcefield;
	//void Expmeels(bool toggle);
	extern void Fireammos(bool toggle);
	extern void Expammos(bool toggle);
	extern void Expammos2(bool toggle);
	extern void RBGuner(bool toggle);

	extern int number;
	extern int Dirt;
	extern int carsdelay;
	extern int moneyLevel;
	extern int moneyLevelx;
	extern int moneyLevely;
	extern int LIGHTNINGTHUNDERLevel;
	extern float WaterLEVEL;
	extern float RAINFXINTENSITY;

	extern float vehicledamagefloat;
	extern float meleefloat;
	extern bool LIGHTNINGTHUNDER;
	extern void LIGHTNINGTHUNDER1(bool toggle);

	extern bool RAINFXINTENSITY2;
	extern void RAINFXINTENSITY1(bool toggle);

	extern bool WaterLEVEL2;
	extern void WaterLEVEL3(bool toggle);

	//void tester(int i);

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	//void setName(char * name);

	extern bool cstrcmp(const char* s1, const char* s2);

	extern bool antiafk;
	extern void awayfromkeyboard(bool toggle);
	extern bool antiinfiniteload;
	extern void antiinfiniteloads(bool toggle);
	extern bool CeoKick5;
	extern void CeoKicks5(bool toggle);
	extern bool antimission;
	extern void antimissions(bool toggle);
	extern bool antispkick;
	extern void antispkicks(bool toggle);
	extern bool ceoban1;
	extern void ceobans1(bool toggle);

	extern bool norecoilbool;
	extern void norecoilvoid(bool toggle);

	extern bool headlightbool;
	extern void headlightvoid(bool toggle);

	extern int neverwantedint;
	extern bool Neverwanted;
	extern void NeverGetWanted(bool toggle);

	extern bool Neverwanted2;
	extern void NeverGetWanted2(Player target);

	/*extern bool mkrocket;
	extern void mkrocketbool(bool toggle);*/

	//extern bool Invisible;
	//void Invisibilities(bool toggle);

	void RequestControlOfid(DWORD netid);

	extern bool rainbowmenu;
	extern void Rainbowmenu(bool toggle);

	extern bool RPLoop;
	extern int RPLoopDelay;
	extern void rpLoop();

	extern bool AutoClear;
	extern void ClearReports();
	extern int ClearReport();
	extern int notifies();


	extern bool fastrun;
	extern void RunFast(bool toggle);
	extern bool fastswim;
	extern void SwimFast(bool toggle);

	extern bool osk;
	extern bool superman;
	extern void OSKR(bool toggle);
	extern void Superman(bool toggle);
	extern bool SonicRun;
	extern void RunSonic(bool toggle);

	extern void SetRank(int rpvalue);
	extern int setlevel;
	extern bool shootcash;
	extern bool AttachDetach[32];
	//void AttachToPlayer(int me, int cli);
	/*extern bool playerbunker;
	void bunker(bool toggle);*/

	extern bool playerGodModecheck;
	extern bool playerGodMode;
	extern void GodMode(bool toggle);

	//	extern bool lowriderbool;
	//	void lowrider(bool toggle);
	extern int playerjumpint;
	extern bool playersuperjump;
	extern void SuperJump(bool toggle);
	extern bool superjumpBeast;
	extern void BeastSuperJump(bool toggle);
	extern bool playersuperjumpUltra;
	extern void SuperJumpUltra(bool toggle);

	extern bool pedhornboostbool;
	extern void pedhornboost();
	extern bool hornhavocbool;
	extern void hornhavoc();
	extern bool rainbowcarbool;
	extern void rainbowcar();
	//extern bool whotalkbool;
	//void whotalk();

	extern bool SpawnEnemy;
	extern void EnemySpawn(bool toggle);

	extern bool SpawnBody;
	extern void BodySpawn(bool toggle);

	extern bool boolbody;
	extern void bodybool(bool toggle);

	extern bool playerinvisibility;
	extern void Invisibility(bool toggle);

	extern bool playertenkped;
	extern void TenKPedMoney(bool toggle);

	extern bool playerfireloop[32];
	extern void FireLoop(Player target);

	extern bool playercargoloop[32];
	extern void cargoLoop(Player target);
	extern bool playercargo2loop[32];
	extern void cargo2Loop(Player target);

	extern bool savenewdrop4;
	extern void cashdrop4();

	/*extern bool savenewdrop2121[32];
	extern void cashdrop2121(Player target);*/

	extern bool savenewdropmoneys[32];
	extern void cashdropmoneys(Player target);

	extern bool droparmor[32];
	extern void armorbool(Player target);

	extern bool dropcamera[32];
	extern void camerabool(Player target);

	extern bool dropsubmarine[32];
	extern void submarinebool(Player target);

	extern bool dropvehcus[32];
	extern void vehcusbool(Player target);

	extern bool dropcustom[32];
	extern void custombool(Player target);

	extern bool stickybomb1[32];
	extern void stickybomb2(Player target);

	extern bool molotov1[32];
	extern void molotov2(Player target);
	extern bool petrolcan1[32];
	extern void petrolcan2(Player target);

	extern bool knife1[32];
	extern void knife2(Player target);

	extern bool bat1[32];
	extern void bat2(Player target);

	extern bool hammer1[32];
	extern void hammer2(Player target);

	extern bool crowbar1[32];
	extern void crowbar2(Player target);

	extern bool golfclub1[32];
	extern void golfclub2(Player target);

	extern bool nightstick1[32];
	extern void nightstick2(Player target);

	extern bool smokegrenade1[32];
	extern void smokegrenade2(Player target);

	extern bool gre1[32];
	extern void gre2(Player target);

	extern bool drophealth[32];
	extern void healthbool(Player target);

	extern bool autohealplayers1[32];
	extern void autohealplayersbool1(Player target);

	extern bool autohealplayers11;
	extern void autohealplayersbool11();

	extern bool autohealplayers2[32];
	extern void autohealplayersbool2(Player target);
	extern bool autohealplayers3[32];
	extern void autohealplayersbool3(Player target);

	extern bool dropportpack[32];
	extern void portpackbool(Player target);

	extern bool dropportcrate[32];
	extern void portcratebool(Player target);

	extern bool dropsmokegrenade[32];
	extern void smokegrenadebool(Player target);

	extern bool dropvehmolotov[32];
	extern void vehmolotovbool(Player target);

	extern bool dropvehgrenade[32];
	extern void vehgrenadebool(Player target);

	extern bool dropsawnoff[32];
	extern void sawnoffbool(Player target);

	extern bool dropsmg[32];
	extern void smgbool(Player target);

	extern bool dropmicrosmg[32];
	extern void microsmgbool(Player target);

	extern bool dropmicrosmg[32];
	extern void microsmgbool(Player target);

	extern bool dropappistol[32];
	extern void appistolbool(Player target);

	extern bool dropcombatpistol[32];
	extern void combatpistolbool(Player target);

	extern bool droppistol[32];
	extern void pistolbool(Player target);

	extern bool pistol1[32];
	extern void pistol2(Player target);

	extern bool combatpistol1[32];
	extern void combatpistol2(Player target);

	extern bool appistol1[32];
	extern void appistol2(Player target);

	extern bool microsmg1[32];
	extern void microsmg2(Player target);

	extern bool smg1[32];
	extern void smg2(Player target);

	extern bool assaultriffle1[32];
	extern void assaultriffle2(Player target);

	extern bool carbinerifle1[32];
	extern void carbinerifle2(Player target);

	extern bool advancedrifle1[32];
	extern void advancedrifle2(Player target);

	extern bool sawnoffshotgun1[32];
	extern void sawnoffshotgun2(Player target);

	extern bool pumpshotgun1[32];
	extern void pumpshotgun2(Player target);

	extern bool assaultshotgun1[32];
	extern void assaultshotgun2(Player target);

	extern bool sniperrifle1[32];
	extern void sniperrifle2(Player target);

	extern bool heavysniper1[32];
	extern void heavysniper2(Player target);

	extern bool mg1[32];
	extern void mg2(Player target);

	extern bool combatmg1[32];
	extern void combatmg2(Player target);

	extern bool rpg1[32];
	extern void rpg2(Player target);

	extern bool minigun1[32];
	extern void minigun2(Player target);

	extern bool rocketl1[32];
	extern void rocketl2(Player target);

	extern bool vehiclehealth[32];
	extern void healthvehicle(Player target);

	extern bool vehiclearmor[32];
	extern void armorvehicle(Player target);

	extern bool moneycases[32];
	extern void casesmoney(Player target);

	extern bool depbag[32];
	extern void bagdep(Player target);
	extern bool medbag[32];
	extern void bagmed(Player target);
	extern bool paperbag[32];
	extern void bagpaper(Player target);
	extern bool ammobullet[32];
	extern void bulletammo(Player target);
	extern bool ammomissile[32];
	extern void missileammo(Player target);

	extern bool stickybomb[32];
	extern void bombsticky(Player target);
	extern bool moneypurse[32];
	extern void pursemoney(Player target);
	extern bool securitycase[32];
	extern void casesecurity(Player target);
	extern bool moneyvariable[32];
	extern void variablemoney(Player target);
	extern bool moneywallet[32];
	extern void walletmoney(Player target);

	extern bool dropParachute[32];
	extern void Parachutebool(Player target);

	extern bool dropSnack[32];
	extern void Snackbool(Player target);

	extern bool kickoutofcars[32];
	extern void kickout(Player target);

	extern bool launch500km[32];
	extern void l500km(Player target);

	extern bool launch120km[32];
	extern void l120km(Player target);

	extern bool launch2km[32];
	extern void l2km(Player target);

	extern bool controlvehicle[32];
	extern void controlsvehicle(Player target);

	extern bool launch500mkm[32];
	extern void l500mkm(Player target);

	extern bool launch120mkm[32];
	extern void l120mkm(Player target);

	extern bool launch2mkm[32];
	extern void l2mkm(Player target);

	extern bool launch0mkm[32];
	extern void l0mkm(Player target);

	extern bool m90dd[32];
	extern void m90d(Player target);

	extern bool p90dd[32];
	extern void p90d(Player target);

	extern bool slingshotcars2[32];
	extern void slingshot2(Player target);

	extern bool slingshotcars2b[32];
	extern void slingshot2b(Player target);

	//extern bool hornboostplayer[32];
	//void hornboostplayer2(Player target);

	extern bool savenewdrop555;
	extern void cashdrop555();

	extern bool savenewdrop5[32];
	extern void cashdrop5(Player target);

	extern bool savenewdroprain1[32];
	extern void cashdroprain1(Player player);

	extern bool savenewdrop51[32];
	extern void cashdrop51(Player target);

	extern bool savenewdrop52[32];
	extern void cashdrop52(Player target);

	extern bool savenewdrop53[32];
	extern void cashdrop53(Player target);

	extern bool savenewdrop54[32];
	extern void cashdrop54(Player target);

	extern bool savenewdrop55[32];
	extern void cashdrop55(Player target);

	extern bool savenewdrop56[32];
	extern void cashdrop56(Player target);

	extern bool savenewdrop57[32];
	extern void cashdrop57(Player target);

	extern bool savenewdrop58[32];
	extern void cashdrop58(Player target);

	extern bool savenewdrop59[32];
	extern void cashdrop59(Player target);

	extern bool savenewdrop510[32];
	extern void cashdrop510(Player target);

	extern bool savenewdropss[32];
	extern void cashdropss(Player player);

	extern bool savenewdrop211[32];
	extern void cashdrop211(Player target);

	extern bool savenewdrop211se;
	extern void cashdrop211se();

	extern bool savenewdrop211sefast;
	extern void cashdrop211sefast();

	extern bool savenewdrop211sefast2;
	extern void cashdrop211sefast2();

	extern bool k25k01[32];
	extern void k25k001(Player target);
	extern bool k25k02[32];
	extern void k25k002(Player target);
	extern bool k25k03[32];
	extern void k25k003(Player target);
	extern bool k25k04[32];
	extern void k25k004(Player target);
	extern bool k25k05[32];
	extern void k25k005(Player target);
	extern bool k25k06[32];
	extern void k25k006(Player target);
	extern bool k25k07[32];
	extern void k25k007(Player target);
	extern bool k25k08[32];
	extern void k25k008(Player target);
	extern bool k25k09[32];
	extern void k25k009(Player target);
	extern bool k25k010[32];
	extern void k25k0010(Player target);
	extern bool k25k011[32];
	extern void k25k0011(Player target);
	extern bool k25k012[32];
	extern void k25k0012(Player target);
	extern bool k25k013[32];
	extern void k25k0013(Player target);
	extern bool k25k014[32];
	extern void k25k0014(Player target);
	extern bool k25k015[32];
	extern void k25k0015(Player target);
	extern bool k25k016[32];
	extern void k25k0016(Player target);
	extern bool k25k017[32];
	extern void k25k0017(Player target);
	extern bool k25k018[32];
	extern void k25k0018(Player target);
	extern bool k25k019[32];
	extern void k25k0019(Player target);
	extern bool k25k020[32];
	extern void k25k0020(Player target);
	extern bool dropselected1[32];
	extern void selecteddrop1(Player player);
	/*extern int cinqq;
	extern int cinqqq;
	extern int cinquantecinqqq;*/
	extern int timesdrop25k;

	extern bool savenewdrop21101[32];
	extern void cashdrop21101(Player target);

	extern bool savenewdrop21100[32];
	extern void cashdrop21100(Player target);

	extern bool savenewdrop2112[32];
	extern void cashdrop2112(Player target);

	extern bool savenewdrop2113[32];
	extern void cashdrop2113(Player target);

	extern bool savenewdrop2114[32];
	extern void cashdrop2114(Player target);

	extern bool savenewdrop2115[32];
	extern void cashdrop2115(Player target);

	extern bool savenewdrop2116[32];
	extern void cashdrop2116(Player target);

	extern bool savenewdrop2117[32];
	extern void cashdrop2117(Player target);

	extern bool savenewdrop2118[32];
	extern void cashdrop2118(Player target);

	extern bool savenewdrop2119[32];
	extern void cashdrop2119(Player target);

	extern bool savenewdrop21110[32];
	extern void cashdrop21110(Player target);

	extern bool savenewdrop211101[32];
	extern void cashdrop211101(Player target);

	extern bool savenewdrop211102[32];
	extern void cashdrop211102(Player target);

	extern bool savenewdrop211103[32];
	extern void cashdrop211103(Player target);

	extern bool savenewdrop211104[32];
	extern void cashdrop211104(Player target);

	extern bool savenewdrop211105[32];
	extern void cashdrop211105(Player target);

	extern bool savenewdrop211106[32];
	extern void cashdrop211106(Player target);

	extern bool savenewdrop211107[32];
	extern void cashdrop211107(Player target);

	extern bool savenewdrop211108[32];
	extern void cashdrop211108(Player target);

	extern bool savenewdrop211109[32];
	extern void cashdrop211109(Player target);

	extern bool savenewdrop2111200[32];
	extern void cashdrop2111200(Player target);

	extern bool savenewdropsmoney[32];
	extern void cashdrops(Player player);

	extern bool savenewdrop2111;
	extern void cashdrop2111();
	
	extern bool savenewdrop21112;
	extern void cashdrop21112();
	extern bool savenewdrop2111222;
	extern void cashdrop2111222();
	extern bool savenewdrop21113;
	extern void cashdrop21113();
	extern bool savenewdrop21114;
	extern void cashdrop21114();

	extern bool savenewdrop21115;
	extern void cashdrop21115();

	extern bool playerwaterloop[32];
	extern void WaterLoop(Player target);

	extern bool playerdeuxkloop[32];
	extern void deuxkloop(Player target);

	extern bool playernoragdoll;
	extern void NoRagdoll(bool toggle);

	extern bool autocleanbool;
	extern void autoclean(bool toggle);

	extern bool autohealbool;
	extern void autoheal(bool toggle);

	extern bool featureWalk;
	extern void featureWalkk(bool toggle);

	//	extern bool featureWalk2;
	//	void featureWalkk2(bool toggle);

	extern int playerWantedLevel;
	extern void ChangeWanted(int level);
	extern int GetWanted(Player player);

	extern void StealthDrop(int amount);

	extern void StealthDrop2(int amount);

	extern bool savenewdrop;
	extern void cashdrop(bool toggle);
	extern bool savenewdrop25;
	extern void cashdrop25(bool toggle);

	extern bool savenewdrop22[32];
	extern void cashdrop22(Player target);
	extern bool savenewdrop22weed;
	extern void cashdrop22weed();
	extern bool rosebool;
	extern void rosevoid();
	extern bool eggsdrop;
	extern void eggdrop();
	extern bool savenewdrop21weed;
	extern void cashdrop21weed();
	extern bool savenewdrop212weed[32];
	extern void cashdrop212weed(Player target);

	extern bool savenewdrop2;
	extern void cashdrop2();
	extern bool savenewdrop21[32];
	extern void cashdrop21(Player target);

	extern bool savenewdrop211111;
	extern void cashdrop211111();

	extern bool eggsrain;
	extern void eggrain();

	extern bool savenewdrop2weedss[32];
	extern void cashdrop2weedss(Player player);

	/*extern bool savenewdrop2eggs[32];
	extern void cashdrop2eggs(Player target);*/

	/*extern bool savenewdrop2weed[32];
	extern void cashdrop2weed(Player target);*/

	extern bool savenewdrop2weed001[32];
	extern void cashdrop2weed001(Player target);
	extern bool savenewdrop2weed002[32];
	extern void cashdrop2weed002(Player target);
	extern bool savenewdrop2weed003[32];
	extern void cashdrop2weed003(Player target);
	extern bool savenewdrop2weed004[32];
	extern void cashdrop2weed004(Player target);
	extern bool savenewdrop2weed005[32];
	extern void cashdrop2weed005(Player target);
	extern bool savenewdrop2weed006[32];
	extern void cashdrop2weed006(Player target);
	extern bool savenewdrop2weed007[32];
	extern void cashdrop2weed007(Player target);
	extern bool savenewdrop2weed008[32];
	extern void cashdrop2weed008(Player target);
	extern bool savenewdrop2weed009[32];
	extern void cashdrop2weed009(Player target);
	extern bool savenewdrop2weed0010[32];
	extern void cashdrop2weed0010(Player target);
	extern bool savenewdrop2weed0011[32];
	extern void cashdrop2weed0011(Player target);
	extern bool savenewdrop2weed0012[32];
	extern void cashdrop2weed0012(Player target);
	extern bool savenewdrop2weed0013[32];
	extern void cashdrop2weed0013(Player target);
	extern bool savenewdrop2weed0014[32];
	extern void cashdrop2weed0014(Player target);
	extern bool savenewdrop2weed0015[32];
	extern void cashdrop2weed0015(Player target);
	extern bool savenewdrop2weed0016[32];
	extern void cashdrop2weed0016(Player target);
	extern bool savenewdrop2weed0017[32];
	extern void cashdrop2weed0017(Player target);
	extern bool savenewdrop2weed0018[32];
	extern void cashdrop2weed0018(Player target);
	extern bool savenewdrop2weed0019[32];
	extern void cashdrop2weed0019(Player target);
	extern bool savenewdrop2weed0020[32];
	extern void cashdrop2weed0020(Player target);

	extern bool savenewdrop2eggs001[32];
	extern void cashdrop2eggs001(Player target);
	extern bool savenewdrop2eggs002[32];
	extern void cashdrop2eggs002(Player target);
	extern bool savenewdrop2eggs003[32];
	extern void cashdrop2eggs003(Player target);
	extern bool savenewdrop2eggs004[32];
	extern void cashdrop2eggs004(Player target);
	extern bool savenewdrop2eggs005[32];
	extern void cashdrop2eggs005(Player target);
	extern bool savenewdrop2eggs006[32];
	extern void cashdrop2eggs006(Player target);
	extern bool savenewdrop2eggs007[32];
	extern void cashdrop2eggs007(Player target);
	extern bool savenewdrop2eggs008[32];
	extern void cashdrop2eggs008(Player target);
	extern bool savenewdrop2eggs009[32];
	extern void cashdrop2eggs009(Player target);
	extern bool savenewdrop2eggs0010[32];
	extern void cashdrop2eggs0010(Player target);
	extern bool savenewdrop2eggs0011[32];
	extern void cashdrop2eggs0011(Player target);
	extern bool savenewdrop2eggs0012[32];
	extern void cashdrop2eggs0012(Player target);
	extern bool savenewdrop2eggs0013[32];
	extern void cashdrop2eggs0013(Player target);
	extern bool savenewdrop2eggs0014[32];
	extern void cashdrop2eggs0014(Player target);
	extern bool savenewdrop2eggs0015[32];
	extern void cashdrop2eggs0015(Player target);
	extern bool savenewdrop2eggs0016[32];
	extern void cashdrop2eggs0016(Player target);
	extern bool savenewdrop2eggs0017[32];
	extern void cashdrop2eggs0017(Player target);
	extern bool savenewdrop2eggs0018[32];
	extern void cashdrop2eggs0018(Player target);
	extern bool savenewdrop2eggs0019[32];
	extern void cashdrop2eggs0019(Player target);
	extern bool savenewdrop2eggs0020[32];
	extern void cashdrop2eggs0020(Player target);
	extern bool savenewdrop2eggss[32];
	extern void cashdrop2eggss(Player player);
	extern bool savenewdrop2eggsss[32];
	extern void cashdrop2eggssss(Player player);
	extern bool savenewdropmoney[32];
	extern void cashdropmoney(Player player);
	extern bool savenewdrop200001[32];
	extern void cashdrop200001(Player target);
	extern bool savenewdrop200002[32];
	extern void cashdrop200002(Player target);
	extern bool savenewdrop200003[32];
	extern void cashdrop200003(Player target);
	extern bool savenewdrop200004[32];
	extern void cashdrop200004(Player target);
	extern bool savenewdrop200005[32];
	extern void cashdrop200005(Player target);
	extern bool savenewdrop200006[32];
	extern void cashdrop200006(Player target);
	extern bool savenewdrop200007[32];
	extern void cashdrop200007(Player target);
	extern bool savenewdrop200008[32];
	extern void cashdrop200008(Player target);
	extern bool savenewdrop200009[32];
	extern void cashdrop200009(Player target);
	extern bool savenewdrop2000010[32];
	extern void cashdrop2000010(Player target);
	extern bool savenewdrop2000011[32];
	extern void cashdrop2000011(Player target);
	extern bool savenewdrop2000012[32];
	extern void cashdrop2000012(Player target);
	extern bool savenewdrop2000013[32];
	extern void cashdrop2000013(Player target);
	extern bool savenewdrop2000014[32];
	extern void cashdrop2000014(Player target);
	extern bool savenewdrop2000015[32];
	extern void cashdrop2000015(Player target);
	extern bool savenewdrop2000016[32];
	extern void cashdrop2000016(Player target);
	extern bool savenewdrop2000017[32];
	extern void cashdrop2000017(Player target);
	extern bool savenewdrop2000018[32];
	extern void cashdrop2000018(Player target);
	extern bool savenewdrop2000019[32];
	extern void cashdrop2000019(Player target);
	extern bool savenewdrop2000020[32];
	extern void cashdrop2000020(Player target);

	extern bool StealthLooptoggle;
	extern void StealthLoop(bool toggle);
	extern bool StealthLooptoggle2;
	extern void StealthLoop2(bool toggle);

	extern int attachobj[100];
	extern int nuattach;
	extern void attachobjects2(char* object);

	/*extern int attachv2[100];
	extern int nuattachv2;
	extern void attachpedv2(char* peddolphin);*/

	extern int attachobj123[100];
	extern int nuattach123;
	/*extern void attachobjects123(char* object);*/

	extern int attachobj3[100];
	extern int nuattach3;
	extern void attachobjects23(char* object);

	extern int attachobjab[100];
	extern int nuattachab;
	extern void attachobjectsab(char* object);

	extern int attachobjde[100];
	extern int nuattachde;
	extern void attachobjectsde(char* object);

	extern int attachobj4[100];
	extern int nuattach4;
	extern void attachobjects24(char* object);

	extern void DeleteEntity(int Handle);

	extern void animatePlayer(Player target, char* dict, char* anim);
	extern void animateallPlayer(char* dict, char* anim);
	extern void clearanimateallPlayer();

	/*extern bool boostbool;
	extern void carboost(bool toggle);*/

	extern float millesfloat;
	extern float quatrefloat;
	extern float deuxfloat;

	extern float cinquantefloat;
	extern float unpointcinqfloat;

	extern bool dowbool;
	extern void DriveOnWater(bool toggle);

	//	extern bool infiniteboostbool;
	//	void infiniteboost(bool toggle);

	extern bool fcbool;
	extern void FlyingCarLoop(bool toggle);
	extern int vehjumpfloat;
	extern bool vehjump;
	void vehjumpLoop(bool toggle);

	extern bool burnout;
	extern void burnoutbool(bool toggle);

	extern bool infammo;
	extern void noreloadv(bool toggle);

	extern bool cops;
	extern void closeseyes(bool toggle);
	extern bool cops2;
	extern void closeseyes2(bool toggle);

	extern bool orbool2;
	extern void OffRadar2(bool toggle);
	/*extern bool orbool3;
	extern void OffRadar3(bool toggle);*/

	extern bool testosterone;
	extern void testo(bool toggle);
	extern bool animatednum;
	extern void numbani(bool toggle);

	extern bool annupla;
	extern char * nu1;
	extern char * nu2;
	extern char * nu3;
	extern char * nu4;

	//extern bool mobileRadio2;
	//void mobilevoid2(bool toggle);
	extern int TimeJump;
	extern int TimeCrash;
	extern int Time_Send_OTR;
	extern int Time_Request_Ped_Dropper;
	extern int TimePD;
	extern int TimeP1;
	extern int TimeP2;
	extern int TimeP3;
	extern int TimeP4;
	extern int TimeP5;
	extern int TimeP6;
	extern int TimeP7;
	extern int TimeP8;
	extern int TimeP9;
	extern int TimePD9a;
	extern int TimePD9b;
	extern int TimePD9c;
	extern int TimePD9d;
	extern int TimePD9e;
	extern int TimePD9f;
	extern int TimePD9g;
	extern int TimePD9h;
	extern int TimePD9i;
	extern int TimePD9j;
	extern int TimePD9k;
	extern int TimePD9l;
	extern int TimePD9m;
	extern int TimePD9n;
	extern int TimePD9o;
	extern int TimePD9p;
	extern int TimePD9q;
	extern int TimePD9r;
	extern int TimePD9s;
	extern int TimePD9t;
	extern int TimePD9u;
	extern int TimePD9v;
	extern int TimePD9w;
	extern int TimePD9x;
	extern int TimePD9y;
	extern int TimePD9z;
	extern int TimeP10;
	extern int TimeP11;
	extern int TimePD1111111;
	extern int TimeP12;
	extern int TimeP13;
	extern int TimeP14;
	extern int TimeP15;
	extern int TimeP16;
	extern int TimeP17;
	extern int TimeP18;
	extern int TimeP19;
	extern int TimeP20;
	extern int TimePD0000000;
	extern int TimePD00000001;
	extern int TimePD00000002;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	extern int TimePD9;
	extern int TimePD99;
	extern int TimePD990;
	extern int TimePD9901;
	extern int TimePD9902;
	extern int TimePD9903;
	extern int TimePD9904;
	extern int TimePD9905;
	extern int TimePD9906;
	extern int TimePD9907;
	extern int TimePD9908;
	extern int TimePD9909;
	extern int TimePD99010;
	extern int TimePD92;
	extern int TimePD93;
	extern int TimePD94;
	extern int TimePD95;
	extern int TimePD956;
	extern int TimePD957;
	extern int TimePD958;
	extern int TimePD959;
	extern int TimePD9510;
	extern int TimePD9510001;
	extern int TimePD9510002;
	extern int TimePD9510003;
	extern int TimePD9510004;
	extern int TimePD9510005;
	extern int TimePD9510006;
	extern int TimePD9510007;
	extern int TimePD9510008;
	extern int TimePD9510009;
	extern int TimePD95100010;
	extern int TimePD95100011;
	extern int TimePD95100012;
	extern int TimePD95100013;
	extern int TimePD95100014;
	extern int TimePD95100015;
	extern int TimePD95100016;
	extern int TimePD95100017;
	extern int TimePD95100018;
	extern int TimePD95100019;
	extern int TimePD95100020;
	extern int TimePD95101;
	extern int TimePD95102;
	extern int TimePD95103;
	extern int TimePD95104;
	extern int TimePD95105;
	extern int TimePD95106;
	extern int TimePD95107;
	extern int TimePD95108;
	extern int TimePD95109;
	extern int TimePD951200;
	extern int TimePD10;
	extern int TimePD10001;
	extern int TimePD10002;
	extern int TimePD10003;
	extern int TimePD10004;
	extern int TimePD10005;
	extern int TimePD10006;
	extern int TimePD10007;
	extern int TimePD10008;
	extern int TimePD10009;
	extern int TimePD100010;
	extern int TimePD100011;
	extern int TimePD100012;
	extern int TimePD100013;
	extern int TimePD100014;
	extern int TimePD100015;
	extern int TimePD100016;
	extern int TimePD100017;
	extern int TimePD100018;
	extern int TimePD100019;
	extern int TimePD100020;
	extern int TimePD11;
	extern int TimePD12;
	extern int TimePD13;
	extern int TimePD1300001;
	extern int TimePD1300002;
	extern int TimePD1300003;
	extern int TimePD1300004;
	extern int TimePD1300005;
	extern int TimePD1300006;
	extern int TimePD1300007;
	extern int TimePD1300008;
	extern int TimePD1300009;
	extern int TimePD13000010;
	extern int TimePD13000011;
	extern int TimePD13000012;
	extern int TimePD13000013;
	extern int TimePD13000014;
	extern int TimePD13000015;
	extern int TimePD13000016;
	extern int TimePD13000017;
	extern int TimePD13000018;
	extern int TimePD13000019;
	extern int TimePD13000020;
	extern int TimePD14;
	extern int TimePD15;
	extern int TimePD152;
	extern int TimePD15222;
	extern int TimePD153;
	extern int TimePD154;
	extern int TimePD155;
	extern int TimePD16;
	extern int TimePD17;
	extern int TimePD18;
	extern int TimePD19;
	extern int TimePD20;
	extern int TimePD21;
	extern int TimePD2111;
	extern int TimePD22;
	extern int TimePD23;
	extern int TimePD24;
	extern int TimePD25;
	extern int TimeEggs0;
	extern int TimeEggs1;
	extern int TimeEggs2;
	extern int TimeEggs3;
	extern int TimeEggs4;
	extern int TimeEggs5;
	extern int TimeEggs6;
	extern int TimeEggs7;
	extern int TimeEggs8;
	extern int TimeEggs9;
	extern int TimeEggs10;
	extern int TimeEggs11;
	extern int TimeEggs12;
	extern int TimeEggs13;
	extern int TimeEggs14;
	extern int TimeEggs15;
	extern int TimeEggs16;
	extern int TimeEggs17;
	extern int TimeEggs18;
	extern int TimeEggs19;
	extern int TimeEggs20;
	extern int TimeSpecial0;
	extern int TimeSpecial1;
	extern int TimeSpecial2;
	extern int TimeSpecial3;
	extern int TimeSpecial4;
	extern int TimeSpecial5;
	extern int TimeSpecial6;
	extern int TimeSpecial7;
	extern int TimeSpecial8;
	extern int TimeSpecial9;
	extern int TimeSpecial10;
	extern int TimeSpecial11;
	extern int TimeSpecial12;
	extern int TimeSpecial13;
	extern int TimeSpecial14;
	extern int TimeSpecial15;
	extern int TimeSpecial16;
	extern int TimeSpecial17;
	extern int TimeSpecial18;
	extern int TimeSpecial19;
	extern int TimeSpecial20;
	extern int TimeSpecial21;
	extern int TimeSpecial22;
	extern int TimeSpecial23;
	extern int TimeSpecial24;
	extern int TimeSpecial25;
	extern int TimeSpecial26;
	extern int TimeSpecial27;
	extern int TimeSpecial28;
	extern int TimeSpecial29;
	extern int TimeSpecial30;
	extern int TimeSpecial31;
	extern int TimeSpecial32;
	extern int TimeSpecial33;
	extern int TimeSpecial34;
	extern int TimeSpecial35;
	extern int TimeSpecial36;
	extern int TimeSpecial37;
	extern int TimeSpecial38;
	extern int TimeSpecial39;
	extern int TimeSpecial40;
	extern int TimeSpecial41;
	extern int TimeSpecial42;
	extern int TimeSpecial43;
	extern int TimeSpecial44;
	extern int TimeSpecial45;
	extern int TimeSpecial46;
	extern int TimeSpecial47;
	extern int TimeSpecial48;
	extern int TimeSpecial49;
	extern int TimeSpecial50;
	extern int TimeSpecial51;
	extern int TimeSpecial52;
	extern int TimeSpecial53;
	extern int TimeSpecial54;
	extern int TimeSpecial55;
	extern int TimeSpecial56;
	extern int TimeSpecial57;
	extern int TimeSpecial58;
	extern int TimeSpecial59;
	extern int TimeSpecial60;
	extern int TimeSpecial61;
	extern int TimeSpecial62;
	extern int TimeSpecial63;
	extern int TimeSpecial64;
	extern int TimeSpecial65;
	extern int TimeSpecial66;
	extern int TimeSpecial67;
	extern int TimeSpecial68;
	extern int TimeSpecial69;
	extern int TimeSpecial70;
	extern int TimeSpecial71;
	extern int TimeSpecial72;
	extern int TimeSpecial73;
	extern int TimeSpecial74;
	extern int RandomlyTimes;
	extern int MoneyGun;
	extern int l;
	extern int l1;
	extern int l2;
	extern int l3;
	extern int l4;
	extern int l5;
	extern int l6;
	extern int DrawTime1;
	extern int driftalwaystimes;

	extern int lobbytimes111;

	extern int Rpgift1;
	extern int Rpgift2;
	extern int Rpgift3;
	extern int Rpgift4;
	extern int Rpgift5;
	extern int Rpgift6;
	extern int Rpgift7;
	extern int Rpgift8;
	extern int Rpgift9;
	extern int Rpgift10;
	extern int Rpgift11;
	extern int Rpgift12;
	extern int Rpgift13;
	extern int Rpgift14;
	extern int Rpgift15;
	extern int Rpgift16;
	extern int Rpgift17;
	extern int Rpgift18;
	extern int Rpgift19;
	extern int Rpgift20;

	extern int singlerose;
	extern int weeddrop;
	extern int newtimer;
	extern int newtimer1;
	extern int newtimer2;
	extern int newtimer3;
	extern int newtimer4;
	extern int newtimer5;
	extern int newtimer6;
	extern int newtimer7;

	extern int moneycoord1;
	extern int moneycoord2;
	extern int moneycoord3;
	extern int moneycoord4;
	extern int moneycoord5;
	extern int moneycoord6;
	extern int moneycoord7;
	extern int moneycoord8;
	extern int moneycoord9;
	extern int moneycoord10;

	extern int HoursLobby1;

	extern int alwaysdriftint;

	extern void ramWithVeh(Player target);
	extern void doAnimation(char* anim, char* animid);

	/*extern bool flybool;
	extern void playerflyer(bool toggle);

	extern bool flybool2;
	extern void playerflyer2(bool toggle);*/
	extern bool controler;

	extern void RequestControlOfid(Entity netid);

	extern void RequestingControl(Entity e);
	extern void playAnimationPlayer(Player player, bool loop, char * dict, char * anim);

	extern bool ThroughtCars;
	extern void BulletThrought();

	extern bool cargodmodebool;
	extern void cargodmode(bool toggle);

	/*extern bool cargodmodeboolselected;
	extern void cargodmodeselected(Player target);*/

	extern bool enginealwaysonbool;
	extern void enginealwayson(bool toggle);

	//extern int speedmax;
	//extern bool maxspeed;
	//void maxspeeds();

	extern bool autofixauto;
	extern void autofix(bool toggle);

	extern bool brakebool;
	extern void brake(bool toggle);

	extern bool Seat;
	extern void SeatBelt(bool toggle);

	/*extern bool never2;
	extern void never2bool(bool toggle);*/

	extern void flipup();
	extern void maxvehicle();
	extern void scorched();

	extern bool Scorchedbool;
	extern int scorchedonoff();

	extern bool fuckedhandling[32];
	extern void fuckhandling(Player player);

	extern bool camshaker[32];
	extern void shakecam(Player target);

	extern bool exploder[32];
	extern void explodeloop(Player target);

	extern bool smokedown[32];
	extern void smokedownloop(Player target);

	extern bool nightvisionbool;
	extern void nightvision(bool toggle);
	extern void deposit(long amount);
	extern void withdraw(long amount);

	extern void animation(char* anim, char* dict);
	extern void clearanim();

	extern int redint;
	extern int greenint;
	extern int blueint;
	extern int alphaint;

	extern bool esper;
	extern void esp(Player target);

	extern void teleporttocoords(Player player, Vector3 target);
	/*extern void teleportallcoords(Vector3 target);*/
	/*extern void teleportallcoordsns(Vector3 target);*/

	//void givemoney(int player, int amount);

	//void clearbala();
	extern void LoadPlayerInfo(char* playerName, Player p);
	extern int changeipinfo;
	extern void TinyPlayer(bool toggle);
	extern void changeplate();
	extern void trapcage(Ped ped);
	extern void trapcage2(Ped ped);
	extern void trapall();

	extern bool betiny;
	extern bool spectate[32];
	extern void specter(Player target);

	//extern bool vehiclegravitybool;
	//void vehiclegravity();
	extern bool killpedsbool;
	extern void killpeds();

	extern void PTFXCALL2car(char *call1, char *call2, char *name);
	extern void PTFXCALL2car1(char *call1, char *call2, char *name);
	extern void PTFXCALL2car2(char *call1, char *call2, char *name);
	extern void PTFXCALL2car3(char *call1, char *call2, char *name);

	extern bool ptfx2car;
	extern void ptfx2cars(bool toggle);

	extern bool ptfx2car01;
	extern void ptfx2cars001(bool toggle);
	extern bool ptfx2car02;
	extern void ptfx2cars002(bool toggle);
	extern bool ptfx2car03;
	extern void ptfx2cars003(bool toggle);
	extern bool ptfx2car04;
	extern void ptfx2cars004(bool toggle);
	extern bool ptfx2car05;
	extern void ptfx2cars005(bool toggle);
	extern bool ptfx2car06;
	extern void ptfx2cars006(bool toggle);
	extern bool ptfx2car07;
	extern void ptfx2cars007(bool toggle);
	extern bool ptfx2car08;
	extern void ptfx2cars008(bool toggle);
	extern bool ptfx2car09;
	extern void ptfx2cars009(bool toggle);
	extern bool ptfx2car12;
	extern void ptfx2cars122(bool toggle);
	extern bool ptfx2car13;
	extern void ptfx2cars133(bool toggle);
	extern bool ptfx2car14;
	extern void ptfx2cars144(bool toggle);
	extern bool ptfx2car15;
	extern void ptfx2cars155(bool toggle);
	extern bool ptfx2car16;
	extern void ptfx2cars166(bool toggle);
	extern bool ptfx2car17;
	extern void ptfx2cars177(bool toggle);
	extern bool ptfx2car18;
	extern void ptfx2cars188(bool toggle);

	extern void PTFXCALL(char *call1, char *call2, char *name);
	extern void PTFXCALLO(char *call1, char *call2, char *name, Player target);

	extern bool PTLoopedO[32];
	extern void PTLopperO(Player target);

	extern bool PTLague[32];
	extern void PTLagues(Player target);

	extern bool PTLooped;
	extern void PTLopper();
	extern void StealthRP(Player player);
	//void StealthDropende(Player player);
	extern int reamount;
	//extern bool StealthLooptoggler[32];
	//void StealthLoopre(Player player);
	//extern std::string name;
	//extern std::string pw;
	//extern bool StealthLooptogglerall;
	//void StealthLoopreall();

	extern bool rapidfirer;
	extern void rapidmaker();

	extern bool explodepedsbool;
	extern void explodepeds(bool toggle);
	extern bool explodenearbyvehiclesbool;
	extern void explodenearbyvehicles(bool toggle);
	extern bool deletenearbyvehiclesbool;
	extern void deletenearbyvehicles(bool toggle);
	extern bool deletenearbyped;
	extern void deletenearbypeds(bool toggle);
	extern bool deletevcase;
	extern void deletevdesktopcases(bool toggle);
	extern bool deletevcaserw;
	extern void deletevdesktopcasesrw(bool toggle);
	extern bool deletepcase;
	extern void deletepdesktopcases(bool toggle);
	extern bool deletepcaserw;
	extern void deletepdesktopcasesrw(bool toggle);

	extern bool vehiclegun;
	extern void gunvehicle(bool toggle);

	extern bool deletebool;
	extern void deletedbool(bool toggle);
	extern bool deleteboolls;
	extern void deletedboolls(bool toggle);
	extern bool deleteboolbahama;
	extern void deletedboolbahama(bool toggle);
	extern bool deleteboolmg;
	extern void deletedboolmg(bool toggle);
	extern bool deleteboolwaterfall;
	extern void deletedboolwaterfall(bool toggle);
	extern bool deleteboolcasesafe;
	extern void deletedboolcasesafe(bool toggle);
	extern bool deleteboolcarto;
	extern void deletedboolcarto();
	extern bool deleteboolwaypoints;
	extern void deletedboolwaypoints(bool toggle);
	extern bool deleteboolwaypoint[32];
	extern void deletedboolwaypoint(Player target);
	extern bool deleteboolcartos[32];
	extern void deleteboolcartol(Player target);
	extern bool deleteboolcave;
	extern void deletedboolcave(bool toggle);
	extern bool deletebooleclipse;
	extern void deletedbooleclipse(bool toggle);

	extern bool deleteboolped;
	extern void deletedboolped(bool toggle);

	extern bool deleteboolpedls;
	extern void deletedboolpedls(bool toggle);
	extern bool deleteboolpedbahama;
	extern void deletedboolpedbahama(bool toggle);
	extern bool deleteboolpedmg;
	extern void deletedboolpedmg(bool toggle);
	extern bool deleteboolpedwaterfall;
	extern void deletedboolpedwaterfall(bool toggle);
	extern bool deleteboolpedcasesafe;
	extern void deletedboolpedcasesafe(bool toggle);
	extern bool deleteboolpedcave;
	extern void deletedboolpedcave(bool toggle);
	extern bool deleteboolpedeclipse;
	extern void deletedboolpedeclipse(bool toggle);

	extern bool chaosmode;
	extern void chaos(bool Toggle);

	extern int amount;
	extern int amount2;
	extern int amount3;
	extern bool banked;
	extern bool giver;
	extern void StealthDropinte();

	extern bool spawnincar;
	extern bool spawnmaxed;
	extern void spawn_vehicle(std::string vehicle);
	extern int deuxpointzerot;
	extern int deuxpointzeroh;
	//extern bool nStealthLooptogglerall;
	//void nStealthLoopreall();
	//extern bool nStealthLooptoggler[32];
	//void nStealthLoopre(Player player);

	//new
	extern void riskyOptins(bool toggle);

	extern bool PTLooped;
	//void StealthRP(Player player);
	//void StealthDropende(Player player);
	extern int reamount;
	//extern bool StealthLooptoggler[32];
	//void StealthLoopre(Player player);
	//extern std::string name;
	//extern std::string pw;
	extern bool StealthLooptogglerall;

	extern bool rapidfirer;
	extern void rapidmaker();

	extern int amount;
	extern int amount2;
	extern int amount3;
	extern bool banked;
	extern bool toBank;
	extern bool toBankw10;
	extern bool toBankb10;
	extern bool toBankw;
	extern bool toBank9;
	extern bool toBank5;
	//void StealthLoopreall(bool toggle);
	extern void StealthDropintee(bool toggle);
	//extern void StealthDropintee10(bool toggle);
	extern void StealthDropinteeb10(bool toggle);	
	extern void StealthDropinteew10(bool toggle);
	extern void StealthDropintee9(bool toggle);
	extern void StealthDropintee5(bool toggle);
	//void StealthDropinte();

	extern bool spawnincar;
	extern bool spawnmaxed;

	extern bool Sell;
	extern void Sel(bool toggle);

	extern bool clearareabool;
	extern void clearArea(bool toggle);

	extern bool Speedometerbool;
	extern void Speedometer(bool toggle);

	extern bool boundarylimitbool2;
	extern void boundarylimit2(bool toggle);
	//	extern bool Laserbool2;
	//	void Laser2(bool toggle);

		//extern bool nStealthLooptogglerall;
		//void nStealthLoopreall();
		//extern bool nStealthLooptoggler[32];
		//void nStealthLoopre(Player player);
		//till here

		//so your done?

	extern bool ZoneStreetbool;
	extern void ZoneStreet(bool toggle);

	extern float runlevel;
	extern float SwimLevel;
	/*extern int camlevel;
	extern int camlevel2;*/
	extern int BOOSTLEVEL;
	extern int BOOSTLEVEL2;
	extern int camlevel22;
	extern float menuXPositionX;
	extern float zeropointquarantecinq;
	extern float zeropointtrentedeux;

	extern float zeropointcentvingtf;
	extern float zeropointundeuxtroisf;
	extern float zeropointtroiscentsoixantequinzef;

	extern float zeropointhuitcent;
	extern float zeropointmillecentsoixantequinze;
	extern float zeropointvingtetun;

	extern int intexploits;
	extern int intoffensive;
	extern int REPORTSTRENGTH;

	extern int OFFENSIVETAGPLATE;
	extern int OFFENSIVEUGC;
	extern int EXPLOITS;
	extern int GRIEFING;
	extern int COMMENDSTRENGTH;
	extern int FRIENDLY;
	extern int HELPFUL;
	extern int VCANNOYINGME;
	extern int VCHATE;
	extern int BADCREWNAME;
	extern int BADCREWMOTTO;
	extern int BADCREWSTATUS;
	extern int BADCREWEMBLEM;
	extern int ISPUNISHED;

	//void gunmoney(bool toggle);
	extern int MoneyLevelAll;

	extern int driftfront;
	extern int driftbehind;

	extern int torso;
	extern void torser();
	extern int torsotexture;
	extern void torsertexture();
	extern int face;
	extern void facer();
	extern int facetexture;
	extern void facertexture();
	extern int head;
	extern void header();
	extern int headtexture;
	extern void headertexture();
	extern int hair;
	extern void hairer();
	extern int hairtexture;
	extern void hairertexture();
	extern int legs;
	extern void legser();
	extern int legstexture;
	extern void legsertexture();
	extern int hands;
	extern void handser();
	extern int handstexture;
	extern void handsertexture();
	extern int feet;
	extern void feeter();
	extern int feettexture;
	extern void feetertexture();
	extern int eyes;
	extern void eyeser();
	extern int eyestexture;
	extern void eyesertexture();
	extern int accesories;
	extern void accesorieser();
	extern int accesoriestexture;
	extern void accesoriesertexture();
	extern int accesoriessec;
	extern void accesoriesersec();
	extern int accesoriessectexture;
	extern void accesoriesersectexture();
	extern int textures;
	extern void textureser();
	extern int texturestexture;
	extern void texturesertexture();
	extern int torsosec;
	extern void torsersec();
	extern int torsosectexture;
	extern void torsersectexture();

	extern int HeadPropint;
	extern void HeadProp();
	extern int EyePropint;
	extern void EyeProp();
	extern int EarPropint;
	extern void EarProp();

	//extern int SPENTtaxi;
	//extern int SPENTbetting;
	//extern int SPENTstrip;
	//extern int SPENTammo;
	//extern int SPENTheli;
	//extern int SPENTboat;
	//extern int SPENTbull;
	//extern int SPENTcash;
	//extern int SPENTmugger;
	//extern int SPENTrobbed;
	//extern int SPENTmercenary;
	//extern int SPENTwantedlevel;
	//extern int SPENToffradar;
	//extern int SPENTreveal;
	//extern int SPENTcarwash;
	//extern int SPENTcinema;
	//extern int SPENTtelescope;
	//extern int SPENTholdups;
	//extern int SPENTpassive;
	//extern int SPENTprostitutes;
	//extern int SPENTarrestbail;
	//extern int SPENTpayvehicle;
	//extern int SPENTcallplayer;
	//extern int SPENTbounty;
	//extern int SPENTrockstar;
	//extern int SPENThealthcare;
	//extern int SPENTnocops;
	//extern int SPENTrequestjob;
	//extern int SPENTrequesheist;

	extern int zeropointhuitcentt;
	extern int zeropointmillecentsoixantequinzet;
	extern int zeropointvingtetunt;

	extern bool SCRIPT_DATA_VERIFY_EVENT2;
	extern void SCRIPT_DATA_VERIFY_EVENT1(bool t);
	extern bool REQUEST_CONTROL_EVENT2;
	extern void REQUEST_CONTROL_EVENT1(bool t);
	extern bool GIVE_CONTROL_EVENT2;
	extern void GIVE_CONTROL_EVENT1(bool t);
	extern bool WEAPON_DAMAGE_EVENT2;
	extern void WEAPON_DAMAGE_EVENT1(bool t);
	extern bool REQUEST_PICKUP_EVENT2;
	extern void REQUEST_PICKUP_EVENT1(bool t);
	extern bool REQUEST_MAP_PICKUP_EVENT2;
	extern void REQUEST_MAP_PICKUP_EVENT1(bool t);
	/*extern bool GAME_CLOCK_EVENT2;
	extern void GAME_CLOCK_EVENT1(bool t);
	extern bool GAME_WEATHER_EVENT2;
	extern void GAME_WEATHER_EVENT1(bool t);*/
	extern bool RESPAWN_PLAYER_PED_EVENT2;
	extern void RESPAWN_PLAYER_PED_EVENT1(bool t);
	extern bool GIVE_WEAPON_EVENT2;
	extern void GIVE_WEAPON_EVENT1(bool t);
	extern bool REMOVE_WEAPON_EVENT2;
	extern void REMOVE_WEAPON_EVENT1(bool t);
	extern bool REMOVE_ALL_WEAPONS_EVENT2;
	extern void REMOVE_ALL_WEAPONS_EVENT1(bool t);
	extern bool VEHICLE_COMPONENT_CONTROL_EVENT2;
	extern void VEHICLE_COMPONENT_CONTROL_EVENT1(bool t);
	extern bool FIRE_EVENT2;
	extern void FIRE_EVENT1(bool t);
	extern bool EXPLOSION_EVENT2;
	extern void EXPLOSION_EVENT1(bool t);
	extern bool START_PROJECTILE_EVENT2;
	extern void START_PROJECTILE_EVENT1(bool t);
	extern bool UPDATE_PROJECTILE_TARGET_EVENT2;
	extern void UPDATE_PROJECTILE_TARGET_EVENT1(bool t);
	extern bool BREAK_PROJECTILE_TARGET_LOCK_EVENT2;
	extern void BREAK_PROJECTILE_TARGET_LOCK_EVENT1(bool t);
	extern bool REMOVE_PROJECTILE_ENTITY_EVENT2;
	extern void REMOVE_PROJECTILE_ENTITY_EVENT1(bool t);
	extern bool ALTER_WANTED_LEVEL_EVENT2;
	extern void ALTER_WANTED_LEVEL_EVENT1(bool t);
	extern bool CHANGE_RADIO_STATION_EVENT2;
	extern void CHANGE_RADIO_STATION_EVENT1(bool t);
	extern bool RAGDOLL_REQUEST_EVENT2;
	extern void RAGDOLL_REQUEST_EVENT1(bool t);
	extern bool PLAYER_TAUNT_EVENT2;
	extern void PLAYER_TAUNT_EVENT1(bool t);
	extern bool PLAYER_CARD_STAT_EVENT2;
	extern void PLAYER_CARD_STAT_EVENT1(bool t);
	extern bool DOOR_BREAK_EVENT2;
	extern void DOOR_BREAK_EVENT1(bool t);
	extern bool SCRIPTED_GAME_EVENT2;
	extern void SCRIPTED_GAME_EVENT1(bool t);
	extern bool REMOTE_SCRIPT_INFO_EVENT2;
	extern void REMOTE_SCRIPT_INFO_EVENT1(bool t);
	extern bool REMOTE_SCRIPT_LEAVE_EVENT2;
	extern void REMOTE_SCRIPT_LEAVE_EVENT1(bool t);
	extern bool MARK_AS_NO_LONGER_NEEDED_EVENT2;
	extern void MARK_AS_NO_LONGER_NEEDED_EVENT1(bool t);
	extern bool CONVERT_TO_SCRIPT_ENTITY_EVENT2;
	extern void CONVERT_TO_SCRIPT_ENTITY_EVENT1(bool t);
	extern bool SCRIPT_WORLD_STATE_EVENT2;
	extern void SCRIPT_WORLD_STATE_EVENT1(bool t);
	extern bool INCIDENT_ENTITY_EVENT2;
	extern void INCIDENT_ENTITY_EVENT1(bool t);
	extern bool CLEAR_AREA_EVENT2;
	extern void CLEAR_AREA_EVENT1(bool t);
	extern bool CLEAR_RECTANGLE_AREA_EVENT2;
	extern void CLEAR_RECTANGLE_AREA_EVENT1(bool t);
	extern bool REQUEST_NETWORK_SYNCED_SCENE_EVENT2;
	extern void REQUEST_NETWORK_SYNCED_SCENE_EVENT1(bool t);
	extern bool START_NETWORK_SYNCED_SCENE_EVENT2;
	extern void START_NETWORK_SYNCED_SCENE_EVENT1(bool t);
	extern bool STOP_NETWORK_SYNCED_SCENE_EVENT2;
	extern void STOP_NETWORK_SYNCED_SCENE_EVENT1(bool t);
	extern bool UPDATE_NETWORK_SYNCED_SCENE_EVENT2;
	extern void UPDATE_NETWORK_SYNCED_SCENE_EVENT1(bool t);
	extern bool GIVE_PED_SCRIPTED_TASK_EVENT2;
	extern void GIVE_PED_SCRIPTED_TASK_EVENT1(bool t);
	extern bool GIVE_PED_SEQUENCE_TASK_EVENT2;
	extern void GIVE_PED_SEQUENCE_TASK_EVENT1(bool t);
	extern bool CLEAR_PED_TASKS_EVENT2;
	extern void CLEAR_PED_TASKS_EVENT1(bool t);
	extern bool START_NETWORK_PED_ARREST_EVENT2;
	extern void START_NETWORK_PED_ARREST_EVENT1(bool t);
	extern bool START_NETWORK_PED_UNCUFF_EVENT2;
	extern void START_NETWORK_PED_UNCUFF_EVENT1(bool t);
	extern bool NETWORK_CAR_HORN_EVENT2;
	extern void NETWORK_CAR_HORN_EVENT1(bool t);
	extern bool VOICE_DRIVEN_MOUTH_MOVEMENT_FINISHED_EVENT2;
	extern void VOICE_DRIVEN_MOUTH_MOVEMENT_FINISHED_EVENT1(bool t);
	extern bool NETWORK_ENTITY_AREA_STATUS_EVENT2;
	extern void NETWORK_ENTITY_AREA_STATUS_EVENT1(bool t);
	extern bool MODIFY_VEHICLE_LOCK_WORLD_STATE_DATA_EVENT2;
	extern void MODIFY_VEHICLE_LOCK_WORLD_STATE_DATA_EVENT1(bool t);
	extern bool MODIFY_PTFX_WORLD_STATE_DATA_SCRIPTED_EVOLVE_EVENT2;
	extern void MODIFY_PTFX_WORLD_STATE_DATA_SCRIPTED_EVOLVE_EVENT1(bool t);
	extern bool NETWORK_GARAGE_OCCUPIED_STATUS_EVENT2;
	extern void NETWORK_GARAGE_OCCUPIED_STATUS_EVENT1(bool t);
	extern bool PED_CONVERSATION_LINE_EVENT2;
	extern void PED_CONVERSATION_LINE_EVENT1(bool t);
	/*extern bool SET_LOOK_AT_ENTITY2;
	extern void SET_LOOK_AT_ENTITY1(bool t);
	extern bool SET_TASK_VEHICLE_TEMP_ACTION2;
	extern void SET_TASK_VEHICLE_TEMP_ACTION1(bool t);*/
	extern bool SCRIPT_ENTITY_STATE_CHANGE_EVENT2;
	extern void SCRIPT_ENTITY_STATE_CHANGE_EVENT1(bool t);
	extern bool PLAY_SOUND_EVENT2;
	extern void PLAY_SOUND_EVENT1(bool t);
	extern bool STOP_SOUND_EVENT2;
	extern void STOP_SOUND_EVENT1(bool t);
	extern bool NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT2;
	extern void NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT1(bool t);
	extern bool BANK_REQUEST_EVENT2;
	extern void BANK_REQUEST_EVENT1(bool t);
	extern bool REQUEST_DOOR_EVENT2;
	extern void REQUEST_DOOR_EVENT1(bool t);
	extern bool NETWORK_TRAIN_REQUEST_EVENT2;
	extern void NETWORK_TRAIN_REQUEST_EVENT1(bool t);
	extern bool NETWORK_TRAIN_REPORT_EVENT2;
	extern void NETWORK_TRAIN_REPORT_EVENT1(bool t);
	extern bool NETWORK_INCREMENT_STAT_EVENT2;
	extern void NETWORK_INCREMENT_STAT_EVENT1(bool t);
	extern bool REQUEST_PHONE_EXPLOSION_EVENT2;
	extern void REQUEST_PHONE_EXPLOSION_EVENT1(bool t);
	extern bool REQUEST_DETACHMENT_EVENT2;
	extern void REQUEST_DETACHMENT_EVENT1(bool t);
	extern bool KICK_VOTES_EVENT2;
	extern void KICK_VOTES_EVENT1(bool t);
	extern bool NETWORK_GIVE_PICKUP_REWARDS_EVENT2;
	extern void NETWORK_GIVE_PICKUP_REWARDS_EVENT1(bool t);
	extern bool NETWORK_CRC_HASH_CHECK_EVENT2;
	extern void NETWORK_CRC_HASH_CHECK_EVENT1(bool t);
	extern bool BLOW_UP_VEHICLE_EVENT2;
	extern void BLOW_UP_VEHICLE_EVENT1(bool t);
	extern bool ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT2;
	extern void ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT1(bool t);
	extern bool NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON2;
	extern void NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON1(bool t);
	extern bool NETWORK_RESPONDED_TO_THREAT_EVENT2;
	extern void NETWORK_RESPONDED_TO_THREAT_EVENT1(bool t);
	extern bool NETWORK_SHOUT_TARGET_POSITION_EVENT2;
	extern void NETWORK_SHOUT_TARGET_POSITION_EVENT1(bool t);
	extern bool PICKUP_DESTROYED_EVENT2;
	extern void PICKUP_DESTROYED_EVENT1(bool t);
	extern bool UPDATE_PLAYER_SCARS_EVENT2;
	extern void UPDATE_PLAYER_SCARS_EVENT1(bool t);
	extern bool NETWORK_CHECK_EXE_SIZE_EVENT2;
	extern void NETWORK_CHECK_EXE_SIZE_EVENT1(bool t);
	/*extern bool NETWORK_INFO_CHANGE_EVENT2;
	extern void NETWORK_INFO_CHANGE_EVENT1(bool t);*/
	extern bool NETWORK_PTFX_EVENT2;
	extern void NETWORK_PTFX_EVENT1(bool t);
	extern bool PED_SEEN_DEAD_PED_EVENT2;
	extern void PED_SEEN_DEAD_PED_EVENT1(bool t);
	extern bool REMOVE_STICKY_BOMB_EVENT2;
	extern void REMOVE_STICKY_BOMB_EVENT1(bool t);
	extern bool INFORM_SILENCED_GUNSHOT_EVENT2;
	extern void INFORM_SILENCED_GUNSHOT_EVENT1(bool t);
	extern bool PED_PLAY_PAIN_EVENT2;
	extern void PED_PLAY_PAIN_EVENT1(bool t);
	extern bool CACHE_PLAYER_HEAD_BLEND_DATA_EVENT2;
	extern void CACHE_PLAYER_HEAD_BLEND_DATA_EVENT1(bool t);
	extern bool REMOVE_PED_FROM_PEDGROUP_EVENT2;
	extern void REMOVE_PED_FROM_PEDGROUP_EVENT1(bool t);
	/*extern bool UPDATE_FXN_EVENT2;
	extern void UPDATE_FXN_EVENT1(bool t);*/
	extern bool REPORT_CASH_SPAWN_EVENT2;
	extern void REPORT_CASH_SPAWN_EVENT1(bool t);
	/*extern bool BLOCK_WEAPON_SELECTION2;
	extern void BLOCK_WEAPON_SELECTION1(bool t);
	extern bool NETWORK_CHECK_CATALOG_CRC2;
	extern void NETWORK_CHECK_CATALOG_CRC1(bool t);*/
	/*extern bool REQUESTING_CONTROL2;
	extern void REQUESTING_CONTROL1(bool t);
	extern bool DESTROYING_EVENT2;
	extern void DESTROYING_EVENT1(bool t);*/

	extern int rr, gg, bb, aa;
	extern int rr5, gg5, bb5, aa5;
	extern int rw, gw, bw;

	extern int rw1, gw1, bw1;
	extern int rw2, gw2, bw2;
	extern int rrr;
	extern int ggg;
	extern int bbb;
	extern int aaa;

	extern int rr2;
	extern int gg2;
	extern int bb2;
	extern int aa2;

	/*extern int vkmultiply;*/

	extern int raindelay;

	extern int Scroller1;
	extern int Scroller2;
	extern int Scroller3;
	extern int Scroller4;

	extern bool scroller0;
	extern void scrollers(bool toggle);

	extern float zeropointhuitcenttt;
	extern float zeropointmillecentsoixantequinzettt;
	extern float zeropointvingtetunttt;
	extern float zeropointzeroquatrevingtcinq;
	extern float zerooo;
	extern int cinquanteee;
	extern int deuxcentcinquantecinqun;
	extern int deuxcentcinquantecinqdeux;
	extern int deuxcentcinquantecinqtrois;

	extern bool header0;
	extern void header01(bool toggle);
	extern bool header02;
	extern void header03(bool toggle);
	extern bool header04;
	extern void header05(bool toggle);

	extern bool header10;
	extern void header011(bool toggle);
	extern bool header012;
	extern void header013(bool toggle);
	extern bool header014;
	extern void header015(bool toggle);
	extern bool rgbdeuxcentcinquantecinq;
	extern void rgbdeuxcentcinquantecinqs(bool toggle);
	extern int rgb1, rgb2, rgb3;

	extern bool heatvision;
	extern void heatvisions(bool toggle);

	extern bool titlestext;
	extern void titlestextes(bool toggle);

	extern int title1;
	extern int title2;
	extern int title3;
	extern int title4;
	extern int title5;

	extern int optionText3;
	extern int optionText4;
	extern int optionText5;
	extern int optionText6;
	extern int optionText7;

	extern bool optionText1;
	extern void optionText2(bool toggle);

	extern bool optionText1bool;
	extern void optionText2bool(bool toggle);

	extern bool titlestextbool;
	extern void titlestextesbool(bool toggle);

	extern bool scroller0bool;
	extern void scrollersbool(bool toggle);

	extern int submenustyle;

	//extern int ExploCh;
	//extern bool vehbypass;
	//void bypassveh(bool toggle);

	//extern bool vehbypass2;
	//void bypassveh2(bool toggle);
	//void BypassOnlineVehicleKick();
	//extern bool BypassOnlineVehicleKick1;
	//void BypassOnlineVehicleKick(Vehicle vehicle);
	extern int alldropint;
	extern bool alldrop[32];
	extern void alldrops(Player target);

	extern int allrainint;
	extern bool allrain[32];
	extern void allrains(Player target);

	extern bool dropweapon[32];
	extern void dropweapons(Player target);
	extern bool dropweapon2[32];
	extern void dropweapons2(Player target);

	extern bool dropplayer[32];
	extern void dropplayers(Player target);
	extern bool dropvehicle[32];
	extern void dropvehicles(Player target);

	extern bool shootmaxvehicle;
	extern void shootmaxvehicles(bool toggle);
	extern int weaponscarsis;
	extern int weaponscarswillbe;
	extern bool shootmaxvehicle2;
	extern void shootmaxvehicles2(bool toggle);
	//extern void gameCycle();

	extern int FPStimes;
	extern int FPS;

	extern bool allcar2;
	extern void allcars2(bool toggle);

	extern bool arenawar;
	extern void arenawarr(bool toggle);

	extern bool showback;
	extern void showback1(bool toggle);

	extern bool ThunderLog;
	extern void LogThunder(bool toggle);
	/*extern int timeslobby1, timeslobby2, timeslobby3;
	extern void Hours();
	extern bool lobbytimes2;
	void lobbytimes3(bool toggle);*/
	/*extern bool NoClips2;*/

	extern int waveofban;
	extern int banwave(bool toggle);
	extern bool waveban;
	extern void ForceKick(int selectedPlayer);
	extern void nonhostkick(int selectedPlayer);
	extern void nonhostkickns(int selectedPlayer);
	extern void ceobansss(int selectedPlayer);
	extern void ceokicksss(int selectedPlayer);
	/*extern void ceobanno(int selectedPlayer);
	extern void ceokickno(int selectedPlayer);*/
	extern void kicksingles(int selectedPlayer);
	extern void InfiniteLoadingScreen(int selectedPlayer);
	extern void SendBounty(int selectedPlayer);
	extern void turnbountybool();
	//extern int timersecondsbounty;
	extern int bountytimerseconds;
	extern bool SendBountyALLbool;
	extern void SendBountyALLvoid();
	extern void AllSendBounty();
	extern bool all;
	extern void Send10k(int selectedPlayer);
	extern void SendInsuranceMessage(int selectedPlayer);
	extern void SendRemovedMoneyMessage(int selectedPlayer);
	extern void SendSpectatingMessage(int selectedPlayer);
	extern void SendToJob(int selectedPlayer);
	extern void SendToJobAll(int selectedPlayer, int mission);
	extern void SendTransactionError(int selectedPlayer);
	extern void ShowBanner(int selectedPlayer);	
	extern bool pLobby;
	extern void privateLobby(bool t);
	extern bool CheckWord(char* filename, char* search);
	extern void write(std::string path, std::string content);
	extern void kick_sp(int selectedPlayer);
	extern void kick_sp2(bool t);
	extern void kick_(int selectedPlayer);
	extern void kick_2(bool t);
	extern void teleportsPLAYER();
	extern void teleports(int selectedPlayer);
	extern void teleports2(int selectedPlayer);

	/*extern bool vkdecimal;
	extern void vkdecimals(bool toggle);
	extern bool vkadd;
	extern void vkadds(bool toggle);
	extern bool vkdivide;
	extern void vkdivides(bool toggle);
	extern bool vkcontrol;
	extern void vkcontrols(bool toggle);
	extern bool vksubstract;
	extern void vksubstracts(bool toggle);
	extern bool vkf1;
	extern void vkf1l(bool toggle);
	extern bool vkf2;
	extern void vkf2l(bool toggle);
	extern bool vkf3;
	extern void vkf3l(bool toggle);
	extern bool vkf4;
	extern void vkf4l(bool toggle);
	extern bool vkf5;
	extern void vkf5l(bool toggle);
	extern bool vkf6;
	extern void vkf6l(bool toggle);
	extern bool vkf7;
	extern void vkf7l(bool toggle);
	extern bool vkf8;
	extern void vkf8l(bool toggle);
	extern bool vkf9;
	extern void vkf9l(bool toggle);
	extern bool vkf10;
	extern void vkf10l(bool toggle);
	extern bool vkf11;
	extern void vkf11l(bool toggle);
	extern bool vkf12;
	extern void vkf12l(bool toggle);
	extern bool vkmenu;
	extern void VKMENUl(bool toggle);
	extern bool vknumpad1;
	extern void VKNUMPAD1l(bool toggle);
	extern bool vknumpad3;
	extern void VKNUMPAD3l(bool toggle);
	extern bool vknumpad7;
	extern void VKNUMPAD7l(bool toggle);
	extern bool vknumpad9;
	extern void VKNUMPAD9l(bool toggle);
	extern bool vkback;
	extern void VKBACKl(bool toggle);*/

	extern void ceokicks(int selectedPlayer);
	extern void ceokicks2(int selectedPlayer);
	extern void ceokicks2(bool t);
	extern void ceobans(int selectedPlayer);
	extern void ceobans2(bool t);
	extern void transactionserror(int selectedPlayer);
	extern bool errorsend[32];
	extern bool activatetransactionserrorbool[32];
	extern void transactionserrorbool(bool togglesend);
	extern void transactionserror2(bool t);
	/*extern void showbanner(int selectedPlayer);*/
	extern void ceokickwithnotification(int selectedPlayer);
	extern void ceobanwithnotification(int selectedPlayer);
	/*extern void invitation(int selectedPlayer);*/

	extern void soundspams1(int selectedPlayer);
	extern void soundspams2(int selectedPlayer);
	extern void soundspams3(int selectedPlayer);
	extern void soundspams4(int selectedPlayer);
	extern void soundspams5(int selectedPlayer);
	extern void soundspams6(int selectedPlayer);
	extern 	void sendtomissions1(int selectedPlayer);
	extern 	void sendtomissions2(int selectedPlayer);
	extern 	void sendtomissions3(int selectedPlayer);
	extern 	void sendtomissions4(int selectedPlayer);
	extern 	void sendtomissions5(int selectedPlayer);
	extern 	void sendtomissions6(int selectedPlayer);
	extern 	void sendtomissions7(int selectedPlayer);
	extern 	void sendtomissions8(int selectedPlayer);
	extern 	void sendtomissions9(int selectedPlayer);
	extern 	void sendtomissions10(int selectedPlayer);
	extern 	void sendtomissions11(int selectedPlayer);
	extern 	void sendtomissions12(int selectedPlayer);
	extern 	void sendtomissions13(int selectedPlayer);
	extern 	void sendtomissions14(int selectedPlayer);
	extern 	void sendtomissions15(int selectedPlayer);
	extern void privateLobby2(bool t);
	extern int allteleports;
	extern int allteleports2;
	extern void teleportsall(int selectedPlayer);

	extern void newhostkick(int selectedPlayer);
	extern void rotatecam(int selectedPlayer);
	extern void bankedmoney(int selectedPlayer);
	extern void withdrawmoney(int selectedPlayer);
	extern void stolenmoney(int selectedPlayer);
	extern int ammount;
	extern void sendbanner(int selectedPlayer);
	extern void vehiclekick(int selectedPlayer);

	extern void newone(int selectedPlayer);
	extern void newtwo(int selectedPlayer);
	extern void newthree(int selectedPlayer);
	extern void newfour(int selectedPlayer);
	extern void newfive(int selectedPlayer);
	extern void newsix(int selectedPlayer);
	extern void newseven(int selectedPlayer);
	extern void neweight(int selectedPlayer);
	extern void newnine(int selectedPlayer);
	extern void newten(int selectedPlayer);

	/*extern void newhostkick2(int selectedPlayer);*/
	/*extern void rotatecam2(int selectedPlayer);*/
	/*extern void bankedmoney2(int selectedPlayer);
	extern void withdrawmoney2(int selectedPlayer);
	extern void stolenmoney2(int selectedPlayer);*/
	/*extern int ammount2;
	extern void sendbanner2(int selectedPlayer);*/
	/*extern void vehiclekick2(int selectedPlayer);
	extern void newone2(int selectedPlayer);
	extern void newtwo2(int selectedPlayer);
	extern void newthree2(int selectedPlayer);
	extern void newfour2(int selectedPlayer);
	extern void newfive2(int selectedPlayer);
	extern void newsix2(int selectedPlayer);
	extern void newseven2(int selectedPlayer);
	extern void neweight2(int selectedPlayer);
	extern void newnine2(int selectedPlayer);
	extern void newten2(int selectedPlayer);*/

	bool is_ped_shooting(Ped ped);

	struct IPAddress
	{
		union
		{
			struct
			{
				std::uint8_t four;
				std::uint8_t three;
				std::uint8_t two;
				std::uint8_t one;
			} fields;

			std::uint32_t packed;
		};
	};
	extern bool IsPlayerFriend(Player player);
	/*extern bool IsPlayerInvincible(Player player);
	extern bool IsPlayerInGodmode(Ped handle);	*/
	//link-https://www.unknowncheats.me/forum/grand-theft-auto-v/144819-grand-theft-auto-scripting-78-print.html
	//namespace playerMenu {
	//	extern void setFrameFlag(uint32_t flag);
	//}

	extern bool savenewdrop23[32];
	void cashdrop23(Player target);
	extern bool savenewdrop222[32];
	void cashdrop222(Player target);
	extern bool savenewdrop2222[32];
	void cashdrop2222(Player target);
	extern int DropAmount;
	extern int DropHeight;
	extern int DropDelay;
	extern int Bags;
	extern Hash bagHash;
	extern bool DropAll20;
	void dropAll2();
	extern bool DropAll0;
	void dropAll();
	extern bool alldropv20;
	extern void alldropsv2();

	extern bool menucolors;
	extern void menucolor(bool toggle);

	extern bool protectv2;
	extern void allprotectv2(bool toggle);
	extern bool allrainy;
	extern void rainsall();
	extern bool alldropv22[32];
	extern void alldropsv22(Player target);

	extern bool dropbool;
	extern void dropbools(bool toggle);
	extern char* nameEffect;
	extern bool boostboolb;
	extern bool screeneffect;
	extern void carboostb(bool toggle);
	extern int modkit;
	extern int bennysok;
	extern int bennystypeok;

	extern int xdrop1;
	extern int xdrop2;
	extern int xdrop3;
	extern int xdrop4;
	extern int xdrop5;
	extern int xdrop6;
	extern int xdrop7;
	extern int xdrop8;

	extern int paintcolor01;
	extern int paintcolor02;
	extern int paintcolor03;
	extern int chrome;
	//extern int CustomMod5;

	extern int hornsound;

	extern bool cloneProtection;
	extern bool crashProtection;
	extern bool crashProtectionv2;

	extern void CrashPlayer(Player selectedPed);
	extern void CrashPlayer2(Player selectedPed);
	extern void CloneProtection();
	extern void AntiCrash();
	extern void antiCrashV2();
	extern bool aimbottoggle;
	extern void aimbot(bool toggle);
	extern bool aimbottoggle2;
	extern void aimbot2(bool toggle);
	extern bool Trigger;
	extern void Triggerbot();

	/*extern int saveoptions();*/
	extern bool CustomCar;
	extern void CustomCars(bool toggle);
	/*extern int saveoptions2();*/

	extern float deuxzerosepthuit;
	extern float zerounquatredeux;
	extern float deuxzeroquinze;
	extern float deuxzerodeuxsept;

	extern bool selecArrow;
	extern void selecArrows(bool toggle);

	extern bool CartoonGun;
	extern void CartoonGuns(bool toggle);

	extern bool LagueGun;
	extern void LagueGuns(bool toggle);
	
	extern bool effectshoot;
	extern void effectshoots(bool toggle);

	/*extern bool noclip2;
	extern void noclips2(bool toggle);*/
	extern std::string myIPSelected;
	extern std::string IPSelected;
	extern std::string UserId;
	//extern float zeropointcentsoixantequinze;
	//extern float zeropointzeroquatrevinghtdix;
	//extern float zeropointquatrecentvingtcinq;
	//extern float zeropointmillecentsoixantequinzee;
	//extern float zeropointzerodixneuf;
	//extern float zeropointcentquinze;
	//extern float zeropointzeroquarantecinq;
	//extern int centquatrevingt;
	//extern float zeropointdeuxcentquatrevingtquinze;
	//extern int seize;
	//extern float zeropointzerotrentecinq;
	//extern float deuxpointzeroo;
	//extern float zeropointcentcinquanteneuf;
	//extern float zeropointcenttrentecinq;
	//extern float zeropointcentvingtcinq;
	//extern float zeropointcentquatrevingttreize;
	//extern float zeropointdeuxcentvingthuit;
	//extern float zeropointcentvingt;
	//extern float zerozerovingt;
	//extern float centvingttrois;
	//extern float zeropointtroiscentsoixtantequinze;
	extern std::string username;
	extern void namechanged();
	/*extern void memoryChangeName(std::string& name);*/
	extern void SetName(const std::string& name);
	extern bool GeoLocation;
	void GeoLocalisation(Player target);
	/*extern bool apikey1;
	extern void keyapi1();
	extern bool apikey2;
	extern void keyapi2();
	extern bool apikey3;
	extern void keyapi3();
	extern bool apikey4;
	extern void keyapi4();
	extern bool apikey5;
	extern void keyapi5();
	extern bool apikey6;
	extern void keyapi6();
	extern bool apikey7;
	extern void keyapi7();
	extern bool apikey8;
	extern void keyapi8();
	extern bool apikey9;
	extern void keyapi9();
	extern bool apikey10;
	extern void keyapi10();
	extern bool apikey11;
	extern void keyapi11();
	extern bool apikey12;
	extern void keyapi12();
	extern bool apikey13;
	extern void keyapi13();
	extern bool apikey14;
	extern void keyapi14();
	extern bool apikey15;
	extern void keyapi15();

	extern bool apikeyIPAPI;
	extern void keyapiIPAPI();*/
	extern int testmoney;
	extern bool vipplus;

	extern bool casino;
	extern void casinos(bool toggle);

	extern bool cayoss;
	extern void cayospericos(bool toggle);

	extern bool showall;
	extern void showallplayers(bool toggle);
	extern void playeroffradar(int selectedPlayer);
	extern void spectatemessages(int selectedPlayer);
	extern void clearwantedlevel(int selectedPlayer);
	extern void remotebribe(int selectedPlayer);
	extern bool despawndlc;
	extern void mpinspdlc(bool toggle);
	extern bool sp_vehicle_bypass;
	extern void mpinsp(bool toggle);

	extern bool savenewdropeggs[32];
	extern void cashdropeggs(Player target);

	extern bool savenewdropweeds[32];
	extern void cashdropweeds(Player target);
	extern bool savenewdropweeds2[32];
	extern void cashdropweeds2(Player target);
	extern bool singlerosebool;/*[32]*/
	extern void singlerosevoid();/*Player player*/

	extern float floatone;
	extern float floattwo;
	extern float floatthree;
	extern float floatfour;
	extern float floatfive;
	extern float floatsix;
	extern float floatseven;

	/*extern int intautoheal;
	extern int intautoheal1;
	extern int intautoheal2;
	extern float floatautoheal;
	extern float floatautoheal1;*/

	extern bool free_cam;
	extern void freecam0(bool toggle);
	extern float noclipspeed;
	extern int noclipspeed2;
	extern bool noclipinvis;
	extern bool noclipattackmode;
	extern bool Flex0;
	extern void Flex1(bool toggle);

	namespace Online 
	{
		extern int selectedPlayer;
		extern int blamePlayer;
		extern void TeleportToPlayer(Player player);
		/*extern void TeleportIntoVehicle(Player player);*/
		/*extern void TeleportVehicleToMe(Player player);*/
		/*extern void TeleportVehicleToMe2(Player player);*/
	}
	/*extern bool playerone25;
	extern bool playertwo25;
	extern bool playerthree25;
	extern bool playerfour25;
	extern bool playerfive25;
	extern bool playersix25;
	extern bool playerseven25;
	extern bool playereight25;
	extern bool playernine25;
	extern bool playerten25;
	extern bool playereleven25;
	extern bool playertwelve25;
	extern bool playerthirteen25;
	extern bool playerfourteen25;
	extern bool playerfifteen25;
	extern bool playersixteen25;
	extern bool playerseventeen25;
	extern bool playereighteen25;
	extern bool playernineteen25;
	extern bool playertwenty25;
	extern bool playertwentyone25;
	extern bool playertwentytwo25;
	extern bool playertwentythree25;
	extern bool playertwentyfour25;
	extern bool playertwentyfive25;
	extern bool playertwentysix25;
	extern bool playertwentyseven25;
	extern bool playertwentyeight25;
	extern bool playertwentynine25;
	extern bool playerthirty25;*/
	extern int playerme;
	extern std::string weaponscars;
	extern float vehicleBulletX;
	extern float vehicleBulletY;

	extern std::string wepsshoot;
	extern std::string shooteffect;
	extern std::string shooteffects;

	extern bool wepshoot;
	extern void wepshots(bool toggle);

	extern void playerid();

	extern float onefloat;
	extern float twofloat;
	extern float threefloat;
	extern float fourfloat;
	extern float fivefloat;
	extern float sixfloat;
	extern float sevenfloat;

	/*extern bool xenon;
	extern void xenons(bool toggle);

	extern bool xenon2;
	extern void xenons2(bool toggle);

	extern bool xenon3;
	extern void xenons3(bool toggle);*/
	extern int vehicleheadlight;

	extern bool mainprotection;
	extern void mainprotections(bool toggle);

	extern bool onlineplayer;

	extern bool infoplayer;
	extern void infoplayers(bool toggle);

	/*extern bool noclip_;
	extern void noclip3(bool inVehicle);*/

	extern float screenX;
	extern float screenY;
	extern float width;
	extern float height;
	extern float heading;
	extern int red;
	extern int green;
	extern int blue;
	extern int alpha;

	extern void DownloadMp3(const std::string title);

	/*extern bool stoppednoclip;*/
	extern bool loop_no_clip;
	extern bool loop_no_clip_toggle;
	extern void set_no_clip();
	extern void set_no_clip_off1();
	extern void set_no_clip_off2();

	extern bool bit_noclip_show_help;

	extern void PrintBottomCentre(const std::string& s, int time = 2500);
	extern void PrintBottomCentre(std::ostream& s, int time = 2500);
	extern void PrintBottomCentre(std::wostream& s, int time = 2500);

	extern bool misc_freecam_on;
	extern bool misc_freecam_off;

	extern bool stoppedglare;
	extern void glare_test();
	extern bool NoclipsFree;

	extern void Bodyguard(char* model);

	extern std::string hudcolor1;
	extern std::string hudcolor2;
	extern std::string hudcolor01;
	extern std::string hudcolor02;

	extern std::string Notify;
	extern std::string Sounds1;
	extern std::string Sounds2;

	extern float titleRectrr;
	extern float titleRectgg;
	extern float titleRectbb;
	extern float titleRectaa;
	extern float titleRectrrr;
	extern float titleRectggg;
	extern float titleRectbbb;
	extern float titleRectaaa;


	extern float optionsRectrr5;
	extern float optionsRectgg5;
	extern float optionsRectbb5;
	extern float optionsRectrr2;
	extern float optionsRectgg2;
	extern float optionsRectbb2;
	extern float optionsRectaa2;
	extern float optionTextrw2;
	extern float optionTextgw2;
	extern float optionTextbw2;
	extern float optionText33;
	extern float optionText44;
	extern float optionText55;
	extern float optionText66;
	extern float optionText77;
	extern float Scrollerrw;
	extern float Scrollergw;
	extern float Scrollerbw;
	extern float Scroller11;
	extern float Scroller22;
	extern float Scroller33;
	extern float Scroller44;
	extern float titleTextrw1;
	extern float titleTextgw1;
	extern float titleTextbw1;
	extern float titleText1;
	extern float titleText2;
	extern float titleText3;
	extern float titleText4;
	extern float titleText5;

	extern std::string HeaderMenu;
	extern std::string HeaderMenu2;

	extern bool titleRect;
	extern bool optionRect;
	extern bool RGBSCROLLER;
	extern bool RGBTITLE;
	extern bool RGBTEXTE;

	/*extern Vector21 menuPos;*/
	extern void add_text_component_long_string(const std::string& text);
	extern INT16 bind_no_clip;

	extern bool rpgiftbool[32];
	extern void rpgiftvoid(Player target);
	extern bool rpgiftbool1[32];
	extern void rpgiftvoid1(Player target);
	extern bool rpgiftbool2[32];
	extern void rpgiftvoid2(Player target);
	extern bool giftrpallbool;
	extern void giftrpallvoid();
	extern bool moneygiftrpallbool;
	extern void moneygiftrpallvoid();
	extern bool giftstatuebool;
	extern void giftstatuevoid();
	extern bool giftstatuebool2;
	extern void giftstatuevoid2();
	extern bool statuebool1[32];
	extern void statuevoid1(Player target);
	extern bool moneystatuebool1[32];
	extern void moneystatuevoid1(Player target);
	extern bool statuebool2[32];
	extern void statuevoid2(Player target);
	extern bool statuebool3[32];
	extern void statuevoid3(Player target);
	extern bool statuebool4[32];
	extern void statuevoid4(Player target);
	extern bool statuebool5[32];
	extern void statuevoid5(Player target);
	extern bool statuebool11[32];
	extern void statuevoid11(Player target);
	extern bool statuebool21[32];
	extern void statuevoid21(Player target);
	extern bool statuebool31[32];
	extern void statuevoid31(Player target);
	extern bool statuebool41[32];
	extern void statuevoid41(Player target);
	extern bool statuebool51[32];
	extern void statuevoid51(Player target);
	extern bool boolsnack[32];
	extern void voidsnack(Player target);
	extern int posx;
	extern int posy;
	extern int posz;
	extern int pospitch;
	extern int posroll;
	extern int posyaw;
	extern int attachobj2[100];
	extern int nuattach2;
	extern void attachobjects22(char* object);
	extern int posx2;
	extern int posy2;
	extern int posz2;
	extern int pospitch2;
	extern int posroll2;
	extern int posyaw2;
	extern int posx2a;
	extern int posy2a;
	extern int posz2a;
	extern int pospitch2a;
	extern int posroll2a;
	extern int posyaw2a;
	extern int attachobja2[100];
	extern int nuattacha2;
	extern void attachobjects22a(char* object);
	extern bool loop_self_deleteGun;
	extern void set_self_deleteGun();
	extern bool loop_self_resurrectionGun;
	extern void set_self_resurrectionGun();
	extern bool onlinemenuplayerlist;
	extern bool MatrixPlates;
	extern void MatrixPlate();
	extern bool InvisibleCarBool;
	extern void InvisibleCar(bool toggle);
	/*extern void SetLobbyTime(int hr, int min, int sec);*/
	/*extern bool TimeSpamBool;*/
	/*extern void TimeSpam();*/
	extern bool SnowLocal;
	extern void LocalSnow();
	extern int snowonoff();
	extern int vehicle_fly_speed;
	extern bool vehi_fly;
	extern void unfreeze_vehicle();
	extern void vehicle_fly(bool toggle);
	extern int travelSpeed;
	extern bool flyingcars_;
	extern void _FlyingCars(bool toggle);
	/*extern bool noclipbool;
	extern int camlevelint;
	extern void noclipvoid(bool toggle);*/
	extern bool noragsdoll;
	extern void noragdoll(bool toggle);

	/*extern void SaveOutfit(std::string name);
	extern void *LoadOutfit(std::string name);*/
	/*extern std::vector<std::string> list;
	extern std::vector<std::string> ListOutfit;
	extern std::vector<std::string> listoutfit();*/

	/*extern int testa;
	extern int testb;
	extern int testc;
	extern int testd;
	extern int teste;
	extern int testf;
	extern int testg;
	extern int testh;
	extern int testi;
	extern int testj;
	extern int testk;
	extern int testl;
	extern int testm;
	extern int testn;
	extern int testo1;
	extern std::size_t ListPos1;*/

	extern int tireSmokeColor3;
	extern int tireSmokeColor2;
	extern int tireSmokeColor1;
	extern int pearlescentColor;
	extern int wheelColor;
	extern bool smoketyrebool;
	extern void smoketyrevoid(bool toggle);
	extern bool Rainb2;
	extern void Rainbow2(bool toggle);
	extern bool Rcolor2;
	extern void RainbowColor2(bool toggle);
	extern bool Rneon2;
	extern void RainbowNeon2(bool toggle);
	extern bool Staminabool;
	extern void Stamina(bool toggle);
	extern int changeint;
	extern bool InvisibleMoves;
	extern bool disallowNewEntity;
	extern bool newblackhole;
	extern void AttractToMe();
	extern int RequestTimes;
	extern int BlackHoleZ;
	extern float blackheigh;
	extern float blackwidth;
	extern float blacklength;
	extern bool mypositionblack;
	extern bool playerpositionblack;
	extern bool coordonate;
	extern float coordonatex;
	extern float coordonatey;
	extern float coordonatez;
	extern bool getfirstcoordbool;
	extern void getblackcoord();
	extern void getblackcoord1();
	extern void getblackcoord2();
	extern void getblackcoord3();
	extern void BlackHole();
	extern Object blacklatest;
	extern Object blacklatest2;
	extern float blackMoveX2;
	extern float blackMoveY2;
	extern float blackMoveZ2;
	extern float blackroll12;
	extern float blackyaw12;
	extern float blackpitch12;
	extern void objectBlack();
	extern bool EasyWayOutbool;
	extern void EasyWayOutvoid(bool toggle);
	extern bool PassiveModebool;
	extern void PassiveModevoid(bool toggle);
	extern int test_value;
	extern void car_club_level();
	extern void send_off_the_radar_dispatch(int target);
	extern void sendtoisland(int Handle);
	extern void Sendtoisland1(int selectedPlayer);
	/*extern void send_to_island(bool position);*/
	/*extern void sendtoisland0(int Handle);*/
	extern void give_never_wanted_dispatch(int target);
	extern bool multiplystockbool;
	extern void multiplystockvoid();
	extern bool Cocainebool;
	extern void Cocainevoid();
	extern bool Cocainebool2;
	extern void Cocainevoid2();
	extern int DrugValue;
	/*extern void remotecrash(int selectedPlayer);
	extern void clubkick(int selectedPlayer);*/
	extern void session_starter();
	extern bool activeboolall;
	extern void send_off_the_radar_dispatch_all();
	extern void remote_level_cops(int selectedPlayer);
	extern void ped_dropper();
	extern void ballistic_armor();
	extern int ballistic_armor_value;
	extern void loadSession(int id);
	extern void NeverWanted(int selectedPlayer);
	extern int AllNeverWanted();
	/*extern void Bounty()*/;
	extern bool allneverwantedplayer;
	extern bool neverwantedplayer[32];
	extern bool ChangedAllPed[32];
	extern void ChangeAllPed(bool toggle);
	extern bool featureWalk1;
	extern int featureWalkk1(bool toggle);
	extern float objectx;
	extern float objecty;
	extern float objectz;
	extern float objectpitch;
	extern float objectroll;
	extern float objectyaw;
	extern int rotationOrder;
	extern char* Driveinairdword;
	extern char* walkinairdword;
	extern bool walkinairvisible;
	extern float Normal;
	extern float Down;
	extern float Up;
	extern float Vehicular;
	extern Vector3 CombineVector(float x, float y, float z);
	extern float millesfloatair;
	extern float quatrefloatair;
	extern float deuxfloatair;
	extern float cinquantefloatair;
	extern float unpointcinqfloatair;
	extern bool dowboolair;
	extern void DriveOnair(bool toggle);
	extern bool incars;
	extern bool ifwalkorincar;
	extern int checkifwalk(char* ObjectName);
	extern bool Lupbool;
	extern int Lupint();
	extern bool Lupbool2;
	extern int Lupint2();
	extern bool timerchangebool;
	extern int timerchange;
	extern void ChangePlayerModels1(int a1);
	extern bool ChangePlayerModelsbool1[32];
	extern void ChangePlayerModels2(int a1);
	extern bool ChangePlayerModelsbool2[32];
	extern void ChangePlayerModels3(int a1);
	extern bool ChangePlayerModelsbool3[32];
	extern void ChangePlayerModels4();
	extern bool ChangePlayerModelsbool4;
	extern void ChangePlayerModels(int a1);
	extern bool ChangePlayerModelsbool[32];
	extern void ChangePlayerModelsall();
	extern bool ChangePlayerModelsboolall;
	extern void ChangePlayerModelsall1();
	extern bool ChangePlayerModelsboolall1;
	extern void ChangePlayerModelsall2();
	extern bool ChangePlayerModelsboolall2;
	extern void ChangePlayerModelsall3();
	extern bool ChangePlayerModelsboolall3;
	extern int mpglobal3();
	extern int mpglobal2();
	extern int mpglobal1();
	extern int mpglobal();
	extern bool mpglobalbool3;
	extern bool activateInfo;
	extern bool maxspeed;
	extern int maxspeedint;
	extern bool maxallcarnearbool;
	extern int maxallcarnear();
	extern int attachs[100];
	extern int attachped;
	extern int particletimes;
	extern bool particlebool;
	extern bool particlebool2;
	extern int timerpaticle();
	extern int timerpaticle2();
	extern int fireexplosionparticle();
	extern int fireexplosionparticle2();
	extern int particleheight;
	extern int particleheightmin;
	extern int particleheightmax;
	extern bool turnupdownparticle;
	extern bool turnupparticle;
	extern int paticleupdown();
	extern int particlerheight;
	extern int particlerheightmin;
	extern int particlerheightmax;
	extern bool turnrupdownparticle;
	extern bool turnrupparticle;
	extern int paticlerupdown();

	extern int particleheight2;
	extern int particleheightmin2;
	extern int particleheightmax2;
	extern bool turnupdownparticle2;
	extern bool turnupparticle2;
	extern int paticleupdown2();
	extern int particlerheight2;
	extern int particlerheightmin2;
	extern int particlerheightmax2;
	extern bool turnrupdownparticle2;
	extern bool turnrupparticle2;
	extern int paticlerupdown2();
	extern float gravityspeed;
	///*extern Vector33 CombineVector(float x, float y, float z);*/
}

namespace MenuFX
{
	extern int particles();
	extern int particles2();
	extern int particleFXMENU();
}
namespace ParticleFX
{
	extern bool particlefxbool;
	extern int particlefxloop();
	extern float x;
	extern float y;
	extern float z;
	extern float rotx;
	extern float roty;
	extern float rotz;
	extern float scale;
}

namespace particle
{
	extern bool auraglimmer;
	extern int auraincrement;
	extern float incrementaura;
	extern float auraradius;
	extern float auraZ;
	extern int auratype;
	extern float auraexplosion;
	extern bool audible;
	extern bool visible;
	extern float camerashake;
	extern int auraspeed;

	extern bool auraglimmer2;
	extern int auraincrement2;
	extern float incrementaura2;
	extern float auraradius2;
	extern float auraZ2;
	extern int auratype2;
	extern float auraexplosion2;
	extern bool audible2;
	extern bool visible2;
	extern float camerashake2;
	extern int auraspeed2;
}

#define M_PI       3.14159265358979323846
#define DEG2RAD( x ) ( ( float )( x ) * ( float )( ( float )( M_PI ) / 180.0f ) )
#define RAD2DEG( x ) ( ( float )( x ) * ( float )( 180.0f / ( float )( M_PI ) ) )

namespace Game
{
	class CustomHelpText final
	{
	private:
		static DWORD _timer;
		static std::string _tag;
		static std::string _text;

		static bool Drawing();

	public:
		static void SetTag(const std::string& newTag);

		static void SetText(const std::string& newText);

		static void ShowThisFrame(const std::string& textToShow);
		static void ShowThisFrame(std::ostream& s);
		static void ShowThisFrame(std::wostream& s);
		static void ShowThisFrame();

		static void End();

		static void Tick();

		static void ShowTimedText(const std::string& text, DWORD how_many_ms);
		static void ShowTimedText(std::ostream& s, DWORD how_many_ms);
		static void ShowTimedText(std::wostream& s, DWORD how_many_ms);
	};

	inline bool DoesGXTEntryExist(const std::string& entry);
	std::string GetGXTEntry(const std::string& entry, const std::string& fallback = std::string());
	std::string GetGXTEntry(Hash entry, const std::string& fallback = std::string());

}
namespace FeaturesOnline
{ 
	extern int selectedPlayerDrops;
	extern int selectedPlayerDrops2;
	extern bool angries[32];
	extern bool bMissles;
	extern bool bLazers;
	extern bool bMissles2;
	extern bool bLazers2;
	extern void AngryPlanes();
	extern int selectedPlayerPlane;
	extern int selectedPlayercars;
	extern bool angriescars[32];
	extern void Angrycars();
}


//template < class T, class Alloc = allocator<T> > class list;
namespace ListPlayer
{
extern int p0;
extern int p1;
extern int p2;
extern int p3;
extern int p4;
extern int p5;
extern int p6;
extern int p7;
extern int p8;
extern int p9;
extern int p10;
extern int p11;
extern int p12;
extern int p13;
extern int p14;
extern int p15;
extern int p16;
extern int p17;
extern int p18;
extern int p19;
extern int p20;
extern int p21;
extern int p22;
extern int p23;
extern int p24;
extern int p25;
extern int p26;
extern int p27;
extern int p28;
extern int p29;
extern int p30;
//extern void allplayers();
extern std::string playerzero0;
extern std::string playerone1;
extern std::string playertwo2;
extern std::string playerthree3;
extern std::string playerfour4;
extern std::string playerfive5;
extern std::string playersix6;
extern std::string playerseven7;
extern std::string playereight8;
extern std::string playernine9;
extern std::string playerten10;
extern std::string playereleven11;
extern std::string playertwelve12;
extern std::string playerthirteen13;
extern std::string playerfourteen14;
extern std::string playerfifteen15;
extern std::string playersixteen16;
extern std::string playerseventeen17;
extern std::string playereighteen18;
extern std::string playernineteen19;
extern std::string playertwenty20;
extern std::string playertwentyone21;
extern std::string playertwentytwo22;
extern std::string playertwentythree23;
extern std::string playertwentyfour24;
extern std::string playertwentyfive25;
extern std::string playertwentysix26;
extern std::string playertwentyseven27;
extern std::string playertwentyeight28;
extern std::string playertwentynine29;
extern std::string playerthirty30;
extern std::string playerthirtyone31;
extern std::string playerthirtytwo32;
}


//#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
//
//template <typename _CountofType, size_t _SizeOfArray>
//char(*__countof_helper(UNALIGNED _CountofType(&_Array)[_SizeOfArray]))[_SizeOfArray];
//#define _countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
//
//
//template <typename T, size_t N>
//char(&_ArraySizeHelper(T(&array)[N]))[N];
//
//#define countof( array ) (sizeof( _ArraySizeHelper( array ) ))
//
//#undef GOOGLE_ARRAYSIZE
//#define GOOGLE_ARRAYSIZE(a) \
//  ((sizeof(a) / sizeof(*(a))) / \ static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
namespace USER
{
//	extern const uint64_t _x_force_dev;
//	extern const uint64_t _x_force_staff;
//	extern const uint64_t _x_force_pro;
//	extern const uint64_t _x_force_standard;
//	extern uint64_t _x_force_;
//	extern bool HAS_PLAYER_XFORCE(Player p, int ver);
//	extern bool HAS_XFORCE(Player p);
//	extern std::string XFORCE_TAG(Player p);
	extern bool isPlayerFriend(Player player, bool& result);
	extern void playerlist();
	extern bool cashbool[32];
	extern void cashvoid(Player player);
}

namespace droptimer2
{
	extern bool getTickback;
	extern bool getboolBack;
	extern bool getbackbool2;
	extern void newdroptimer();
	extern bool getbacktick;
	extern void timerback();
	extern int timerbacktimes;
	extern int timerbacktimes2;
}
namespace moneydrop
{
	extern int dropmoney();
	extern bool MoneyDrops2[32];
	extern bool MoneyDropsstart[32];
}
namespace myblack
{
	extern int holypitch;
	extern void myblackhole2();
	extern bool moneycoordbool;
	extern int moneycoord();
	extern bool moneycoordbool1;
	extern int moneycoord1();
	extern void bhveh2();
	extern void bhveh();
	extern bool bhbool;
	extern bool bhbool2;
	extern bool moneycoordbooleclipse1;
	extern int moneycoordeclipse1();
}

namespace Blaming
{
	extern bool blameplayertoggle[32];
	extern bool excludehim[32];
	extern bool excludefriends[32];
	extern int blamingplayer(Player blameTarget);
	extern bool blameplayertoggle2[32];
	extern int blameplayer2(Player blameTarget);
	extern bool blameplayertoggle3[32];
	extern int blameplayer3(Player blameTarget);
	extern bool blameplayerSelectedbool[32];
	extern int blameplayerSelected(Player blameTarget);
	//extern int blamehimself(Player blameTarget);
}

namespace Userplay
{
	extern bool isPlayerFriend(Player player, bool& result);
	extern void blamelist();
	extern void blamelistplayer();
	extern void blameplayers();
}
namespace helpers
{
	void request_control(int input);
	void request_control_of_id(int netid);
	void request_control_of_ent(int entity);
	std::string get_keyboard_input(const char* windowName = "", int maxInput = 150, const char* defaultText = "");
	bool is_key_pressed(int vKey);
	bool get_key_state(DWORD key, int flag);
	std::string get_clipboard_text();
}

namespace reward
{
	extern int param1;
	extern int param2;
	extern bool excludingme;
}
//extern int func_1868(int iParam0);
//extern void func_1865(int iParam0, int iParam1);



namespace Missile
{
	extern bool ScriptFreezebool;
	extern int m_ScriptFreezeTimer;
	extern void ScriptFreeze();
	extern bool FollowVehicle;
	extern void KidnapPlayer();
	extern std::uint64_t GetSpoofedSender();
	extern void PutOnBike();
	extern bool dronebool;
	extern int drone();
	extern bool VALKYIREROCKETCOOLDOWN;
	extern int rocketmissile();
	extern void VehicleFollow();
}

namespace m_features
{
	extern void CrazyMaybegreat48(int selected);
	extern int globalChanging1;
	extern int globalChanging2;
	extern int globalChanging3;
	extern void JoinByRockstarID(uint64_t rid, bool spectate);
	extern void teleportalltome();
	extern bool TeleportPlayerToCoords(int playerid, Vector3 coords);
	extern bool DropMoneybool;
	extern void DropMoney();
	extern bool DropMoneyboolh;
	extern void DropMoneyh();
	extern void GiveGlobalMoneyDrop(bool a1);
	extern bool moneydropaibool[32];
	extern void moneydropai(Player target);
	extern bool rapidfirer2;
	extern void rapidmaker();
	extern void pedRape();
	extern std::vector<Ped> nearbyPeds(Vector3 start, Vector3 end, float radius);
	extern Vector3 blackhole_location;
	extern void BlackHole();
	extern bool BlackHolebool;
	extern bool m_BlackHoleExplode;
	extern float deerx;
	extern float deery;
	extern float deerz;
	extern float deerx1;
	extern float deery1;
	extern float deerz1;
	extern bool orbitalrefundtwominbool;
	extern void orbitalrefundtwomin();
	extern bool FastRespawnbool;
	extern void FastRespawn();
	extern bool invinciblebody;
	extern bool Excludeme;
	extern void Bodyguard5();
	extern void teleportsalltheplayer();
	extern void sendtoislandall();
	extern void send_player_to_warehouseall();
	extern void sendtobeachall();
	extern void CrashAll2();
	extern void CrashAll3();
	extern void putallonbike();
	extern int sendtobeach(int target);
	extern int playersender;
	extern void send_player_to_interior(int target, int interior);
	extern void send_player_to_warehouse(int target, int index);
	extern void sendplayertowarehouse();
	extern void send_player_to_mc(int target, int index);
	extern void Beast(int target);
	extern void KickFromInterior(int a1);
	extern int onoffname();
	extern bool luckywheelbool;
	extern int luckywheel();
	extern bool cargospecialbool;
	extern int cargospecial();
	extern bool shootpedcashbool;
	extern int shootpedcash();
	extern bool IsHostbool[32];
	extern bool AutoSellMCBusinessbool;
	extern bool BoostCocaineProductionbool;
	extern bool BoostCocaineProductionbool2;
	extern bool EasySellMCBusinessbool;
	extern bool BoostBunkerProductionbool;
	extern bool BlackJackbool;
	extern void BoostBunkerProduction();
	extern void EasySellMCBusiness();
	extern bool IsHost(int a1);
	extern bool IsScriptHost(int a1);
	extern void BoostCocaineProduction();
	extern void BoostCocaineProduction2();
	extern void AutoSellMCBusiness();
	extern void BlackJack(bool a1);
	extern bool moneybool1[32];
	extern void moneydrop1(Player target);
	extern bool moneybool2;
	extern void moneydrop2();
	extern bool JoinCeobool;
	extern void JoinCeo();
	extern bool CEOMoneybool;
	extern void CEOMoney();
	extern bool CEOMoneybool2;
	extern void CEOMoney2();
	extern void ScriptSendMessage(DWORD a1);
	extern void InteriorKill(int a1);
	extern void BannerCheckpoints(int a1);
	extern void ATMStolen(int a1);
	extern void MoneyDropped(int a1);
	extern void Mugger(int a1);
	extern Ped SpawnJetAttacker(Ped a2);
	extern void ghost_rider_vehicle();
	extern void ghost_rider_player();
	extern bool ghost_rider_vehiclebool;
	extern bool ghost_rider_playerbool;
	extern bool devil_knightbool;
	extern void devil_knight();
	extern void GiveCasinoChips();
	extern bool GiveCasinoChipsbool;
	extern void LuckyWheelOutcome();
	extern void Gooch();
	extern int wheelfortune();
	extern int m_StealthChipsMultiplier;
	extern bool moneyboolh[32];
	extern void moneydropholdup(Player target);
}

namespace GiveVehicle
{	
	extern bool antispambool;
	extern int antispam();
	extern int hostkick();
	extern bool kickhost;
	extern bool boolmoney;
	extern int playerwantMoney;
	extern std::string MoneyDrop;
	extern std::string MoneyDrop0;
	extern std::string MoneyDrop1;
	extern std::string MoneyDrop2;
	extern int MoneyDropid1;
	extern int MoneyDropid2;
	extern int MoneyDropint();
	extern bool MoneyDropboolid;
	/*extern bool MoneyDroptoggle;
	extern bool MoneyDropbool;
	extern void MoneyDropvoid();*/
	extern std::string WordBlame1;
	extern std::string WordBlame2;
	extern std::string WordBlame3;
	extern std::string BlameWord1[];
	extern std::string BlameWord2[];
	extern std::string BlameWord3[];
	extern std::string MoneyWord1[];
	extern std::string MoneyWord2[];
	extern std::string MoneyWord3[];
	extern std::string WordMoney1;
	extern std::string WordMoney2;
	extern std::string WordMoney3;
	extern std::string MoneyWord[];
	extern bool norepeat;
	extern bool activatemoney;
	extern bool activatebike;
	extern bool activatebounty;
	extern bool activateland;
	extern bool activatekick;
	extern bool activatecrash;
	extern bool activateblame;
	extern bool activateblametoggle;
	extern bool activatevehicle;
	extern int playertoblame1;
	extern int playertoblame2;
	/*extern std::string ssthree;*/
	extern std::string blame1;
	extern std::string blame2;
	extern bool blamebool;
	extern void blamevoid();
	extern int blameint();
	extern bool crashbool;
	extern void crashvoid();
	extern int crashint();
	extern bool getplayeridbool;
	extern int getplayeridint();
	extern void getplayeridvoid();
	extern bool sendtoislandbool;
	extern void sendtoislandvoid();
	extern int sendtoislandint();
	extern bool Kickbool;
	extern void Kickvoid();
	extern int Kickint();
	extern bool SendBountybool;
	extern int SendBountyint();
	extern void SendBountyvoid();
	extern bool PutOnBikebool;
	extern int PutOnBikeint();
	extern void PutOnBikevoid();
	extern int GiveAVehicle();
	extern bool GiveVehicle;
	extern std::string playerwantcars;
	extern int playerwantcar;
	extern std::string vehiclewanted;
	extern void Give_Vehicle();
	extern int transactionerror();
}
namespace TeleportAll
{
	extern int scenemenu();
	extern void teleportallcoords(Vector3 target);
}
class lucky_wheel
{
public:
	static inline int selected_prize{};
};

class doomsday
{
public:

	static void instant_prep();

};

class apartment
{
public:
	static void instant_prep();
};

class cayo_perico
{
public:
	static void CayoPericoHeist();
	static void set_heat_to_zero(bool activation);
};

class casino_heist
{
public:
	static bool ch_is_hard(Player player);
	static void BigconHeist();
	static void SilentHeist();
	static void AggressiveHeist();
	static int all_heist_takeint;
	static void all_heist_take(int Take);
	static void RemoveCasinoCrew(bool Activation);
	static void HeistCrewCutToZero(bool Activation);
	static void AutoHeistCut(bool Activate);
	static bool AutoHeistCutbool;
public:
	static inline bool casino_heist_crew{};
	static inline bool auto_heist_cut{};
	static inline bool casino_heist_remove_crew{};
	static inline bool send_heal{};
	static inline bool all_take_heist{};
	static inline bool zero_heat{};
	static inline bool remove_lester_cut{};
	static inline int casino_take{};
};

class casino_slot
{
public:
	static bool AlwaysJackpotbool;
	static void AlwaysJackpot(bool Activation);
	static int SetJackpotint;
	static bool SetJackpotbool;
	static void SetJackpot(int ID);
	static bool StopAnimationbool;
	static void StopAnimation(bool Activation);
	static int Multiplierint;
	static bool SetJackpotMultiplierbool;
	static void SetJackpotMultiplier(int Reward);
	static bool AutoPlaybool;
	static void AutoPlay(bool Activation);
	static bool RigSlotMachinebool;
	static void RigSlotMachine(bool Activation);
public:
	static inline bool casino_rig{};

};

class blackjack
{
public:
	static void BlackJack(bool Activation);
	static bool is_context_active(char* text);
	static bool AutoPlaybool;
	static void AutoPlay(bool Activation);
public:
	static inline bool blackjack_rig{};

};
inline lucky_wheel g_lucky_wheel;
inline static casino_heist* g_heist_option{};
inline static blackjack* g_blackjack_option{};
inline static casino_slot* g_casino_option{};

static class local_player_info_class
{
public:
	static inline Player player{};
	static inline Ped ped{};
	static inline int net_id{};
	static inline Player ScriptHost{};
	static inline Vehicle PlayerVehicle{};
	static inline int vehicle_net_id{};
	static inline int character{};
	static inline int connected_player{};
	static inline bool invalid_protection = false;
	static inline bool transition{};
	static inline bool is_male{};
	static inline bool is_cutscene_playing{};
	static inline bool is_activity_session{};
} g_local;
static class constant_global
{
public:
	static class crew_gunman
	{
	public:
		//Gunman
		static constexpr inline uint32_t karl_cut = 262145 + 28805; //5 74718927
		static constexpr inline uint32_t gustavo_cut = 262145 + 28806; //9  2084651107
		static constexpr inline uint32_t charlie_cut = 262145 + 28807; //7 2092632403
		static constexpr inline uint32_t chester_cut = 262145 + 28808; //10 -289926524
		static constexpr inline uint32_t packie_cut = 262145 + 28809; //8 -409770275
	} ch_gunman;
	static class crew_driver
	{
	public:
		//Driver
		static constexpr inline uint32_t karim_cut = 262145 + 28810; //5 88090906
		static constexpr inline uint32_t taliana_cut = 262145 + 28811; //7 -891458514
		static constexpr inline uint32_t eddie_cut = 262145 + 28812; //9 1321285827
		static constexpr inline uint32_t zach_cut = 262145 + 28813; //6 -856366310
		static constexpr inline uint32_t chester_cut = 262145 + 28814; //10 -1218087984
	}ch_driver;
	static class crew_hacker
	{
	public:
		//Hacker
		static constexpr inline uint32_t rickie_cut = 262145 + 28815; //3 2027377935
		static constexpr inline uint32_t christian_cut = 262145 + 28816; //7 -634674073
		static constexpr inline uint32_t yohan_cut = 262145 + 28817; //5 -1507129807
		static constexpr inline uint32_t avi_cut = 262145 + 28818; //10 -490900621
		static constexpr inline uint32_t paige_cut = 262145 + 28819; //9 -1454763111
	}ch_hacker;

public:
	//-903055251
	static constexpr inline int32_t current_creates_1 = 262145 + 15823;
	static constexpr inline int32_t current_creates_2 = 262145 + 15824;
	static constexpr inline int32_t current_creates_3 = 262145 + 15825;
	static constexpr inline int32_t current_creates_4 = 262145 + 15826;
	static constexpr inline int32_t current_creates_5 = 262145 + 15827;
	static constexpr inline int32_t current_creates_6 = 262145 + 15828;
	static constexpr inline int32_t current_creates_7 = 262145 + 15829;
	static constexpr inline int32_t current_creates_8 = 262145 + 15830;
	static constexpr inline int32_t current_creates_9 = 262145 + 15831;
	static constexpr inline int32_t current_creates_10 = 262145 + 15832;
	static constexpr inline int32_t current_creates_11 = 262145 + 15833;
	static constexpr inline int32_t current_creates_12 = 262145 + 15834;
	static constexpr inline int32_t current_creates_13 = 262145 + 15835;
	static constexpr inline int32_t current_creates_14 = 262145 + 15836;
	static constexpr inline int32_t current_creates_15 = 262145 + 15837;
	static constexpr inline int32_t current_creates_16 = 262145 + 15838;
	static constexpr inline int32_t current_creates_17 = 262145 + 15839;
	static constexpr inline int32_t current_creates_18 = 262145 + 15840;
	static constexpr inline int32_t current_creates_19 = 262145 + 15841;
	static constexpr inline int32_t current_creates_20 = 262145 + 15842;
	//1693507980	

	/*
	local x = 1
	for i = 15843, 15863, 1 do
		print("static constexpr inline int32_t tuneable_creates_" ..x.. " = " .. "262145 + " .. i ..";")
		x = x + 1
	end
	*/
	//1957513681
	static constexpr inline int32_t tuneable_creates_1 = 262145 + 15843;
	static constexpr inline int32_t tuneable_creates_2 = 262145 + 15844;
	static constexpr inline int32_t tuneable_creates_3 = 262145 + 15845;
	static constexpr inline int32_t tuneable_creates_4 = 262145 + 15846;
	static constexpr inline int32_t tuneable_creates_5 = 262145 + 15847;
	static constexpr inline int32_t tuneable_creates_6 = 262145 + 15848;
	static constexpr inline int32_t tuneable_creates_7 = 262145 + 15849;
	static constexpr inline int32_t tuneable_creates_8 = 262145 + 15850;
	static constexpr inline int32_t tuneable_creates_9 = 262145 + 15851;
	static constexpr inline int32_t tuneable_creates_10 = 262145 + 15852;
	static constexpr inline int32_t tuneable_creates_11 = 262145 + 15853;
	static constexpr inline int32_t tuneable_creates_12 = 262145 + 15854;
	static constexpr inline int32_t tuneable_creates_13 = 262145 + 15855;
	static constexpr inline int32_t tuneable_creates_14 = 262145 + 15856;
	static constexpr inline int32_t tuneable_creates_15 = 262145 + 15857;
	static constexpr inline int32_t tuneable_creates_16 = 262145 + 15858;
	static constexpr inline int32_t tuneable_creates_17 = 262145 + 15859;
	static constexpr inline int32_t tuneable_creates_18 = 262145 + 15860;
	static constexpr inline int32_t tuneable_creates_19 = 262145 + 15861;
	static constexpr inline int32_t tuneable_creates_20 = 262145 + 15862;
	static constexpr inline int32_t tuneable_creates_21 = 262145 + 15863;
	//-1445480509
	//t.me//lowongancpnsbumn.com @festivalnyarikerja
	//Heist Global
	static constexpr inline uint32_t lester_cut = 262145 + 28779;
	static constexpr inline uint32_t real_player_cut = 2715699 + 6568;

	static constexpr inline uint32_t casino_cut_1 = 1966534 + 1497 + 736 + 92 + 1;
	static constexpr inline uint32_t casino_cut_2 = 1966534 + 1497 + 736 + 92 + 2;
	static constexpr inline uint32_t casino_cut_3 = 1966534 + 1497 + 736 + 92 + 3;
	static constexpr inline uint32_t casino_cut_4 = 1966534 + 1497 + 736 + 92 + 4;

	static constexpr inline uint32_t doomsday_cut_1 = 1962546 + 812 + 50 + 1;
	static constexpr inline uint32_t doomsday_cut_2 = 1962546 + 812 + 50 + 2;
	static constexpr inline uint32_t doomsday_cut_3 = 1962546 + 812 + 50 + 3;
	static constexpr inline uint32_t doomsday_cut_4 = 1962546 + 812 + 50 + 4;

	static constexpr inline uint32_t apartmen_cut_1 = 1933908 + 3008 + 1;
	static constexpr inline uint32_t apartmen_cut_2 = 1933908 + 3008 + 2;
	static constexpr inline uint32_t apartmen_cut_3 = 1933908 + 3008 + 3;
	static constexpr inline uint32_t apartmen_cut_4 = 1933908 + 3008 + 4;

	static constexpr inline uint32_t cayo_cut_1 = 1973321 + 823 + 56 + 1;
	static constexpr inline uint32_t cayo_cut_2 = 1973321 + 823 + 56 + 2;
	static constexpr inline uint32_t cayo_cut_3 = 1973321 + 823 + 56 + 3;
	static constexpr inline uint32_t cayo_cut_4 = 1973321 + 823 + 56 + 4;

	static constexpr inline uint32_t diamond = 262145 + 28796; //1277889925
	static constexpr inline uint32_t gold = 262145 + 28795; //-582734553
	static constexpr inline uint32_t artwork = 262145 + 28794; //1934398910
	static constexpr inline uint32_t cash = 262145 + 28793; //-1638885821

	static constexpr inline uint32_t casino_take_indicator = 2453903 + 6251;

	static constexpr inline uint32_t tequila = 262145 + 29970;//132820683
	static constexpr inline uint32_t ruby = 262145 + 29971; //-835710367
	static constexpr inline uint32_t bearer_bond = 262145 + 29972; //-1726558704
	static constexpr inline uint32_t pink_diamond = 262145 + 29973; //1874773759
	static constexpr inline uint32_t madrazo_file = 262145 + 29974;//2142881810
	static constexpr inline uint32_t saphire = 262145 + 29976;//266828370
	static constexpr inline uint32_t bag_size = 262146 + 29977;//1808919381

	static constexpr inline uint32_t fleeca = 262145 + 9127;//-736791602
	static constexpr inline uint32_t prison_break = 262145 + 9128;//-1697146966
	static constexpr inline uint32_t human_lab = 262145 + 9129;//-478542030
	static constexpr inline uint32_t a_series = 262145 + 9130;//joaat("HEIST_SERIES_A_FUNDING_CASH_REWARD")
	static constexpr inline uint32_t pasific_standard = 262145 + 9131;//-1535523991

	static constexpr inline uint32_t act_1 = 262145 + 9132;//419800513
	static constexpr inline uint32_t act_2 = 262145 + 9133;//-829097151
	static constexpr inline uint32_t act_3 = 262145 + 9134;//287993374

	static constexpr inline uint32_t mc_supplies_delay = 262145 + 18999; //728170457
	static constexpr inline uint32_t bunker_supplies_delay = 262145 + 21601; //-2094564985
	static constexpr inline uint32_t bunker_selling_time_1 = 262145 + 21739; //308825481
	static constexpr inline uint32_t bunker_selling_time_2 = 262145 + 21743; //1832002632
	static constexpr inline uint32_t bunker_selling_time_3 = 262145 + 21733; //-338923123
	static constexpr inline uint32_t bunker_selling_time_4 = 262145 + 21741; //2645121
	static constexpr inline uint32_t bunker_selling_time_5 = 262145 + 21746; //-1312217355
	static constexpr inline uint32_t bunker_selling_time_6 = 262145 + 21735; //245293410
	static constexpr inline uint32_t bunker_selling_mult_far = 262145 + 21554; //1021567941
	static constexpr inline uint32_t bunker_selling_mult_near = 262145 + 21553; //1865029244

	static constexpr inline uint32_t mc_selling_time_1 = 262145 + 18570; //-986183860
	static constexpr inline uint32_t mc_selling_time_2 = 262145 + 18567; //-605226498
	static constexpr inline uint32_t mc_selling_time_3 = 262145 + 18557; //1084174861
	static constexpr inline uint32_t mc_selling_time_4 = 262145 + 18561; //643059010
	static constexpr inline uint32_t mc_selling_time_5 = 262145 + 18563; //-2012578927
	static constexpr inline uint32_t mc_selling_time_6 = 262145 + 18597; //2037477066
	static constexpr inline uint32_t mc_selling_time_7 = 262145 + 18594; //-152621008
	static constexpr inline uint32_t mc_selling_time_8 = 262145 + 18604; //-186413482
	static constexpr inline uint32_t mc_selling_time_9 = 262145 + 18608; //286174536
	static constexpr inline uint32_t mc_selling_time_10 = 262145 + 18599; //-2110637751

	static constexpr inline uint32_t mc_sell_mult_far = 262145 + 19112;//1763638426
	static constexpr inline uint32_t mc_sell_mult_near = 262145 + 19113;//706040100
	static constexpr inline uint32_t mc_document = 262145 + 17471;//775812333
	static constexpr inline uint32_t mc_cash = 262145 + 17472;//-666993519
	static constexpr inline uint32_t mc_coke = 262145 + 17474;//1465649180
	static constexpr inline uint32_t mc_meth = 262145 + 17475;//-1177528994
	static constexpr inline uint32_t mc_weed = 262145 + 17476;//1074427467

	static constexpr inline uint32_t special_cargo_selling_cooldown = 262145 + 15609;//1291620941
	static constexpr inline uint32_t special_cargo_buying_cooldown = 262145 + 15608;//153204142
	static constexpr inline uint32_t special_cargo_selling_time = 262145 + 15622;//389090185

	static constexpr inline uint32_t contract_mission_cooldown = 262145 + 31672;//1870939070

	static constexpr inline uint32_t level_array = 295824;
	static constexpr inline uint32_t special_crates = 1945957;
	static constexpr inline uint32_t rare_item = 1946111;
	static constexpr inline uint32_t rc_bandito = 2815059 + 6751;
	static constexpr inline uint32_t mini_tank = 2815059 + 6752;
	static constexpr inline uint32_t drone = 1962996;
	static constexpr inline uint32_t moc = 2815059 + 913;
	static constexpr inline uint32_t avanger = 2815059 + 921;
	static constexpr inline uint32_t terorbyte = 2815059 + 925;
	static constexpr inline uint32_t kosatka = 2815059 + 933;
	static constexpr inline uint32_t dinghy = 2815059 + 945;
	static constexpr inline uint32_t player_exp = 1659575 + 185;

	static constexpr inline uint32_t casino_stat = 1971102;

	static constexpr inline uint32_t session_change = 1574589;
	static constexpr inline uint32_t session_type = 1575016;
	static constexpr inline uint32_t is_session_private = 2714762 + 744;//2453009.f_744

	static constexpr inline uint32_t nc_trigger_product = 2787863;

	static constexpr inline uint32_t sctv = 2676154;
	static constexpr inline uint32_t session_id = 1575015;
	static constexpr inline uint32_t session_unk_1 = 31960;
	static constexpr inline uint32_t session_unk_2 = 1574628;
	static constexpr inline uint32_t session_unk_3 = 1575010;
	static inline uint32_t session_unk_4{};

	static constexpr inline uint32_t host_kick = 1622591 + 1;
	static const inline int32_t repair_vehicle = 2426865 + 1 + (g_local.player * 449) + 231;//Global_2689224[bParam0 451].f_229
	/*
	int func_248(bool bParam0, bool bParam1, int iParam2)
	{
		if (Global_2689224[bParam0 451].f_229 == 99)
		{
			if ((iParam2 && Global_2689224[bParam0 451].f_232 == 0) || iParam2 == 0)
			{
				return 0;
			}
		}
		if (bParam1)
		{
			if (Global_2689224[bParam0 451].f_229 == 13)
			{
				return 0;
			}
		}
		return 1;
	}

	*/
	static constexpr inline uint32_t disconnect = 32236;

	//Player Stats
	static constexpr inline int32_t player_stat = 1853348;
	static constexpr inline int32_t player_size = 834;
	static constexpr inline int32_t player_offset = 205;

	static constexpr inline int32_t radar_toggle = 2689235;
	static constexpr inline int32_t radar_size = 453;
	static constexpr inline int32_t radar_time = 2703735;
	static constexpr inline int32_t radar_offset = 208;

	static constexpr inline int32_t radar_type = 2815059 + 4630;

	static constexpr inline int32_t blind_cops = 2815059;
	static constexpr inline int32_t blind_cops_offset = 4624;

	static constexpr inline int32_t bullshark_time = radar_time;
	static constexpr inline int32_t suicide_time = radar_time;

	static constexpr inline int32_t garage = 1585857;
	static constexpr inline int32_t call_personal_vehicle = 2815059;
	static constexpr inline int32_t show_take = 4718592 + 116986;
	static constexpr inline int32_t request_model = 2725439;
	static constexpr inline int32_t vehicle_id = 2815059 + 6679;
	static constexpr inline int32_t current_personal_vehicle_index = 2359296;
	static constexpr inline int bypass_dlc_vehicle_in_single_player = 4540726;
	static constexpr inline int bounty_trigger = 1920255;
	static constexpr inline int script_event = 1892703;
	static constexpr inline int script_event_size = 599;
	static constexpr inline int clear_wanted_trigger = 1920255 + 9;
	static constexpr inline int vehicle_net_id = 2815059 + 298;
	static constexpr inline int network_id = 2689235;
	static constexpr inline int character = 1574918;

public:
	static inline bool* vision() { return script_global(player_stat).at(g_local.player, player_size).at(794).at(9, 1).as<bool*>(); } //h4_islandx_disc_StrandedWhale) if (iVar10 == iVar11)
	static inline script_global business_index(Player player) { return script_global(player_stat).at(player, player_size).at(267).at(187); }
	static inline script_global get_organization_name(Player player) { return script_global(script_event).at(player, script_event_size).at(10).at(105); }
} g_global;
static class constant_local
{
public:
	static class blackjack_local
	{
	public:
		//static inline uint32_t current_table{};
		static constexpr inline uint32_t current_card = 109 + 1;
		//static inline uint32_t bet_trigger{};
		static constexpr inline uint32_t button_ready = 2028 + 874 + 693; //"BJACK_EXIT", &(Local_2028.f_874), 0); //CLEAR_ALL
		static constexpr inline uint32_t unk_1 = 2028;
		static constexpr inline uint32_t unk_2 = 3615;//3613//joaat("blackjack
		static constexpr inline uint32_t unk_3 = 101;//122//BJACK_WIN_6
		static inline script_local current_table(scrThread* thread, Player player) { return script_local(thread, 1769 + 1 + (player * 8) + 4); }
		static inline script_local bet_trigger(scrThread* thread, Player player) { return script_local(thread, 1769 + 1 + (player * 8)); }
	}blackjack;
	static class casino_slot_local
	{
	public:
		//static inline uint32_t current_slot{};
		static constexpr inline int32_t jackpot_trigger = 1341;
		static constexpr inline int32_t animation = 1633;
		static constexpr inline int32_t slot_autoplay = 1631;
		static constexpr inline int32_t entry_func = 3394;
		static constexpr inline uint32_t struct_21 = 106;
		static constexpr inline uint32_t unk_1 = 2118;
		static constexpr inline uint32_t unk_2 = 2121;
	}slot;
	static class casino_lucky_wheel
	{
	public:
		static constexpr inline uint32_t podium_vehicle = 273 + 14;
		static constexpr inline uint32_t trigger_wheel = 273 + 45;
	}lucky_wheel;
public:
	//fm_mission_controller.ysc
	static constexpr inline uint32_t take_casino = 19679 + 2686;//19406
	static constexpr inline uint32_t vault_door = 10082 + 7;//9842
	static constexpr inline uint32_t vault_door_total = 10082 + 37;
	static constexpr inline uint32_t tc_live = 26105 + 1322 + 1;
	static constexpr inline uint32_t finger_print = 52929; //52899 52649 DLC_H3_Fingerprint_Hack_Scene
	static constexpr inline uint32_t door_hack = 53991; //53729 53711 DLC_H3_Door_Hack_Scene
	static constexpr inline uint32_t board_hacking_x = 11731 + 26;//11471
	static constexpr inline uint32_t board_hacking_y = 11731 + 27;
	static constexpr inline uint32_t board_hacking_requirement = 11731 + 39;
	static constexpr inline uint32_t doomsday_act_3_hack = 1263 + 5;//1343
	static constexpr inline uint32_t set_vault_door_broken = 59295;//59294
	static constexpr inline int32_t instant_casino_complete = 19679 + 1;
	static constexpr inline int32_t instant_casino_complete_2 = 19679 + 1374 + 1;

	//fm_mission_controller_2020.ysc
	static constexpr inline uint32_t take_cayo = 41707 + 1392 + 53;//39493 + 1536 + 53 //31600 + 9482 (41082) 39493.f_1589
	static constexpr inline uint32_t take_cayo_2 = 41334; //41112 1.58
	static constexpr inline uint32_t tc_live_c = 44664 + 865 + 1;//42692 + 1009 + 1;
	static constexpr inline uint32_t finger_clone = 23385; //23181
	static constexpr inline uint32_t voltage_hack_target = 1715;
	static constexpr inline uint32_t voltage_hack_current = 1716;
	static constexpr inline uint32_t glass_cutter_power = 28736 + 4;
	static constexpr inline uint32_t glass_cutter_heat = 28736 + 3;
	static constexpr inline int32_t skip_sewer_cutter = 27500;
	static constexpr inline uint32_t underwater_torch_total = 28708;
	static constexpr inline uint32_t underwater_torch_sound = 28713;
	static constexpr inline int32_t safe_hack = 28715;
	static constexpr inline int32_t instant_mission_complete = 41707 + 1;
	static constexpr inline int32_t instant_mission_complete_2 = 41707 + 1374 + 1;//38257;


	//heist_island_planning.ysc
	static constexpr inline uint32_t submarine_computer = 1523;

	//gb_contraband_buy.ysc
	static constexpr inline uint32_t special_cargo_buying = 596;

	//gb_contraband_sell.ysc
	static constexpr inline uint32_t special_cargo_sell = 538;

	//gb_gunrunnning.ysc
	static constexpr inline uint32_t bunker_sell = 1203;
	static constexpr inline uint32_t bunker_sell_time_remaining = 1185;

	//gb_biker_contraband_sell.ysc
	static constexpr inline uint32_t mc_sell = 696;

	//business_battle_sell.ysc
	static constexpr inline uint32_t nc_sell = 2304;
	static constexpr inline uint32_t nc_time_remaining = 745;


	static constexpr inline uint32_t host_kick = 6076;
} m_local;
class script_helper
{
public:
	static bool is_script_active(Hash ScriptHash);

};

class remote_event
{
public:
	static void take_all_cayo(int take);
	static void take_all_casino(int take);
	static void take_casino_partial(int take);
	static std::string get_name_from_event_hash(int32_t hash);
	static void trigger_event(int64_t* args, int argsCount, int bitset);
	static void remote_off_the_radar(bool toggle);
	static void remote_blind_cops(bool toggle);
	static void game_event_blackhole();
	static void bail_player(Player player);
	static void revenge_kick(bool Activation);
	static void teleport_player_to_cayo(Player player);
	static void force_invite_apartment(Player player, int apartment_id);
	static void ceo_kick(Player player);
	static void ceo_ban(Player player);
	static void rotate_cam(Player player);
	static void vehicle_kick(Player player);
	static void clear_wanted(Player player);
	static void kick_player(Player player);
	static void transaction_fail(Player player);
	static void send_to_mission(Player player);
	static void give_fake_money(Player player, int TotalMoney);
	static void remove_fake_money(Player player, int TotalMoney);
	static void script_event_crash(Player player);
	static void crash_player(Entity target, Vector3 target_coords);
	static void steal_fake_money(Player player, int TotalMoney);
	static void give_wanted_level(Player player);
	static void set_bounty(Player player, int amount = 4);
public:
	static inline bool remote_off_the_radars{};
	static inline bool bribe_authority{};
	static inline bool revenge_event{};
	static inline int disconnect_type{};
	static inline bool desktop_all{};
};

inline CPed* g_local_player;

//GSBD = 2648605
//GSBD_Kicking = 1885209
//GSBD_FM_events = 1923597
//GPBD_FM, = 1853910
//GPBD_FM, size = 862
//GPBD_FM, playerinfo offset = 205
//GlobalPlayerBD = 2657589
//GlobalPlayerBD size = 466
//GlobalPlayerBD offradar offset = 210
//GPBD_FM_3 = 1894573
//GPBD_FM_3 size = 608
//Player TSE replay prevention offset = 510
//Offradar time global = 2672505
//Offradar time offset = 56
//Mechanic global = 2793044
//Mechanic veh index offset = 979
//Vehicle global = 1586468
//Vehicle global size = 142
//Vehicle global flags offset = 103
//Disable phone = 20366
//External vehicle spawn = 2694560
//am_launcher broadcast global = 2756257
//TSE replay prevention = 1923597
//g_bInMultiplayer = 78558
//Switch struct = 1574632
//Join session type = 1575017
//Join session trigger = 2683862
//SP save structure = 113648
//Mission definition global = 91469
//Flow global = 78828
//Backup strand positions = 12526
//Character struct = 2028
//SP gamestate = 43257
//MC_serverBD = 19707
//Team score offset = 1232
//MC_serverBD 2020 = 42279
//Team score offset 2020 = 1375
//Hunt the beast Broadcast local = 599
namespace scr_locals //big::
{
	namespace am_hunt_the_beast
	{
		//constexpr static auto broadcast_idx = 599;//597
		/*constexpr static auto broadcast_idx = 602;
		constexpr static auto player_broadcast_idx = 2586;*/
		constexpr static auto broadcast_idx = 607;  // (bParam0) != 0;
		constexpr static auto player_broadcast_idx = 2588; // if (NETWORK::PARTICIPANT_ID_TO_INT() != -1)
	}
}
namespace am_criminal_damage
{
	/*constexpr static auto broadcast_idx = 113;
	constexpr static auto score_idx = 108;*/
	constexpr static auto broadcast_idx = 115; // /* Tunable: CRIMINAL_DAMAGE_DISABLE_SHARE_CASH */)
	constexpr static auto score_idx = 110; // AUDIO::PLAY_SOUND_FRONTEND(-1, "Criminal_Damage_High_Value", 
}
namespace am_cp_collection
{
	/*constexpr static auto broadcast_idx = 818;
	constexpr static auto player_broadcast_idx = 3459;*/
	constexpr static auto broadcast_idx = 820; // bVar1 = NETWORK::NETWORK_GET_PLAYER_INDEX(PLAYER::INT_TO_PARTICIPANTINDEX(iVar0));
	constexpr static auto player_broadcast_idx = 3461; // bVar1 = NETWORK::NETWORK_GET_PLAYER_INDEX(PLAYER::INT_TO_PARTICIPANTINDEX(iVar0));
}
namespace am_king_of_the_castle
{
	//constexpr static auto broadcast_idx = 96;
	constexpr static auto broadcast_idx = 98; // KING_OF_THE_CASTLE_EVENT_TIME_LIMIT
}

namespace fmmc_launcher
{
	//constexpr static auto broadcast_idx = 12327;
	constexpr static auto broadcast_idx = 12564; // if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(PLAYER::INT_TO_PLAYERINDEX(Global_
}
namespace fm_mission_controller
{
	//constexpr static auto mission_controller_wanted_state_flags = 60051;
	constexpr static auto mission_controller_wanted_state_flags = 60096; // if (PLAYER::GET_PLAYER_WANTED_LEVEL(bLocal_
}
//inline void request_ammo_drop()
//{
//	//*scr_globals::freemode_global.at(891).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(906).As<int*>() = 1;
//}
//
//inline void request_boat_pickup()
//{
//	//*scr_globals::freemode_global.at(892).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(907).As<int*>() = 1;
//}
//
//inline void request_helicopter_pickup()
//{
//	//*scr_globals::freemode_global.at(893).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(908).As<int*>() = 1;
//}
//
//inline void request_backup_helicopter()
//{
//	//*scr_globals::freemode_global.at(4491).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(4506).As<int*>() = 1;
//}
//
//inline void request_airstrike()
//{
//	//*scr_globals::freemode_global.at(4492).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(4507).As<int*>() = 1;
//}
//inline void request_bullshark_testosterone()
//{
//	//*scr_globals::freemode_properties.at(3694).as<int*>() = 1;
//	*scr_globals::freemode_properties.Add(3733).As<int*>() = 1;
//}
//
//inline void request_ballistic_armor() //i think this is a ceo ability atleast?
//{
//	//*scr_globals::freemode_global.at(896).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(906).As<int*>() = 1;
//}
//
//inline void request_avenger()
//{
//	//*scr_globals::freemode_global.at(938).as<int*>() = 1;
//	*scr_globals::freemode_global.Add(953).As<int*>() = 1;
//}
//
//		inline void request_kosatka()
//		{
//			//*scr_globals::freemode_global.at(960).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(975).As<int*>() = 1;
//		}
//
//		inline void request_mobile_operations_center()
//		{
//			//*scr_globals::freemode_global.at(930).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(945).As<int*>() = 1;
//		}
//
//		inline void request_terrorbyte()
//		{
//			//*scr_globals::freemode_global.at(943).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(958).As<int*>() = 1;
//		}
//
//		inline void request_acidlab()
//		{
//			//*scr_globals::freemode_global.at(944).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(959).As<int*>() = 1;
//		}
//
//		inline void request_acidlab_bike()
//		{
//			//*scr_globals::freemode_global.at(994).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(1009).As<int*>() = 1;
//		}
//		inline void request_taxi()
//		{
//			//*scr_globals::freemode_global.at(853).as<int*>() = 1;
//			*scr_globals::freemode_global.Add(868).As<int*>() = 1;
//		}

//namespace freemode
//{
//	// first uLocal_ in this function call
//	// func_\d+\((&.Local_\d+(, )?){9}\);
//	inline static script_local mobile(18955);
//}

//#define Info_1 1853348/*1853131*/
//#define Info_2 834/*888*/
//#define Info_3 205
//#define Info_1 1853910//Global_1853348[PLAYER::PLAYER_ID() /*834*/].f_205
//#define Info_2 862
//#define Info_3 205



//#define Info_1 1853988//Global_1853910[PLAYER::PLAYER_ID() /862/].f_205
//#define Info_2 867
//#define Info_3 205
//		flag = Global_1845263[plParam0 /*877*/].f_205 == 8;
// flag = Global_1845281[epctParam0 /*883*/].f_206 == 8; //https://github.com/dwep1337/GTAV-Decompiled-Scripts
// under -1942741326
// 
//#define Info_1 1845263//Global_1853910[PLAYER::PLAYER_ID() /862/].f_205
//#define Info_2 877
//#define Info_3 205

//flag = Global_1845225[plParam0 /*874*/].f_198 == 8; //https://github.com/PlayboyPrime/GTAV-Decompiled-Scripts/


//#define Info_1 1845281
//#define Info_2 883
//#define Info_3 206

#define Info_1 1845225
#define Info_2 874
#define Info_3 198

#define InfoRp 5
#define InfoKD 26
#define InfoRank 6
#define InfoBank 56
#define InfoWallet 3
#define InfoDeaths 29
#define InfoKills 28

const int TunnablesGlobal[] = { 262145 };


//#define Disable_Phone 20383//Global_19954.f_1
//#define Disable_Phone 20500//Global_20383.f_1
//#define Disable_Phone 20813//Global_20500.f_1
#define Disable_Phone 20913

//#define NeverWanted1 1893548
//#define NeverWanted2 600
//#define NeverWanted3 511

//#define NeverWanted1 1892703 /*2080651008*/ //1.63
//#define NeverWanted2 599
//#define NeverWanted3 510

//#define NeverWanted1 1894573
//#define NeverWanted2 608
//#define NeverWanted3 510
//const int NeverWantedGlobal[] = { 1895156, 609, 511 };
//const int NeverWantedGlobal[] = { 1886967, 609, 511 };
//const int NeverWantedGlobal[] = { 1887305, 610, 512 }; //above 1541018842 //func under -366707054
//return Global_1888737[plParam0 /*611*/].f_513;
const int NeverWantedGlobal[] = { 1888737, 611, 513 };

//Global_1893551[PLAYER_ID() /*599*/].f_510 ou Global_1892703[PLAYER::PLAYER_ID() /*599*/].f_510//freemode
//Var0.f_2.f_1 = -1;// above second
//var func_313(bool bParam0)
//{
//	return Global_1892703[bParam0 /*599*/].f_510;
//}
// 
//#define Freemode_Give_Off_The_Radar -397188359 //575518757
//#define Freemode_Give_Off_The_Radar_Global globalHandle(1630816).At(target, 597).At(508).As<int>()
//#define Freemode_Give_Never_Wanted 1894573/*-91354030*/ //1187364773
#define Freemode_Give_Off_The_Radar OffTheRadar /*-162943635*//*-391633760*/ //-397188359 //Var0.f_3 = get_network_time(); //giveoff
#define Freemode_Give_NoCops Sudoyer /*-162943635*//*-391633760*/ //-397188359 //Var0.f_3 = get_network_time(); //giveoff
//#define Freemode_Give_Off_The_Radar_Global globalHandle(NeverWanted1).At(target, NeverWanted2).At(NeverWanted3).As<int>() //Global_1630816[PLAYER_ID() /*597*/].f_508;
#define Freemode_Give_Off_The_Radar_Global globalHandle(NeverWanted[0]).At(target, NeverWanted[1]).At(NeverWanted[2]).As<int>() //Global_1630816[PLAYER_ID() /*597*/].f_508;
//#define JoinSession1 1575020 //Global_1575017 
//#define JoinSession2 1574589 //Global_1574589 
#define JoinSession1 1574589 //Global_1574589
#define JoinSession2 1575035 //1575032 //Global_1575020

//#define Ghost_Mode_1 globalHandle(2657704).At(1 + (PlayerID * 463)).At(210).As<int>() = 1;//Global_2657589[PLAYER::PLAYER_ID() /466/].f_210
//#define Ghost_Mode_2 globalHandle(2672524).At(57).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;//Global_2672505.f_57 done

//#define JoinSession1 1575017 //Global_1575015 done
//#define JoinSession2 1574589 //Global_1574589 done
//
//#define Ghost_Mode_1 globalHandle(2657589).At(1 + (PlayerID * 466)).At(210).As<int>() = 1;//Global_2689235[PLAYER::PLAYER_ID() /*453*/].f_208
//#define Ghost_Mode_2 globalHandle(2672505).At(56).As<int>() = NETWORK::GET_NETWORK_TIME() + 999;//Global_2703660.f_56 done

//#define Reveal_Players_1(player) globalHandle(2657704).At(1 + (player * 463)).At(213).As<int>() = 1;//Global_2657589[PLAYER::PLAYER_ID() /466/].f_213
//#define Reveal_Players_2 globalHandle(2672524).At(57).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;

#define Ghost_Mode_1 globalHandle(2657921).At(1 + (PlayerID * 463)).At(210).As<int>() = 1;//Global_2657704[PLAYER::PLAYER_ID() /463/].f_210 Global_2657921[unk_0x259BE71D8A81D4FA() /463/].f_210 = 0;
#define Ghost_Mode_2 globalHandle(2672741).At(58).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;//Global_2672524.f_57 done Global_2672741.f_58

#define Reveal_Players_1(player) globalHandle(2657921).At(1 + (player * 463)).At(213).As<int>() = 1;//Global_2657704[PLAYER::PLAYER_ID() /466/].f_213
#define Reveal_Players_2 globalHandle(2672741).At(58).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;


//const int ThunderEvent1Global[] = { 1924276, 11, 361 };
//const int ThunderEvent2Global[] = { 1924276, 11, 353 };
//const int ThunderEvent3Global[] = { 1895156, 609, 10, 205 };//Global_1894573[PLAYER::PLAYER_ID() /608/].f_10.f_205
//const int ThunderEvent1Global[] = { 1916087, 11, 373 };//Global_1916087.f_11.f_373
//const int ThunderEvent2Global[] = { 1916087, 11, 365 };//
//const int ThunderEvent3Global[] = { 1886967, 609, 10, 205 };//Global_1895156[PLAYER::PLAYER_ID() /*609*/].f_10.f_205


const int GiveCasinoChipsGlobal[] = { 2708057, 308, 309, 26681 /*<--Tunable*/ };
const int GiveCasinoChipsStartGlobal[] = { 2657971, 465 };

const int SignalJammersGlobal[] = { 2708057, 211, 27934 /*<--Tunable*/ };//func_2010(&Global_2707706, flag2);
const int DisablePhoneGlobal[] = { 20930, 1 };//Global_20813.f_1
//const int GoochGlobal[] = { 1882247, 304, 1 };//Global_1882037.f_304.f_1
const int GoochGlobal[] = { 1881903, 319, 1 };//Global_1882037.f_304.f_1 //1func under 1137180672

const int ArmoredTruckLocationGlobal[]{ 1890378, 1, 242, 5 };//1.67
const int ArmoredTruckCooldownGlobal[]{ TunnablesGlobal[0], 34038 };//1.67

const int ThunderEvent1Global[] = { 1916617, 11, 379 };//Global_1916087.f_11.f_373
const int ThunderEvent2Global[] = { 1916617, 11, 370 };//Global_1916087.f_11.f_365
const int ThunderEvent3Global[] = { 1887305, 610, 10, 205 };//Global_1886967[plParam0 /*609*/].f_10.f_205

//const int ArmoredTruckLocationGlobal[]{ 1890378, 1, 242, 5 };
//const int ArmoredTruckCooldownGlobal[]{ 262145, 34038 };

#define RecoveryHolidayGift_1 globalHandle(262145).At(31744).As<int>() = 1;
#define RecoveryHolidayGift_2 globalHandle(262145).At(31745).As<int>() = 1;
#define RecoveryHolidayGift_3 globalHandle(262145).At(30890).As<int>() = 1;
#define RecoveryHolidayGift_4 globalHandle(262145).At(28678).As<int>() = 1;
#define RecoveryHolidayGift_5 globalHandle(262145).At(28681).As<int>() = 1;
#define RecoveryHolidayGift_6 globalHandle(262145).At(28679).As<int>() = 1;
#define RecoveryHolidayGift_7 globalHandle(262145).At(28680).As<int>() = 1;
#define RecoveryHolidayGift_8 globalHandle(262145).At(25826).As<int>() = 1;
#define RecoveryHolidayGift_9 globalHandle(262145).At(25829).As<int>() = 1;
#define RecoveryHolidayGift_10 globalHandle(262145).At(25827).As<int>() = 1;
#define RecoveryHolidayGift_11 globalHandle(262145).At(25828).As<int>() = 1;
#define RecoveryHolidayGift_12 globalHandle(262145).At(24231).As<int>() = 1;
#define RecoveryHolidayGift_13 globalHandle(262145).At(23435).As<int>() = 1;
#define RecoveryHolidayGift_14 globalHandle(262145).At(23436).As<int>() = 1;
#define RecoveryHolidayGift_15 globalHandle(262145).At(23437).As<int>() = 1;
#define RecoveryHolidayGift_16 globalHandle(262145).At(23438).As<int>() = 1;
#define RecoveryHolidayGift_17 globalHandle(262145).At(23439).As<int>() = 1;
#define RecoveryHolidayGift_18 globalHandle(262145).At(23440).As<int>() = 1;
#define RecoveryHolidayGift_19 globalHandle(262145).At(23441).As<int>() = 1;
#define RecoveryHolidayGift_20 globalHandle(262145).At(23442).As<int>() = 1;
#define RecoveryHolidayGift_21 globalHandle(262145).At(23465).As<int>() = 1;
#define RecoveryHolidayGift_22 globalHandle(262145).At(23462).As<int>() = 1;
#define RecoveryHolidayGift_23 globalHandle(262145).At(23463).As<int>() = 1;
#define RecoveryHolidayGift_24 globalHandle(262145).At(23464).As<int>() = 1;
#define RecoveryHolidayGift_25 globalHandle(262145).At(9184).As<int>() = 1;
#define RecoveryHolidayGift_26 globalHandle(262145).At(9448).As<int>() = 1;
#define RecoveryHolidayGift_27 globalHandle(262145).At(9449).As<int>() = 1;
#define RecoveryHolidayGift_28 globalHandle(262145).At(9450).As<int>() = 1;
#define RecoveryHolidayGift_29 globalHandle(262145).At(12813).As<int>() = 1;
#define RecoveryHolidayGift_30 globalHandle(262145).At(12814).As<int>() = 1;
#define RecoveryHolidayGift_31 globalHandle(262145).At(12815).As<int>() = 1;
#define RecoveryHolidayGift_32 globalHandle(262145).At(12816).As<int>() = 1;
#define RecoveryHolidayGift_33 globalHandle(262145).At(23443).As<int>() = 1;
#define RecoveryHolidayGift_34 globalHandle(262145).At(25822).As<int>() = 1;
#define RecoveryHolidayGift_35 globalHandle(262145).At(25824).As<int>() = 1;

#define Idle_Kick_1 globalHandle(262145).At(87).As<int>() = INT_MAX;//Global_262145.f_87
#define Idle_Kick_2 globalHandle(262145).At(88).As<int>() = INT_MAX;//Global_262145.f_88
#define Idle_Kick_3 globalHandle(262145).At(89).As<int>() = INT_MAX;//Global_262145.f_89
#define Idle_Kick_4 globalHandle(262145).At(90).As<int>() = INT_MAX;//Global_262145.f_90

const int EasyBusinessSellLocal[] = { 698, 17 };

const int InstantHeistLocal[] = { 38396, 1375, 1 };
//const int MiniMapStateGlobal[] = { 2646729, 1593 };//Global_2678393.f_1593
//const int MiniMapStateGlobal[] = { 2646835, 1593 };//Global_2646729.f_1593
//const int MiniMapStateGlobal[] = { 2647042, 1593 };//Global_2646835.f_1593 Global_2647042.f_1593
const int MiniMapStateGlobal[] = { 2647061, 1593 };//Global_2647042.f_1593

//const int VisionGlobal[] = { 1853910, 1, 862, 795, 9, 1 };/*1853348, 1, 834, 794, 9, 1*/
//const int VisionGlobal[] = { 1845263, 877, 833, 11 };
const int VisionGlobal[] = { 1845281, 883, 849, 11 };//Global_1845263[i /*877*/].f_833.f_

//const int WeatherGlobal[] = { TunnablesGlobal[0], 4752 };//Global_262145.f_4752
const int WeatherGlobal[] = { TunnablesGlobal[0], 4413 };//Global_262145.f_4575 //fm_mission_creator

//const int JoinCEOGlobal[] = { 1886967, 609, 10 };//Global_1894573[PLAYER::PLAYER_ID() /*608*/].f_10 DONE
//const int JoinCEOGlobal[] = { 1887305, 610, 10 };//Global_1886967[PLAYER::PLAYER_ID() /*609*/].f_10
const int JoinCEOGlobal[] = { 1888737, 611, 10 };//Global_1886967[PLAYER::PLAYER_ID() /*609*/].f_10
const int CEOMoneyGlobal[] = { -337848027, 198210293 /*SERVICE_EARN_FMBB_WAGE_BONUS*/ };//75579707, 198210293

//const int JoinCEOGlobal[] = { 1895156, 609, 10 };//Global_1892703[PLAYER::PLAYER_ID() /*599*/].f_10 //FMMC_MPM_TY16
//const int JoinCEOGlobal[] = { 1894573, 608, 10 };//Global_1892703[PLAYER::PLAYER_ID() /*599*/].f_10
//const int CEOMoneyGlobal[] = { 245065909, 198210293 };//547083265, 198210293
//const int CEOMoneyGlobal[] = { 75579707, 198210293 };//245065909, 198210293

//const int CEOMoneyGlobal[] = { -337848027, 198210293 };//75579707, 198210293

const int BunkerResearchGlobal[] = { TunnablesGlobal[0], 22067 };//Global_262145.f_22037
//const int BunkerResearchGlobal[] = { TunnablesGlobal[0], 21857 };//Global_262145.f_21901
//const int AvengerGlobal[] = { 2793044, 933 };//Global_2815059.f_921
//const int TerrobyteGlobal[] = { 2793044, 937 };//Global_2815059.f_925
//const int KosatkaGlobal[] = { 2793044, 954 };//Global_2815059.f_933
//const int DingyGlobal[] = { 2793044, 988 };//Global_2815059.f_945
//const int BallisticArmorGlobal[] = { 2793044, 896 };//Global_2815059.f_884
//const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20288 };//Global_262145.f_20333
//int BallisticArmorGlobal[] = { 2793044, 896 };//Global_2815059.f_884
//const int BallisticArmorGlobal[] = { 2738587, 901 };//Global_2794162.f_901
//const int BallisticArmorGlobal[] = { 2738587, 901 };//Global_2794162.f_901
//const int BallisticArmorGlobal[] = { 2738934, 916 };//Global_2738587.f_901
const int BallisticArmorGlobal[] = { 2740054,928 };//2738934, 916 //Global_2738587.f_901 //AM_AMMO_DROP
const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20089 };//Global_262145.f_20318 //19851 //CELL_MP_1009H
const int FastRespawnGlobal[] = { 2672964, 1761, 756 }; //2672855, 1728, 756 //Global_2672741.f_1689.f_756 //timerbar_lines

//int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20288 };//Global_262145.f_20333
//const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20318 };//Global_262145.f_20288
//const int FreeBallisticArmorGlobal[] = { TunnablesGlobal[0], 20318 };//Global_262145.f_20288
//const int FastRespawnGlobal[] = { 2672741, 1689, 756 };//Global_2672524.f_1685.f_756 Global_2672741.f_1689.f_756
//const int MOCGlobal[] = { 2738934, 945 };//Global_2738587.f_930 = 1;
//const int MOCGlobal[] = { 2738587, 930 };//Global_2794162.f_930 Global_2738587.f_930 = 1;
//const int MOCGlobal[] = { 2793044, 925 };//Global_2815059.f_913 MP_JOB_CHANGE_RADIO_MUTE
//const int BullsharkGlobal[] = { 2672505, 3689 };//Global_2703735.f_3576
//const int AirstrikeGlobal[] = { 2793044, 4485 };//Global_2815059.f_4455 am_airstrike
//const int AmmoDropGlobal[] = { 2793044, 900 };//Global_2815059.f_888
//const int CrateDropGlobal[] = { 2793044, 894 };//Global_2815059.f_882

//const int AcidLabGlobal[] = { 2738587, 944 };//Global_2794162.f_944 Global_2738587.f_944 = 0;
//const int AvengerGlobal[] = { 2738587, 938 };//Global_2794162.f_938 Global_2738587.f_938 = 1;
//const int TerrobyteGlobal[] = { 2738587, 943 };//Global_2794162.f_943 Global_2738587.f_930
//const int KosatkaGlobal[] = { 2738587, 960 };//Global_2794162.f_960 Global_2738587.f_960
//const int DingyGlobal[] = { 2738587, 972 };//Global_2794162.f_972 Global_2738587.f_972

const int TaxiGlobal[] = { 2740054, 880 }; //2738934, 868 FM_IHELP_BST //if (!IS_BIT_SET(Global_2740054.f_880, 2))
//
const int MOCGlobal[] = { 2738934, 945 };//Global_2738587.f_930 = 1;
const int AcidLabGlobal[] = { 2738934, 959 };//Global_2738587.f_944 = 0;
const int AcidLabBikeGlobal[] = { 2738934, 1009 };//Global_2738587.f_944 = 0;

const int AvengerGlobal[] = { 2738934, 953 };//Global_2738587.f_938 = 1;
const int TerrobyteGlobal[] = { 2738934, 958 };//Global_2738587.f_943
const int KosatkaGlobal[] = { 2738934, 975 };//Global_2738587.f_960
const int DingyGlobal[] = { 2738934, 987 };//Global_2738587.f_972
//const int BullsharkGlobal[] = { 2672524, 3690 };//Global_2672505.f_3690
//const int AirstrikeGlobal[] = { 2794162, 4492 };//Global_2793046.f_4485
//const int AmmoDropGlobal[] = { 2794162, 905 };//Global_2793046.f_900
//const int CrateDropGlobal[] = { 2794162, 899 };//Global_2793046.f_894

//const int BullsharkGlobal[] = { 2672741, 3694 };//Global_2672524.f_3690
//const int AirstrikeGlobal[] = { 2738587, 4492 };//Global_2794162.f_4492 Global_2738587.f_4492
//const int AmmoDropGlobal[] = { 2738587, 905 };//Global_2794162.f_905 Global_2738587.f_905
//const int CrateDropGlobal[] = { 2738587, 899 };//Global_2794162.f_899 Global_2738587.f_899

const int BoatPickupGlobal[] = { 2738934, 907 };//Global_2738587.f_892
const int MiniTankGlobal[] = { 2738934, 6957 };//Global_2738587.f_6919
const int RCBanditoGlobal[] = { 2740054, 7011 };//Global_2738587.f_6918 //rcbandito if (Global_2740054.f_7011) //2738934, 6956
const int DroneGlobal[] = { 1959772 };//Global_1956030 //am_mp_drone //1956920

const int BullsharkGlobal[] = { 2672964, 3766 };//Global_2672741.f_3694 //BULL_SHARK_TESTOSTERONE_01 if (IS_BIT_SET(Global_2672964.f_3766, 4)) //2672855, 3733
const int AirstrikeGlobal[] = { 2740054, 4525 };//Global_2738587.f_4492 //am_airstrike  		case 1: if (Global_2740054.f_4525) //2738934, 4507
const int AmmoDropGlobal[] = { 2740054, 932 };//Global_2738587.f_905 //MP_CELEB_SCREEN_SCENE //if (Global_2740054.f_932) //2738934, 920
const int CrateDropGlobal[] = { 2740054, 926 };//Global_2738587.f_899 //AM_BRU_BOX //2738934, 914 //if (Global_2740054.f_926)

//const int BoatPickupGlobal[] = { 2793044, 887 };//Global_2815059.f_875
//const int BoatPickupGlobal[] = { 2738587, 892 };//Global_2794162.f_892
//const int HelicopterBackupGlobal[] = { 2793044, 4484 };//Global_2815059.f_4454
//const int HelicopterPickupGlobal[] = { 2793044, 888 };//Global_2815059.f_876
//const int SpectateDeathPatchGlobal[] = { 2793044, 6876 };//Global_2815059.f_6753 TRI_WARP
//const int TeleportInPersonalVehicleGlobal[] = { 2639783, 8 };//Global_2671449.f_8
//const int VehicleBypassGlobal[] = { 4540726 };//Global_4539659 shop_controller.c

//const int HelicopterBackupGlobal[] = { 2794162, 4491 };//Global_2793046.f_4484
//const int HelicopterPickupGlobal[] = { 2794162, 893 };//Global_2793046.f_888
//const int SpectateDeathPatchGlobal[] = { 2794162, 6881 };//Global_2793046.f_6876
//const int TeleportInPersonalVehicleGlobal[] = { 2639889, 8 };//Global_2639783.f_8
//const int VehicleBypassGlobal[] = { 4540731 };//Global_4540726 shop_controller.c

//const int SpectateDeathPatchGlobal[] = { 2794162, 6881 };//Global_2793046.f_6876

//const int HelicopterBackupGlobal[] = { 2738587, 4491 };//Global_2794162.f_4491 Global_2738587.f_4491
//const int HelicopterPickupGlobal[] = { 2738587, 893 };//Global_2794162.f_893 Global_2738587.f_893
//const int SpectateDeathPatchGlobal[] = { 2738587, 6920 };//Global_2794162.f_6881 Global_2738587.f_6920
//const int TeleportInPersonalVehicleGlobal[] = { 2640095, 8 };//Global_2639889.f_8
//const int VehicleBypassGlobal[] = { 4541512 };//4541411//Global_4540726 shop_controller.c //calico +8times
const int HelicopterBackupGlobal[] = { 2738934, 4506 };//Global_2738587.f_4491
const int HelicopterPickupGlobal[] = { 2738934, 908 };//Global_2738587.f_893
const int SpectateDeathPatchGlobal[] = { 2738934, 6958 };//Global_2738587.f_6920
const int TeleportInPersonalVehicleGlobal[] = { 2640096, 8 };//Global_2640095.f_8
//
//const int VehicleBypassGlobal[] = { 4541512 };//Global_4541411 shop_controller.c
const int VehicleBypassGlobal[] = { 4542730 };//4542146 //Global_4541411 shop_controller.c //4541512 //https://github.com/dwep1337/GTAV-Decompiled-Scripts
//le deuxième
// != 999

//   if (Global_4542146)
//return false;
//
//if (Global_4542147)
//return true;
//
//if (func_226() || func_1520() || func_1519() || HUD::BUSYSPINNER_IS_ON())
//return false;

//const int PlayerPictureGlobal[] = { 1666668, 2 };//Global_1660783[iVar0 /*5*/].f_2
//const int PlayerPictureGlobal[] = { 1666485, 2 };//Global_1666668[iVar0 /5/].f_2
//const int PlayerPictureGlobal[] = { 1680805, 2 };//Global_1666668[iVar0 /5/].f_2
//const int PlayerPictureGlobal[] = { 1681225, 2 };//Global_1666668[iVar0 /5/].f_2
const int PlayerInfoGlobal[] = { 1845281, 883, 206 };//Global_1845263[PLAYER::PLAYER_ID() /877/].f_205
//const int MiniTankGlobal[] = { 2793044, 6875 };//Global_2815059.f_6752
//const int RCBanditoGlobal[] = { 2793044, 6874 };//Global_2815059.f_6751
//const int DroneGlobal[] = { 1962996 };//AM_MP_DRONE
//const int DroneGlobal[] = { 1963795 };//AM_MP_DRONE

//const int MiniTankGlobal[] = { 2738587, 6919 };//Global_2794162.f_6880 Global_2738587.f_6919
//const int RCBanditoGlobal[] = { 2738587, 6918 };//Global_2794162.f_6879 Global_2738587.f_6918
//const int DroneGlobal[] = { 1956920 };//1956030//Global_1963795//am_mp_drone

//const int DisableErrorScreenGlobal[] = { 4536677 };//Global_4536673
//const int InteriorStateGlobal[] = { 2657704, 1, 463, 245 };//Global_2657589[bVar0 /*466*/].f_245
//const int BusinessGlobal[] = { 1853988, 867, 267, 193, 13 };//Global_1853910[PLAYER::PLAYER_ID() /*862*/].f_267.f_193[bParam0 /*13*/]
//const int AddBusinessSupplyGlobal[] = { 1648657, 1 };//Global_1648637
//const int NightClubStockGlobal[] = { 1853988, 867, 267, 311, 8 };//Global_1853910[PLAYER::PLAYER_ID() /*862*/].f_267.f_310.f_8
//const int NightClubVaultGlobal[] = { 1853988, 867, 267, 354, 5 };//Global_1853910[PLAYER::PLAYER_ID() /*862*/].f_267.f_353.f_5
//const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 24553 };//Global_262145.f_24371
//const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 24548 };//Global_262145.f_24366
//const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 24551 };//Global_262145.f_24369
//const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 24554 };//Global_262145.f_24372
//const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 24552 };//Global_262145.f_24370
//const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 24549 };//Global_262145.f_24367
//const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 24550 };//Global_262145.f_24368
//const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 24575 };//Global_262145.f_24393
//const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 24570 };//Global_262145.f_24388
//const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 24573 };//Global_262145.f_24391
//const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 24576 };//Global_262145.f_24394
//const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 24574 };//Global_262145.f_24392
//const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 24571 };//Global_262145.f_24389
//const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 24572 };//Global_262145.f_24390
//const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 24561 };//Global_262145.f_24379
//const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 24556 };//Global_262145.f_24374
//const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 24559 };//Global_262145.f_24377
//const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 24562 };//Global_262145.f_24380
//const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 24560 };//Global_262145.f_24378
//const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 24557 };//Global_262145.f_24375
//const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 24558 };//Global_262145.f_24376
//const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17573, 3000000 };//Global_262145.f_17393
//const int MethBoostGlobal[] = { TunnablesGlobal[0], 17572, 1800000 };//Global_262145.f_17392
//const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17571, 360000 };//Global_262145.f_17391
//const int CashBoostGlobal[] = { TunnablesGlobal[0], 17575, 720000 };//Global_262145.f_17395
//const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17574, 300000 };//Global_262145.f_17394
//const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21712 , 600000 };//Global_262145.f_21532
const int DisableErrorScreenGlobal[] = { 4537455 };//Global_4537356
const int InteriorStateGlobal[] = { 2657971, 1, 465, 246 };//Global_2657921[bVar0 /*463*/].f_245
const int BusinessGlobal[] = { 1845281, 883, 268, 197, 13 };//Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_195[iParam0 /*13*/]
const int AddBusinessSupplyGlobal[] = { 1663182, 1 };//Global_1662881 [[fallthrough]];
const int NightClubStockGlobal[] = { 1845281, 883, 268, 315, 8 };//Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_313.f_8[num]
const int NightClubVaultGlobal[] = { 1845281, 883, 268, 358, 5 };//Global_1845263[PLAYER::PLAYER_ID() /*877*/].f_267.f_356.f_5

const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 23953 };//Global_262145.f_24583
const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 23948 };//Global_262145.f_24578
const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 23951 };//Global_262145.f_24581
const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 23954 };//Global_262145.f_24584
const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 23952 };//Global_262145.f_24582
const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 23949 };//Global_262145.f_24579
const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 23950 };//Global_262145.f_24580
const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 23975 };//Global_262145.f_24605
const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 23970 };//Global_262145.f_24600
const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 23973 };//Global_262145.f_24603
const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 23976 };//Global_262145.f_24606
const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 23974 };//Global_262145.f_24604
const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 23971 };//Global_262145.f_24601
const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 23972 };//Global_262145.f_24602
const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 23961 };//Global_262145.f_24591
const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 23956 };//Global_262145.f_24586
const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 23959 };//Global_262145.f_24589
const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 23962 };//Global_262145.f_24592
const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 23960 };//Global_262145.f_24590
const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 23957 };//Global_262145.f_24587
const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 23958 };//Global_262145.f_24588
const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17601, 3000000 };//Global_262145.f_17601
const int MethBoostGlobal[] = { TunnablesGlobal[0], 17291, 1800000 };//Global_262145.f_17600
const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17290, 360000 };//Global_262145.f_17599
const int CashBoostGlobal[] = { TunnablesGlobal[0], 17294, 720000 };//Global_262145.f_17603
const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17293, 300000 };//Global_262145.f_17602
const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21249 , 600000 };//Global_262145.f_21742

//const int DisableErrorScreenGlobal[] = { 4537356 };//Global_4536677
//const int InteriorStateGlobal[] = { 2657921, 1, 463, 245 };//Global_2657704[bVar0 /*463*/].f_245
//const int BusinessGlobal[] = { 1845263, 877, 267, 195, 13 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_193[bParam0 /*13*/] Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_195[iParam0 /*13*/]
//const int AddBusinessSupplyGlobal[] = { 1662881, 1 };//Global_1648657
//const int NightClubStockGlobal[] = { 1845263, 877, 267, 313, 8 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_311.f_8 Global_1845263[unk_0x259BE71D8A81D4FA() /*877*/].f_267.f_313.f_8[num]
//const int NightClubVaultGlobal[] = { 1845263, 877, 267, 356, 5 };//Global_1853988[PLAYER::PLAYER_ID() /*867*/].f_267.f_354.f_5
//
//const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 24583 };//Global_262145.f_24553 Global_262145.f_24583
//const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 24578 };//Global_262145.f_24548 Global_262145.f_24578
//const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 24581 };//Global_262145.f_24551 Global_262145.f_24581
//const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 24584 };//Global_262145.f_24554 Global_262145.f_24584
//const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 24582 };//Global_262145.f_24552 Global_262145.f_24582
//const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 24579 };//Global_262145.f_24549 Global_262145.f_24579
//const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 24580 };//Global_262145.f_24550 Global_262145.f_24580
//const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 24605 };//Global_262145.f_24575 Global_262145.f_24605
//const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 24600 };//Global_262145.f_24570 Global_262145.f_24600
//const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 24603 };//Global_262145.f_24573 Global_262145.f_24603
//const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 24606 };//Global_262145.f_24576 Global_262145.f_24606
//const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 24604 };//Global_262145.f_24574 Global_262145.f_24604
//const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 24601 };//Global_262145.f_24571 Global_262145.f_24601
//const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 24602 };//Global_262145.f_24572 Global_262145.f_24602
//const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 24591 };//Global_262145.f_24561 Global_262145.f_24591
//const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 24586 };//Global_262145.f_24556 Global_262145.f_24586
//const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 24589 };//Global_262145.f_24559 Global_262145.f_24589
//const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 24592 };//Global_262145.f_24562 Global_262145.f_24592
//const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 24590 };//Global_262145.f_24560 Global_262145.f_24590
//const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 24587 };//Global_262145.f_24557 Global_262145.f_24587
//const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 24588 };//Global_262145.f_24558 Global_262145.f_24588
//const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17601, 3000000 };//Global_262145.f_17573 Global_262145.f_17601
//const int MethBoostGlobal[] = { TunnablesGlobal[0], 17600, 1800000 };//Global_262145.f_17572 Global_262145.f_17600
//const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17599, 360000 };//Global_262145.f_17571 Global_262145.f_17599
//const int CashBoostGlobal[] = { TunnablesGlobal[0], 17603, 720000 };//Global_262145.f_17575 Global_262145.f_17603
//const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17602, 300000 };//Global_262145.f_17574 Global_262145.f_17602
//const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21742 , 600000 };//Global_262145.f_21712 Global_262145.f_21742

//const int DisableErrorScreenGlobal[] = { 4536673 };//Global_4535606
//const int InteriorStateGlobal[] = { 2657589, 1, 466, 245 };//Global_2689235[bVar0 /*453*/].f_243
//const int BusinessGlobal[] = { 1853910, 862, 267, 193, 13 };//Global_1853348[PLAYER::PLAYER_ID() /*834*/].f_267.f_191[bParam0 /*13*/]
//const int AddBusinessSupplyGlobal[] = { 1648637, 1 };//Global_1640642
//const int NightClubStockGlobal[] = { 1853910, 862, 267, 310, 8 };//Global_1853348[PLAYER::PLAYER_ID() /*834*/].f_267.f_295.f_8
//const int NightClubVaultGlobal[] = { 1853910, 862, 267, 353, 5 };//Global_1853348[PLAYER::PLAYER_ID() /*834*/].f_267.f_336.f_5
//const int CashCreationTimerGlobal[] = { TunnablesGlobal[0], 24371 };//Global_262145.f_24399
//const int SportingGoodsTimerGlobal[] = { TunnablesGlobal[0], 24366 };//Global_262145.f_24394
//const int OrganicProduceTimerGlobal[] = { TunnablesGlobal[0], 24369 };//Global_262145.f_24397
//const int CargoandShipmentsTimerGlobal[] = { TunnablesGlobal[0], 24372 };//Global_262145.f_24400
//const int PrintingCopyingTimerGlobal[] = { TunnablesGlobal[0], 24370 };//Global_262145.f_24398
//const int AmericanImportsTimerGlobal[] = { TunnablesGlobal[0], 24367 };//Global_262145.f_24395
//const int PharmaceuticalTimerGlobal[] = { TunnablesGlobal[0], 24368 };//Global_262145.f_24396
//const int CashCreationMaxStockGlobal[] = { TunnablesGlobal[0], 24393 };//Global_262145.f_24421
//const int SportingGoodsMaxStockGlobal[] = { TunnablesGlobal[0], 24388 };//Global_262145.f_24416
//const int OrganicProduceMaxStockGlobal[] = { TunnablesGlobal[0], 24391 };//Global_262145.f_24419
//const int CargoandShipmentsMaxStockGlobal[] = { TunnablesGlobal[0], 24394 };//Global_262145.f_24422
//const int PrintingCopyingMaxStockGlobal[] = { TunnablesGlobal[0], 24392 };//Global_262145.f_24420
//const int AmericanImportsMaxStockGlobal[] = { TunnablesGlobal[0], 24389 };//Global_262145.f_24417
//const int PharmaceuticalMaxStockGlobal[] = { TunnablesGlobal[0], 24390 };//Global_262145.f_24418
//const int CashCreationPriceGlobal[] = { TunnablesGlobal[0], 24379 };//Global_262145.f_24407
//const int SportingGoodsPriceGlobal[] = { TunnablesGlobal[0], 24374 };//Global_262145.f_24402
//const int OrganicProducePriceGlobal[] = { TunnablesGlobal[0], 24377 };//Global_262145.f_24405
//const int CargoandShipmentsPriceGlobal[] = { TunnablesGlobal[0], 24380 };//Global_262145.f_24408
//const int PrintingCopyingPriceGlobal[] = { TunnablesGlobal[0], 24378 };//Global_262145.f_24406
//const int AmericanImportsPriceGlobal[] = { TunnablesGlobal[0], 24375 };//Global_262145.f_24403
//const int PharmaceuticalPriceGlobal[] = { TunnablesGlobal[0], 24376 };//Global_262145.f_24404
//const int CocaineBoostGlobal[] = { TunnablesGlobal[0], 17393, 3000000 };//Global_262145.f_17448
//const int MethBoostGlobal[] = { TunnablesGlobal[0], 17392, 1800000 };//Global_262145.f_17447
//const int WeedBoostGlobal[] = { TunnablesGlobal[0], 17391, 360000 };//Global_262145.f_17446
//const int CashBoostGlobal[] = { TunnablesGlobal[0], 17395, 720000 };//Global_262145.f_17450
//const int DocumentsBoostGlobal[] = { TunnablesGlobal[0], 17394, 300000 };//Global_262145.f_17449
//const int BunkerBoostGlobal[] = { TunnablesGlobal[0], 21532 , 600000 };//Global_262145.f_21576
//auto mechanic_global = script_global(2793046);//2815059
//auto vehicle_global = script_global(1586468);//1585857

//int DisableErrorScreenGlobal[] = { 4535606 };
//int BallisticArmorGlobal[] = { 2815059, 884 };
//int FreeBallisticArmorGlobal[] = { 262145, 20333 };
//const int VehicleBypassGlobal[] = { 4539659 };
//const int DroneGlobal[] = { 1958711 };

const int BusinessStockGlobal[] = { 1853348, 834, 267, 191, 13, 1 };
const int BusinessSupplyGlobal[] = { 1853348, 834, 267, 191, 13, 3 };

//int NightClubStockGlobal[] = { 1853348, 834, 267, 295, 8 };
//int NightClubVaultGlobal[] = { 1853348, 834, 267, 336, 5 };
//
//int CashCreationTimerGlobal[] = { 262145, 24399 };
//int SportingGoodsTimerGlobal[] = { 262145, 24394 };
//int OrganicProduceTimerGlobal[] = { 262145, 24397 };
//int CargoandShipmentsTimerGlobal[] = { 262145, 24400 };
//int PrintingCopyingTimerGlobal[] = { 262145, 24398 };
//int AmericanImportsTimerGlobal[] = { 262145, 24395 };
//int PharmaceuticalTimerGlobal[] = { 262145, 24396 };
//
//int CashCreationMaxStockGlobal[] = { 262145, 24421 };
//int SportingGoodsMaxStockGlobal[] = { 262145, 24416 };
//int OrganicProduceMaxStockGlobal[] = { 262145, 24419 };
//int CargoandShipmentsMaxStockGlobal[] = { 262145, 24422 };
//int PrintingCopyingMaxStockGlobal[] = { 262145, 24420 };
//int AmericanImportsMaxStockGlobal[] = { 262145, 24417 };
//int PharmaceuticalMaxStockGlobal[] = { 262145, 24418 };
//
//int CashCreationPriceGlobal[] = { 262145, 24407 };
//int SportingGoodsPriceGlobal[] = { 262145, 24402 };
//int OrganicProducePriceGlobal[] = { 262145, 24405 };
//int CargoandShipmentsPriceGlobal[] = { 262145, 24408 };
//int PrintingCopyingPriceGlobal[] = { 262145, 24406 };
//int AmericanImportsPriceGlobal[] = { 262145, 24403 };
//int PharmaceuticalPriceGlobal[] = { 262145, 24404 };
//
//int BusinessGlobal[] = { 1853348, 834, 267, 191, 13 };
//int AddBusinessSupplyGlobal[] = { 1640642, 1 };

//const int JoinCEOGlobal[] = { 1892703, 599, 10 };

//BountyEvent = 1370461707,//1294995624

//int iParam0, var uParam1, int iParam2, int iParam3, int iParam4//above second//freemode
//constexpr auto BountyTransaction = 1920255;//1921039


namespace scr_globals
{
	namespace size
	{
		constexpr int globalplayer_bd = 466; //453
		constexpr int gpbd_fm_3 = 608; //599
		constexpr int gpbd_fm_1 = 862; //888
	}

	namespace offset
	{
		namespace globalplayer_bd
		{
			constexpr int orbital_cannon_bitset = 416;
		}
	}

	//static inline ScriptGlobal gsbd(2648605); //2680265
	//static inline ScriptGlobal gsbd_fm(1835504); //1923597 //1835502
	//static inline ScriptGlobal gsbd_kicking(1885209); //1883751
	//static inline ScriptGlobal gsbd_fm_events(BountyTransaction); //1920255
	//static inline ScriptGlobal gsbd_block_c(2652258); //2683918

	//static inline ScriptGlobal gsbd(2648711);
	//static inline ScriptGlobal gsbd_fm(1835504);
	//static inline ScriptGlobal gsbd_kicking(1885447);
	//static inline ScriptGlobal gsbd_fm_events(1924276);
	//static inline ScriptGlobal gsbd_block_c(2652364);

	//static inline ScriptGlobal gsbd(2648918);
	//static inline ScriptGlobal gsbd_fm(1845263);
	//static inline ScriptGlobal gsbd_kicking(1877042);
	//static inline ScriptGlobal gsbd_fm_events(1916087);
	//static inline ScriptGlobal gsbd_block_c(2652572);

	static inline ScriptGlobal gsbd(2648929);
	static inline ScriptGlobal gsbd_kicking(1876908);
	static inline ScriptGlobal gsbd_fm_events(1918241);

	//static inline ScriptGlobal gsbd(2648938);
	//static inline ScriptGlobal gsbd_fm(1845281);
	//static inline ScriptGlobal gsbd_kicking(1877042);
	//static inline ScriptGlobal gsbd_fm_events(1916617);
	//static inline ScriptGlobal gsbd_block_c(2657971);
	//static inline ScriptGlobal gsbd_property_instances(1936863);
	//static inline ScriptGlobal globalplayer_bd(2657589); //2689235
	//static inline ScriptGlobal gpbd_fm_3(1894573); //1892703
	//static inline ScriptGlobal gpbd_fm_1(1853910); //1853348

	//static inline ScriptGlobal globalplayer_bd(2657704);
	//static inline ScriptGlobal gpbd_fm_3(1895156);
	//static inline ScriptGlobal gpbd_fm_1(1853988);

	//static inline ScriptGlobal globalplayer_bd(2657921);
	//static inline ScriptGlobal gpbd_fm_3(1886967);
	//static inline ScriptGlobal gpbd_fm_1(1845263);
	//static inline ScriptGlobal interiors(1942781);

	//static inline ScriptGlobal globalplayer_bd(2657971);
	//static inline ScriptGlobal gpbd_fm_3(1887305);
	//static inline ScriptGlobal gpbd_fm_1(1845281);
	//static inline ScriptGlobal interiors(1943520);

	static inline ScriptGlobal globalplayer_bd(2658016);
	static inline ScriptGlobal gpbd_fm_3(1888737);
	static inline ScriptGlobal gpbd_fm_1(1845225);
	static inline ScriptGlobal interiors(1945923);

	//static inline ScriptGlobal launcher_global(2756257); //2779753

	//static inline ScriptGlobal launcher_global(2756336);
	//static inline ScriptGlobal launcher_global(2699171);
	//static inline ScriptGlobal launcher_global(2699172);
	static inline ScriptGlobal launcher_global(2699544);

	/*static inline ScriptGlobal launcher_global(2698947);*/

	//static inline ScriptGlobal sp(113648); //113386
	//static inline ScriptGlobal mission_definition(91469); //91229

	//static inline ScriptGlobal sp(113810); // check flow_controller
	//static inline ScriptGlobal mission_definition(91601); // standard_global_init (66, "agency_heist1", "AH1", 230, 1, 1, -1, -1, 8192)

	//static inline ScriptGlobal sp(114370); // check flow_controller
	static inline ScriptGlobal mission_definition(92160); // standard_global_init (66, "agency_heist1", "AH1", 230, 1, 1, -1, -1, 8192)

	//static inline ScriptGlobal creator_job_metadata(4718592);
	//static inline ScriptGlobal terminate_creator(1574607); // NETWORK::NETWORK_BAIL(1, 0, 0); fm_*_creator
	//static inline ScriptGlobal switch_struct(1574632); //1574632
	//static inline ScriptGlobal mission_creator_radar_follows_camera(2621443);
	//static inline ScriptGlobal mission_creator_exited(1574530);

	static inline ScriptGlobal creator_job_metadata(4718592);
	static inline ScriptGlobal terminate_creator(1574607); // NETWORK::NETWORK_BAIL(1, 0, 0); fm_*_creator
	/*static inline ScriptGlobal switch_struct(1574632);*/
	static inline ScriptGlobal switch_struct(1574633);
	static inline ScriptGlobal mission_creator_radar_follows_camera(2621443);
	static inline ScriptGlobal mission_creator_exited(1574530);

	//static inline ScriptGlobal in_multiplayer(78558); // g_bInMultiplayer //78319

	//static inline ScriptGlobal in_multiplayer(78689); // g_bInMultiplayer
	//static inline ScriptGlobal transition_state(1574996);

	//static inline ScriptGlobal in_multiplayer(79248); // g_bInMultiplayer
	//static inline ScriptGlobal transition_state(1575008);
	//static inline ScriptGlobal sctv_spectator(2697509); // pausemenu_multiplayer function 0xE49C42EC

	static inline ScriptGlobal in_multiplayer(79389); // g_bInMultiplayer
	static inline ScriptGlobal transition_state(1575011);
	//static inline ScriptGlobal sctv_spectator(2697731); // pausemenu_multiplayer function 0xE49C42EC
	static inline ScriptGlobal sctv_spectator(2697732); // pausemenu_multiplayer function 0xE49C42EC


	//static inline ScriptGlobal vehicle_global = ScriptGlobal(1586468);//1585857
	//static inline ScriptGlobal mechanic_global = ScriptGlobal(2793044); //2815059

	//static inline ScriptGlobal spawn_global = ScriptGlobal(2694560);//2725439

	//static inline ScriptGlobal vehicle_global = ScriptGlobal(1586488);
	/*static inline ScriptGlobal vehicle_global(1586504);*/
	//static inline ScriptGlobal vehicle_global(1586521);
	static inline ScriptGlobal vehicle_global(1586540);
	//static inline ScriptGlobal mechanic_global = ScriptGlobal(2794162);

	//static inline ScriptGlobal spawn_global = ScriptGlobal(2694613);

	//static inline ScriptGlobal offradar_time(2672524);

	/*static inline ScriptGlobal freemode_properties(2672741);
	static inline ScriptGlobal freemode_global(2738587);*/
	//static inline const ScriptGlobal freemode_properties(2672855);
	//static inline const ScriptGlobal freemode_global(2738934);
	//static inline const ScriptGlobal freemode_global(2738935);
	static inline ScriptGlobal freemode_properties(2672964);
	static inline ScriptGlobal freemode_global(2740054);

	/*static inline ScriptGlobal spawn_global(2695991);*/
	//static inline ScriptGlobal spawn_global(2696212);
	static inline ScriptGlobal spawn_global(2696579);
	/*static inline ScriptGlobal dance_state(1942774);*/
	//static inline ScriptGlobal dance_state(1943520);
	/*static inline ScriptGlobal transaction_overlimit(20796);*/
	//static inline ScriptGlobal transaction_overlimit(20913);
	static inline ScriptGlobal transaction_overlimit(4538671);
	//static inline ScriptGlobal stats(2359296);
	static inline ScriptGlobal stats(2359296);
	//static inline ScriptGlobal session(1574589);
	//static inline ScriptGlobal session2(1575032);
	//static inline ScriptGlobal session3(32829);
	//static inline ScriptGlobal session4(1574941);
	//static inline ScriptGlobal session5(1575007);
	//static inline ScriptGlobal session6(2695909);
	//static inline ScriptGlobal session(1574589);
	//static inline ScriptGlobal session2(1575035);
	//static inline ScriptGlobal session3(32949);
	//static inline ScriptGlobal session4(1574942);
	//static inline ScriptGlobal session5(1575010);
	//static inline ScriptGlobal session6(2696130);
	//static inline ScriptGlobal gooch(1882037);
	static inline ScriptGlobal session(1574589);
	static inline ScriptGlobal session2(1575038);
	static inline ScriptGlobal session3(33282);
	static inline ScriptGlobal session4(1574943);
	static inline ScriptGlobal session5(1575013);
	static inline ScriptGlobal session6(2696496); // freemode -> if (NETWORK::NETWORK_IS_GAME_IN_PROGRESS() && !NETWORK::NETWORK_IS_ACTIVITY_SESSION())

	//static inline const ScriptGlobal gun_van(1949748); // return -29.532f, 6435.136f, 31.162f;
	static inline ScriptGlobal gun_van(1952452); // return -29.532f, 6435.136f, 31.162f;
	//static inline ScriptGlobal gun_van(1948900);

	//static inline ScriptGlobal interaction_menu_access(2710115); // am_pi_menu -> PI_BIK_13_2_H -> global = true;
	//static inline ScriptGlobal interaction_menu_access(2710429); // am_pi_menu -> PI_BIK_13_2_H -> global = true;
	//static inline ScriptGlobal interaction_menu_access(2710430); // am_pi_menu -> PI_BIK_13_2_H -> global = true;
	static inline ScriptGlobal interaction_menu_access(2711261); // am_pi_menu -> if (NETWORK::NETWORK_IS_SIGNED_ONLINE()) first global after that

	//static inline ScriptGlobal disable_wasted_sound(2707352); // freemode -> AUDIO::PLAY_SOUND_FRONTEND(-1, "Wasted", "POWER_PLAY_General_Soundset", true);
	//static inline ScriptGlobal disable_wasted_sound(2707679); // freemode -> AUDIO::PLAY_SOUND_FRONTEND(-1, "Wasted", "POWER_PLAY_General_Soundset", true);
	//static inline ScriptGlobal disable_wasted_sound(2707680); // freemode -> AUDIO::PLAY_SOUND_FRONTEND(-1, "Wasted", "POWER_PLAY_General_Soundset", true);
	static inline ScriptGlobal disable_wasted_sound(2708261); // freemode -> AUDIO::PLAY_SOUND_FRONTEND(-1, "Wasted", "POWER_PLAY_General_Soundset", true);

	static inline ScriptGlobal passive(1574582);

	//static inline ScriptGlobal property_garage(1936959);
	//static inline ScriptGlobal property_names(1312263);
	/*static inline ScriptGlobal property_garage(1586521);
	static inline ScriptGlobal property_names(1312298);*/
	static inline ScriptGlobal property_garage(1940049);
	static inline ScriptGlobal property_names(1312335);
	static inline ScriptGlobal pickups(2707706);

	//static inline ScriptGlobal reset_clothing(103936); // freemode 75, &iLocal_.*, 2\);
	//static inline ScriptGlobal reset_clothing(104077); // freemode 75, &iLocal_.*, 2\);
	static inline ScriptGlobal reset_clothing(104448); // freemode 75, &iLocal_.*, 2\);

	//static inline ScriptGlobal gsbd_property_instances(1944302);
	//static inline ScriptGlobal gsbd_property_instances(1936138);

}


namespace Addresss
{
	extern DWORD64 AddressPTR1;
	extern char* AddressPTR2;
	extern DWORD64 AddressPTR01;
	extern char* AddressPTR02;
	extern DWORD64 SunPointer;
	extern DWORD64 getSunPointer;
	extern DWORD64 SunPointerred;
	extern DWORD64 SunPointergreen;
	extern DWORD64 SunPointerblue;
	extern DWORD64 SunPointerpatch;
	extern DWORD64 SunPointerat;
	extern DWORD64 getSunPointerat;
	extern DWORD64 SunPointerredat;
	extern DWORD64 SunPointergreenat;
	extern DWORD64 SunPointerblueat;
	extern DWORD64 SunPointerpatchat;
	extern DWORD64 StarPointer;
	extern DWORD64 getStarPointer;
	extern DWORD64 StarIntensity;
	extern DWORD64 StarPointerred;
	extern DWORD64 StarPointergreen;
	extern DWORD64 StarPointerblue;
	extern DWORD64 StarPointerpatch;
	extern DWORD64 StarPointer2;
	extern DWORD64 getStarPointer2;
	extern DWORD64 StarIntensity2;
	extern DWORD64 StarPointerred2;
	extern DWORD64 StarPointergreen2;
	extern DWORD64 StarPointerblue2;
	extern DWORD64 StarPointerpatch2;
	extern DWORD64 MoonPointer;
	extern DWORD64 getMoonPointer;
	extern DWORD64 MoonPointerred;
	extern DWORD64 MoonPointergreen;
	extern DWORD64 MoonPointerblue;
	extern DWORD64 MoonPointerpatch;
	extern DWORD64 MoonPointerpatch_;
	extern DWORD64 SkyPointer;
	extern DWORD64 getSkyPointer;
	extern DWORD64 SkyPointerred;
	extern DWORD64 SkyPointergreen;
	extern DWORD64 SkyPointerblue;
	extern DWORD64 SkyPointerpatch;
	extern DWORD64 SkyPointerpatch_;
	extern DWORD64 SkyIntensity;
	extern DWORD64 SkyPointer1;
	extern DWORD64 getSkyPointer1;
	extern DWORD64 SkyPointerred1;
	extern DWORD64 SkyPointergreen1;
	extern DWORD64 SkyPointerblue1;
	extern DWORD64 SkyPointerpatch1;
	extern DWORD64 SkyIntensity1;
	extern DWORD64 SkyPointer2;
	extern DWORD64 getSkyPointer2;
	extern DWORD64 SkyPointerred2;
	extern DWORD64 SkyPointergreen2;
	extern DWORD64 SkyPointerblue2;
	extern DWORD64 SkyPointerpatch2;
	extern DWORD64 SkyPointerpatch2_;
	extern DWORD64 SkyIntensity2;
	extern DWORD64 SkyPointer3;
	extern DWORD64 getSkyPointer3;
	extern DWORD64 SkyPointerred3;
	extern DWORD64 SkyPointergreen3;
	extern DWORD64 SkyPointerblue3;
	extern DWORD64 SkyPointerpatch3;
	extern DWORD64 SkyPointerpatch3_;
	extern DWORD64 SkyIntensity3;
	extern DWORD64 SkyPointerbw3;
	extern DWORD64 getSkyPointerbw3;
	extern DWORD64 SkyPointerredbw3;
	extern DWORD64 SkyPointergreenbw3;
	extern DWORD64 SkyPointerbluebw3;
	extern DWORD64 SkyPointerpatchbw3;
	extern DWORD64 SkyPointerpatchbw3_;
	extern DWORD64 SkyIntensitybw3;
	extern DWORD64 SkyPointer4;
	extern DWORD64 getSkyPointer4;
	extern DWORD64 SkyPointerpatch4;
	extern DWORD64 SkyIntensity4;
	extern DWORD64 SkyPointer5;
	extern DWORD64 getSkyPointer5;
	extern DWORD64 SkyPointerpatch5;
	extern DWORD64 SkyIntensity5;
}
namespace anywhere
{
	extern int swim();
	extern bool swimbool;
}

namespace HostCrash
{
	extern bool HostCrashbool;
	extern bool boolHostCrash;
	extern void HostCrash();
}

class Networked
{
public:
	static scrThread* Networked::find_networked(std::uint32_t hash)
	{
		/*for (auto thread : *g_GameVariables->script_threads)*/
		for (auto thread : *g_GameVariables->m_scriptThreads)
		{
			if (!thread)
			{
				continue;
			}
			if (thread->m_context.m_state != eThreadState::running)
			{
				continue;
			}
			if (thread->m_context.m_script_hash != hash)
			{
				continue;
			}
			return thread;
		}
		return nullptr;
	}
};


struct PlayersData
{
	std::string PlayerName{};
	float Distance{};
	bool IsFriend{};
	bool IsSameTeam{};
	bool IsEntityExist{};
	Vector3 TargetCoords{};

	//Skeleton Esp
	Vector3 LClavicle{};
	Vector3 LUpperarm{};
	Vector3 LForearm{};
	Vector3 LHand{};
	Vector3 LThigh{};
	Vector3 LCalf{};
	Vector3 LFoot{};
	Vector3 Head{};
	Vector3 Neck{};
	Vector3 Pelvis{};
	Vector3 RClavicle{};
	Vector3 RUpperarm{};
	Vector3 RForearm{};
	Vector3 RHand{};
	Vector3 RThigh{};
	Vector3 RCalf{};
	Vector3 RFoot{};

};
inline PlayersData players_data[32];
namespace myfunctions
{
	extern void function();
	extern void function2();
	extern void givemoney10();
}

static void getThehost(int player) //sendmillion::
{
	Log::Msg("free1");
	if (ForceHost(RAGE_JOAAT("freemode")))
	{
		Log::Msg("free2");
		//if (auto freemode_thread = findscriptthread::findscriptthread2(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
		if (auto freemode_thread = gta_util::find_script_thread(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
		{
			Log::Msg("free3");
			freemode_thread->m_net_component->block_host_migration(true);
			Log::Msg("free4");
			rage2::packet msg/*{}*/;
			Log::Msg("free5");
			msg.write_message(eNetMessage::MsgScriptMigrateHost);
			Log::Msg("free6");
			freemode_thread->m_handler->get_id()->serialize(&msg.m_buffer);
			Log::Msg("free7");
			msg.write<int>(0, 16);
			msg.write<int>(0, 32);
			/*auto msg_id = player->get_net_game_player()->m_msg_id;*/
			Log::Msg("free8");
			auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
			msg.send(msg_id);
			Log::Msg("free9");

			freemode_thread->m_context.m_stack_size *= 2;
			Log::Msg("free10");

		}
	}
}
static int millionchangehash = 288806;

static void moneytenmillion(int player) //sendmillion::
{
	//if (ForceHost(RAGE_JOAAT("freemode")))
	//{
	//	/*simpletime2 simpltime;
	//	simpltime.start(1000);*/

	//	//if (auto freemode_thread = findscriptthread::findscriptthread2(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
	//	if (auto freemode_thread = gta_util::find_script_thread(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
	//	{

	//		freemode_thread->m_net_component->block_host_migration(true);

	//		rage2::packet msg{};
	//		msg.write_message(eNetMessage::MsgScriptMigrateHost);
	//		freemode_thread->m_handler->get_id()->serialize(&msg.m_buffer);
	//		msg.write<int>(0, 16);
	//		msg.write<int>(0, 32);
	//		/*auto msg_id = player->get_net_game_player()->m_msg_id;*/
	//		auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
	//		msg.send(msg_id);

			int one = millionchangehash;
			int two = one + 1;
			int three = one + 2;
			int four = one + 3;
			int five = one + 4;
			int six = one + 5;
			int seven = one + 6;
			int eight = seven / 11;

			//freemode_thread->m_context.m_stack_size *= 2;
			unsigned int playerBit = (1 << Features::Online::selectedPlayer);
			uint64_t args[4] = { milliondrop, PLAYER::PLAYER_ID(), one, 0 };//2764877 - 2764875
			//g_GameFunctions->m_trigger_script_event(1, args, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args1[4] = { milliondrop, PLAYER::PLAYER_ID(), two, 10000000 };//gta_util::get_network_player_mgr()->m_local_net_player->m_player_id
			//g_GameFunctions->m_trigger_script_event(1, args1, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args1, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args2[4] = { milliondrop, PLAYER::PLAYER_ID(), three, 393059668 };
			//g_GameFunctions->m_trigger_script_event(1, args2, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args2, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args3[4] = { milliondrop, PLAYER::PLAYER_ID(), four, 0 };
			//g_GameFunctions->m_trigger_script_event(1, args3, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args3, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args4[4] = { milliondrop, PLAYER::PLAYER_ID(), five, 0 };
			//g_GameFunctions->m_trigger_script_event(1, args4, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args4, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args5[4] = { milliondrop, PLAYER::PLAYER_ID(), six, 1 };
			//g_GameFunctions->m_trigger_script_event(1, args5, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args5, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args6[4] = { milliondrop, PLAYER::PLAYER_ID(), seven, 2147483647 }; //3 func under HAND_SHAKE 
			//g_GameFunctions->m_trigger_script_event(1, args6, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args6, 4, 1 << playerBit, (int)milliondrop);
			uint64_t args7[4] = { milliondrop, PLAYER::PLAYER_ID(), eight, 1 };
			//g_GameFunctions->m_trigger_script_event(1, args7, 4, 1 << playerBit);
			Hooking::trigger_script_event(1, args7, 4, 1 << playerBit, (int)milliondrop);
		/*}
	}*/

}
namespace togglegethost
{
	extern bool gethosttoggle;
}
namespace Newmain
{
	extern void mainshot(int player, int playertarget);
	extern void mainStinger(int playerPed);
}


/*Windows includes*/
#include <windows.h>
#include <windowsx.h>

#include <string>
#include <xstring>

#include <tlhelp32.h>

#include <sstream>
#include <fstream>
#include <filesystem>
#include <iostream>

#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <chrono>

#include <memory>
#include <Psapi.h>

#include <timeapi.h>
#pragma comment(lib, "winmm.lib")

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>

#include <iostream> // Pour la gestion des entrées/sorties standard
#include <string> // Pour les chaînes de caractères
#include <vector> // Pour les tableaux dynamiques
#include <map>    // Pour les tableaux associatifs
#include <cstdint> // Pour les types de données entiers de taille fixe
#include <functional> // Pour les fonctions lambda et les objets fonctionnels
#include <fstream> // Pour les opérations sur les fichiers
#include <cstring> // Pour les opérations de manipulation de chaînes de caractères
#include <cmath> // Pour les fonctions mathématiques


enum VehicleModTypes {
	MOD_SPOILER,
	MOD_FRONTBUMPER,
	MOD_REARBUMPER,
	MOD_SIDESKIRT,
	MOD_EXHAUST,
	MOD_CHASSIS, //Or roll cage
	MOD_GRILLE,
	MOD_HOOD,
	MOD_FENDER,
	MOD_RIGHTFENDER,
	MOD_ROOF,
	MOD_ENGINE,
	MOD_BRAKES,
	MOD_TRANSMISSION,
	MOD_HORNS,
	MOD_SUSPENSION,
	MOD_ARMOR,
	MOD_UNK17 = 17,
	MOD_TURBO = 18,
	MOD_UNK19 = 19,
	MOD_TIRESMOKE = 20,
	MOD_UNK21 = 21,
	MOD_XENONLIGHTS = 22,
	MOD_FRONTWHEELS = 23,
	MOD_BACKWHEELS = 24, //Bikes only

	// Benny's
	MOD_PLATEHOLDER = 25,
	MOD_VANITY_PLATES = 26,
	MOD_TRIM1 = 27,
	MOD_ORNAMENTS = 28,
	MOD_DASHBOARD = 29,
	MOD_DIAL = 30,
	MOD_DOOR_SPEAKER = 31,
	MOD_SEATS = 32,
	MOD_STEERINGWHEEL = 33,
	MOD_SHIFTER_LEAVERS = 34,
	MOD_PLAQUES = 35,
	MOD_SPEAKERS = 36,
	MOD_TRUNK = 37,
	MOD_HYDRULICS = 38,
	MOD_ENGINE_BLOCK = 39,
	MOD_AIR_FILTER = 40,
	MOD_STRUTS = 41,
	MOD_ARCH_COVER = 42,
	MOD_AERIALS = 43,
	MOD_TRIM = 44,
	MOD_TANK = 45,
	MOD_WINDOWS = 46,
	MOD_UNK47 = 47,
	MOD_LIVERY = 48
};
typedef struct RGB_A {
	int r;
	int g;
	int b;
	int a;

	RGB_A() {
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}

	RGB_A(int r1, int g1, int b1, int a1) {
		r = r1;
		g = g1;
		b = b1;
		a = a1;
	}
};
#define STRINGIZE(x) #x
#define PROFILER_START(x) Test2 x(__FILE__, STRINGIZE(x));
#define PROFILER() Test2 x(__FILE__, __FUNCTION__);
#define PROFILER_END(x) x.end();

const double NANOTOMILLI = 1.0 / 1000000.0;
//typedef const char* String;
using namespace std;

class ProfileEntry {
private:
	bool m_started;
	const char* m_fileName;
	const char* m_functionName;
	__int64 m_cyclesBegin;
	__int64 m_cyclesTotal;
	__int64 m_cyclesLatest;

	chrono::steady_clock::time_point m_timeBegin;
	uint64_t m_timeTotal;

	double m_timeAverageList[600];
	int m_timeAverageIndex;
	double m_timeAverageSum;
	double m_timeLatest;
	uint64_t m_calls;
public:
	ProfileEntry() : m_started(false), m_fileName(""), m_functionName(""), m_cyclesBegin(0), m_cyclesLatest(0), m_cyclesTotal(0), m_calls(0), m_timeAverageIndex(0), m_timeAverageSum(0), m_timeLatest(0), m_timeAverageList{ 0 } {}
	ProfileEntry(const char* fileName, const char* functionName) : m_started(false), m_fileName(fileName), m_functionName(functionName), m_cyclesBegin(0), m_cyclesLatest(0), m_cyclesTotal(0), m_calls(0), m_timeAverageIndex(0), m_timeAverageSum(0), m_timeLatest(0), m_timeAverageList{ 0 } {}

	void start() {
		if (m_started) {
			//LOG_ERROR("[Profile] call PROFILER_END(%s) before calling PROFILER_START(%s)", m_functionName, m_functionName);
			return;
		}
		m_calls++;
		m_cyclesBegin = __rdtsc();
		m_timeBegin = chrono::high_resolution_clock::now();
		m_started = true;
	}

	void end() {
		if (!m_started) {
			//LOG_ERROR("[Profile] call PROFILER_START(%s) before calling PROFILER_END(%s)", m_functionName, m_functionName);
			return;
		}
		m_cyclesLatest = __rdtsc() - m_cyclesBegin;
		m_cyclesTotal += m_cyclesLatest;

		m_timeLatest = double(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - m_timeBegin).count()) * NANOTOMILLI;
		calculateAverage(m_timeLatest);
		//m_timeTotal += m_timeLatest;
		m_started = false;

	}

	void calculateAverage(double newtick) {
		m_timeAverageSum -= m_timeAverageList[m_timeAverageIndex];
		m_timeAverageSum += newtick;
		m_timeAverageList[m_timeAverageIndex] = newtick;
		if (++m_timeAverageIndex == 600) m_timeAverageIndex = 0;
	}

	const char* getFileName() { return m_fileName; }
	const char* getFunctionName() { return m_functionName; }

	__int64 getCalls() { return m_calls; }
	__int64 getCycles() { return m_cyclesLatest; }
	double getLatest() { return m_timeLatest; }
	double getAverage() { return (m_timeAverageSum / 600.0); }
};

class Profiler {
private:
	/*map<const char*, ProfileEntry> m_entries;*/
public:
	map<const char*, ProfileEntry> m_entries;
	ProfileEntry* getEntry(const char* fileName, const char* functionName) {
		if (m_entries.find(functionName) != m_entries.end()) return &m_entries[functionName];
		m_entries.insert({ functionName, ProfileEntry(fileName, functionName) });
		return &m_entries[functionName];
	}

	void Push(const char* fileName, const char* functionName) {
		getEntry(fileName, functionName)->start();
	}

	void Pop(const char* fileName, const char* functionName) {
		ProfileEntry* entry = getEntry(fileName, functionName);
		entry->end();
		//LOG_PRINT("%s %f %f", entry->getFunctionName(), entry->getLatest(), entry->getAverage());
	}

	vector<ProfileEntry> GetEntries() {
		vector<ProfileEntry> toRet;
		for (auto it = m_entries.begin(); it != m_entries.end(); ++it) {
			toRet.push_back(it->second);
		}
		return toRet;
	}

};

Profiler* GetProfiler();

class Test2 {
public:
	const char* m_fileName;
	const char* m_functionName;
	bool m_hasEnded;
	Test2(const char* fileName, const char* functionName) : m_fileName(fileName), m_functionName(functionName), m_hasEnded(false) { GetProfiler()->Push(m_fileName, functionName); }
	~Test2() {
		end();
	}

	void end() {
		if (!m_hasEnded) GetProfiler()->Pop(m_fileName, m_functionName);
		m_hasEnded = true;
	}
};

struct EntityControlStruct
{
	const char* m_name;
	Entity m_entity;
	function<void(Entity)> m_function;
	int m_networkID;
	int m_tries;
	int64_t m_id;
	bool m_valid;

	inline bool operator==(const EntityControlStruct& str2) {
		return m_id == str2.m_id;
	}
};

struct EntityModelStruct {
	int m_model;
	function<void(int)> m_function;
	int m_tries;
	int64_t m_id;

	inline bool operator==(const EntityModelStruct& str2) {
		return m_id == str2.m_id;
	}
};

class EntityControl
{
private:
	queue<EntityControlStruct> m_requests;
	vector<EntityModelStruct> m_models;
public:
	static void _Update();
	void Update();

	void RequestControl(const char* name, Entity entity, function<void(Entity)> funcptr);
	/*void SimpleRequestControl(Entity entity);
	void VerySimpleRequestControl(Entity entity);*/
	void RequestModel(int model, function<void(int)> funcptr);
	/*void SimpleRequestModel(int model);
	void DeleteEntity(Entity entity);
	void SimpleDeleteEntity(Entity entity);
	void DeleteVehicle(Vehicle vehicle);
	void SimpleDeleteVehicle(Vehicle vehicle);*/
};

EntityControl* GetEntityControl();

class SPlayer {
public:
	int id;

	// Constructeur
	explicit SPlayer(int playerId) : id(playerId) {}

	// Opérateur d'assignation
	SPlayer& operator=(const SPlayer& other) {
		if (this != &other) { // Éviter l'auto-affectation
			this->id = other.id;
		}
		return *this;
	}

	// Opérateur d'addition
	SPlayer operator+(const SPlayer& other) const {
		return SPlayer(this->id + other.id);
	}

	// Opérateur de soustraction
	SPlayer operator-(const SPlayer& other) const {
		return SPlayer(this->id - other.id);
	}

	//int id;
	//explicit SPlayer(CNetGamePlayer* player) {
	//	// Initialize SPlayer from CNetGamePlayer*
	//	// Example:
	//	this->id = player->m_player_id;
	//}

	//SPlayer& operator=(CNetGamePlayer* player) {

	//	this->id = player->m_player_id;
	//	return *this;
	//}

	SPlayer(const rage::snPlayer& player);
	//SPlayer(int playerID) : playerID(playerID) {
	//	// Constructor code here
	//}

	//static SPlayer& createPlayer(int playerID) {
	//	static SPlayer player(playerID);
	//	return player;
	//}

	//// Other members and methods of SPlayer class

	//int getPlayerId() const {
	//	return playerID;
	//}

private:

	int playerID; // Assuming there's an int member variable representing the player ID

public:
	SPlayer() {
	}
	// Conversion operator to convert SPlayer to int
	explicit operator int() const {
		return playerID;
	}
	const char* m_name;
	Player m_id;
	Ped m_ped;
	Ped m_ped32[32];
	Vehicle m_vehicle;
	Vehicle m_lastVehicle;
	int m_entity;
	//int m_weaponEntity;
	//Hash m_weaponHash;
	////int m_handle[13];
	//int m_headshotHandle;

	//int m_health;
	//int m_maxHealth;
	//int m_team;
	//bool m_passive;
	//bool m_paused;
	//bool m_typing;
	//bool m_joining;
	//bool m_modding;
	//bool m_isOTR;
	bool m_exists;
	//bool m_isHost;
	//bool m_isScriptHost;
	//bool m_isInInt;
	//bool m_isGod;
	//bool m_isFriend;
	//bool m_isMenuUser;
	bool m_isInVehicle;
	bool m_isLocalPlayer;
	//bool m_hasWeaponInHand;
	//bool m_isTalking;
	//bool m_rstardev;
	//bool m_cutscene;

	Vector3 m_coordinates;
	//Vector2 m_w2s;
	float m_heading;

	////Player vars!
	//bool m_karma;
	//bool m_rainWeapons;
	//bool m_giveMoneyGun;
	//bool m_giveOptionGun;
	//bool m_soundrape;
	//bool m_particles;
	//bool m_setwaypoint;

	//bool m_explode;
	//bool m_waterLoop;
	//bool m_fireLoop;
	//bool m_onFire;
	//int m_onFireHandle;
	//bool m_hostileTraffic;
	//bool m_hostilePeds;
	//bool m_rainRockets;
	//bool m_demiGodmode;
	//bool m_bulletgodmode;
	//bool m_cameraShake;
	//bool m_freezeVehicle;
	//bool m_forcefield;
	//bool m_isEvolveUserHidden;
	//bool m_isEvolveUser;
	//bool m_isEvolveStaff;
	//bool m_isEvolveVIP;
	//bool m_isThunderUserBlock;
	//Vector3 m_attachmentToMeClientPosition;
	//Vector3 m_attachmentToMeClientRotation;
	//float m_attachmentToMeClientPrecision = 10.0f;
	//bool m_attachmentToMeClientAttachedTo;
	//Vector3 m_attachmentMeToClientVehiclePosition;
	//Vector3 m_attachmentMeToClientVehicleRotation;
	//float m_attachmentMeToClientVehiclePrecision = 10.0f;
	//bool m_attachmentMeToClientVehicleAttachedTo;
	//int m_attachmentMyVehicleToTheirVehicleAttachmentType;
	//float m_attachmentMyVehicleToTheirVehicleRelativeDistance;
	//int m_attachmentTheirVehicleToMyVehicleAttachmentType;
	//float m_attachmentTheirVehicleToMyVehicleRelativeDistance;
	//bool m_disableTasks;
	//bool m_smokePlayer;
	//bool m_electrocute;
	//bool m_trapplayer;
	//bool m_alwaysWanted;
	//bool m_fakeMoney;
	//bool m_standardMoneyDropai;
	//bool m_standardMoneyDrop;
	//bool m_standardCircleDrop;
	//bool m_standardPedDrop;
	//bool m_enableDrop;
	//int m_dropAmount = 2500;
	//int m_dropType;
	//int m_dropModel;
	//float m_dropHeight = 2.0;
	//float m_dropRadius = 0.5;
	//int m_dropDelay = 300;
	//bool m_nameESP;
	//bool m_boxESP;
	//bool m_lineESP;
	//bool m_lineLOSESP;
	//bool m_headMarkerESP;
	//bool m_footMarkerESP;
	//bool m_infoESP;
	//bool m_bonesESP;
	//bool m_skylineESP;

	//bool m_chatCommand;
	//bool m_chatCommandMoneyDrop;
	//bool m_chatCommandSpawnVehicle;
	//bool m_chatCommandSpawnPed;
	//bool m_chatCommandSpawnObject;
	//bool m_chatCommandSpawnBodyguard;
	//bool m_chatCommandGiveWeapons;
	//bool m_chatCommandExplodeSession;
	//bool m_chatCommandVehicleRepair;
	//bool m_chatCommandVehicleBoost;
	//bool m_chatCommandVehicleJump;
	//bool m_chatCommandVehicleUpgrade;
	////
	//bool m_chatCommandWeatherDay;
	//bool m_chatCommandWeatherNight;
	//bool m_chatCommandWeatherSnow;
	//bool m_chatCommandWeatherClear;
	//bool m_chatCommandWeatherHalloween;
	////
	//bool m_chatCommandGlobalsCopsturnblind;
	//bool m_chatCommandGlobalsOfftheradar;

	////Vehicle
	//bool m_hornBoost;
	//bool m_kickLoop;

	////Remote
	//bool m_otr;
	//bool JoinCeobool;
	//bool CeoMoneybool;
	////bool m_sbounty;
	//bool m_neverWanted;
	//bool m_facecamera;
	//bool m_blindEye;
	//bool m_bribeauthorities;
	//bool m_soundSpam;
	//bool m_displaySpectatingMessage;
	//bool m_transactionSpam;
	//bool m_badsport;
	//bool m_removebadsport;
	//bool m_wantedlevelloop;

	void Reset() {
		m_id = 0;
		m_ped = -1;
		m_entity = -1;
		/*m_weaponEntity = -1;
		m_weaponHash = -1;*/
		m_name = "";
		/*m_isOTR = false;*/
		m_exists = false;
		/*m_isGod = false;
		m_isHost = false;
		m_isScriptHost = false;
		m_isInInt = false;
		m_isFriend = false;
		m_isTalking = false;
		m_isMenuUser = false;
		m_hasWeaponInHand = false;*/
		m_isLocalPlayer = false;
	}

	/*void resetPlayerVars() {
		m_karma = false;
		m_explode = false;
	}

	void setVisible(bool visible) { ENTITY::SetEntityVisible(m_ped, visible, visible); }
	void setInvincible(bool invincible) { ENTITY::SetEntityInvincible(m_ped, invincible); };
	void setProfInvin(bool profinv) { ENTITY::SetEntityProofs(m_ped, profinv, profinv, profinv, profinv, profinv, 0, 0, profinv); };*/
};

class PlayerManager {
//private:
//	SPlayer m_players[33];
//	SPlayer* m_localPlayer;
public:
	SPlayer m_players[33];
	SPlayer* m_localPlayer;
	//SPlayer m_players32[32];
	PlayerManager() : m_localPlayer(&m_players[0]) {}
	void Update();
	inline SPlayer& GetPlayer(int index) { return  m_players[index]; }
	inline SPlayer* GetAllPlayers() { return m_players; }
	inline SPlayer& GetLocalPlayer() { return *m_localPlayer; }

	void OnlinePlayerCallback(bool overrideExcludes, function<void(SPlayer)> callback);
};
PlayerManager* GetPlayerManager();
SPlayer& GetPlayer(int index);
SPlayer& GetLocalPlayer();
SPlayer& GetSelectedPlayer();
void GetOnlinePlayerCallback(bool overrideExcludes, function<void(SPlayer)> callback);

namespace PlayerMenuVars {
	extern int player;
}
namespace VEHICLEPLAYER
{
	extern void FixVehicle(SPlayer& player);
	extern void TuneVehicle(SPlayer& player);
	extern void FixVehicle2(SPlayer& player);
	extern void TuneVehicle2(SPlayer& player);
}
namespace LSCMenuVars
{
	extern void MaxVehicle(Vehicle veh);
}

extern void FixVCallback();
extern void TuneVCallback();
class Backend
{
public:
	static bool NetworkIsInSession() { return m_isInSession ? true : false; }
private:
	static uint8_t m_isInSession;
};

namespace GlobalScript
{
	extern bool Mocbool;
	extern int Mocint();
	extern bool AcidLabGlobalbool;
	extern int AcidLabGlobalint();
	extern bool AcidLabBikeGlobalbool;
	extern int AcidLabBikeGlobalint();
	extern bool AvengerGlobalbool;
	extern int AvengerGlobalint();
	extern bool TerrobyteGlobalbool;
	extern int TerrobyteGlobalint();
	extern bool KosatkaGlobalbool;
	extern int KosatkaGlobalint();
	extern bool DingyGlobalbool;
	extern int DingyGlobalint();
	extern bool BullsharkGlobalbool;
	extern int BullsharkGlobalint();
	extern bool AirstrikeGlobalbool;
	extern int AirstrikeGlobalint();
	extern bool AmmoDropGlobalbool;
	extern int AmmoDropGlobalint();
	extern bool CrateDropGlobalbool;
	extern int CrateDropGlobalint();
	extern bool EasyBusinessSellLocalbool;
	extern int EasyBusinessSellLocalint();
	extern bool InstantHeistLocalbool;
	extern int InstantHeistLocalint();
	extern bool MiniMapStateGlobalbool;
	extern int MiniMapStateGlobalint();
	extern bool VisionGlobalbool;
	extern int VisionGlobalint();
	extern bool WeatherGlobalbool;
	extern int WeatherGlobalint();
	extern bool BunkerResearchGlobalbool;
	extern int BunkerResearchGlobalint();
	extern bool DisableErrorScreenGlobalbool;
	extern int DisableErrorScreenGlobalint();
	extern bool InteriorStateGlobalbool;
	extern int InteriorStateGlobalint();
	extern bool BusinessGlobalbool;
	extern int BusinessGlobalint();
	extern bool AddBusinessSupplyGlobalbool;
	extern int AddBusinessSupplyGlobalint();
	extern bool NightClubStockGlobalbool;
	extern int NightClubStockGlobalint();
	extern bool NightClubVaultGlobalbool;
	extern int NightClubVaultGlobalint();
	extern bool CashCreationTimerGlobalbool;
	extern int CashCreationTimerGlobalint();
	extern bool SportingGoodsTimerGlobalbool;
	extern int SportingGoodsTimerGlobalint();
	extern bool OrganicProduceTimerGlobalbool;
	extern int OrganicProduceTimerGlobalint();
	extern bool CargoandShipmentsTimerGlobalbool;
	extern int CargoandShipmentsTimerGlobalint();
	extern bool PrintingCopyingTimerGlobalbool;
	extern int PrintingCopyingTimerGlobalint();
	extern bool AmericanImportsTimerGlobalbool;
	extern int AmericanImportsTimerGlobalint();
	extern bool PharmaceuticalTimerGlobalbool;
	extern int PharmaceuticalTimerGlobalint();
	extern bool CashCreationMaxStockGlobalbool;
	extern int CashCreationMaxStockGlobalint();
	extern bool SportingGoodsMaxStockGlobalbool;
	extern int SportingGoodsMaxStockGlobalint();
	extern bool OrganicProduceMaxStockGlobalbool;
	extern int OrganicProduceMaxStockGlobalint();
	extern bool CargoandShipmentsMaxStockGlobalbool;
	extern int CargoandShipmentsMaxStockGlobalint();
	extern bool PrintingCopyingMaxStockGlobalbool;
	extern int PrintingCopyingMaxStockGlobalint();
	extern bool AmericanImportsMaxStockGlobalbool;
	extern int AmericanImportsMaxStockGlobalint();
	extern bool PharmaceuticalMaxStockGlobalbool;
	extern int PharmaceuticalMaxStockGlobalint();
	extern bool CashCreationPriceGlobalbool;
	extern int CashCreationPriceGlobalint();
	extern bool SportingGoodsPriceGlobalbool;
	extern int SportingGoodsPriceGlobalint();
	extern bool OrganicProducePriceGlobalbool;
	extern int OrganicProducePriceGlobalint();
	extern bool CargoandShipmentsPriceGlobalbool;
	extern int CargoandShipmentsPriceGlobalint();
	extern bool PrintingCopyingPriceGlobalbool;
	extern int PrintingCopyingPriceGlobalint();
	extern bool AmericanImportsPriceGlobalbool;
	extern int AmericanImportsPriceGlobalint();
	extern bool PharmaceuticalPriceGlobalbool;
	extern int PharmaceuticalPriceGlobalint();
	extern bool CocaineBoostGlobalbool;
	extern int CocaineBoostGlobalint();
	extern bool MethBoostGlobalbool;
	extern int MethBoostGlobalint();
	extern bool WeedBoostGlobalbool;
	extern int WeedBoostGlobalint();
	extern bool CashBoostGlobalbool;
	extern int CashBoostGlobalint();
	extern bool DocumentsBoostGlobalbool;
	extern int DocumentsBoostGlobalint();
	extern bool BunkerBoostGlobalbool;
	extern int BunkerBoostGlobalint();
	extern bool HelicopterBackupGlobalbool;
	extern int HelicopterBackupGlobalint();
	extern bool HelicopterPickupGlobalbool;
	extern int HelicopterPickupGlobalint();
	extern bool SpectateDeathPatchGlobalbool;
	extern int SpectateDeathPatchGlobalint();
	extern bool TeleportInPersonalVehicleGlobalbool;
	extern int TeleportInPersonalVehicleGlobalint();
	extern bool GiveCasinoChipsGlobalbool;
	extern int GiveCasinoChipsGlobalint();
	extern bool GiveCasinoChipsStartGlobalbool;
	extern int GiveCasinoChipsStartGlobalint();
	extern bool SignalJammersGlobalbool;
	extern int SignalJammersGlobalint();
	extern bool DisablePhoneGlobalbool;
	extern int DisablePhoneGlobalint();
	extern bool GoochGlobalbool;
	extern int GoochGlobalint();
	extern bool ArmoredTruckLocationGlobalbool;
	extern int ArmoredTruckLocationGlobalint();
	extern bool ArmoredTruckCooldownGlobalbool;
	extern int ArmoredTruckCooldownGlobalint();
	extern bool ThunderEventGlobalbool;
	extern int ThunderEventGlobalint();
	extern bool Taxibool;
	extern int Taxiint();
}

namespace TiresMenu
{
	extern int HeightTire;
	extern int TireHeight();
	extern float WidthTire;
	extern int TireWidth();
}
namespace VehCheck
{
	extern int CheckUpgrade();
	extern int Vlogcheck();
	/*extern bool isVehicleUpgrade;
	extern int VehicleUpgrade();*/
}

//#ifndef CHECKVEH_H
//#define CHECKVEH_H

//class CheckVeh {
//public:
//	// Vérifie si un véhicule a un certain mod défini
//	static bool HasVehicleMod(Vehicle vehicle, int modType) {
//		// Vérifie si le véhicule a le mod kit 1
//		if (VEHICLE::GET_VEHICLE_MOD_KIT(vehicle) != 1) {
//			return false; // Retourne false si le véhicule n'a pas le mod kit 1
//		}
//
//		// Vérifie si le véhicule a un mod défini pour le type de mod spécifié
//		int currentMod = VEHICLE::GET_VEHICLE_MOD(vehicle, modType);
//		return currentMod != -1; // Retourne true si un mod est défini, sinon false
//	}
//
//	// Détermine si le véhicule dans lequel se trouve le joueur a un certain mod défini
//	static bool VehicleHasMod(int modType) {
//		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
//		return HasVehicleMod(vehicle, modType);
//	}
//
//	// Méthode pour vérifier si le véhicule du joueur a un certain mod défini
//	static bool CheckUpgrade(int modType) {
//		return VehicleHasMod(modType);
//	}
//};

class CheckVeh {
public:
	static bool IsVehicleFullyUpgraded(Vehicle vehicle) {

		/*if (VEHICLE::GET_VEHICLE_MOD_KIT(vehicle) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}*/

		//return hasModKit ? 1 : 0;
		bool hasModKit = 0;
		 //Vérifie si le véhicule a le mod kit 1
		if (VEHICLE::GET_VEHICLE_MOD_KIT(vehicle) == 1) {
			//return true; // Retourne false si le véhicule n'a pas le mod kit 1
			hasModKit = true;
		}
		else
		{
			hasModKit = false;
		}
		// Vérifie si le véhicule a un mod défini pour le type de mod spécifié
		//int currentMod = VEHICLE::GET_VEHICLE_MOD(vehicle, hasModKit);
		//return currentMod != -1; // Retourne true si un mod est défini, sinon false

		/*for (int modType = 0; modType < 50; modType++) {
			int numMods = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, modType);
			if (numMods == 0) {
				return false;
			}
			int currentMod = VEHICLE::GET_VEHICLE_MOD(vehicle, modType);
			if (currentMod != (numMods - 1)) {
				return false;
			}
		}*/

		return hasModKit;
	}
	static bool isVehicleUpgrade;

	static bool VehicleUpgrade() {
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		isVehicleUpgrade = IsVehicleFullyUpgraded(vehicle);
		return isVehicleUpgrade;
	}

	static bool CheckUpgrade() {
		CheckVeh checkVeh;
		return checkVeh.VehicleUpgrade();
	}
};

//#endif // CHECKVEH_H
