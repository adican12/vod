#ifndef	 _Series_
#define	_Series_
#include "ViewAble.hpp"
#include <iostream>
using namespace std;

class series:public ViewAble{																		//
	protected:																						//
	int EpisodeNum;																					//
	int SeasonNum;																					//
																									//
	public:																							//
	series(){ViewAble();};																			//
	series(string _id, string _name, int _run, int e_num, int s_num):ViewAble(_id,_name,_run),EpisodeNum(e_num),SeasonNum(s_num){};
																									//
	string getInfo(){string a("getInfo Seriese"); return a;};										//										//
//	bool register (smartPtr<client> _cl){return true;};												//
	bool unregister (string id){return true;};														//
	bool play();																					//
	void printSeries(){cout<<"Serie detailed- "<<"Id: "<<getID()<<" ,Name: "<<getName()<<" ,Episode Number: "<<EpisodeNum<<" ,Season Number: "<<SeasonNum <<" ,Runtime: "<<getRuntime()<<endl;};			
};																									//

#endif
