#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Client {
    int code;
    int duration;
    int year;
    int month;
};

bool compareByMonths(const std::pair<int, int>& client1, const std::pair<int, int>& client2) {
    if (client1.second == client2.second) {
        return client1.first < client2.first;
    }
    return client1.second < client2.second;
}

bool compareByTotalDuration(const std::pair<int, int>& month1, const std::pair<int, int>& month2) {
    if (month1.second == month2.second) {
        return month1.first < month2.first;
    }
    return month1.second > month2.second;
}

void STL7Mix5(const std::vector<Client>& clients) {
    std::map<int, int> clientMonths;

    for (const Client& client : clients) {
        int key = client.code;
        clientMonths[key]++;
    }

    std::vector<std::pair<int, int>> sortedClients(clientMonths.begin(), clientMonths.end());
    std::sort(sortedClients.begin(), sortedClients.end(), compareByMonths);

    for (const auto& client : sortedClients) {
        std::cout << "Number of months: " << client.second << ", Client code: " << client.first << std::endl;
    }
}

void STL7Mix6(const std::vector<Client>& clients) {
    std::vector<std::pair<int, int>> months(12, { 0, 0 });

    for (const Client& client : clients) {
        int month = client.month - 1;
        months[month].first += client.duration;
        months[month].second = month + 1;
    }

    std::sort(months.begin(), months.end(), compareByTotalDuration);

    for (const auto& month : months) {
        std::cout << "Sum duration: " << month.first << ", Month number: " << month.second << std::endl;
    }
}

void STL7Mix7(const std::vector<Client>& clients, int clientCode) {
    std::map<int, std::pair<int, int>, std::greater<int>> yearMonths;

    for (const Client& client : clients) {
        if (client.code == clientCode) {
            int year = client.year;
            int month = client.month;
            int duration = client.duration;

            if (yearMonths.find(year) == yearMonths.end()) {
                yearMonths[year] = { duration, month };
            }
            else if (yearMonths[year].first < duration) {
                yearMonths[year] = { duration, month };
            }
        }
    }

    for (const auto& yearMonth : yearMonths) {
        std::cout << "Year: " << yearMonth.first << ", Number of month with bbigest duration: " << yearMonth.second.second << std::endl;
    }
}

void STL7Mix8(const std::vector<Client>& clients, int clientCode) {
    std::map<int, std::pair<int, int>> yearMonths;

    for (const Client& client : clients) {
        if (client.code == clientCode) {
            int year = client.year;
            int month = client.month;
            int duration = client.duration;

            if (yearMonths.find(year) == yearMonths.end()) {
                yearMonths[year] = { duration, month };
            }
            else if (yearMonths[year].first > duration) {
                yearMonths[year] = { duration, month };
            }
        }
    }

    for (const auto& yearMonth : yearMonths) {
        std::cout << "Year: " << yearMonth.first << ", Number of month with smalest duration: " << yearMonth.second.second << std::endl;
    }
}

void task1() {

    std::vector<Client> clients = {
        { 1, 30, 2021, 1 },
        { 2, 20, 2021, 1 },
        { 1, 40, 2021, 2 },
        { 2, 10, 2021, 2 },
        { 3, 50, 2021, 2 },
        { 1, 25, 2022, 1 },
        { 2, 35, 2022, 1 },
        { 1, 15, 2022, 2 },
        { 2, 45, 2022, 2 },
        { 3, 5, 2022, 2 }
    };

    STL7Mix5(clients);
    STL7Mix6(clients);
    STL7Mix7(clients, 1);
    STL7Mix8(clients, 1);


}