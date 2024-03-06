#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

// here we include your solution
#include "solution.h"

Worker readWorker(std::istream& istr)
{
    std::string line;
    std::getline(istr, line);

    std::stringstream sstr(line);

    std::string name;
    sstr >> name;
    std::string login;
    sstr >> login;
    int maxWorkload = 0;
    sstr >> maxWorkload;

    Worker worker(name, login, maxWorkload);
    return worker;
}


Task readTask(std::istream& istr)
{
    std::string line;
    std::getline(istr, line);
    std::stringstream sstr(line);

    std::string text;
    std::getline(sstr, text, ',');

    std::string date;
    std::getline(sstr, date, ',');

    std::string buffer;
    std::map<std::string, int> workloads;
    while (std::getline(sstr, buffer, ','))
    {
        std::stringstream sstr2(buffer);
        std::string login;
        int load;
        sstr2 >> login;
        sstr2 >> load;
        workloads.insert({login, load});
    }
    Task task(text, date, workloads);
    return task;
}


void readData(const std::string& fileName, std::vector<Task>& tasks, std::vector<Worker>& workers)
{
    std::ifstream istr(fileName);
    if (!istr.is_open())
        throw std::runtime_error("Can't open file");

    std::string buffer;
    std::getline(istr, buffer);
    int taskCount = std::stoi(buffer);

    for (int i = 0; i < taskCount; ++i)
    {
        Task task = readTask(istr);
        tasks.push_back(task);
    }

    std::getline(istr, buffer);
    int workerCount = std::stoi(buffer);

    for (int i = 0; i < workerCount; ++i)
    {
        Worker worker = readWorker(istr);
        workers.push_back(worker);
    }
}

void printTasks(const std::vector<Task>& tasks)
{
    for (const Task& task: tasks)
    {
        std::cout << task.text << " ";
        std::cout << task.date << " ";
        for (const Task::Workload& w: task.workloads)
        {
            std::cout << w.first << " " << w.second << " ";
        }
        std::cout << std::endl;
    }
}


void printWorkers(const std::vector<Worker>& workers)
{
    for (const Worker& worker: workers)
    {
        std::cout << worker.name << " ";
        std::cout << worker.login << " ";
        std::cout << worker.maxLoad;
        std::cout << std::endl;
    }
}


// TODO: put the full path to the given file tasks_workers.txt in your system
const char* DATA_FILE_NAME = "../data/tasks_workers.txt";

// reads and prints data
void test1()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    std::cout << "Test1\n";
    printTasks(tasks);
    printWorkers(workers);
}


// gets total workloads of tasks and prints them
void test2()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    std::cout << "Test2\n";
    for (const Task& t: tasks)
    {
        int total = t.getTotalLoad();
        std::cout << total << std::endl;
    }
}

// Prints sorted task vector
void test3()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    std::cout << "Test3\n";
    sortTasks(tasks);
    printTasks(tasks);
}

// Gets total workload of each worker, prints their name and workload
void test4()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    std::cout << "Test4\n";
    for (const Worker& worker: workers)
    {
        int total = getWorkerLoad(tasks, worker);
        std::cout << worker.login << " " << total << std::endl;
    }
}

// Tries to add a new task to the tasks vector
// If successful, prints tasks
// If failed, prints the error message
void test5()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    // adds the last task again
    Task newTask = tasks.back();

    std::cout << "Test5\n";
    try
    {
        addTask(tasks, newTask, workers);
        std::cout << "Added successfully\n";
        printTasks(tasks);

    } catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// Tries to add a new task to the tasks vector
// If successful, prints tasks
// If failed, prints the error message
void test6()
{
    std::vector<Task> tasks;
    std::vector<Worker> workers;
    readData(DATA_FILE_NAME, tasks, workers);

    // adds the last task again
    Task newTask = tasks.back();

    std::cout << "Test6\n";
    try
    {
        addTaskVerbose(tasks, newTask, workers);
        std::cout << "Added successfully\n";
        printTasks(tasks);

    } catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
