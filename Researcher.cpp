#include "Researcher.h"

Researcher::Researcher(const string& name) : Person(name) 
{
	if (name.empty()) {
		cout << "Warning: Researcher name cannot be empty!" << endl;
	}
}

bool Researcher::addArticle(const Article& article)
{
	allArticles.push_back(article);  
	return true;
}

void Researcher::print() const
{
	cout << "Name: " << getName() << endl;
	printArticles();
}

void Researcher::printArticles() const
{
	cout << "Articles by " << getName() << ":\n";
	for (const auto& article : allArticles)
	{
		article.print();
		cout << "\n----------------------------\n";

	}
	if (allArticles.empty())
	{
		cout << "No articles available.\n"; 
	}
}

bool Researcher::operator<(const Researcher& other) const
{
	if (allArticles.size() < other.allArticles.size())
	{
		cout << other.getName() << " has more articles (" << other.allArticles.size() << ") than " << getName() << " (" << allArticles.size() << ")." << endl;
		return true;
	}
	else
	{
		cout << getName() << " has more articles (" << allArticles.size() << ") than " << other.getName() << " (" << other.allArticles.size() << ")." << endl;
		return false;
	}
}