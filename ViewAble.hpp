#ifndef	 _ViewAble_
#define	_ViewAble_
#include <string>
#include <iostream>
#include <vector>
#include "SmartPtr.hpp"
#include "Client.hpp"
using namespace std;

class ViewAble{																						//
																									//
	protected:																						//
	string id;																						//
	string name;																					//
	int Runtime;																					//
	vector<client> currentlyWatchingMe;																//	
																
	public:																							//
	ViewAble(){};																					//	
	~ViewAble(){};																					//
	ViewAble(string _id, string _name, int _run):id(_id),name(_name),Runtime(_run){};				//
	string getID(){return id;};																		//
	string getName(){return name;};																	//
	int getRuntime(){return Runtime;};																//
																									//
	string getInfo() ;																			//
//	bool register (SmartPtr<client> _cl);															//
	bool unregister (string id);																	//
//	bool play()=0;																					//
																									//
};
	
#endif
