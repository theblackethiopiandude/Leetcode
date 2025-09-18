// Readable but getting TLE
class TaskManager(tasks: List<List<Int>>) {
    class Task(val userId: Int, val taskId: Int, val priority: Int){}
    val q = PriorityQueue<Task>(
        compareByDescending<Task> { it.priority }
            .thenByDescending { it.taskId }
    )

    init{        
        tasks.forEach {q.add(Task(it[0], it[1], it[2]))}
    }

    fun add(userId: Int, taskId: Int, priority: Int) {
        q.add(Task(userId, taskId, priority))
    }

    fun edit(taskId: Int, newPriority: Int) {
        val task = q.find { it.taskId == taskId }!!

        q.remove(task)
        q.add(Task(task.userId, task.taskId, newPriority))
    }

    fun rmv(taskId: Int) {
        q.removeIf { it.taskId == taskId }
    }

    fun execTop(): Int {
        return q.poll()?.userId ?: -1
    }

}

-----------------

class TaskManager(tasks: List<List<Int>>) {
    class Task(val userId: Int, val taskId: Int, val priority: Int, var active: Boolean = true){}
    val q = PriorityQueue<Task>(
        compareByDescending<Task> { it.priority }
            .thenByDescending { it.taskId }
    )

    private val taskMap = mutableMapOf<Int, Task>()

    init{        
        tasks.forEach {
            add(it[0], it[1], it[2])
        }
    }

    fun add(userId: Int, taskId: Int, priority: Int) {
        val t = Task(userId, taskId, priority)
        q.add(t)
        taskMap[t.taskId] = t
    }

    fun edit(taskId: Int, newPriority: Int) {
        val old = taskMap[taskId]!!
        old.active = false
        val t = Task(old.userId, old.taskId, newPriority)
        q.add(t)
        taskMap[taskId] = t
    }

    fun rmv(taskId: Int) {
        taskMap[taskId]!!.active = false
    }

    fun execTop(): Int {
        while (q.isNotEmpty() && !q.peek().active) {
            q.poll()
        }
        
        return q.poll()?.userId ?: -1
    }

}

/**
 * Your TaskManager object will be instantiated and called as such:
 * var obj = TaskManager(tasks)
 * obj.add(userId,taskId,priority)
 * obj.edit(taskId,newPriority)
 * obj.rmv(taskId)
 * var param_4 = obj.execTop()
 */
