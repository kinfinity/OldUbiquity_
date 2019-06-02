/*
 *logBuffer header
 *holds two pointers to form
 * Linked ptr Queue which holds nodes containing the logData
 * new logData is pushed onto the Queue
 * when full:
	-the pointers swap references
	-the Queue is sorted then popped till the end into the logPolicies' holder for flushing to different streams based on logPolicy
 *
 * and the
 */
#pragma once
#include "logConstants.h"

using namespace std;

namespace k_logger {

	template <typename T>
	class logBuffer
	{
	private:
		struct node {
			std::shared_ptr<T> data;
			node* next;
			node() : next(nullptr) {}
		};
		std::atomic<node*> head;
		std::atomic<node*> tail;
		std::atomic<node*> aux_ptr;//temp pointer for sorting the list

		node* pop_head() {
			node* const old_head = head.load();
			if (old_head == tail.load()) {
				return nullptr;
			}
			head.store(old_head->next);
			return old_head;
		};
	public:
		logBuffer() : head(new node), tail(head.load()) {};
		logBuffer(const logBuffer& other) = delete;
		logBuffer& operator=(const logBuffer& other) = delete;
		node& operator=(const node& other) = delete;

		void bufferSwap() {
			// swap pointer references;
			std::swap(head, aux_ptr);
			head = nullptr;
			tail = nullptr;
		};
		void sortList() {
			// sort list

		};
		~logBuffer() {
			while (node * const old_head = head.load()) {
				head.store(old_head->next);
				delete old_head;
			}
		};
		std::shared_ptr<T> pop() {
			node* old_head = pop_head();
			if (!old_head) {
				return std::shared_ptr<T>();
			}
			std::shared_ptr<T> const res(old_head->data);
			delete old_head;
			return res;
		}
		void push(T new_value) {
			std::shared_ptr<T> new_data(std::make_shared<T>(new_value));
			node* p = new node;
			node* const old_tail = tail.load();
			old_tail->data.swap(new_data);
			old_tail->next = p;
			tail.store(p);
		}
	};
}

/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */