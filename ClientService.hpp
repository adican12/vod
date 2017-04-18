#ifndef	 _ClientService_
#define	_ClientService_
#include "Client.hpp"
#include <vector>
class clientService{
	private:																	//
	vector<client> Clients;														//
																				//
	public:																		//
	clientService(){};															//
	~clientService(){};															//	
	vector<client>& getClients(){return Clients;};								//
	void print_inactive(){return ;};
	void addClient(client& _cl){Clients.push_back(_cl);};  /// replce			//
//	void addClient(SmartPtr<client> _cl){Clients.push_back(_cl);};				//
};
#endif
