#include <iostream>
#include <string>
#include <vector>

struct TicketRequest {
    std::string destination;
    std::string flight_number;
    std::string passenger_name;
    std::string departure_date;

    TicketRequest(const std::string& dest, const std::string& flight, const std::string& name, const std::string& date)
        : destination(dest), flight_number(flight), passenger_name(name), departure_date(date) {}
};
template <typename T>
class ListNode {
public:
    T value;
    ListNode* next;

    ListNode(const T& val) : value(val), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}
    void add(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
    }
    void remove(const T& value) {
        ListNode<T>* temp = head;
        ListNode<T>* prev = nullptr;
        while (temp != nullptr && temp->value.flight_number != value.flight_number) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void printAll() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << "Destination: " << temp->value.destination
                      << ", Flight Number: " << temp->value.flight_number
                      << ", Passenger Name: " << temp->value.passenger_name
                      << ", Departure Date: " << temp->value.departure_date << std::endl;
            temp = temp->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<TicketRequest> ticketRequests;
    ticketRequests.add(TicketRequest("New York", "NY123", "Ivanov I.I.", "2024-05-20"));
    ticketRequests.add(TicketRequest("Tokyo", "TK789", "Petrov P.P.", "2024-06-15"));
    ticketRequests.printAll();
    ticketRequests.remove(TicketRequest("", "NY123", "", "")); 
    ticketRequests.printAll();

    return 0;
}