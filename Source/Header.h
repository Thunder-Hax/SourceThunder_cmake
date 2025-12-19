#pragma once
namespace headers {
	extern bool filesearch;
	extern bool firstimage;
	extern void randomlyvoid();
	extern float timesdelays;
	extern bool boolrandomlytimes();
	extern bool boolrandomlytimes2();
	extern int thunderheaders();
	extern int thunderbackgrounds();
	extern int StringToInteger2(string NumberAsString);
	extern int randomlytimesbool1, randomlytimesbool2, randomlytimesbool3;
	extern bool randomtimerbool;
	extern bool randomtimerbool2;
	extern std::string Background;
	extern std::string Background2;
	extern int readbackground();
	extern int searchfile();
}

namespace timesback
{
	extern bool blackhole1;
	extern bool blackhole232;
	extern bool blackhole392;
	extern bool blackhole63;
	extern bool Darkside1;
	extern bool Darkside2;
	extern bool Darkside3;
	extern bool Darkside32;
	extern bool Darkside4;
	extern bool Darkside5;
	extern bool Darkside6;
	extern bool Darkside7;
	extern bool Darkside8;
	extern bool Darkside82;
	extern bool Darkside9;
	extern bool Darkside10;
	extern bool Darkside11;
	extern bool Darkside12;
	extern bool Darkside13;
	extern bool Darkside14;
	extern bool Darkside142;
	extern bool Darkside15;
	extern bool Darkside16;
	extern bool Darkside17;
	extern bool Darkside18;
	extern bool Darkside19;
	extern bool Darkside20;
	extern bool Darkside21;
	extern bool Darkside22;
	extern int anybacktime();
	extern int id;
	extern int lastpicid;
	extern bool imagebool();
	extern int anybacktime2();
	extern int id2;
	extern int lastpicid2;
	extern bool imagebool2();
	extern std::string backgroundfile;
	extern std::string filechoosen;
	extern std::string filechoosen2;
	extern std::string thundermenu;
	extern bool boolThor21;
	extern bool boolThor1;
	extern bool boolThor6;
	extern bool boolThor5;
	extern bool boolThor0;
	extern bool boolThor20;
	extern bool boolThor2;
	extern bool boolThor03;
	extern bool boolThor23;
	extern bool boolThor04;
	extern bool boolThor24;

}

class RGBA01
{
public:
	int R, G, B, A;
	RGBA01() : R(0), G(0), B(0), A(0)
	{
	}
	RGBA01(int r, int g, int b, int a) : R(r), G(g), B(b), A(a)
	{
	}
	RGBA01(const RGBA01& imp, int a) : R(imp.R), G(imp.G), B(imp.B), A(a)
	{
	}
	RGBA01 Inverse(bool inverseAlpha)
	{
		return RGBA01(255 - R, 255 - G, 255 - B, inverseAlpha ? 255 - A : A);
	}
	void operator = (const RGBA01& right)
	{
		this->R = right.R;
		this->G = right.G;
		this->B = right.B;
		this->A = right.A;
	}
	friend bool operator == (const RGBA01& left, const RGBA01& right)
	{
		return (left.R == right.R && left.G == right.G && left.B == right.B && left.A == right.A);
	}
};

namespace hashedcode
{
	extern void CODEHASH();
	extern RGBA01 valuecode;
	extern int a1;
	extern int r1;
	extern int g1;
	extern int b1;
	extern int a2;
	extern int r2;
	extern int g2;
	extern int b2;
	extern DWORD value;
	extern std::string hexcolor;
	extern std::string hexcolorstring;
	extern DWORD colorhex;
	extern void HASHCOLOR();
}

