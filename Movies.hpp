#ifndef	 _Movies_
#define	_Movies_
#include "ViewAble.hpp"

class movies:public ViewAble{																			//
																										//
	protected:																							//
	bool oscarWinner;																					//
																										//
	public:																								//
	movies(){ViewAble();};																				//
	movies(string _id,string _name,int _runtime,bool _oscarWinner):ViewAble(_id,_name,_runtime),oscarWinner(_oscarWinner){};
	~movies(){};																						//
	string getInfo(){string a("getInfo Movies"); return a;};											//
				
//	bool register (smartPtr<client> _cl){return true;};													//
	bool unregister (string id){return true;};															//
	bool play();																						//
	void printMovie(){cout<<"Movie detailed- "<<" Id: "<<getID()<<" ,Name: "<<getName()<<" ,Runtime: "<<getRuntime()<<" ,Oscar winner: "<<oscarWinner<<endl;};
																										//
};

#endif
