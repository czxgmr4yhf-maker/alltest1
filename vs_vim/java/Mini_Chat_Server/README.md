# Mini Chat Room（Java）

一个基于 Java 的简易聊天室项目，用于练习：

- 类设计（User / Message / ChatRoom）
- 集合（List / Set / Map）
- 基础多线程（Thread）

---

## 项目结构

```text
MiniChat/
├── src/
│   ├── Main.java
│   ├── chat/
│   │   ├── ChatRoom.java
│   │   ├── User.java
│   │   └── Message.java
│   ├── thread/
│   │   └── UserThread.java
```

---

## 核心设计

### User（用户）
- `username`：用户名
- `online`：是否在线
- `messageCount`：发送消息数量

### Message（消息）
- `sender`：发送者
- `content`：消息内容

### ChatRoom（聊天室）
- `Set<String> users`：用户集合
- `List<Message> messages`：聊天记录

---

## 功能

- 用户加入聊天室
- 发送消息
- 查看在线用户 `/users`
- 查看聊天记录 `/history`

---

## 运行方式

```bash
javac Main.java
java Main
```

---

## 使用示例

```text
1:Hello
2:Hi
/users
/history
```

---

## 当前限制

- 输入由 `Main` 统一处理，不是真实多用户输入
- 多线程目前主要用于结构演示
- 暂不支持网络通信

---

## 后续扩展

- 私聊功能
- 多线程消息队列
- Socket 网络聊天室
- GUI 界面

---

## 学习收获

- 面向对象设计
- Java 集合使用
- 多线程基础理解
- 简单系统架构能力
