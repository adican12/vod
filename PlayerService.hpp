#ifndef	 _PlayerService_
#define	_PlayerService_
#include "Movies.hpp"
#include "Series.hpp"

class playerService{																			//
	private:																					//
	vector<ViewAble> database;																	//
	int requests; 																				//
																								//
	public:																						//
	vector<ViewAble>& getDatabase(){return database;};											//
	void addTodatabase_Series(series& sr){database.push_back(sr);};								//
	void addTodatabase_Movies(movies& mo){database.push_back(mo);};								//
	void printSeries(){return;};																//
	void printMovies(){return;};																//
//	SmartPtr<ViewAble> requestsViewAble(string id);												//
//	void addSeries(SmartPtr<Series>);															//
//	void addMovies(SmartPtr<Movies>);															//
																								//
};

#endif
