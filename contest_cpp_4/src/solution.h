#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this->name = name;
    this->login = login;
    this->maxLoad = maxLoad;
}


// task 2
int Task::getTotalLoad() const
{
    int totalLoad = 0;
    for (const auto& workload : workloads) {
        totalLoad += workload.second;
    }
    return totalLoad;
}

// Custom comparator
bool compareTasks(const Task& task1, const Task& task2) {
    // by total workload
    if (task1.getTotalLoad() != task2.getTotalLoad())
        return task1.getTotalLoad() < task2.getTotalLoad();
    // compare by date
    if (task1.date != task2.date)
        return task1.date < task2.date;
    // compare by text
    return task1.text < task2.text;
}

void sortTasks(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareTasks);
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int totalLoad = 0;
    for (const auto& task : allTasks) {
        auto workloadIt = task.workloads.find(worker.login);
        if (workloadIt != task.workloads.end())
            totalLoad += workloadIt->second;
    }
    return totalLoad;
}
// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers) {
    for (const auto& worker : workers) {
        int totalLoad = 0;
        auto it = newTask.workloads.find(worker.login);
        if (it != newTask.workloads.end()) {
            totalLoad = getWorkerLoad(tasks, worker) + it->second;
            if (totalLoad > worker.maxLoad) {
                throw std::runtime_error("Overworked");
            }
        }
    }

    tasks.push_back(newTask);
}

// task 6


void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers) {
    std::map<std::string, int> a;

    tasks.emplace_back(newTask);

    for (const auto& worker : workers) {
        if (newTask.workloads.count(worker.login) > 0) {
            int totalLoad = getWorkerLoad(tasks, worker);
            if (totalLoad > worker.maxLoad)
                a.emplace(worker.login, totalLoad - worker.maxLoad);
        }
    }
    int c = 0;
    if (!a.empty()) {
        std::string s = "Overworked: ";
        for (const auto& pair : a) {
            c++;
            if (c != a.size()) (s += ", ");
            s += pair.first + " by " + std::to_string(pair.second);
        }
        throw std::runtime_error(s);
    }
}

