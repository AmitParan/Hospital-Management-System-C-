#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std; 
#include "Person.h"
#include "Article.h"

#ifndef __RESEARCHER_H
#define __RESEARCHER_H


class Researcher : public Person
{
protected:
	vector<Article> allArticles;


public:
	Researcher(const string& name);

	bool addArticle(const Article& article);
	void print() const;
	void printArticles() const;

	int getArticleCount() const {return allArticles.size();}

	bool operator<(const Researcher& other) const;
	


};
#endif