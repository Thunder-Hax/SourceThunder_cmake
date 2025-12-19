#pragma once
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>

namespace supplyBusiness
{
	extern int m_BusinessSupplyMin;
};

namespace Business
{
extern std::string AcidStock;
extern std::string AcidSupply;
extern std::string BunkerStock;
extern std::string BunkerSupply;
extern std::string WeedStock;
extern std::string WeedSupply;
extern std::string MethStock;
extern std::string MethSupply;
extern std::string CocaineStock;
extern std::string CocaineSupply;
extern std::string DocumentsStock;
extern std::string DocumentsSupply;
extern std::string CashStock;
extern std::string CashSupply;
}

namespace m_business
{
	/*extern bool AcidStockbool;
	extern bool AcidSupplybool;
	extern bool AddAcidSupplybool;*/
	extern int AcidStock();
	extern int AcidSupply();
	extern void AddAcidSupply();
	extern int CocaineStock();
	extern int CocaineSupply();
	extern void AddCocaineSupply();
	extern int MethStock();
	extern int MethSupply();
	extern void AddMethSupply();
	extern int WeedStock();
	extern int WeedSupply();
	extern void AddWeedSupply();
	extern int CashStock();
	extern int CashSupply();
	extern void AddCashSupply();
	extern int DocumentsStock();
	extern int DocumentsSupply();
	extern void AddDocumentsSupply();
	extern int BunkerStock();
	extern int BunkerSupply();
	extern void AddBunkerSupply();
	extern void BusinessTick();
	extern int CocaineStock2();
	extern int CocaineSupply2();
	extern void AddCocaineSupply2();
	extern int MethStock2();
	extern int MethSupply2();
	extern void AddMethSupply2();
	extern int WeedStock2();
	extern int WeedSupply2();
	extern void AddWeedSupply2();
	extern int CashStock2();
	extern int CashSupply2();
	extern void AddCashSupply2();
	extern int DocumentsStock2();
	extern int DocumentsSupply2();
	extern void AddDocumentsSupply2();
	extern int BunkerStock2();
	extern int BunkerSupply2();
	extern void AddBunkerSupply2();
	extern void BusinessTick2();
}