#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
enum class CitationType
{
    WebPage,
    Article,
    PublishedWork
};

class Citation
{
public:
    std::string _title;
    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    // task 3 function included here
    virtual std::string getInlineCitation() const = 0;

protected:
    int _year;
};

// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }
    std::string getInlineCitation() const override
    {
        return "[Web page, " + std::to_string(_year) + "]";
    }

protected:
    std::string _url;
};

class PublishedWork : public Citation
{
public:
    std::string _lastname;
    PublishedWork(const std::string& title, int year, const std::string& firstname, const std::string& lastname)
        : Citation(title, year),
          _firstname(firstname),
          _lastname(lastname)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << " " << _lastname << std::endl;
    }

protected:
    std::string _firstname;
};

class Article : public PublishedWork
{
public:
    Article(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& journal)
         : PublishedWork(title, year, firstname, lastname),
          _journal(journal)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        PublishedWork::printCitation(ostr);
        ostr << "Journal: " << _journal << std::endl;
    }
    std::string getInlineCitation() const override
    {
        return "[" + _lastname + ", " + std::to_string(_year) + "]";
    }

protected:
    std::string _journal;
};

// example 2 - Book
// included only as an example, not used in the tasks
// class Book : public PublishedWork
// {
// public:
//     Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
//         : PublishedWork(title, year, firstname, lastname),
//           _publisher(publisher)
//     {
//     }

//     void printCitation(std::ostream& ostr) const override
//     {
//         PublishedWork::printCitation(ostr);
//         ostr << "Publisher:" << _publisher << std::endl;
//     }

// protected:
//     std::string _publisher;
// };

// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;
    // your code
    if (type == CitationType::WebPage)
    {
        std::string title = data.at("title");
        int year = std::stoi(data.at("year"));
        std::string url = data.at("url");
        citationToAdd = new WebPage(title, year, url);
    }
    else if (type == CitationType::Article)
    {
        std::string title = data.at("title");
        int year = std::stoi(data.at("year"));
        std::string firstname = data.at("firstname");
        std::string lastname = data.at("lastname");
        std::string journal = data.at("journal");
        citationToAdd = new Article(title, year, firstname, lastname, journal);
    }

    citations[data.at("key")] = citationToAdd;
    
    return citationToAdd;
}

// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    for (const std::pair<const std::string, Citation *> citation: citations) {
        std::string key = citation.first;
        size_t position = text.find(key);
        
        while (position != -1) {
            text.replace(position, key.length(), citation.second->getInlineCitation());
            position = text.find(key, position + citation.second->getInlineCitation().length());
        }
    }
}

// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> keys;
    std::set<std::string> keysSet;

    size_t position = text.find('{', 0);

    while (position != -1) {
        position = text.find('{', position);

        size_t end = text.find('}', position);
        if (end != -1) {
            keys.push_back(text.substr(position, end - position + 1));
            position = end + 1;
        }
        else break;
    }

    int c = 1;

    for (const std::string& key: keys) {
        if (keysSet.find(key) == keysSet.end()) {
            for (const std::pair<const std::string, Citation *>& citation: citations) {
                if (key == citation.first) {
                    std::cout << c++ << ".\n";
                    citation.second->printCitation(std::cout);
                    keysSet.insert(key);
                    break;
                }
            }
        }
    }
}

// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions

bool sort(const std::pair<std::string, Citation*>& a, const std::pair<std::string, Citation*>& b)
{
    Article* articleA = dynamic_cast<Article*>(a.second);
    Article* articleB = dynamic_cast<Article*>(b.second);
    WebPage* webpageA = dynamic_cast<WebPage*>(a.second);
    WebPage* webpageB = dynamic_cast<WebPage*>(b.second);

    if (articleA and webpageB) return 1;
    else if (articleA and articleB) return articleA->_lastname < articleB->_lastname;
    else if (webpageA and webpageB) return webpageA->_title < webpageB->_title;
    return 0;
}



void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::map<std::string, int> keys;
    std::vector<std::pair<std::string, Citation*>> citation(citations.begin(), citations.end());
    std::sort(citation.begin(), citation.end(), sort);

    size_t c = 1;
    for (const std::pair<std::string, Citation *>& kek: citation)
        keys.insert({kek.first, c++});

    size_t pos = 0;
    
    while ((pos = text.find('{', pos)) != -1) {
        
        size_t _end = text.find('}', pos);
        
        if (_end != -1) {
            std::string key = text.substr(pos, _end - pos + 1);
            if (keys.find(key) != keys.end())
                text.replace(pos, key.length(), "[" + std::to_string(keys.at(key)) + "]");
            pos = _end + 1;
        } 
    }
}


#endif
