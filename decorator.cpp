#include<iostream>
#include<string>
#include<list>

using namespace std;


class LibraryItem
{
public:
  void SetNumCopies(int value)
  {
    numCopies_ = value;
  }
  int GetNumCopies(void)
  {
    return numCopies_;
  }
  virtual void Display(void)=0;
private:
  int numCopies_;
};


class Book : public LibraryItem
{
public:
  Book(string author, string title, int numCopies) : author_(author), title_(title)
  {
    SetNumCopies(numCopies);
  }
  void Display(void)
  {
    cout<<"\nBook ------ "<<endl;
    cout<<" Author : "<<author_<<endl;
    cout<<" Title : "<<title_<<endl;
    cout<<" # Copies : "<<GetNumCopies()<<endl;
  }
private:
  Book(); //Default not allowed
  string author_;
  string title_;
};

class Video : public LibraryItem
{
public:
  Video(string director, string title, int playTime, int numCopies) : director_(director), title_(title), playTime_(playTime)
  {
    SetNumCopies(numCopies);
  }
  void Display(void)
  {
    cout<<"\nVideo ------ "<<endl;
    cout<<" Director : "<<director_<<endl;
    cout<<" Title : "<<title_<<endl;
    cout<<" Play Time : "<<playTime_<<" mins"<<endl;
    cout<<" # Copies : "<<GetNumCopies()<<endl;
  }
private:
  Video(); //Default not allowed
  string director_;
  string title_;
  int playTime_;
};

class Magzine : public LibraryItem
{
public:
  Magzine(string name, string type, int cost,int numCopies) : name_(name),type_(type), cost_(cost)
  {
    SetNumCopies(numCopies);
  }
  void Display(void)
  {
    cout<<"\nMagazine ------ "<<endl;
    cout<<" Name : "<<name_<<endl;
    cout<<" Type : "<<type_<<endl;
    cout<<" Cost : "<<cost_<<" mins"<<endl;
    cout<<" # Copies : "<<GetNumCopies()<<endl;
  }
private:
  Magzine(); //Default not allowed
  string name_;
  string type_;
  int cost_;
};


class PlayStation : public libraryItem
{


}


class Decorator
{
public:
  Decorator(LibraryItem* libraryItem) 
{
       	this->libraryItem_=libraryItem;
 }
  void Display(void)
  {
    libraryItem_->Display();
  }
  int GetNumCopies(void)
  {
    return libraryItem_->GetNumCopies();
  }
protected:
  LibraryItem* libraryItem_;
private:
  Decorator(); //not allowed
};


class Borrowable : public Decorator
{
public:
  Borrowable(LibraryItem* libraryItem) : Decorator(libraryItem)
  {}
  void BorrowItem(string name)
  {
    borrowers_.push_back(name);
  }
  void Display()
  {
    Decorator::Display();
    int size = borrowers_.size();
    cout<<" # Available Copies : "<<(Decorator::GetNumCopies() - size)<<endl;
    auto it = borrowers_.begin();
    while(it != borrowers_.end())
    {
      cout<<" borrower: "<<*it<<endl;
      ++it;
    }
  }
protected:
  list<string> borrowers_;
};

class Sellable : public Decorator
{


};



int main()
{


  Video video1("Peter Jackson", "The Lord of the Rings", 683, 24);
Video video2("spiel berg", "jurrassic", 544, 24);
video1.Display();
video2.Display();
Book book1("C++ Complete Refrence","Herbert schield",20);
Book book2("Disection of C++ ","Wrox publication",15);
book1.Display();
book2.Display();

Magzine m1("Outlook","Weekly",45,10);
Magzine m2("EFY","Monthly",250,5);
Magzine m3("India Today","yearly",500,3);
m1.Display();
m2.Display();
m3.Display();

Magzine p1();
Magzine p2();

  cout<<"Making video borrowable"<<endl;

  Borrowable borrowvideo(&video1);
  borrowvideo.BorrowItem("Bill Gates");
  borrowvideo.BorrowItem("Steve Jobs");
  borrowvideo.BorrowItem("jeff bezos");
  borrowvideo.BorrowItem("alan musk");
borrowvideo.Display();
  
Borrowable borrowbook(&book2);
  borrowbook.BorrowItem("Mukesh Ambani");
  borrowbook.BorrowItem("Goutham Adani");
  borrowbook.BorrowItem("Radhakrishanan Damani");
  borrowbook.BorrowItem("Ratan Tata");
  borrowbook.BorrowItem("Bajaj");
borrowbook.Display();


Borrowable borrowmagazine(&m2);
  borrowmagazine.BorrowItem("Mukesh Ambani");
  borrowmagazine.BorrowItem("Goutham Adani");
  borrowmagazine.BorrowItem("Radhakrishanan Damani");
  borrowmagazine.Display();




Sellable sellbook1(&video3);

 return 0;
}
