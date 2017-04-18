///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////         
////////////////////////////////////////   ADI CANTOR    200647253 ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <vector>
#include "SimulationService.hpp"
#include "SmartPtr.hpp"
using namespace std;

int main(int argc, char** argv) {															//
	string buffer;																			//
	string oscar;																			//
	bool winner;																			//
	string id,name,location;																//
	string e_Num,s_Num,r_time;																//
	int episodeNum,seasonNum,runtime;														//
	clientService ClientService;															//
	playerService	PlayerService;															//
	ifstream Client(argv[1]);																//
	if(!(Client.is_open())){																//
		cerr<<"client not open"<<endl;														//
		}																					//
	else{																					//
		getline(Client,buffer);																//
		while(getline(Client,buffer)!=NULL){												//
			if(buffer[0]=='#') continue;													//
			if(buffer.empty())  continue;													//
																							//
			istringstream StrLine(buffer);													//
																							//
			getline(StrLine,id,',');														//
			getline(StrLine,name,',');														//
   			getline(StrLine,location);														//
   			client cl(id,name,location);													//
//   			SmartPtr<client> _cl=&cl;													//
																							//
//			ClientService.addClient(cl);													//
		}																					//
	}																						//
																							//
																							//
	ifstream Series(argv[2]);																//
	if(!(Series.is_open())){																//
		cerr<<"Series not open"<<endl;														//
		}																					//
	else{																					//
		getline(Series,buffer);																//
		while(getline(Series,buffer)!=NULL){												//
			if(buffer[0]=='#') continue;													//
			if(buffer.empty())  continue;													//
			istringstream StrLine(buffer);													//
			getline(StrLine,id,',');														//
			getline(StrLine,name,',');														//
			getline(StrLine,e_Num,',');														//
			stringstream str(e_Num);														//
   			str>>episodeNum;																//
			getline(StrLine,s_Num,',');														//
			stringstream str2(s_Num);														//
   			str2>>seasonNum;																//
			getline(StrLine,r_time);														//
			stringstream str3(r_time);														//
   			str3>>runtime;																	//
   																							//
   			series sr(id,name,runtime,episodeNum,seasonNum); 								//
//			sr.printSeries();																//
			PlayerService.addTodatabase_Series(sr);											//
		}																					//
	}																						//
																							//
	ifstream Movies;																		//
	Movies.open(argv[3]);																	//
	if(!(Movies.is_open())){																//
		cerr<<"Movies not open"<<endl;														//
		}																					//
	else{																					//
		getline(Movies,buffer);																//
		while(getline(Movies,buffer)!=NULL){												//
			if(buffer[0]=='#') continue;													//
			if(buffer.empty())  continue;													//
			istringstream StrLine1(buffer);													//
			getline(StrLine1,id,',');														//
			getline(StrLine1,name,',');														//	
			getline(StrLine1,r_time,',');													//
			stringstream str4(r_time);														//
   			str4>>runtime;																	//
   			getline(StrLine1,oscar);														//
   			if(oscar[0]=='f') winner=false;													//
   			else if(oscar[0]=='t') winner=true;												//
			else {cerr<<"oscar convert error"<<endl;										//
			}   																			//
   			movies mo(id,name,runtime,winner); 												//
//   		mo.printMovie();																//
			PlayerService.addTodatabase_Movies(mo);											//
		}																					//
	}																						//
//		cout<<PlayerService.getDatabase().size()<<endl;										//
	SmartPtr<playerService> ps(new playerService);											//
	ps=&PlayerService;
//	SmartPtr<playerService> ps=&PlayerService;												//
	SmartPtr<clientService> cs(new clientService);
//	SmartPtr<clientService> cs=&ClientService;												//
	cs=&ClientService;
	simulationService SimulationService(ps,cs);												//
																							//
	ifstream Simulation;																	//
	Simulation.open(argv[4]);																//	
	if(!(Simulation.is_open())){															//
		cerr<<"Simulation not open"<<endl;													//
		}																					//
	else{																					//
		getline(Simulation,buffer);															//
		while(getline(Simulation,buffer)!=NULL){											//
			if(buffer[0]=='#') continue;													//
			if(buffer.empty())  continue;													//
			if(buffer[0]=='p'){																//
//				cout<<"print case"<<endl;													//
				istringstream StrLine1(buffer);												//
				if(buffer.compare("printSeries")==0){										//
//					PlayerService.printSeries();
//					cout<<"print __ printSeries ____"<<endl;								//
																							//
				}																			//
																							//
				else if(buffer.compare("printMovies")==0){									//
//					cout<<"print __ printMovies ____"<<endl;								//
//					PlayerService.printSeries();
				}																			//
																							//
				else if(buffer.compare("printInactives")==0){								//
//					cout<<"print __ printInactives ____"<<endl;								//
//					ClientService.print_inactive();
				}																			//
				else {																		//
					getline(StrLine1,id,':');												//
					getline(StrLine1,id,' ');												//	
//					cout<<id<<endl;															//
				}																			//
				continue;																	//
			}																				//
			if(buffer[0]=='u'){																//
//				cout<<"update"<<endl;														//
//				playViewAble();
				continue;																	//
			}																				//
//			cout<<buffer<<endl;																//	
			istringstream StrLine2(buffer);													//
			getline(StrLine2,id,':');														//
//			cout<<id<<endl;																	//
			getline(StrLine2,name,' ');														//
//			cout<<name<<endl;																//
			if(name[0]=='s'){																//
//				cout<<"stop"<<endl;															//
			}																				//
			else{																			//
//				cout<<"id: "<<id<<"  name: "<<name<<endl;									//	
			}																				//
   		}																					//
	}																						//
	system("pause");																		//
	Simulation.close();																		//
	Movies.close();																			//
	Series.close();																			//
	Client.close();																			//
	
	return 0;																					
}
