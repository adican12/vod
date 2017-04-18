#ifndef	 _Client_
#define	_Client_
#include <string>
#include <iostream>
#include "SmartPtr.hpp"

using namespace std;

class ViewAble;																						//  class decleration

class client{																						//
	private:																						//
	int timer;																						//
	string id;																						//
	string name;																					//
	string location;																				//
	SmartPtr<ViewAble> currentViewAble;																//
																									//
	public:																							//
	client(){};																						//
	~client(){};																					//
	client(string _id, string _name, string loc):id(_id),name(_name),location(loc),timer(0){};		//
	void 	createClinet(string buffer);															//
	void 	addTimer(){timer+=5;};																	//
	void 	resetTimer(){timer=0;};																	//
	void 	setId(string _id){id=_id; };															//
	string 	getID()const{return id;};																//
	void 	setName(string _name){name=_name; };													//
	string 	getName()const{return name;};															//
	void 	setLocation(string _location){location=_location; };									//
	string 	getLocation()const{return location;};													//
	bool 	playViewAble();																			//
	void 	printClient(){cout<<"Client detailed-  "<<"id: "<<getID()<<" ,name: "<<getName()<<" ,location:"<<getLocation()<<endl;};
};																									//

#endif
