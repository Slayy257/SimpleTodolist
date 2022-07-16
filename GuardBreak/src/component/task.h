#pragma once
#include <string>
#include <vector>
#include <utility>

enum class taskState {
	Done,
	NotDone
};

class Task
{
public:

	inline static void add_task(std::string taskName) { std::pair<std::string, taskState> task_pair = std::make_pair(taskName, taskState::NotDone); v_task.push_back(task_pair); };
	inline static void remove_task(int taskId) { if (v_task.size() > taskId) { v_task.erase(v_task.begin() + taskId); } };
	inline static void set_task_state(int taskId, taskState state) { if (v_task.size() > taskId) { v_task.at(taskId).second = state; } };
	inline static size_t get_lenght() { return v_task.size(); };
	inline static std::pair<std::string, taskState> get_task(int taskId) { return v_task.at(taskId); };

private:
	inline static std::vector<std::pair<std::string, taskState>> v_task;
};