enum enumeration
{
	Thor,
	Thor1,
	Thor2,
	Thor3,
	Thor4,
	Thor20,
	Thor21,
	Thor22,
	Thor23,
	Thor24,
	LDarkside1,
	LDarkside2,
	LDarkside3,
	LDarkside4,
	LDarkside5,
	LDarkside6,
	LDarkside7,
	LDarkside8,
	LDarkside9,
	LDarkside10,
	LDarkside11,
	LDarkside12,
	LDarkside13,
	LDarkside14,
	LDarkside15,
	LDarkside16,
	LDarkside17,
	LDarkside18,
	LDarkside19,
	LDarkside20,
	LDarkside21,
	LDarkside22,
	Blackhole1,
	Blackhole2,
	Blackhole3,
	Blackhole4,
	Blackhole5,
	Blackhole6,
	Blackhole7,
	Blackhole8,
	Blackhole9,
	Blackhole10,
	Blackhole11,
	Blackhole12,
	Blackhole13,
	Blackhole14,
	Blackhole15,
	Blackhole16,
	Blackhole17,
	Blackhole18,
	Blackhole19,
	Blackhole20,
	Blackhole21,
	Blackhole22,
	Blackhole23,
	Blackhole24,
	Blackhole25,
	Blackhole26,
	Blackhole27,
	Blackhole272,
	Blackhole28,
	Blackhole29,
	Blackhole30,
	Blackhole31,
	Blackhole32,
	Blackhole33,
	Blackhole333,
	Blackhole34,
	Blackhole35,
	Blackhole36,
	Blackhole37,
	Blackhole38,
	Blackhole39,
	Blackhole40,
	Blackhole41,
	Blackhole42,
	Blackhole43,
	Blackhole44,
	Blackhole45,
	Blackhole46,
	Blackhole47,
	Blackhole48,
	Blackhole49,
	Blackhole50,
	Blackhole51,
	Blackhole52,
	Blackhole53,
	Blackhole54,
	Blackhole55,
	Blackhole56,
	Blackhole57,
	Blackhole58,
	Blackhole59,
	Blackhole60,
	Blackhole61,
	Blackhole62,
	Blackhole63,
	Blackhole64,
	Blackhole65,
	Blackhole66,
	Blackhole67,
	Blackhole68,
	Blackhole69,
	Blackhole70,
	Blackhole71,
	Blackhole72,
	Blackhole73,
	Blackhole74,
	Blackhole75,
	Blackhole76
};

namespace boolactive
{
	extern bool activebool1;
	extern bool activebool2;
	extern bool activebool3;
	extern bool activebool4;
	extern bool activebool5;
	extern bool activebool6;
	extern bool activebool7;
	extern bool activebool8;
	extern bool activebool9;
	extern bool activebool10;
	extern bool activebool11;
	extern bool activebool12;
	extern bool activebool13;
	extern bool activebool14;
	extern bool activebool15;
	extern bool activebool16;
	extern bool activebool17;
	extern bool activebool18;
	extern bool activebool19;
	extern bool activebool20;
	extern bool activebool21;
	extern bool activeboold21;
	extern bool activebool22;
	extern bool activebool23;
	extern bool activebool;

	extern bool blackhole1;
	extern bool blackhole2;
	extern bool blackhole3;
	extern bool blackhole4;
	extern bool blackhole5;
	extern bool blackhole6;
	extern bool blackhole7;
	extern bool blackhole8;
	extern bool blackhole9;
	extern bool blackhole10;
	extern bool blackhole11;
	extern bool blackhole12;
	extern bool blackhole13;
	extern bool blackhole14;
	extern bool blackhole15;
	extern bool blackhole16;
	extern bool blackhole17;
	extern bool blackhole18;
	extern bool blackhole19;
	extern bool blackhole20;
	extern bool blackhole21;
	extern bool blackhole22;
	extern bool blackhole23;
	extern bool blackhole24;
	extern bool blackhole25;
	extern bool blackhole26;
	extern bool blackhole27;
	extern bool blackhole272;
	extern bool blackhole28;
	extern bool blackhole29;
	extern bool blackhole30;
	extern bool blackhole31;
	extern bool blackhole32;
	extern bool blackhole33;
	extern bool blackhole333;
	extern bool blackhole34;
	extern bool blackhole342;
	extern bool blackhole35;
	extern bool blackhole36;
	extern bool blackhole37;
	extern bool blackhole38;
	extern bool blackhole39;
	extern bool blackhole40;
	extern bool blackhole41;
	extern bool blackhole42;
	extern bool blackhole43;
	extern bool blackhole44;
	extern bool blackhole45;
	extern bool blackhole46;
	extern bool blackhole47;
	extern bool blackhole48;
	extern bool blackhole49;
	extern bool blackhole50;
	extern bool blackhole51;
	extern bool blackhole52;
	extern bool blackhole53;
	extern bool blackhole54;
	extern bool blackhole55;
	extern bool blackhole56;
	extern bool blackhole57;
	extern bool blackhole58;
	extern bool blackhole59;
	extern bool blackhole60;
	extern bool blackhole61;
	extern bool blackhole62;
	extern bool blackhole63;
	extern bool blackhole64;
	extern bool blackhole65;
	extern bool blackhole66;
	extern bool blackhole67;
	extern bool blackhole68;
	extern bool blackhole69;
	extern bool blackhole70;
	extern bool blackhole71;
	extern bool blackhole72;
	extern bool blackhole73;
	extern bool blackhole74;
	extern bool blackhole75;
	extern bool blackhole76;
	extern bool blackhole502;
	extern bool blackhole352;
	extern bool blackhole552;
	extern bool blackhole622;
	extern bool blackhole392;
}