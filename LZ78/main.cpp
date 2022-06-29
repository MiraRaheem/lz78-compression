#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
using namespace std;

//this will have all entities of the map
map <string, int  > dic;

//this is the building unit for every dic.
//We choose not to use static at counting due to the trouble of deep copying ... it was easier to just use the size of the map at each increment.
//We also choose map container because it is easier in searching
//each entity has a string that is not repeated and an index.
class dictionaryEntity
{
public:
    dictionaryEntity() {}
    dictionaryEntity(string symbol)
    {
        dic.insert(pair<string, int>(symbol, dic.size()+1));
    }
    void setSymbol(string symbol)
    {
        dic.insert(pair<string, int>(symbol, dic.size()+1));
    }
    bool isFound(string symbol)
    {
        return dic.find(symbol)->second;
    }
    int getIndex(string symbol)
    {
        //cout<<dic.find(symbol)->second;

        return dic.find(symbol)->second;


    }
};

class dictionary
{
public:
    void print()
    {
        map<string, int>::iterator itr;
        cout << "\nThe map gquiz1 is : \n";
        cout << "\tKEY\tELEMENT\n";
        for (itr = dic.begin(); itr != dic.end(); ++itr)
        {
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';
        }
        cout << endl;
    }


};

//end of dictionary
//--------------------------------------------------
//begining of tags

class tag
{
private:
    int indexInDec;
    string finalSymbol;

public:
    tag() {}
    tag(int indexInDec, string finalSymbol)
    {
        this->finalSymbol=finalSymbol;
        this->indexInDec=indexInDec;
    }
    void setIndexInDec (int i)
    {
        indexInDec=i;
    }
    void setFinalSymbol (string fs)
    {
        finalSymbol=fs;
    }
    int getIndexInDec()
    {
        return indexInDec;
    }
    string getFinalSymbol()
    {
        return finalSymbol;
    }

};

//this will have all final tags.
vector <tag> output;

class tags
{
public:
    void print()
    {
        for (int i=0; i<output.size(); i++)
        {
            cout<<endl<<"("<<output[i].getFinalSymbol()<<","<<output[i].getIndexInDec()<<")"<<endl;
        }
    }

};





/*read string-->check if it exists
-->no
    1. tag=(0,string)
    2. insert as a new entity
    3. add to the output your tag
-->yes
    1.get index from dictionary
    2.concatenate next character in the string
    3.while (!eof or end of string)--> keep concatenating and cheeking until you find a new entity.
        PS->update the tag every time you find an entity in the dic
           a.once found tag=(dicindex, concatenated string)
           b.insert as a new entity
           c.add tag to the output*/

/*functions used
  1.add tag (constructor in class tag COMMON
  2.insert from class dictionaryEntity COMMON
  3.insert in class tag (to add to the output) COMMON
  4.isFound in class dictionaryEntity
  5.getIndex class dictionaryEntity*/

class LZ78
{
private:
    string firstChar;
    string temp;
public:
    LZ78(string sentence)
    {
        firstChar=sentence[0];
        tag t1(0,firstChar);
        output.push_back(t1);
        dictionaryEntity d1(firstChar);

        for( int i = 1; i < sentence.size(); ++i)
        {
            firstChar=sentence[i];
            tag t1;
            dictionaryEntity d1;
            string temp;
            int foundIndex=0;
            if (!(d1.isFound(firstChar)))
            {
                t1.setFinalSymbol(firstChar);
                t1.setIndexInDec(0);
                output.push_back(t1);
                dictionaryEntity d1(firstChar);
            }
            else {
                   //cout<<foundIndex;
                while(d1.isFound(firstChar)){
                    foundIndex=d1.getIndex(firstChar);
                    temp=sentence[i+1];
                    i=i+1;
                    firstChar=firstChar+temp;
                    //temp=" ";

                    }
                t1.setFinalSymbol(firstChar);
                t1.setIndexInDec(foundIndex);
                output.push_back(t1);
                dictionaryEntity d1(firstChar);

            }

        }

    }

};



int main()
{
    string s="abbcbcababcaa";
    LZ78 l1(s);
    dictionary d1;
    d1.print();
    tags t1;
    t1.print();

/*
int f;
dictionaryEntity d1("a");
dictionaryEntity d2("b");
dictionaryEntity d3("bc");
dictionaryEntity d4("bca");
dictionaryEntity d5("ba");
f=d1.getIndex("bca");
cout<<f;*/
}
