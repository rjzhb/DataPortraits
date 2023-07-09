//
// Created by 86183 on 2023/7/9.
//
#include "task_queue.h"

void process_worker(DataLoader& loader, TaskQueue& queue) {
    Task task;
    while (queue.pop(task)) {
        loader.processBlock(task.data);
    }
}

void TaskQueue::push(const Task& task) {
    size_t tail = tail_.load(std::memory_order_relaxed);
    queue_[tail] = task;
    tail_.store((tail + 1) % queue_.size(), std::memory_order_release);
}

bool TaskQueue::pop(Task& task) {
    size_t head = head_.load(std::memory_order_relaxed);
    if (head == tail_.load(std::memory_order_acquire)) {
        return false;
    }
    task = queue_[head];
    head_.store((head + 1) % queue_.size(), std::memory_order_release);
    return true;
}


bool TaskQueue::empty() const {
    return head_.load(std::memory_order_relaxed) == tail_.load(std::memory_order_relaxed);
}