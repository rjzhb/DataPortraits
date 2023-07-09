//
// Created by 86183 on 2023/7/9.
//

#ifndef DATAPORTRAITS_TASKQUEUE_H
#define DATAPORTRAITS_TASKQUEUE_H


#include <queue>
#include <atomic>
#include <vector>
#include <iostream>
#include "dataloader.h"

struct Task {
    std::vector<char> data;
    size_t start_pos;
};

class TaskQueue {
public:
    explicit TaskQueue(size_t capacity) : head_(0), tail_(0), queue_(capacity) {}

    void push(const Task &task);

    bool pop(Task &task);

    // Check if the queue is empty
    bool empty() const;


private:
    std::atomic<size_t> head_{0};
    std::atomic<size_t> tail_{0};
    std::vector<Task> queue_;
};


void process_worker(DataLoader &loader, TaskQueue &queue);

#endif //DATAPORTRAITS_TASKQUEUE_H
