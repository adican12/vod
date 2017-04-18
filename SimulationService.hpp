#ifndef	 _SimulationService_
#define	_SimulationService_
#include "PlayerService.hpp"
#include "ClientService.hpp"

class simulationService{																				//
	private:																							//
		SmartPtr<playerService> PlayerServices;															//
		SmartPtr<clientService> ClientServices;															//
																										//
	public:																								//
		simulationService(){};																			//
		~simulationService(){};																			//
		simulationService(SmartPtr<playerService> ps,SmartPtr<clientService> cs):PlayerServices(ps),ClientServices(cs){};
																										//
		void update();																					//
		bool loadData();																				//
		bool executeSimulation();																		//
};

#endif
