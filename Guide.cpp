#include "TV.h"
#include "Feuillton.h"
#include "Guide.h"
#include <iostream>
#include <typeinfo>


list <TV*>::iterator Guide::rechercher(string i)
{

 {for (list <TV*>::iterator it = tab1.begin(); it!=tab1.end(); ++it)
    {
        if((*it)->get_intitule()==i)
            return it;
    }
    return tab1.end();}

}
void Guide::ajouter(const TV& T)
{
list <TV*>::iterator i=rechercher(T.get_intitule());
try
{
    if(i==tab1.end())
{
   TV *p =new TV(T);
   tab1.push_back(p);
}
else
{
    throw string("erreur TV");
}
}

catch(const string& chaine)
{
    cout<<chaine<<endl;
}


}
void Guide::ajouter(const Feuillton& F)
{
list <TV*>::iterator i=rechercher(F.get_intitule());
try
{
    if(i==tab1.end())
{

   Feuillton *p =new Feuillton(F);
   tab1.push_back(p);
}
else
{
    throw string("erreur feuillton");
}
}

catch(const string& chaine)
{
    cout<<chaine<<endl;
}

}

void Guide::supprimer(TV* P  )
{
    list<TV*>::iterator i=rechercher(P->get_intitule());
    if(i!=tab1.end())
    {
        delete(*i);
        tab1.erase(i);
    }
}

void Guide::afficher()
{

   for (list <TV*>::iterator it = tab1.begin(); it!=tab1.end(); ++it)
    {
     (*it)->afficher();
      if(typeid(*(*it))==typeid(Feuillton))
{
Feuillton *p=(Feuillton*)(*it);
cout << endl<<" noura ken mawjouda y affichihelek: " << p->rechercherF("noura");
}
    }
    cout<<endl<<"nombre totale de ses prgrammes="<<tab1.size()<<endl;

}

int Guide:: nb_Feuillton()
{
      int somme=0;
     for(list<TV*>::iterator i=tab1.begin();i!=tab1.end();++i)
     {
         if (typeid(*(*i))==typeid(Feuillton))
         {
             somme++;
         }
     }
     return(somme);
}

Guide::Guide(const Guide &G)
{
    TV *p;
    //tab heya tebaa el H
    //M.tab bech tparcouri el M
    for (list<TV*>::const_iterator i=G.tab1.begin();i!=G.tab1.end();++i)
    {
        if (typeid(*(*i))==typeid(TV))
        {
            p=new TV(*(*i));
        }
        else
        {
             p=new Feuillton(static_cast<const Feuillton&> (*(*i)));
        }

    tab1.push_back(p);

    }

}

Guide& Guide::operator=(const Guide &M)
{
    if (this!=&M)//this fiha l'adresse mtaa l'objet
    {
        for (list<TV*>::iterator it=tab1.begin();it!=tab1.end();++it)
        {
            delete(*it);
            tab1.clear(); //ou tab.erase(*it);
        }
         TV *p;
    //tab heya tebaa el E
    //M.tab bech tparcouri el M
        for (list<TV*>::const_iterator i=M.tab1.begin();i!=M.tab1.end();++i)
        {
            if (typeid(*(*i))==typeid(TV))
            {
                p=new TV(*(*i));
            }
            else
            {
                 p=new Feuillton(static_cast<const Feuillton&>(*(*i)));
            }

        tab1.push_back(p);
        }
    }
    return(*this);
}

Guide::~Guide()
{
    for(list<TV*>::iterator i=tab1.begin();i!=tab1.end();++i)
    {
        delete(*i);
    }
}


TV* Guide::rechercherTV(string n)
{
  list <TV*>::iterator i=rechercher(n);
  if (i!=tab1.end())
  {
      return (*i);
  }
  else
  {
      return (NULL);
  }
}

