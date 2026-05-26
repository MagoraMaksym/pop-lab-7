#include <iostream>
#include <string>

using namespace std;


class OldTicketSystem
{
public:
    string OldCheckTicket()
    {
        return "Old ticket accepted\n";
    }
};


class INewTicketSystem
{
public:
    virtual string NewCheckTicket() = 0;
};


class NewTicketSystem : public INewTicketSystem
{
public:
    string NewCheckTicket()
    {
        return "New ticket accepted\n";
    }
};


class Adapter : public INewTicketSystem
{
private:
    OldTicketSystem* oldSystem;

public:
    Adapter(OldTicketSystem* system)
    {
        oldSystem = system;
    }

    string NewCheckTicket()
    {
        return oldSystem->OldCheckTicket();
    }
};


class CinemaVisitor
{
public:
    static void EnterCinema(INewTicketSystem* ticketSystem)
    {
        cout << ticketSystem->NewCheckTicket();
    }
};

int main()
{
    NewTicketSystem* newSystem = new NewTicketSystem();
    CinemaVisitor::EnterCinema(newSystem);

    OldTicketSystem* oldSystem = new OldTicketSystem();
    Adapter* adapter = new Adapter(oldSystem);

    CinemaVisitor::EnterCinema(adapter);

    delete newSystem;
    delete oldSystem;
    delete adapter;

    return 0;
}