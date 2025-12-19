#pragma once

#include <string>

namespace GTAmodel {
	class Model;
}

namespace sub
{
	namespace PedFavourites_catind
	{
		extern std::string xmlFavouritePeds;
		bool IsPedAFavourite(GTAmodel::Model model);
		bool AddPedToFavourites(GTAmodel::Model model, const std::string& customName);
		bool RemovePedFromFavourites(GTAmodel::Model model);

		/*void ShowInstructionalButton(GTAmodel::Model model);

		void Sub_PedFavourites();*/
	}

	// Model changer

	void ChangeModel_(GTAmodel::Model model);
	/*void AddmodelchangerOption_(const std::string& text, const GTAmodel::Model& model);
	void AddmodelOption_(const std::string& text, const GTAmodel::Model& model, bool* extra_option_code = nullptr);

	void ModelChanger_();
	void ModelChanger_Animal();
	void ModelChanger_AmbientFemale();
	void ModelChanger_AmbientMale();
	void ModelChanger_Cutscene();
	void ModelChanger_GangFemale();
	void ModelChanger_GangMale();
	void ModelChanger_Story();
	void ModelChanger_Multiplayer();
	void ModelChanger_ScenarioFemale();
	void ModelChanger_ScenarioMale();
	void ModelChanger_Story_ScenarioFemale();
	void ModelChanger_Story_ScenarioMale();
	void ModelChanger_Others();*/

}


