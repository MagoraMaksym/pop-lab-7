#include <iostream>
#include <string>

using namespace std;


class TicketSystem
{
public:
    int BuyTicket()
    {
        return 150;
    }
};


class PopcornSystem
{
public:
    int BuyPopcorn()
    {
        return 80;
    }
};


class SeatBookingSystem
{
public:
    int BookSeat()
    {
        return 50;
    }
};


class CinemaFacade
{
private:
    TicketSystem* ticketSystem;
    PopcornSystem* popcornSystem;
    SeatBookingSystem* seatSystem;

public:
    CinemaFacade()
    {
        ticketSystem = new TicketSystem();
        popcornSystem = new PopcornSystem();
        seatSystem = new SeatBookingSystem();
    }

    ~CinemaFacade()
    {
        delete ticketSystem;
        delete popcornSystem;
        delete seatSystem;
    }

    int HaveGoodMovieNight()
    {
        int ticket = ticketSystem->BuyTicket();
        int popcorn = popcornSystem->BuyPopcorn();
        int seat = seatSystem->BookSeat();

        return ticket + popcorn + seat;
    }
};

int main()
{
    CinemaFacade* cinema = new CinemaFacade();

    int totalPrice = cinema->HaveGoodMovieNight();

    cout << "Total price: " << totalPrice;

    delete cinema;

    return 0;
}