//Lottery Scheduling Source Code

//header files
#include<iostream>
#include<vector>
#include<random>


//Process class implementation
class Process
{
  private:
  int id;
  int tickets;

  public:
    
    //Constructor with parameters
  Process(int id, int tickets): id(id), tickets(tickets)
  {}

    //Function to return process id
  int getId()
  {
    return id;
  }

    //Function to return number of tickets
  int getTickets()
  {
    return tickets;
  }

};

//Scheduler Class Implementation
class Scheduler
{
  private:
  std::vector<Process> processes;
  std:: random_device rd; //generates random number(random_device type from random header)
  std:: mt19937 rng; //Mersenne Twister pseudorandom number generator engine

  public:
  
    //Default constructor
  Scheduler(): rng(rd()) //generating random number
  {}

    //Function to add process to scheduler vector stack
  void addProcess(Process& process)
  {
    processes.push_back(process);
  }

    //Function to allocate tickets to process between 0 - 100
  void allocateTickets()
  {
    int total_tickets = 0;
    for(Process& process : processes)
    {
      total_tickets += process.getTickets();    //total number of tickets
    }

    for(Process& process : processes)
    {
      double ratio = double(process.getTickets()) / total_tickets;
      int allocated_tickets = static_cast<int>(ratio * 100);    //truncating the decimals and converting tickets between 0 to 100
      process = Process(process.getId(), allocated_tickets);    //modifying processes with new allocated tickets
    }
  }

    //function that returns winner process
  Process scheduleWinner()
  {

    int winner_ticket = rng() % 100 + 1;    //generating random number between 1 and 100

    int current_ticket = 0;
    for(Process& process : processes)
    {
      current_ticket += process.getTickets();       //iteration that returns winner process
      if(winner_ticket <= current_ticket)
        return process;
    }

    throw std::runtime_error("No winning ticket found!");   //throw error if value not found(impossible if program is correct)

  }

};

int main()
{
    //initializing three processes
  Process process1(1, 33);
  Process process2(2, 33);
  Process process3(3, 33);
    

  Scheduler scheduler;
    //pushing processes into scheduler
  scheduler.addProcess(process1);
  scheduler.addProcess(process2);
  scheduler.addProcess(process3);

    //function call to allocate tickets
  scheduler.allocateTickets();

    //function call to find winner process
  Process winner = scheduler.scheduleWinner();

    //print winner process
  std::cout<< "Process " << winner.getId() << " wins the loterry!" << std::endl;
    
    return 0;

}

