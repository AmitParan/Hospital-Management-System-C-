#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
using namespace std;
#ifndef __ARTICLE_H
#define __ARTICLE_H

class Article
{
private:
	string publicationDate;
	string publisher;

public:
	Article(const string& publicationDate, const string& publisher);
	Article(const Article& other);
	~Article();

	void setPublicationDate(const string& publicationDate);
	bool setPublisher(const string& publisher);

    const string& getPublicationDate() const { return publicationDate; }
	const string& getPublisher() const { return publisher; }

	const void print() const;
};



#endif