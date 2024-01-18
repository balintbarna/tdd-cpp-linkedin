#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace std;


class QueueInterface {
public:
    virtual void enqueue(int data) = 0;
    virtual int dequeue() = 0;
};


class MockQueue : public QueueInterface {
public:
    MOCK_METHOD0(dequeue, int());
    MOCK_METHOD1(enqueue, void(int data));
};


class DataHolder {
public:
    DataHolder(QueueInterface &queue) : queue(queue) {}
private:
    QueueInterface &queue;
};


TEST(GMockTests, CanInstantiateDataHolder) {
    MockQueue myqueue;
    DataHolder dh(myqueue);
}
