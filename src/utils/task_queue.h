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

    auto push(const Task &task) -> void;
    auto pop(Task &task) -> bool;

    // Check if the queue is empty
    auto empty() const -> bool;


private:
    std::atomic<size_t> head_{0};
    std::atomic<size_t> tail_{0};

    std::vector<Task> queue_;
};


auto process_worker(DataLoader &loader, TaskQueue &queue) -> void;

#endif //DATAPORTRAITS_TASKQUEUE_H
