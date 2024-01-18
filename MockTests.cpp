#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace std;
using ::testing::_;
using ::testing::Return;


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

    void addData(int data) {
        queue.enqueue(data);
    }

    int getData() {
        return queue.dequeue();
    }
private:
    QueueInterface &queue;
};


TEST(GMockTests, CanAddData) {
    MockQueue mq;
    DataHolder dh(mq);
    EXPECT_CALL(mq, enqueue(_));
    dh.addData(1);
}


TEST(GMockTests, CanAddAndGetData) {
    MockQueue mq;
    DataHolder dh(mq);
    EXPECT_CALL(mq, enqueue(1));
    EXPECT_CALL(mq, dequeue()).WillOnce(Return(1));
    dh.addData(1);
    ASSERT_EQ(1, dh.getData());
}
