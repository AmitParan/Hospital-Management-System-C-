#include"Article.h"

Article::Article(const string& publicationDate, const string& publisher)
	:publicationDate(publicationDate), publisher(publisher) {}

Article::Article(const Article& other)
	:publicationDate(other.publicationDate), publisher(other.publisher){}

Article::~Article(){}


const void Article::print() const
{
	cout << "\nPublication Date:" << publicationDate << " ,Publisher name:" << publisher << endl;
}

bool Article::setPublisher(const string& publisher)
{
	this->publisher = publisher;
	return true;
}

void Article::setPublicationDate(const string& publicationDate)
{
	this->publicationDate = publicationDate;
}