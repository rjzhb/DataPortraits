//
// Created by 86183 on 2023/7/9.
//
#include "task_queue.h"

auto process_worker(DataLoader &loader, TaskQueue &queue) -> void {
    Task task;
    while (queue.pop(task)) {
        loader.processBlock(task.data);
    }
}

auto TaskQueue::push(const Task &task) -> void {
    size_t tail = tail_.load(std::memory_order_relaxed);
    queue_[tail] = task;
    tail_.store((tail + 1) % queue_.size(), std::memory_order_release);
}

auto TaskQueue::pop(Task &task) -> bool {
    size_t head = head_.load(std::memory_order_relaxed);
    if (head == tail_.load(std::memory_order_acquire)) {
        return false;
    }
    task = queue_[head];
    head_.store((head + 1) % queue_.size(), std::memory_order_release);
    return true;
}


auto TaskQueue::empty() const -> bool {
    return head_.load(std::memory_order_relaxed) == tail_.load(std::memory_order_relaxed);
}